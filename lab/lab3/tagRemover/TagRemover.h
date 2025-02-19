#ifndef TAGREMOVER_H
#define TAGREMOVER_H

using namespace std;

class TagRemover {
    public:
        TagRemover(std::istream& input);
        string specCharRemover();
        string removeTags();
        void print(std::istream& output);
        string getText();
    private:
        string text;
};

#endif