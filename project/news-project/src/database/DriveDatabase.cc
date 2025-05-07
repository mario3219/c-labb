#include "DriveDatabase.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std::filesystem;

DriveDatabase::DriveDatabase() {
    dbPath = "Database";

    if (!exists(dbPath)){
        std::cout << "Tries to create Database directory" << std::endl;
        create_directory(dbPath);
        std::cout << "Created Database directory" << std::endl;
    } else {
        std::cout << "Database directory exists" << std::endl;
    }
}

std::string idConverter(int id, std::string name){
    std::string newsGrpId = std::to_string(id);
    if (id < 10){
        newsGrpId = "0" + newsGrpId;
    }
    std::string dirName = newsGrpId + name;
    return dirName;
}

int extractId(std::string fullString){
    int id;
    try {
        id = std::stoi(fullString.substr(0, 2));
    } catch (const std::invalid_argument&) {
        throw std::runtime_error("A directory or file has an invalid id");
    }
    return id;
}

std::vector<Newsgroup> DriveDatabase::listNewsgroups() const 
{
    std::vector<Newsgroup> result;
    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){
            Newsgroup newsgroup;

            std::string dirString = dir.path().filename().string();
            int dirId = extractId(dirString);
            std::string dirName = dirString.substr(2);

            newsgroup.id = dirId;
            newsgroup.name = dirName;
            result.push_back(newsgroup);

        }
    }
    return result;

}

bool DriveDatabase::createNewsgroup(const std::string &name)
{
    int nextId = 1;

    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){

            std::string dirString = dir.path().filename().string();
            int dirId = extractId(dirString);
            std::string dirName = dirString.substr(2);

            if (dirName == name){
                return false; //it already exists
            }
            nextId = dirId + 1;

            if (nextId > maxLimit){
                return false; //no more newsgroup ids available
            }

        }
    }
    std::string dirName = idConverter(nextId, name);
    create_directory(dbPath / dirName);

    return true;
}

bool DriveDatabase::deleteNewsgroup(int newsgroupId)
{

    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){

            std::string dirString = dir.path().filename().string();
            int dirId = extractId(dirString);
            
            if (dirId == newsgroupId){
                remove_all(dbPath / dirString);
                return true; //newsgroup deleted
            }

        }
    }
    return false;
}

std::vector<Article> DriveDatabase::listArticles(int id) const
{
    std::vector<Article> result;
    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){

            std::string dirString = dir.path().filename().string();
            int dirId = extractId(dirString);
            
            if (dirId == id){

                for(const auto& articleFile : directory_iterator(dbPath / dirString)){

                    std::string fileString = articleFile.path().filename().string();
                    int fileId = extractId(fileString);
                    std::string articleName = fileString.substr(2);

                    Article article;
                    article.title = articleName;
                    article.id = fileId;
                    result.push_back(article);

                }
                return result;

            }
        }
    }
    return result;
}

bool DriveDatabase::createArticle(int id, const std::string &title, const std::string &author, const std::string &content)
{

    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){

            std::string dirString = dir.path().filename().string();
            int dirId = extractId(dirString);
            
            if (dirId == id){

                int nextId = 1;

                for(const auto& articleFile : directory_iterator(dbPath / dirString)){

                    std::string fileString = articleFile.path().filename().string();
                    int fileId = extractId(fileString);
                    nextId = fileId + 1;

                    if (nextId > maxLimit){
                        return false; //no more article ids available
                    }

                }
        
                std::string fileName = idConverter(nextId, title);
        
                path articlePath = dbPath / dirString / fileName;
        
                std::ofstream articleFile(articlePath);
                if (articleFile.is_open()){
                    articleFile << "Title:    " << title << std::endl;
                    articleFile << "Author:   " << author << std::endl;
                    //articleFile << "---------" << std::endl;
                    articleFile << content << std::endl;
                    articleFile.close();
                } else {
                    std::cout << "Failed to create article" << std::endl;
                }
                return true;            
                
            }
        }
    }
    return false;
}

bool DriveDatabase::deleteArticle(int newsgroupId, int articleId)
{
    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){

            std::string dirString = dir.path().filename().string();
            int dirId = extractId(dirString);
            
            if (dirId == newsgroupId){

                for(const auto& articleFile : directory_iterator(dbPath / dirString)){

                    std::string fileString = articleFile.path().filename().string();
                    int fileId = extractId(fileString);

                    std::string articleName = fileString.substr(2);

                    if (fileId == articleId){
                        return remove(dbPath / dirString / fileString); //article deleted
                    }

                }
                
            }
        }
    }
    return false;
}

Article DriveDatabase::getArticle(int newsgroupId, int articleId) const
{
    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){

            std::string dirString = dir.path().filename().string();
            int dirId = extractId(dirString);
            
            if (dirId == newsgroupId){

                for(const auto& articleFile : directory_iterator(dbPath / dirString)){

                    std::string fileString = articleFile.path().filename().string();
                    int fileId = extractId(fileString);
                    std::string articleName = fileString.substr(2);

                    if (fileId == articleId){
                        std::ifstream articleFileName(articleFile.path());
                        std::string titleLine;
                        std::string authorLine;
                        std::string title;
                        std::string author;
                        std::string content;
                        if (std::getline(articleFileName, titleLine)){
                            title = titleLine.substr(10);

                        }
                        if (std::getline(articleFileName, authorLine)){
                            author = authorLine.substr(10);
                        
                            std::ostringstream ss;
                            ss << articleFileName.rdbuf();      
                            content = ss.str();
                            if (!content.empty() && content.back() == '\n') {
                                content.pop_back();
                            }
                        }
                    
                        Article article;
                        article.author = author;
                        article.title = title;
                        article.content = content;
                        article.id = fileId;
                        return article;
                    }

                }
                throw std::runtime_error("Article not found");  
            }
        }
    }
    throw std::runtime_error("Newsgroup not found");
}
