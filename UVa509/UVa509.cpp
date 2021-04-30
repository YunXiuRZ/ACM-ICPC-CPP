#include<iostream>
#include<fstream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

ofstream fout("result.txt");
#define out fout

vector<string> disks;
int d, s, b;
int check;

string get_block(int x, int y);
void print_disks();
int binary_to_decimal(string s);
char to_char(int n);
string decode_level(int l);

int main(){
    int count = 0;
    while(cin>>d && d != 0){
        count++;
        char c;
        cin>>s>>b>>c;
        if(c == 'E'){
            check = 0;
        }else{
            check = 1;
        }
        string str;
        vector<int> xPos(s*b, -1)/*第幾行的x位於第幾個disk*/, lResult(s*b, 0);
        bool can_recover = true;//是否可以復原x
        disks.clear();
        for(int i = 0; i < d; i++){
            cin>>str;
            disks.push_back(str);
            if(!can_recover){
                continue;
            }
            for(int j = 0; j < str.length(); j++){
                if(str[j] == 'x'){
                    if(xPos[j] == -1){
                        xPos[j] = i;
                    }else{//一行有多個x
                        can_recover = false;
                        break;
                    }
                }else{
                    lResult[j] ^= str[j] - '0';
                }
            }
        }

        if(!can_recover){
            out<<"Disk set "<<count<<" is invalid.\n";
            continue;
        }


        bool can_decode = true;
        for(int i = 0; i < s*b; i++){
            if(xPos[i] == -1){
                if(lResult[i] != check){
                    can_decode = false;
                    break;
                }
                continue;
            }
            disks[xPos[i]][i] = check ^ lResult[i] + 48;
        }

        
        if(!can_decode){
            out<<"Disk set "<<count<<" is invalid.\n";
            continue;
        }
        out<<"Disk set "<<count<<" is valid, contents are: ";
        for(int i = 1; i <= b; i++){
            out<<decode_level(i);
        }
        out<<"\n";
    }
}



string get_block(int x, int y){
    string str;
    for(int i = (y-1)*s; i < y*s; i++){
        str+=disks[x-1][i];
    }
    return str;
}

void print_disks(){
    for(int i = 1; i <= b; i++){
        for(int j = 1; j <= d; j++){
            out<<get_block(j, i)<<" ";
        }
        out<<"\n";
    }
}

int binary_to_decimal(string s){
    int total = 0, d = 1;
    for(int i = 3; i >= 0; i--){
        if(s.at(i) == '1'){
            total+=d;
        }
        d*=2;
    }
    return total;
}

char to_char(int n){
    if(n < 10){
        return n + 48;
    }else{
        return n + 55;
    }
}

string decode_level(int l){
    int check_block = l%(d+1);
    string s, result;
    for(int i = 1; i <= d; i++){
        if(check_block == i){
            continue;
        }
        s+=get_block(i, l);
        if(s.length() >= 4){
            result+=to_char(binary_to_decimal(s.substr(0, 4)));
            s.erase(s.begin(), s.begin()+4);
        }
    }
    if(s.length() % 4 != 0){
        int n = 4 - s.length() % 4;
        for(int i = 0; i < n; i++){
            s+='0';
        }
        result+=to_char(binary_to_decimal(s));
    }
    return result;
}
