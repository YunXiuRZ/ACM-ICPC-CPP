#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
//#include<fstream>

using namespace std;

#define out cout
//ofstream fout("result.txt");

struct Rectangle{
    int width, height;

    Rectangle(int w, int h): width(w), height(h){
        if(width > height){
            width = h;
            height = w;
        }
    }
    Rectangle(istream &cin){
        int w, h;
        cin>>w>>h;
        if(w < h){
            width = w;
            height = h;
        }else{
            width = h;
            height = w;
        }
    }
    Rectangle(): width(0), height(0){}
};

bool operator==(Rectangle r1, Rectangle r2){
    return r1.width == r2.width && r1.height == r2.height;
}

bool operator!=(Rectangle r1, Rectangle r2){
    return r1.width != r2.width || r1.height != r2.height;
}

bool operator<(Rectangle r1, Rectangle r2){
    if(r1.width == r2.width)
        return r1.height < r2.height;
    return r1.width < r2.width;
}

int main(){
    int w, h;
    while(cin>>w>>h){
        vector<Rectangle> rectangles;
        if(w > h)
            swap(w, h);
        rectangles.push_back(Rectangle(w, h));
        for(int i = 0; i < 5; i++){
            rectangles.push_back(Rectangle(cin));
        }
        sort(rectangles.begin(), rectangles.end());
        bool result = true;
        for(int i = 0; i < 3; i++){
            if(rectangles[i*2] != rectangles[i*2+1]){
                result = false;
                break;
            }
        }
        if(result){
            Rectangle r1 = rectangles[0], r2 = rectangles[2], r3 = rectangles[4];
            result&= r1.width == r2.width && r1.height == r3.width && r2.height == r3.height;
        }
        if(result)
            out<<"POSSIBLE"<<endl;
        else
            out<<"IMPOSSIBLE"<<endl;
    }
}