#include<iostream>
#include<vector>
//#include<fstream>

using namespace std;

#define out cout
//ofstream fout("result.txt");


struct Point{
    int x, y;
    Point(int x, int y): x(x), y(y){};
    Point() = default;
};
Point operator+(Point p1, Point p2){
    return Point(p1.x+p2.x, p1.y+p2.y);
}
Point operator/(Point p, int n){
    return Point(p.x/n, p.y/n);
}
bool operator==(Point p1, Point p2){
    return p1.x == p2.x && p1.y == p2.y;
}
void operator+=(Point &p1, Point p2){
    p1.x += p2.x;
    p1.y += p2.y;
}

char get_chess(Point p);
Point move[] = {
    Point(1, 0),
    Point(-1, 0),
    Point(0, 1),
    Point(0, -1)},
horse_move[] = {
    Point(1, 2),
    Point(-1, 2),
    Point(1, -2),
    Point(-1, -2),
    Point(2, 1),
    Point(-2, 1),
    Point(2, -1),
    Point(-2, -1)
};


struct Chess{
    Point position;

    Chess(int x, int y): position(Point(x, y)){}
    Chess(): position(Point(0, 0)){}

    Chess operator+(Point p);

    bool position_legal(){
        return position.x >= 1 && position.x <= 10 && position.y >= 1 && position.y <= 9;
    }

    int get_chess_count_to(Point p){
        Point move[] = {
            Point(1, 0),
            Point(-1, 0),
            Point(0, 1),
            Point(0, -1)};
        for(Point m : move){
            int count = 0;
            Chess check = *this + m;
            while(check.position_legal()){
                char c = get_chess(check.position);
                if(check.position == p){
                    return count;
                }else if(c != 0){
                    count++;
                }
                check = check + m;
            }
        }
        return -1;
    }

    virtual bool can_eat(Chess b_general){
        return get_chess_count_to(b_general.position) == 0;
    }

};
bool operator==(Chess c1, Chess c2){
    return c1.position == c2.position;
}
Chess Chess::operator+(Point p){
    return Chess(this->position.x+p.x, this->position.y+p.y);
}
Chess operator-(Chess c, Point p){
    return Chess(c.position.x+p.x, c.position.y+p.y);
}

bool check_mate();

struct General : Chess{
    General(int x, int y): Chess(x, y){}
    General(): Chess(){}
    bool position_legal(){
        return position.x >= 1 && position.x <= 3 && position.y >= 4 && position.y <= 6;
    }

};
General operator+(General c, Point p){
    return General(c.position.x+p.x, c.position.y+p.y);
}
General operator-(General c, Point p){
    return General(c.position.x-p.x, c.position.y-p.y);
}

struct Chariot : Chess{
    Chariot(int x, int y) : Chess(x, y){}
    Chariot() : Chess(){}
};

struct Cannon : Chess{

    Cannon(int x, int y) : Chess(x, y){}
    Cannon() : Chess(){}

    virtual bool can_eat(Chess b_general){
        return get_chess_count_to(b_general.position) == 1;
    }

};

struct Horse : Chess{

    Horse(int x, int y) : Chess(x, y){}
    Horse() : Chess(){}

    virtual bool can_eat(Chess b_general){
        for (Point m : horse_move) {
            Chess check = *this + m;
            if(!check.position_legal())
                continue;
            if (check.position == b_general.position) {
                check = *this + m/2;
                if (get_chess(check.position) == 0) {
                    return true;
                }else {
                    return false;
                }
            }
        }
        return false;
    }

};

char board[11][10];
General b_general, r_general;
vector<Chess*> chesses;



char get_chess(Point p){
    return board[p.x][p.y];
}

int main(){
    char N, C;
    int gx, gy;
    while (cin>>N>>gx>>gy) {
        if (N == '0' && gx == 0 && gy == 0) {
            return 0;
        }
        chesses.clear();
        b_general = General(gx, gy);
        for (int i = 0; i < 11; i++) {
            for (int j = 0; j < 10; j++) {
                board[i][j] = 0;
            }
        }
        for (int i = 48; i < N; i++) {
            cin>>C>>gx>>gy;
            board[gx][gy] = C;
            Chess* c;
            switch (C)
            {
            case 'G':
                c = new General(gx, gy);
                r_general = General(gx, gy);
                break;
            case 'R':
                c = new Chariot(gx, gy);
                break;
            case 'H':
                c = new Horse(gx, gy);
                break;
            case 'C':
                c = new Cannon(gx, gy);
                break;
            }
            chesses.push_back(c);
        }
        if(b_general.can_eat(r_general)){
            out<<"NO"<<endl;
        }else{
            bool flag = true;
            Point move[] = {
                Point(1, 0),
                Point(-1, 0),
                Point(0, 1),
                Point(0, -1)};
            for(Point m : move){
                b_general = b_general+m;
                if(!b_general.position_legal()){
                    b_general = b_general-m;
                    continue;
                }
                if(check_mate()){
                    flag = false;
                }else{
                    flag = true;
                    break;
                }
                b_general = b_general-m;
            }
            if(flag)
                out<<"NO"<<endl;
            else
                out<<"YES"<<endl;
        }
    }
}

bool check_mate(){
    for (Chess* c : chesses) {
        if(c->can_eat(b_general)){
            return true;
        }
    }
    return false;
}
