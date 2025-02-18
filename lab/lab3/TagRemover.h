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
<<<<<<< Updated upstream
        string getResult();
=======
        string specCharRemover(string& str);
>>>>>>> Stashed changes
    private:
        string text;
        string result;
};

#endif