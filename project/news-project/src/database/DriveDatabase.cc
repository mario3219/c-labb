#include "DriveDatabase.h"
#include <stdexcept>

DriveDatabase::DriveDatabase() {}

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

    for (auto &pair : newsgroups)
    {
        if (pair.second.name == name)
        {
            return false; // Newsgroup already exists
        }
    }

    Newsgroup newsgroup;
    newsgroup.id = nextNewsgroupId++;
    newsgroup.name = name;

    newsgroups[newsgroup.id] = newsgroup;

    return true;
}

bool DriveDatabase::deleteNewsgroup(int newsgroupId)
{
    auto it = newsgroups.find(newsgroupId);
    if (it != newsgroups.end())
    {
        newsgroups.erase(it);
        return true;
    }
    return false; // Newsgroup not found
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
