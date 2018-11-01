#include "entry.hpp"
#include "dictionary.hpp"

int dictionary::hash1(string s) {   // polynomial hash function with value of prime p = 31
        ll sum=0,l=s.length();
        for(int i=0;i<l;i++){
            sum=(sum + (s[i]%capacity)*((ll)pow(31,l-i-1)%capacity))%capacity;
        }
        return sum%capacity;
   }

int dictionary::hash2(int x){
       return 13-x%13;
   }

bool dictionary::isDeleted(entry* p){
        return p==empty;
    }

int dictionary::ReturnDistance(string a,string b){
        int n,m,i,j,cost;
        n=a.length()+1; m=b.length()+1;
        int arr[m][n];
        for(i=0;i<m;i++){
            for(j=0;j<n;j++){
                arr[i][j]=0;
            }
        }
        for(i=0;i<n;i++){
            arr[0][i]=i;
        }
        for(i=0;i<m;i++){
            arr[i][0]=i;
        }
        for(i=1;i<n;i++){
            for(j=1;j<m;j++){
                if(a[i-1]==b[j-1]) cost=0;
                else cost=1;
                arr[j][i]=min(min(arr[j-1][i-1]+cost,arr[j-1][i]+1),arr[j][i-1]+1);
            }
        }
        return arr[m-1][n-1];
    }


dictionary::dictionary(int cap){
        capacity=cap+1;
        table.reserve(cap+1);
        for(int i=0;i<capacity;i++){
            table[i]=NULL;
        }
       empty=new entry("###","###");
       size=0;
    }

int dictionary::Size(){
        return size;
    }

bool dictionary::add(string s){
		if(size>=capacity-1){
			return false;		
		}
        string word = s.substr(0,min(s.find('\t'),s.find(' ')));
        string meaning = s.substr(min(s.find('\t'),s.find(' '))+1);
        entry* temp = new entry(word,meaning);
        if(find(word)!="NULL"){
            cout<<"The word is already present\n";
            return false;
        }
        int code=hash1(word),probe;
        cout<<word<<"  "<<code<<endl;
        if(table[code]==NULL || isDeleted(table[code])){
            table[code]=temp;
            cout<<word<<"INDEX = "<<code<<endl;
            probe=-1;
        }

        else{
            int j=1;
            probe=(code+j*hash2(code))%capacity;
            while(probe!=-1 && probe!=code){
				cout<<probe<<" ";
                if(table[probe]==NULL || isDeleted(table[code])){
                  table[probe]=temp;
                   cout<<word<<"INDEX = "<<probe<<endl;
                  probe=-1;
                }
                else{
                  j++;
                  probe=(code+j*hash2(code))%capacity;
                }
            }
        }
		cout<<endl;
        if(probe==code){
			cout<<"FUCK"<<endl;
          return false;
        }
        else{
          size++;
          return true;
        }
    }

string dictionary::find(string w){
        int code=hash1(w),probe;
        if(table[code]==NULL){
        //   cout<<"Could not find !\n";
          return "NULL";
        }
        else if(table[code]->key()==w){
          return table[code]->value();
        }
        else{
          int j=1;
          probe=(code+j*hash2(code))%capacity;
          while(probe!=-1 && probe!=code){
            if(table[probe]==NULL){
            //   cout<<"Could not find !\n";
              return "NULL";
            }
            else if(table[probe]->key()==w){
              return table[probe]->value();
            }
            else{
              j++;
              probe=(code+j*hash2(code))%capacity;
            }
          }
        }
        // cout<<"Could not find !\n";
        return "NULL";
    }

bool dictionary::remove(string w){
      int probe,code=hash1(w);
      if(table[code]==NULL){
        return NULL;
      }
      else if(table[code]->key()==w){
        entry* t=table[code];
        table[code]=empty;
        delete t;
        probe=-1;
        size--;
        return true;
      }
      else{
        int j=1;
        probe=(code+j*hash2(code))%capacity;
        while(probe!=-1 && probe!=code){
          if(table[probe]==NULL){
            // cout<<"Could not find !\n";
            return NULL;
          }
          else if(table[probe]->key()==w){
            entry* t=table[probe];
            table[probe]=empty;
            delete t;
            probe=-1;
            size--;
            return true;
          }
          else{
            j++;
            probe=(code+j*hash2(code))%capacity;
          }
        }
      }
    }

list< pair<string,string> > dictionary::spellcheck(string w){
        // first checking for swaps
        list< pair<string,string> > lss;
        string ans=find(w),temp=w;
        if(ans!="NULL"){
            lss.push_back(make_pair(w,ans));
        }
        else{
            for(int i=0;i<capacity;i++){
                if(table[i]!=NULL && !isDeleted(table[i])){
                    string s=table[i]->key();
                    if(ReturnDistance(s,w)<=2 /*&& abs(w.length()-s.length())<2*/){
                        lss.push_back(make_pair(s,table[i]->value()));
                    } 
                }
            }
        }
        return lss;
    }

list< pair<string,string> > dictionary::spellcheck2(string w){
        list< pair<string,string> > lss;
        string ans=find(w),temp=w;
        if(ans!="NULL"){
            lss.push_back(make_pair(w,ans));
        }
        else{
            // if not found then try for different words by swapping the characters
            for(int i=0;i<w.length()-1;i++){
                swap(temp[i],temp[i+1]);
                if(find(temp)!="NULL"){
                    lss.push_back(make_pair(temp,find(temp)));
                } 
                temp=w;       
            }
            // now check by inserting a single character between two characters in the word
			for(int i=0;i<=w.length();i++){
				temp="";
                for(int j=0;j<i;j++)
                    temp=temp+w[j];
                string t=temp;  // copy this substring in t;
                for(int j=97;j<=122;j++){
                    temp=temp+(char)j;  // add a random character to this substring
                    for(int k=i;k<w.length();k++)
                        temp=temp+w[k]; //complete this string
                    if(find(temp)!="NULL"){
                        lss.push_back(make_pair(temp,find(temp)));
                    }
                    temp=t; // remake the substring
                }
			}
            // now check by replacing a character
            for(int i=0;i<w.length();i++){
                temp=w;
                for(int j=97;j<=122;j++){
                    temp[i]=(char)j;
                    if(find(temp)!="NULL"){
                        lss.push_back(make_pair(temp,find(temp)));
                    }
                }
            }
            // now check by deleting characters
            for(int i=0;i<w.length();i++){
                temp="";
                for(int j=0;j<w.length();j++){
                    if(j!=i)
                    temp=temp+w[j];
                }
                if(find(temp)!="NULL"){
                   lss.push_back(make_pair(temp,find(temp)));
                }
            }	
        }
        return lss;
    }
