#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <algorithm>
 
using namespace std;
 
const int inf = 1e9 + 7;
vector<vector<int> > g, rev_g;
vector<int> used, size, color, order;
vector<bool> accept, loop, reachable;
int cls;
int n, m, k;
queue<int> q;
 
int dfs(int v) {
    if (used[v] == 1)
        return 0;
    if (used[v] == 2)
        return size[v];
    used[v] = 1;
    size[v] = 0;
    for (int i = 0; i < (int)g[v].size(); i++) {
        size[v] += dfs(g[v][i]);
        size[v] %= inf;
    }
    used[v] = 2;
    if (accept[v])
        size[v]++;
    size[v] %= inf;
    return size[v];
}
 
void topsort(int v) {
    used[v] = 3;
    reachable[v] = true;
    for (int i = 0; i < (int)g[v].size(); i++) {
        if (used[g[v][i]] != 3)
            topsort(g[v][i]);
    }
    order.push_back(v);
}
 
void dfsSt(int v, int x) {
    if (!reachable[v])
        return;
    color[v] = x;
    used[v] = 4;
    for (int i = 0; i < (int)rev_g[v].size(); i++) {
        if (used[rev_g[v][i]] != 4)
            dfsSt(rev_g[v][i], x);
    }
}
 
int main() {
    freopen("problem3.in", "r", stdin);
    freopen("problem3.out", "w", stdout);
    cin >> n >> m >> k;
    accept = vector<bool>((unsigned long)n);
    used = vector<int>((unsigned long) n);
    size = vector<int>((unsigned long) n);
    loop = vector<bool>((unsigned long) n);
    color = vector<int>((unsigned long) n);
    reachable = vector<bool>((unsigned long) n);
    cls = 0;
    for (int i = 0; i < k; i++) {
        int t;
        cin >> t;
        accept[t - 1] = true;
    }
    g = vector<vector<int> >((unsigned long) n);
    rev_g = vector<vector<int> >((unsigned long) n);
    for (int i = 0; i < m; i++) {
        int from, to;
        char ch;
        cin >> from >> to >> ch;
        g[from - 1].push_back(to - 1);
        rev_g[to - 1].push_back(from - 1);
        if (from == to)
            loop[from - 1] = true;
    }
    order = vector<int>();
    topsort(0);
    reverse(order.begin(), order.end());
    for (int i = 0; i < (int)order.size(); i++) {
        if (used[order[i]] != 4)
            dfsSt(order[i], cls++);
    }
    vector<int> color_count((unsigned long) cls);
    for (int i = 0; i < (int)order.size(); i++) {
        color_count[color[order[i]]]++;
    }
    for (int i = 0; i < (int)order.size(); i++) {
        if (color_count[color[order[i]]] > 1 || loop[order[i]]) {
            q.push(order[i]);
            used[order[i]] = 5;
        }
    }
    while (q.size() > 0) {
        int now = q.front();
        if (accept[now])
            return cout << "-1" << endl, 0;
        q.pop();
        for (int i = 0; i < (int)g[now].size(); i++) {
            if (used[g[now][i]] != 5) {
                q.push(g[now][i]);
                used[g[now][i]] = 5;
            }
        }
    }
    cout << dfs(0) << endl;
}
