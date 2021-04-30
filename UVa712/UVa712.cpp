#include<iostream>
#include<fstream>
#include<string>
#include<cmath>

using namespace std;

ofstream fout("result.txt");
#define out cout

int main(){
    int N, M, count = 0;
    string s, leaves;
    while(cin>>N && N != 0){
        out<<"S-Tree #"<<++count<<":\n";
        string x;
        for(int i = 0; i < N; i++){
            cin>>s;
            x+= s[1];
        }
        cin>>leaves;
        cin>>M;
        for(int i = 0; i < M; i++) {
            cin>>s;
            int d = 0, u = 1;
            while (d < N) u = 2 * u + (s[x[d++]-'1'] - '0');
            out<<leaves[u - (1 << N)];
        }

        /*while(M--){
            cin>>s;
            int index = 0;
            for(int i = 0; i < x.length(); i++){
                int n = x[i]-'0';
                if(s[i] == '1'){
                    index+=pow(2, N - n);
                }
            }
            out<<leaves[index];
        }*/
        out<<"\n\n";
    }
}