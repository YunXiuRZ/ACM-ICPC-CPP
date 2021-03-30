#include<iostream>
#include<fstream>

using namespace std;

ofstream fout("result.txt");
#define out cout



int main(){
    int n, m, x, y, count = 0;
    while(cin>>n){
        if(count){
            out<<"\n**********************************\n\n";
        }
        count++;
        int Hline[10][10] = {0}, Vline[10][10] = {0};
        cin>>m;
        char command;
        for(int i = 0; i < m; i++){
            cin>>command>>x>>y;
            if(command == 'H'){
                Hline[x][y] = 1;
            }else if(command == 'V'){
                Vline[y][x] = 1;
            }
        }
        
        for(int i = 1; i <= n; i++){
            for(int j = n-1; j >= 1; j--){
                if(Hline[i][j+1] && Hline[i][j]){
                    Hline[i][j] += Hline[i][j+1];
                }
                if(Vline[j+1][i] && Vline[j][i]){
                    Vline[j][i] += Vline[j+1][i];
                }
            }
        }

        int total[10] = {0};
        for(int s = n; s > 0; s--){
            for(int i = 1; i <= n; i++){
                for(int j = 1; j <= n; j++){
                    if((Hline[i][j] >= s && Vline[i][j] >= s && Hline[i+s][j] >= s && Vline[i][j+s] >= s)){
                        total[s]++;
                    }
                }
            }
        }

        out<<"Problem #"<<count<<"\n\n";
        bool flag = false;
        for(int i = 1; i <= n; i++){
            if(total[i] > 0){
                out<<total[i]<<" square (s) of size "<<i<<"\n";
                flag = true;
            }
        }
        if(!flag){
            out<<"No completed squares can be found.\n";
        }

    }
}

