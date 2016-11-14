#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <algorithm>
#include <string>
 
using namespace std;
 
typedef long long ll;
const int N = 1e5 + 3;
const ll INF = 1e9 + 7;
 
string word;
char c;
int n, m, k, a, b, l;
 
int main() {
    freopen("problem4.in", "r", stdin);
    freopen("problem4.out", "w", stdout);

    cin >> n >> m >> k >> l;
    vector <ll> accept(n + 1);
    vector <ll> start(m + 1);
    vector <ll> final(m + 1);
    for(int i = 0; i < k; i++) {
        cin >> a;
        accept[a]++;
    }
 
    for(int i = 1; i <= m; i++) {
        cin >> start[i] >> final[i] >> c;
    }
 
    for (int i = 0; i < l; i++) {
        vector <ll> accept2(n + 1, 0);
        for (int j = 1; j < m + 1; j++) {
            accept2[start[j]] = accept2[start[j]] + accept[final[j]];
            accept2[start[j]] = accept2[start[j]] % INF;
        }
        accept = accept2;
    }
    cout << accept[1] << endl;
    return 0;
}
