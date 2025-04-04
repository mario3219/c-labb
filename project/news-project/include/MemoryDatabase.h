#pragma once
#include "IDatabase.h"
#include <map>

class MemoryDatabase : public IDatabase
{
public:
    MemoryDatabase();

    std::vector<Newsgroup> listNewsgroups() const override;
    bool createNewsgroup(const std::string &name) override;
    bool deleteNewsgroup(int id) override;

    std::vector<Article> listArticles(int newsgroupId) const override;
    bool createArticle(std::string Newsgroup, const std::string &title, const std::string &author, const std::string &content) override;
    bool deleteArticle(std::string Newsgroup, int articleId) override;
    Article getArticle(std::string Newsgroup, int articleId) const override;

private:
    int nextNewsgroupId = 1;
    int nextArticleId = 1;

    std::map<int, Newsgroup> newsgroups; // key = newsgroup id
};
