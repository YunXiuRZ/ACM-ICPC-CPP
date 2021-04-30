// UVa712 S-Trees
// 陈锋
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <functional>
#include <iomanip>
#include <iostream>
#include<fstream>
#include <list>
#include <queue>
#include <set>
#include <unordered_map>
#include <unordered_set>
#include <valarray>
#include <vector>

using namespace std;
ofstream fout("result.txt");
#define out fout
#define _for(i, a, b) for (int i = (a); i < (b); ++i)
#define _rep(i, a, b) for (int i = (a); i <= (b); ++i)

typedef long long LL;
const int MAXN = 8;
int N, x[MAXN];
string leaves, V;

int main() {
  string buf;
  int m;
  for (int t = 1; cin>>N && N; t++) {
      out<<"S-Tree #"<<t<<":\n";
      for(int i = 0; i < N; i++){
        cin>>buf;
        x[i] = buf[1] - '1';
      }
    cin>>leaves;
    cin>>m;
    for(int i = 0; i < m; i++){
        string V;
        cin>>V;
        int d = 0, u = 1;
        while (d < N) u = 2 * u + (V[x[d++]] - '0');
        out<<leaves[u - (1 << N)];
    }
    out<<"\n\n";
  }
}
// 2173418	5565	S-Trees	Accepted	C++11	0.003	2017-05-03 04:47:54