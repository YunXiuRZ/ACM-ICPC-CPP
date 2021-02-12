#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

#define out cout

struct Point{
    int x, y;
    Point(int x, int y):x(x), y(y){}
    Point():x(0), y(0){}
};

Point operator+(const Point p1, const Point p2){
    return Point(p1.x + p2.x, p1.y + p2.y);
}

Point empty;
string puzzle[5];
int puzzle_count = 0;

bool check_point(const Point p){
    return p.x >= 0 && p.x < 5 && p.y >= 0 && p.y < 5;
}

char &char_of_puzzle(Point p){
    return puzzle[p.x][p.y];
} 

void print_puzzle(){
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            out<<puzzle[i][j];
            if (j == 4)
                continue;
            out<<" ";
        }
        out<<endl;
    }
}

bool transfer_puzzle(const char cmd){
    unordered_map<char, Point> move = {{'A', Point(-1, 0)},
                                       {'B', Point(1, 0)},
                                       {'L', Point(0, -1)},
                                       {'R', Point(0, 1)}};
    if(move.find(cmd) == move.cend())
        return false;
    Point target_point = empty + move[cmd];
    if (!check_point(target_point)) 
        return false;
    swap(char_of_puzzle(empty), char_of_puzzle(target_point));
    empty = target_point;
    return true;
}

int main(){
    while (true) {
        string s;
        puzzle_count++;
        for (int i = 0; i < 5; i++) {
            getline(cin, s);
            if (s[0] == 'Z')
                return 0;
            if(puzzle_count != 1 && i == 0)
                out<<endl;
            if(s.length() == 4)
                s+=' ';
            puzzle[i] = s;
            for (int j = 0; j < 5; j++) {
                if (s[j] == ' ') {
                    empty = Point(i, j);
                }
            }
        }
        string cmd;
        bool cmd_end = false, puzzle_solve = true;
        while (!cmd_end) {
            getline(cin, cmd);
            for (const char c : cmd) {
                if (c == '0') {
                    cmd_end = true;
                    break;
                }
                if (!transfer_puzzle(c)) {
                    puzzle_solve = false;
                    empty = Point(-1, -1);
                }
            }
        }
        out<<"Puzzle #"<<puzzle_count<<":"<<endl;
        if(puzzle_solve){
            print_puzzle();
        }else{
            out<<"This puzzle has no final configuration."<<endl;
        }
    }
}