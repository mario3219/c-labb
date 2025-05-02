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
            newsgroups[dirName] = newsgroup;
            nextNewsgroupId = dirId + 1;
        }
    }
    

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
    newsgroups[name] = newsgroup;

    std::cout << "creates directory in Database" << std::endl;

    create_directory(dbPath / dirName); //add number to name: name + newsgroupId++.tostring

    return true;
}

bool DriveDatabase::deleteNewsgroup(std::string newsgroup_name)
{
    //if (!(exists(dbPath / newsgroup_name)))
    //{
    //    return false; // Newsgroup does not exist
    //}
    auto it = newsgroups.find(newsgroup_name);
    
    if (it != newsgroups.end())
    {   
        
        int newsId = it->second.id;
        std::string dirId = std::to_string(newsId);
        if (newsId < 10) {
            dirId = "0" + dirId;
        }
        remove_all(dbPath / (dirId + newsgroup_name));
        newsgroups.erase(newsgroup_name);
        return true;
    }
    return false;
}

std::vector<Article> DriveDatabase::listArticles(std::string newsgroup_name) const
{
    std::vector<Article> result;
    auto it = newsgroups.find(newsgroup_name);
    if (it != newsgroups.end())
    {
        for (const auto &article : it->second.articles)
        {
            result.push_back(article.second);
        }
    }
    return result;
}

bool DriveDatabase::createArticle(std::string newsgroup_name, const std::string &title, const std::string &author, const std::string &content)
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
        newsgroups[newsgroup_name].articles.insert({article.id, article});

        path articlePath = dbPath / newsgroup_name / (title + ".txt"); //add id to name

        std::ofstream articleFile(articlePath);
        if (articleFile.is_open()){
            articleFile << "Title: " << title << std::endl;
            articleFile << "Author: " << author << std::endl;
            articleFile << "---------" << std::endl;
            articleFile << content << std::endl;
            articleFile.close();
        } else {
            std::cout << "Failed to create article" << std::endl;
        }

        return true;
    }
}

bool DriveDatabase::deleteArticle(std::string newsgroup_name, int articleId)
{
    auto it = newsgroups.find(newsgroup_name);
    if (it != newsgroups.end())
    {
        auto articleIt = it->second.articles.find(articleId);
        if (articleIt != it->second.articles.end())
        {
            it->second.articles.erase(articleIt);
            return true;
        }
    }
    return false;
}

Article DriveDatabase::getArticle(std::string newsgroup_name, int articleId) const
{
    auto it = newsgroups.find(newsgroup_name);
    if (it != newsgroups.end())
    {
        auto articleIt = it->second.articles.find(articleId);
        if (articleIt != it->second.articles.end())
        {
            return articleIt->second;
        }
    }
    throw std::runtime_error("Article not found");
}
