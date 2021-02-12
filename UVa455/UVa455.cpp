#include<iostream>
#include<string>
#include<unistd.h>
using namespace std;

bool is_T(string s, int t){
    int l = s.length();
    for(int i = 0; i < l-t; i++){
        if(s[i] != s[i+t])
            return false;
    }
    return true;
}

int main(){
    int N;
    cin>>N;
    usleep(500 * 1000);
    while (N--) {
        string s;
        cin>>s;
        int l = s.length();
        for (int i = 1; i <= l; i++) {
            if (l%i != 0)
                continue;
            if (is_T(s, i)) {
                cout<<i<<endl;
                break;
            }
        }
        if (N == 0)
            break;
        cout<<endl; 
    }
}