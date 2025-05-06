#include "DriveDatabase.h"
#include <stdexcept>
#include <iostream>
#include <fstream>

using namespace std::filesystem;

DriveDatabase::DriveDatabase() {
    std::cout << "Init drive Database" << std::endl;
    std::cout << "Current path: " << current_path() << std::endl;
    dbPath = "Database";

    if (!exists(dbPath)){
        std::cout << "Tries to create Database directory" << std::endl;
        create_directory(dbPath);
        std::cout << "Created Database directory" << std::endl;
    } else {
        std::cout << "Database directory exists" << std::endl;
    }

    for (const auto& dir : directory_iterator(dbPath)){
        if (is_directory(dir)){
            Newsgroup newsgroup;

            std::string dirString = dir.path().filename().string();
            int dirId = stoi(dirString.substr(0, 2));
            std::string dirName = dirString.substr(2);

            newsgroup.id = dirId;
            newsgroup.name = dirName;
            newsgroups[dirId] = newsgroup;
            nextNewsgroupId = dirId + 1;

            for(const auto& articleFile : directory_iterator(dbPath / dirString)){
                std::ifstream articleFileName(articleFile.path());
                std::string titleLine;
                std::string authorLine;
                std::string title;
                std::string author;
                std::string content;

                if (std::getline(articleFileName, titleLine)){
                    title = titleLine.substr(10);
                    //std::cout << title << std::endl; test
                }
                if (std::getline(articleFileName, authorLine)){
                    author = authorLine.substr(10);


                    std::ostringstream ss;
                    ss << articleFileName.rdbuf();      
                    content = ss.str();
                }
                std::string fileString = articleFile.path().filename().string();
                int fileId = stoi(fileString.substr(0, 2));
                std::string fileName = fileString.substr(2);
                

                Article article;
                article.author = author;
                article.title = title;
                article.content = content;
                article.id = fileId;
                newsgroups[dirId].articles.insert({article.id, article});
                nextArticleId = fileId + 1;
            }
        }
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

std::vector<Newsgroup> DriveDatabase::listNewsgroups() const // returns a vector of all newsgroups in the order they where created
{
    std::vector<Newsgroup> result;
    for (const auto &pair : newsgroups)
    {
        result.push_back(pair.second);
    }
    return result;
}

bool DriveDatabase::createNewsgroup(const std::string &name)
{

    //if (exists(dbPath / name))
    //{
    //    return false; // Newsgroup already exists
    //}

    if (newsgroups.find(name) != newsgroups.end())
    {
        return false; // Newsgroup already exists
    }

    std::string newsGrpId = std::to_string(nextNewsgroupId);
    if (nextNewsgroupId < 10){
        newsGrpId = "0" + newsGrpId;
    }
    std::string dirName = newsGrpId + name;
    Newsgroup newsgroup;
    newsgroup.id = nextNewsgroupId++;
    newsgroup.name = name;
    newsgroups[newsgroup.id] = newsgroup;


    //adding to disk
    std::string dirName = idConverter(newsgroup.id, name);
    create_directory(dbPath / dirName);


    return true;
}

bool DriveDatabase::deleteNewsgroup(int newsgroupId)
{
    //if (!(exists(dbPath / newsgroup_name)))
    //{
    //    return false; // Newsgroup does not exist
    //}
    auto it = newsgroups.find(newsgroup_name);
    
    if (it != newsgroups.end())
    {
        std::string dirName = idConverter(newsgroupId, it->second.name);
        remove_all(dbPath / dirName);
        newsgroups.erase(it);

        return true;
    }
    return false;
}

std::vector<Article> DriveDatabase::listArticles(int id) const
{
    std::vector<Article> result;
    auto it = newsgroups.find(id);
    if (it != newsgroups.end())
    {
        for (const auto &article : it->second.articles)
        {
            result.push_back(article.second);
        }
    }
    return result;
}

bool DriveDatabase::createArticle(int id, const std::string &title, const std::string &author, const std::string &content)
{
    //if (!(exists(dbPath / newsgroup_name)))
    //{
    //    return false;
    //}
    if (newsgroups.find(newsgroup_name) == newsgroups.end())
    {
        return false;
    }
    else
    {
        Article article;
        article.author = author;
        article.title = title;
        article.content = content;
        article.id = nextArticleId++;
        newsgroups[id].articles.insert({article.id, article});

        std::string dirName = idConverter(id, newsgroups[id].name);
        std::string fileName = idConverter(article.id, title);

        path articlePath = dbPath / dirName / fileName;

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

bool DriveDatabase::deleteArticle(int newsgroupId, int articleId)
{
    auto it = newsgroups.find(newsgroupId);
    if (it == newsgroups.end())
    {
        return false; // Newsgroup not found
    }
    auto articleIt = it->second.articles.find(articleId);
    if (articleIt == it->second.articles.end())
    {
        return false; // Article not found
    }
    // Remove the article from the newsgroup
    std::string dirName = idConverter(newsgroupId, newsgroups[newsgroupId].name);
    std::string fileName = idConverter(articleId, newsgroups[newsgroupId].articles[articleId].title);
    remove_all(dbPath / dirName / fileName);
    newsgroups[newsgroupId].articles.erase(articleId);
    return true;
}

Article DriveDatabase::getArticle(int newsgroupId, int articleId) const
{
    auto it = newsgroups.find(newsgroupId);
    if (it == newsgroups.end())
    {
        throw std::runtime_error("Newsgroup not found");
    }
    const auto &articles = it->second.articles.find(articleId);
    if (articles == it->second.articles.end())
    {
        throw std::runtime_error("Article not found");
    }
    return articles->second;
}
