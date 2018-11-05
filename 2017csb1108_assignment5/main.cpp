#include "avltree.hpp"

class stcompare{
  public:
    int operator()(const string& lhs, const string& rhs){
        if(lhs==rhs)
          return 0;
        else if(lhs<rhs)
          return 1;
        else 
          return -1;
    }
};

int main(){
  searchtree<string,string,stcompare> st;
  int choice=1;
  while(choice){
    cout<<"Enter\n1:Read entries from the file\n2:Create new entry and add to tree\n3:To get current size\n4:Delete a word from the tree\n5:Count the words in a given range\n6:To search\n7:To print levels\n";
    cin>>choice;
    switch(choice){
      case 1:{
        ifstream fin;
        cout<<"Enter the name of the file \n";
        string name;
        cin>>name;
        fin.open(name);
        while(fin){
          string s,word,meaning;
          getline(fin,s);
          transform(s.begin(),s.end(),s.begin(),::tolower);
          if(!fin)
            break;
          word = s.substr(0,min(s.find('\t'),s.find(' ')));
          meaning = s.substr(min(s.find('\t'),s.find(' '))+1);
          st.insert(word,meaning);
        }
        cout<<"--------------------------------------------------------------\n";
        fin.close();
        break;
      }
      case 2:{
        cout<<"Enter the word followed by the meaning\n";
        string s,word,meaning;
        getline(cin,s);
        getline(cin,s);
        transform(s.begin(),s.end(),s.begin(),::tolower);
        word = s.substr(0,min(s.find('\t'),s.find(' ')));
        meaning = s.substr(min(s.find('\t'),s.find(' '))+1);
        st.insert(word,meaning);
        cout<<"--------------------------------------------------------------\n";
        break;
      }
      case 3:{
        cout<<"The current size is "<<st.size()<<endl;
        cout<<"--------------------------------------------------------------\n";
        break;
      }
      case 4:{
        cout<<"Enter the word you want to delete from the tree\n";
        string w;
        cin>>w;
        st.remove(w);
        cout<<"--------------------------------------------------------------\n";
        break;
      }
      case 5:{
        list< entry<string,string> > ans;
        cout<<"Enter the range bounds k1 and k2\n";
        string k1,k2;
        cin>>k1>>k2;
        ans = st.countAllInRange(k1,k2);
        cout<<"Number of words = "<<ans.size()<<endl;;
        for(list< entry<string,string> >::iterator it = ans.begin();it!=ans.end();++it){
          cout<<(*it).key()<<"  ";
        }
        cout<<endl;
        cout<<"--------------------------------------------------------------\n";
        break;
      }
      case 6:{
        cout<<"Enter the word you want to search\n";
        string w;
        cin>>w;
        st.search(w);
        cout<<"--------------------------------------------------------------\n";
        break;
      }
      case 7:{
        st.printLevels();
        cout<<"--------------------------------------------------------------\n";
        break;
      }
      default:
        choice = 0;
        cout<<"--------------------------------------------------------------\n";
        break;
    }
  }
}
