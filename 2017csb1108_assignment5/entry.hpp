#ifndef ENTRY_HPP
#define ENTRY_HPP
#include <bits/stdc++.h>
using namespace std;
#define ll long long

template < typename K,typename V >
class entry{
public:
    entry(const K& k,const V& v){
      _key = k;
      _value = v;
    }
    entry(){
      
    }
    const K& key() const{
      return _key;
    }
    const V& value() const{
      return _value;
    }
    void setKey(const K& k){
      _key = k;
    }
    void setValue(const V& v){
      _value = v;
    }
private:
    K _key;
    V _value;
};

#endif
