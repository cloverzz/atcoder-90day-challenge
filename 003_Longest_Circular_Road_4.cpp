#include <iostream>
#include <vector>
#include <queue>

using namespace std;


const int INF = (1 << 29);
vector<vector<int>> G(1 << 18);
vector<int> C(1 << 18), P(1 << 18), D(1 << 18);
int N;
void bfs(int s) {
    for (int i = 1; i <= N ; i++) {
        C[i] = 0;
        D[i] = INF;
        P[i] = -1;
    }
    C[s] = 1;
    D[s] = 0;
    P[s] = -1;
    queue<int> q;
    q.push(s);
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : G[u]) {
            if(C[v] == 0) {
                C[v] = 1;
                D[v] = D[u] + 1;
                q.push(v);
            }
        }
        C[u] = 2;
    }
}

int main(){
    cin >> N;
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    bfs(1);
    int md = -1, idx = -1;
    for (int i = 1; i <= N; i++) {
        if (D[i] > md) {
            md = D[i];
            idx = i;
        }
    }
    bfs(idx);
    int ans = -1;
    for (int i = 1; i <=N; i++) {
        ans = max(ans, D[i]);
    }
    cout << ans + 1<< endl;
    return 0;
}