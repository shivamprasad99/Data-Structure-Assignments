#include "entry.hpp"

entry::entry(const string& k,const string& v){
        _key=k;
        _value=v;
    }
const string& entry::key() const{
        return _key;
    }
const string& entry::value() const{
        return _value;
    }
void entry::setKey(const string& k){
        _key=k;
    }
void entry::setValue(const string& v){
        _value=v;
    }