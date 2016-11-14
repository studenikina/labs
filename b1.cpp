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
int n, m, k, accept[N], a, b;
bool flag;
vector<int> g[N][30];
 
int main() {
 
    freopen("problem2.in", "r", stdin);
    freopen("problem2.out", "w", stdout);
 
    cin >> word;
    cin >> n >> m >> k;
    for(int i = 0; i < k; i++) {
        cin >> a;
        accept[a]++;
    }
 
    for(int i = 0; i < m; i++) {
        cin >> a >> b >> c;
        g[a][int(c) - 97].push_back(b);
 
    }
 
    vector <bool> d(n + 1);
    d[1] = true;
    for (int i = 0; i < (int)word.size(); i++) {
        a = int(word[i]) - 97;
        vector <bool> d2(n + 1);
        for (int s = 1; s < n + 1; s++) {
            if (!d[s])
                continue;
            for (int j = 0; j < (int)g[s][a].size(); j++)
                d2[g[s][a][j]] = true;
        }
        d = d2;
    }
 
    for (int i = 1; i < n + 1; i++)
        if (d[i] && accept[i])
            return cout << "Accepts" << endl, 0;
 
    cout << "Rejects" << endl;
    return 0;
}
