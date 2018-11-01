#ifndef DICTIONARY_HPP
#define DICTIONARY_HPP
#include "entry.hpp"

class dictionary{
private:
    vector<entry*>  table;
    int size;
    int capacity;
    entry* empty;

    int hash1(string s);

   int hash2(int x);

    bool isDeleted(entry* p);
    int ReturnDistance(string a,string b);

public:

    dictionary(int cap);

    int Size();

    bool add(string s);

    string find(string w);

    bool remove(string w);

    list< pair<string,string> > spellcheck(string w);

    list< pair<string,string> > spellcheck2(string w);

};

#endif
