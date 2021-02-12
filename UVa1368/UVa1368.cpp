#include<iostream>
#include<string>
//#include<fstream>
#include<vector>
#include<algorithm>

using namespace std;

#define out cout
//ofstream fout("result.txt");

struct Element{
    char letter;
    int count = 0;
    Element(char c):letter(c){}
    void appear(){
        count++;
    }
};

bool operator<(Element e1, Element e2){
    if(e1.count == e2.count)
        return e1.letter > e2.letter;
    return e1.count < e2.count;
};

int main(){
    int T, m, n;
    cin>>T;
    string s;
    while (T--) {
        cin>>m>>n;
        vector<string> DNAs;
        
        int pointer[91];
        pointer['A'] = 0;
        pointer['C'] = 1;
        pointer['G'] = 2;
        pointer['T'] = 3;
        for(int i = 0; i < m; i++){
            cin>>s;
            DNAs.push_back(s);
        }
        int result = 0;
        for(int i = 0; i < n; i++){
            vector<Element> count = {Element('A'), Element('C'), Element('G'), Element('T')};
            for(int j = 0; j < m; j++){
                count[pointer[DNAs[j][i]]].appear();
            }
            sort(count.begin(), count.end());
            result+=m-count[3].count;
            out<<count[3].letter;
        }
        out<<endl<<result<<endl;
    }
}