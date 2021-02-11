#include<iostream>
#include<string>
#include<unordered_map>
#include<iomanip>
using namespace std;

int main(){
    int n;
    cin>>n;
    string s;
    getline(cin, s);
    while (n--) {
        unordered_map<char, int> count;
        char element  = ' ';
        int amount = 0;
        getline(cin, s);
        for (char c : s) {
            if(isdigit(c)){
                amount = amount*10 + c-48;
            }else{
                if(amount == 0)
                    amount++;
                count[element]+=amount;
                element = c;
                amount = 0;
            }
        }
        if(amount == 0)
            amount++;
        count[element]+=amount;
        double result = count['C'] * 12.01 +
                        count['H'] * 1.008 +
                        count['N'] * 14.01 +
                        count['O'] * 16;
        cout<<fixed<<setprecision(3)<<result<<endl;
    }
}