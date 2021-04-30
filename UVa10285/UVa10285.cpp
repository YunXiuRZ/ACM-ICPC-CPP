#include<iostream>
#include<fstream>
#include<algorithm>
#include<string>
#include<vector>

using namespace std;

ofstream fout("result.txt");
#define out cout

int R, C;
vector<vector<int>> map, result;

int dp(int x, int y);

int main(){
    int N;
    cin>>N;
    while(N--){
        map.clear();
        map.shrink_to_fit();
        result.clear();
        result.shrink_to_fit();
        string name;
        cin>>name>>R>>C;
        map.reserve(R);
        result.reserve(R);
        for(int i = 0; i < R; i++){
            vector<int> v;
            v.reserve(C);
            vector<int> r;
            r.reserve(C);
            for(int j = 0; j < C; j++){
                int n;
                cin>>n;
                v.push_back(n);
                r.push_back(-1);
            }
            map.push_back(v);
            result.push_back(r);
        }

        int ans = 0;
        for(int i = 0; i < R; i++){
            for(int j = 0; j < C; j++){
                result[i][j] = dp(i, j);
                ans = max(ans, result[i][j]);
            }
        }
        out<<name<<": "<<ans<<'\n';
    }
}

int dp(int x, int y){
    int &ans = result[x][y];

    if(ans != -1){
        return ans;
    }

    int h = map[x][y];
    if(x > 0 && h > map[x-1][y]){
        ans = max(ans, dp(x-1, y) + 1);
    }
    if(y > 0 && h > map[x][y-1]){
        ans = max(ans, dp(x, y-1) + 1);
    }
    if(x < R-1 && h > map[x+1][y]){
        ans = max(ans, dp(x+1, y) + 1);
    }
    if(y < C-1 && h > map[x][y+1]){
        ans = max(ans, dp(x, y+1) + 1);
    }
    if(ans == -1){
        ans = 1;
    }
    return ans;
}
