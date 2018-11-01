#ifndef ENTRY_HPP
#define ENTRY_HPP
#include <bits/stdc++.h>
using namespace std;
#define ll long long

class entry{
public:
    entry(const string& k,const string& v);
    const string& key() const;
    const string& value() const;
    void setKey(const string& k);
    void setValue(const string& v);
private:
    string _key;
    string _value;
};

#endif
