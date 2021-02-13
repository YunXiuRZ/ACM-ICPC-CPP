#include<iostream>
#include<vector>
//#include<fstream>
#include<algorithm>

using namespace std;

#define out cout
//ofstream fout("result.txt");

int main(){
    int n, m;
    while(cin>>n>>m){
        int time = n/m;
        out<<n<<"/"<<m<<" = "<<time<<".";
        n = n%m * 10;
        int count = 0;
        vector<int> record;
        record.push_back(n);
        while(n = n%m * 10, find(record.cbegin(), record.cend(), n) == record.cend()){
            count++;
            record.push_back(n);
        }
        int recycle_start = find(record.cbegin(), record.cend(), n) - record.cbegin(), recycle_count = count - recycle_start + 1;
        for(int i = 0; i < record.size(); i++){
            if(i == 50){
                out<<"...";
                break;
            }
            int r = record[i];
            if(r == n)
                out<<"(";
            out<<r/m;
        }

        out<<")"<<endl;
        out<<"   "<<recycle_count<<" = number of digits in repeating cycle"<<endl;
        out<<endl;
    }
}