#include<iostream>
#include<string>
using namespace std;

int main(){
    int n;
    cin>>n;
    while (n--) {
        int N;
        cin>>N;
        string s;
        for (int i = 1; i <= N; i++) {
            s+=to_string(i);
        }
        int result[10];
        for(int i = 0; i < 10; i++)
            result[i] = 0;
        for (char c : s) {
            result[c-48]++;
        }
        
        for (int i = 0; i < 10; i++) {
            cout<<result[i];
            if (i != 9)
                cout<<" ";
        }
        cout<<endl;
    }
}