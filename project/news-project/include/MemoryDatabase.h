#pragma once
#include "IDatabase.h"
#include <map>

class MemoryDatabase : public IDatabase
{
public:
    MemoryDatabase();

    std::vector<Newsgroup> listNewsgroups() const override;
    bool createNewsgroup(const std::string &name) override;
    bool deleteNewsgroup(std::string newsgroup_name) override;

    std::vector<Article> listArticles(std::string newsgroup_name) const override;
    bool createArticle(std::string newsgroup_name, const std::string &title, const std::string &author, const std::string &content) override;
    bool deleteArticle(std::string newsgroup_name, int articleId) override;
    Article getArticle(std::string newsgroup_name, int articleId) const override;

private:
    int nextNewsgroupId = 1;
    int nextArticleId = 1;

    std::map<std::string, Newsgroup> newsgroups;
};
