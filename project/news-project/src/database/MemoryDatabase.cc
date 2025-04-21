#include "MemoryDatabase.h"
#include <stdexcept>

MemoryDatabase::MemoryDatabase() {}

std::vector<Newsgroup> MemoryDatabase::listNewsgroups() const // returns a vector of all newsgroups in the order they where created
{
    std::vector<Newsgroup> result;
    for (const auto &pair : newsgroups)
    {
        result.push_back(pair.second);
    }
    return result;
}

bool MemoryDatabase::createNewsgroup(const std::string &name)
{

    if (newsgroups.find(name) != newsgroups.end())
    {
        return false; // Newsgroup already exists
    }

    Newsgroup newsgroup;
    newsgroup.id = nextNewsgroupId++;
    newsgroup.name = name;

    newsgroups[name] = newsgroup;

    return true;
}

bool MemoryDatabase::deleteNewsgroup(std::string newsgroup_name)
{
    if (newsgroups.find(newsgroup_name) == newsgroups.end())
    {
        return false; // Newsgroup does not exist
    }
    else
    {
        newsgroups.erase(newsgroup_name);
        return true;
    }
}

std::vector<Article> MemoryDatabase::listArticles(std::string newsgroup_name) const
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

bool MemoryDatabase::createArticle(std::string newsgroup_name, const std::string &title, const std::string &author, const std::string &content)
{
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
        return true;
    }
}

bool MemoryDatabase::deleteArticle(std::string newsgroup_name, int articleId)
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

Article MemoryDatabase::getArticle(std::string newsgroup_name, int articleId) const
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
