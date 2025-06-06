#pragma once
#include "IDatabase.h"
#include <map>

class MemoryDatabase : public IDatabase
{
public:
    MemoryDatabase();

    std::vector<Newsgroup> listNewsgroups() const override;
    bool createNewsgroup(const std::string &name) override;
    bool deleteNewsgroup(int newsgroupId) override;

    std::vector<Article> listArticles(int newsgroupId) const override;
    bool createArticle(int newsgroupId, const std::string &title, const std::string &author, const std::string &content) override;
    bool deleteArticle(int newsgroupId, int articleId) override;
    Article getArticle(int newsgroupId, int articleId) const override;

private:
    int nextNewsgroupId = 1;

    std::map<int, Newsgroup> newsgroups;
};
