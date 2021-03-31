#include<iostream>
#include<fstream>
#include<stack>

using namespace std;

ofstream fout("result.txt");
#define out cout

bool check(const string& s);

int main(){
    int N;
    string s;
    cin>>N;
    getline(cin, s);
    while(N--){
        getline(cin, s);
        if(check(s)){
            out<<"Yes\n";
        }else{
            out<<"No\n";
        }
    }
}

bool check(const string& s){
    if(s == ""){
        return true;
    }
    stack<char> parenthes_stack;
    for(const char& c : s){
        if(c == '(' || c == '['){
            parenthes_stack.push(c);
        }else{
            if(parenthes_stack.empty()){
                return false;
            }
            if(c == ')'){
                if(parenthes_stack.top() == '('){
                    parenthes_stack.pop();
                }else{
                    break;
                }
            }else if(c == ']'){
                if(parenthes_stack.top() == '['){
                    parenthes_stack.pop();
                }else{
                    break;
                }
            }
        }
    }
    return parenthes_stack.empty();
}
