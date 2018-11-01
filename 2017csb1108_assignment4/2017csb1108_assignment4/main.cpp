#include "entry.hpp"
#include "dictionary.hpp"

int main(){
    int n=0,count=0,choice=1;
    cout<<"Enter the size of the table\n";
    cin>>n;
    dictionary dict(n);
    while(choice){
        cout<<"Enter\n1:Read entries from the file\n2:Create new entry and add to dictionary\n3:To get current size\n4:Delete a word from the dictionary\n5:Search for a word or similar words\n6:To exit\n";
        cin>>choice;
        switch(choice){
            case 1:{
                ifstream fin;
                cout<<"Enter the name of the file \n";
                string name;
                cin>>name;
                fin.open(name);
                int t;
                cout<<"Enter the number of words yout want to read from file\n";
                cin>>t;
                while(fin && t){
                    string s;
                    getline(fin,s);
                    bool b=dict.add(s);
                    if(!b)
                        cout<<s<<"Could not be added\n";
                    t--;
                }
                cout<<"--------------------------------------------------------------\n";
                break;
            }
            case 2:{
                cout<<"Enter the word followed by the meaning\n";
                string s;
                getline(cin,s);
                getline(cin,s);
                bool b=dict.add(s);
                if(!b){
                    cout<<"Could not be added\n";
				}
                else
                    cout<<"Added successfully\n";
                cout<<"--------------------------------------------------------------\n";
                break;
            }
            case 3:{
                cout<<"The current size is "<<dict.Size()<<endl;
                cout<<"--------------------------------------------------------------\n";
                break;
            }
            case 4:{
                cout<<"Enter the word you want to delete from the dictionary\n";
                string w;
                cin>>w;
                bool b=dict.remove(w);
                if(b)
                    cout<<"Removed successfully !\n";
                else
                    cout<<"Could not remove\n";
                cout<<"--------------------------------------------------------------\n";
                break;
            }
            case 5:{
                list< pair<string,string> > similar;
                cout<<"Enter the word you want to spellcheck\n";
                string w;
                cin>>w;
                similar=dict.spellcheck2(w);
                if(similar.size()!=0){
                    cout<<"Did you mean : \n";
                    for(list< pair<string,string> >::iterator it=similar.begin();it!=similar.end();it++){
                        cout<<(*it).first<<" : "<<(*it).second<<endl;
                    }
                }
                else{
                    cout<<"Could not find any similar word\n";
                }
                cout<<"--------------------------------------------------------------\n";
                break;
            }
            case 6:{
                choice=0;
                cout<<"--------------------------------------------------------------\n";
                break;
            }
            default:
                choice=0;
                cout<<"--------------------------------------------------------------\n";
                break;
        }
    }
}
