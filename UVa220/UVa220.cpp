#include<iostream>
#include<fstream>
#include<string>
#include<iomanip>

using namespace std;
#define out cout
ofstream fout("result.txt");

struct Point{
    int x, y;
    Point(int x, int y):x(x), y(y){}
    Point():x(0), y(0){}

};
Point operator+(Point p1, Point p2){
    return Point(p1.x+p2.x, p1.y+p2.y);
}
Point operator-(Point p1, Point p2){
    return Point(p1.x-p2.x, p1.y-p2.y);
}
bool operator==(Point p1, Point p2){
    return p1.x==p2.x && p1.y==p2.y;
}

char& get_char(Point p);
bool position_legal(Point p);
void print_point(Point p);
void print_board();
void change_player();
int can_eat_on_way(Point p, Point way);
void eat_on_way(Point p, Point way);
bool can_place(Point p);
void print_all_move();
void make_move(Point p);

char board[9][9];//紀錄棋盤上的棋子
Point DIR[8] = {
    Point(1, 1),
    Point(1, 0),
    Point(1, -1),
    Point(0, -1),
    Point(-1, -1),
    Point(-1, 0),
    Point(-1, 1),
    Point(0, 1)};
char player[] = {'B', 'W'};
int turn = 0, opposite = 1;//當player的索引值

int main(){
    int N;
    cin>>N;
    while (N--) {
        for(int i = 1; i <= 8; i++){
            string s;
            cin>>s;
            for(int j = 0; j < 8; j++){
                board[i][j+1] = s[j];
            }
        }
        char c;
        cin>>c;
        if(player[turn] != c){
            change_player();
        }

        string command;
        bool flag = true;
        while(flag){
            cin>>command;
            switch(command[0]){
                case 'L':
                    print_all_move();
                    break;
                case 'M':
                    make_move(Point(command[1]-48, command[2]-48));
                    break;
                case 'Q':
                    print_board();
                    flag = false;
                    break;
            }
        }
        if(N){
            out<<"\n";
        }
    }
}

char& get_char(Point p){
    return board[p.x][p.y];
}

void print_point(Point p){
    out<<"("<<p.x<<","<<p.y<<")";
}

bool position_legal(Point p){
    return p.x >= 1 && p.x <= 8 && p.y >= 1 && p.y <= 8;
}

void print_board(){
    for(int i = 1; i <= 8; i++){
        for(int j = 1; j <= 8; j++){
            out<<board[i][j];
        }
        out<<endl;
    }
}

void change_player(){
    turn++;
    opposite++;
    turn%=2;
    opposite%=2;
}

int can_eat_on_way(Point p, Point way){
    int result = 0;
    char c;
    p = p + way;
    do{
        c = get_char(p);
        if(c == '-'){
            break;
        }else if(c == player[turn]){
            return result;
        }else{
            result++;
        }
        p = p + way;
    }while(position_legal(p));
    return -1;
}

void eat_on_way(Point p, Point way){
    int n = can_eat_on_way(p, way);
    for(int i = 0; i < n; i++){
        p = p + way;
        get_char(p) = player[turn];
    }
}

bool can_place(Point p){
    if(get_char(p) != '-'){//檢查是否已有棋子
        return false;
    }
    for(int i = 0; i < 8; i++){
        if(can_eat_on_way(p, DIR[i]) > 0){
            return true;
        }
    }
    return false;
}

void print_all_move(){
    Point p(1, 1);
    bool flag = false;
    for(int i = 0; i < 8; i++){
        for(int j = 0; j < 8; j++){
            Point check = p+Point(i, j);
            if(can_place(check)){
                if(flag){
                    out<<" ";
                }
                print_point(check);
                flag = true;
            }
        }
    }
    if(!flag){
        out<<"No legal move.";
    }
    out<<"\n";
}


void make_move(Point p){
    if(!can_place(p)){
        change_player();
    }
    get_char(p) = player[turn];

    for(int i = 0; i < 8; i++){
        eat_on_way(p, DIR[i]);
    }

    int black = 0, white = 0;
    for(int i = 1; i < 9; i++){
        for(int j = 1; j < 9; j++){
            if(board[i][j] == 'B'){
                black++;
            }else if(board[i][j] == 'W'){
                white++;
            }
        }
    }
    out<<"Black -"<<setw(3)<<black;
    out<<" White -"<<setw(3)<<white<<"\n";
    change_player();
}
