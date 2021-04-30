#include<iostream>
#include<fstream>
#include<cstring>

using namespace std;

ofstream fout("result.txt");
#define out cout

int cherry[21][21][21][21], answer[21][21][21][21];

int cherry_count(int r, int c, int h, int w);

int dp(int r, int c, int h, int w);

int main(){
    int n, m, k;
    while(cin>>n>>m>>k){
        memset(answer, -1, sizeof(answer));
        memset(cherry, -1, sizeof(cherry));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= m; j++){
                cherry[i][j][1][1] = 0;
            }
        }
        while(k--){
            int r, c;
            cin>>r>>c;
            cherry[r][c][1][1] = 1;
        }
    }
}

int cherry_count(int r, int c, int h, int w){
    int &count = cherry[r][c][h][w];
    if(count != -1){
        return count;
    }

    if(h > 1){
        return count = cherry_count(r, c, 1, w) + cherry_count(r+1, c, h-1, w);
    }
    return count = cherry_count(r, c, 1, 1) + cherry_count(r, c+1, 1, w-1);
}

int dp(int r, int c, int h, int w){
    
}

