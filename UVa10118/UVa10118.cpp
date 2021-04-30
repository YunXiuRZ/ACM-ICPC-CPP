#include<iostream>
#include<fstream>
#include<vector>
#include<cstring>

using namespace std;

ofstream fout("result.txt");
#define out cout

struct Basket{
    int candies[21] = {0};
    int size = 0;

    Basket(){}

    bool is_full(){
        return size == 5;
    }

    void put(int color){
        candies[color]++;
        size++;
    }

    void take(int color){
        candies[color] = 0;
        size--;
    }
};

int result[41][41][41][41], piles[4][41];

int dp(Basket &basket, vector<int> &status);

int main(){
    int n;
    while(cin>>n && n != 0){
        vector<int> status;
        status.assign(4, n);
        memset(result, -1, sizeof(result));
        for(int i = 0; i < n; i++){
            for(int j = 0; j < 4; j++){
                cin>>piles[j][n-i-1];
            }
        }
        Basket b;
        out<<dp(b, status)<<"\n";
    }
}

int dp(Basket &basket, vector<int> &status){
    int &r = result[status[0]][status[1]][status[2]][status[3]];
    if(r != -1){
        return r;
    }
    r = 0;
    if(basket.is_full()){
        return r;
    }

    int sum = 0;
    for(int i = 0; i < 4; i++){
        int &h = status[i];
        if(h == 0){
            continue;
        }
        h--;
        int &color = piles[i][h];
        if(basket.candies[color]){
            basket.take(color);
            sum = dp(basket, status)+1;
            basket.put(color);
        }else{
            basket.put(color);
            sum = dp(basket, status);
            basket.take(color);
        }
        h++;
        r = max(sum, r);
    }
    return r;
}
