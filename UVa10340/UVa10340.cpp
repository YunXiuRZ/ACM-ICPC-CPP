#include<iostream>
#include<string>
//#include<fstream>

using namespace std;

#define out cout
//ofstream fout("result.txt");

bool find_char(const char target, int &start_index, const string t){
    const int index_limit = t.length();
    while(t[start_index++] != target){
        if(start_index == index_limit){
            return false;
        }
    }
    return true;
}

int main(){
    string s, t;
    while(cin>>s>>t){
        int i = 0, j = 0;
        bool flag = true;
        const int i_limit = s.length();
        while(flag){
            if(find_char(s[i], j, t)){
                i++;
                if(i == i_limit){
                    break;
                }
            }else{
                flag = false;
                break;
            }
        }
        if(flag)
            out<<"Yes"<<endl;
        else
            out<<"No"<<endl;
    }
}