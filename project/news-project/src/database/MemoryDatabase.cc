#include "MemoryDatabase.h"

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

bool MemoryDatabase::createNewsgroup(const std::string &name) bool MemoryDatabase::deleteNewsgroup(std::string newsgroup_name)
{
}

std::vector<Article> MemoryDatabase::listArticles(std::string newsgroup_name) const
{
}

bool MemoryDatabase::createArticle(std::string newsgroup_name, const std::string &title, const std::string &author, const std::string &content)
{
}

bool MemoryDatabase::deleteArticle(std::string newsgroup_name, int articleId)
{
}

Article MemoryDatabase::getArticle(std::string newsgroup_name, int articleId) const
{
}
