#pragma once

#include <string>
#include <vector>
#include <optional>
#include <unordered_map>

struct Article
{
    int id;
    std::string title;
    std::string author;
    std::string content;
};

struct Newsgroup
{
    int id;
    int nextArticleId = 1;
    std::string name;
    std::unordered_map<int, Article> articles;
};

class IDatabase
{
public:
    virtual ~IDatabase() = default;

    virtual std::vector<Newsgroup> listNewsgroups() const = 0;
    virtual bool createNewsgroup(const std::string &name) = 0;
    virtual bool deleteNewsgroup(int newsgroupId) = 0;

    virtual std::vector<Article> listArticles(int newsgroupId) const = 0;
    virtual bool createArticle(int id, const std::string &title, const std::string &author, const std::string &content) = 0;
    virtual bool deleteArticle(int newsgroupID, int articleId) = 0;
    virtual Article getArticle(int newsgroupId, int articleId) const = 0;
};
