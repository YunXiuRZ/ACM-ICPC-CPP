#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    for (int i = 0; i < n; i++) {
        cin>>s;
        int count = 0, result = 0;
        for (char c : s) {
            if(c == 'O'){
                count++;
                result+=count;
            }else{
                count = 0;
            }
        }
        cout<<result<<endl;
    }
}