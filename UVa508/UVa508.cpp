#include<iostream>
#include<fstream>
#include<unordered_map>
#include<string>
#include<vector>
#include<map>

using namespace std;

ofstream fout("result.txt");
#define out cout

bool is_prefix(const string& s1, const string& s2);

unordered_map<char, string> table;
unordered_map<string, vector<string>> context;

int main(){
    char c;
    string s;
    cin>>c;
    do{
        cin>>s;
        table[c] = s;
        cin>>c;
    }while(c != '*');

    cin>>s;
    do{
        string buffer;
        for(char ch : s){
            buffer+=table[ch];
        }
        context[buffer].push_back(s);
        cin>>s;
    }while(s != "*");


    cin>>s;
    do{
        if(context.find(s) != context.cend()){
            out<<context[s][0];
            if(context[s].size() > 1){
                out<<"!\n";
            }else{
                out<<"\n";
            }
        }else{
            map<int, string> prefix;
            for(auto p : context){
                if(is_prefix(p.first, s)){
                    prefix[s.size()-p.first.size()] = p.first;
                }else if(is_prefix(s, p.first)){
                    prefix[p.first.size()-s.size()] = p.first;
                    
                }
            }
            out<<context[prefix.cbegin()->second][0]<<"?\n";
        }
        cin>>s;
    }while(s != "*");
}

bool is_prefix(const string& s1, const string& s2){
    return s1.size() <= s2.size() && s2.compare(0, s1.size(), s1) == 0;
}

