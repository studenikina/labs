#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
const int N = 1e5 + 3;
 
string word;
char c;
int n, m, k, accept[N], a, b, flag = 1;
//vector <int> g[N];
int g[N][30];
 
 
int main() {
 
    freopen("problem1.in", "r", stdin);
    freopen("problem1.out", "w", stdout);
 
    cin >> word;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> a;
        accept[a]++;
    }
 
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a][int(c) - 97] = b;
 
    }
 
    for(int i = 0; i < (int) word.size(); i++) {
        if(g[flag][int(word[i]) - 97] == 0) {
            return cout << "Rejects" << endl, 0;
        } else {
            flag = g[flag][int(word[i]) - 97];
        }
    }
    if(accept[flag] == 0) cout << "Rejects";
    else cout << "Accepts";
    return 0;
}
