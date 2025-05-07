#include "MemoryDatabase.h"
#include <stdexcept>

MemoryDatabase::MemoryDatabase() {}

std::vector<Newsgroup> MemoryDatabase::listNewsgroups() const
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

    for (auto &pair : newsgroups)
    {
        if (pair.second.name == name)
        {
            return false; // it already exists
        }
    }

    Newsgroup newsgroup;
    newsgroup.id = nextNewsgroupId++;
    newsgroup.name = name;

    newsgroups[newsgroup.id] = newsgroup;

    return true;
}

bool MemoryDatabase::deleteNewsgroup(int newsgroupId)
{
    auto it = newsgroups.find(newsgroupId);
    if (it != newsgroups.end())
    {
        newsgroups.erase(it);
        return true; 
    }
    return false; 
}

std::vector<Article> MemoryDatabase::listArticles(int id) const
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

bool MemoryDatabase::createArticle(int id, const std::string &title, const std::string &author, const std::string &content)
{
    if (newsgroups.find(id) == newsgroups.end())
    {
        return false;
    }
    else
    {
        Article article;
        article.author = author;
        article.title = title;
        article.content = content;
        article.id = newsgroups[id].nextArticleId++;
        newsgroups[id].articles.insert({article.id, article});
        return true;
    }
}

bool MemoryDatabase::deleteArticle(int newsgroupId, int articleId)
{
    auto it = newsgroups.find(newsgroupId);
    if (it == newsgroups.end())
    {
        return false;
    }
    auto articleIt = it->second.articles.find(articleId);
    if (articleIt == it->second.articles.end())
    {
        return false;
    }
    
    newsgroups[newsgroupId].articles.erase(articleId);
    return true; //article removed
}

Article MemoryDatabase::getArticle(int newsgroupId, int articleId) const
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
