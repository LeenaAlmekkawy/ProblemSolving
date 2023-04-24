///MultiPath shortest path
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N = 2e5 + 5;
int n, m;
ll d[N];
vector<pair<int, ll>> g[N];
void dij() {
    priority_queue<pair<ll, int>> q;
    for(int i = 1;i <= n;i++) {
        q.push({-d[i], i});
    }
    while(!q.empty()) {
        ll cost = -q.top().first;
        int node = q.top().second;
        q.pop();
        if(d[node] < cost)
            continue;
        for(auto neg : g[node]) {
            ll ncost = neg.second + cost;
            if(ncost < d[neg.first]) {
                d[neg.first] = ncost;
                q.push({-ncost, neg.first});
            }
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    cin >> n >> m;
    for(int i = 0;i < m;i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        g[u].push_back({v, w * 2});
        g[v].push_back({u, w * 2});
    }
    for(int i = 1;i <= n;i++)
        cin >> d[i];
    dij();
    for(int i = 1;i <= n;i++)
        cout << d[i] << " ";
    return 0;
}