#ifndef TAGREMOVER_H
#define TAGREMOVER_H

using namespace std;

class TagRemover {
    public:
<<<<<<< HEAD
        TagRemover();
        string specCharRemover(string& str);

=======
        TagRemover(std::istream& input);
        string removeTags();
        string removeSpecChars();
        string print();
        string setString(string str);
>>>>>>> d712eb03f1280bad623dd3c70bd00d79d29c2b35
    private:
        string text;
        string result;
};

#endif