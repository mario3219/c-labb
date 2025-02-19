#ifndef TAGREMOVER_H
#define TAGREMOVER_H

using namespace std;

class TagRemover {
    public:
        TagRemover(std::istream& input);
        string specCharRemover();
        string removeTags();
        string removeSpecChars();
        string print();
        string setString(string str);
        string getText();
    private:
        string text;
};

#endif