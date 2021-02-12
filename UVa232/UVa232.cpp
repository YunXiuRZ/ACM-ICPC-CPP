#include<iostream>
#include<string>
#include<vector>
//#include<fstream>
#include<unordered_map>
#include<algorithm>

using namespace std;

#define out cout
//ofstream fout("result.txt");

struct Point{
    int x, y;
    Point(int x, int y):x(x), y(y){}
    Point():x(0), y(0){}
};

Point operator+(Point p1, Point p2){
    return Point(p1.x + p2.x, p1.y + p2.y);
}

bool operator==(Point p1, Point p2){
    return p1.x == p2.x && p1.y == p2.y;
}

vector<string> puzzle;
vector<Point> across_start_points, down_start_points, start_points;
unordered_map<char, Point> direction = {{'A', Point(-1, 0),},
                                        {'B', Point(1, 0)},
                                        {'L', Point(0, -1)},
                                        {'R', Point(0, 1)}};

void clear_data(){
    puzzle.clear();
    across_start_points.clear();
    down_start_points.clear();
    start_points.clear();
}

char &char_of_point(Point p){
    return puzzle[p.x][p.y];
}

bool have_point(Point p){
    return p.x >= 0 && p.x < puzzle.size() && p.y >= 0 && p.y < puzzle[0].length();
}

bool point_not_star(Point p){
    return char_of_point(p) != '*';
}

bool check_point(Point p){
    return have_point(p) && point_not_star(p);
}

int get_number(Point p){
    return find(start_points.cbegin(), start_points.cend(), p) - start_points.cbegin() + 1;
}

int main(){
    int r, c, puzzle_count = 0;
    string s;
    while (true) {
        cin>>r;
        if (!r)
            break;
        cin>>c;
        clear_data();
        puzzle_count++;
        for (int i = 0; i < r; i++) {
            cin>>s;
            puzzle.push_back(s);
            for (int j = 0; j < c; j++) {
                Point p(i, j);
                bool is_start_point = false;
                if (!check_point(p + direction['A']) && check_point(p)) {
                    down_start_points.push_back(p);
                    is_start_point|=true;
                }
                if (!check_point(p + direction['L']) && check_point(p)) {
                    across_start_points.push_back(p);
                    is_start_point|=true;
                }
                if (is_start_point) {
                    start_points.push_back(p);
                }
            }
        }
        if (puzzle_count != 1)
            out<<endl;
        out<<"puzzle #"<<puzzle_count<<":"<<endl;
        out<<"Across"<<endl;
        for (Point sp : across_start_points) {
            //out<<right<<setw(3)<<get_number(sp)<<".";
            printf("%3d.", get_number(sp));
            for (Point p = sp; check_point(p); p = p + direction['R']) {
                out<<char_of_point(p);
            }
            out<<endl;
        }
        out<<"Down"<<endl;
        for (Point sp : down_start_points) {
            //out<<right<<setw(3)<<get_number(sp)<<".";
            printf("%3d.", get_number(sp));
            for (Point p = sp; check_point(p); p = p + direction['B']) {
                out<<char_of_point(p);
            }
            out<<endl;
        }
    }
}