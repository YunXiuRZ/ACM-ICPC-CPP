#include<iostream>
#include<fstream>
#include<string>
#include<algorithm>

using namespace std;

ofstream fout("result.txt");

#define out cout

struct surfaces{
    int a, b;
    surfaces():a(0), b(0){}
    surfaces(int c, int d):a(c > d ? d : c), b(c > d ? c : d){}
};
bool operator<(const surfaces s1, const surfaces s2){
    if(s1.a == s2.a){
        return s1.b < s2.b;
    }
    return s1.a < s2.a;
}
bool operator==(const surfaces s1, const surfaces s2){
    return s1.a == s2.a && s1.b == s2.b;
}

int main(){
    string s;
    while(cin>>s){
        surfaces a[3], b[3];
        for(int i = 0; i < 3; i++){
            a[i] = surfaces(s[i], s[5-i]);
            b[i] = surfaces(s[i+6], s[11-i]);
        }
        sort(a, a+3);
        sort(b, b+3);
        if(a[0] == b[0] && a[1] == b[1] && a[2] == b[2]){
            out<<"TRUE\n";
        }else{
            out<<"FALSE\n";
        }
    }
}