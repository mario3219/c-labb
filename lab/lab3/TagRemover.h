#ifndef TAGREMOVER_H
#define TAGREMOVER_H

using namespace std;

class TagRemover {
    public:
        TagRemover(std::istream& input);
        string removeTags();
        string removeSpecChars();
        string print();
        string setString(string str);
        string getText();
        string getResult();
    private:
        string text;
        string result;
};

#endif