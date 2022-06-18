

/// https://codeforces.com/contest/342/submission/90467624
/// https://codeforces.com/gym/277202/submission/99991953


/// https://codeforces.com/blog/entry/81661
///https://robert1003.github.io/2020/01/16/centroid-decomposition.html



#include<bits/stdc++.h>
using namespace std;


const int N = 1e5 + 5;
int lcaPar[N];
int lev[N];
int table[N][22];
vector<int> edges[N];
void dfs(int child, int papa, int depth){
    lcaPar[child] = papa;
    lev[child] = depth;
    for(int x: edges[child]){
        if(x != papa){
            dfs(x, child, depth + 1);
        }
    }
}
void process(int n){
    memset(table, -1, sizeof table);
    for(int i=1; i<=n; i++){
        table[i][0] = lcaPar[i];
    }
    for(int j=1; (1<<j)<=n; j++){
        for(int i=1; i<=n; i++){
            if(table[i][j-1] != -1){
                table[i][j] = table[table[i][j-1]][j-1];
            }
        }
    }
}
int lca(int p, int q){
    if(lev[p] < lev[q]) swap(p, q);
    int log;
    for(log=1; (1<<log)<=lev[p]; log++);
    log--;
    for(int i=log; i>=0; i--){
        if(lev[p] - (1<<i) >= lev[q]){
            p = table[p][i];
        }
    }
    if(p == q) return p;
    for(int i=log; i>=0; i--){
        if(table[p][i] != -1 and table[p][i] != table[q][i]){
            p = table[p][i];
            q = table[q][i];
        }
    }
    return lcaPar[p];
}
int dist(int x, int y){
    if(x == y) return 0;
    int ancestor = lca(x, y);
    return lev[x] + lev[y] - 2 * lev[ancestor];
}

bool mark[N];
int cenPar[N];
int sub[N];
int findSize(int child, int papa = 0){
    if(mark[child]) return 0;
    sub[child] = 1;
    for(int x: edges[child]){
        if(x != papa){
            sub[child] += findSize(x, child);
        }
    }
    return sub[child];
}
int findCentroid(int child, int papa, int n){
    for(int x: edges[child]){
        if(x != papa){
            if(!mark[x] and sub[x] > n / 2){
                return findCentroid(x, child, n);
            }
        }
    }
    return child;
}

void centroidDecomposition(int child = 1, int papa = 0){
    findSize(child);
    int centroid = findCentroid(child, 0, sub[child]);
    mark[centroid] = true;
    cenPar[centroid] = papa;
    for(int x: edges[centroid]){
        if(!mark[x]){
            centroidDecomposition(x, centroid);
        }
    }
}

int best[N];
void update(int v){
    best[v] = 0;
    int u = v;
    while(cenPar[u] != 0){
        u = cenPar[u];
        best[u] = min(best[u], dist(u, v));
    }
}

int query(int v){
    int res = best[v];
    int u = v;
    while(cenPar[u] != 0){
        u = cenPar[u];
        res = min(res, best[u] + dist(u, v));
    }
    return res;
}


signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int n, m;
    cin >> n >> m;
    for(int i=0; i<n-1; i++){
        int u, v;
        cin >> u >> v;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }
    memset(best, 2e5, sizeof best);
    dfs(1, 0, 1);
    process(n);
    centroidDecomposition();
    update(1);

    while(m--){
        int t, v;
        cin >> t >> v;
        if(t == 1) update(v);
        else cout << query(v) << '\n';
    }
return 0;
}

/// Another Centroid Decomposition Implementation

/*

set<int> G[N]; // adjacency list (note that this is stored in set, not vector)
int sz[N], pa[N];

int dfs(int u, int p) {
  sz[u] = 1;
  for(auto v : G[u]) if(v != p) {
    sz[u] += dfs(v, u);
  }
  return sz[u];
}
int centroid(int u, int p, int n) {
  for(auto v : G[u]) if(v != p) {
    if(sz[v] > n / 2) return centroid(v, u, n);
  }
  return u;
}
Time complexity of above code : O(n)


void build(int u, int p) {
  int n = dfs(u, p);
  int c = centroid(u, p, n);
  if(p == -1) p = c;
  pa[c] = p;

  vector<int> tmp(G[c].begin(), G[c].end());
  for(auto v : tmp) {
    G[c].erase(v); G[v].erase(c);
    build(v, c);
  }
}

It costs O(n) to build each level of the centroid tree,
and the height of the centroid tree is O(logn). The deletion
of edge is also O(nlogn), as we only have O(n) edges to remove
and each removal cost O(logn). Therefore, the total complexity
is O(nlogn).

*/
/// http://codeforces.com/problemset/problem/342/E


#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = (int)1e5 + 5;
const int inf = (int)1e9;

struct CentroidDecomposition {
  set<int> G[N];
  map<int, int> dis[N];
  int sz[N], pa[N], ans[N];

  void init(int n) {
    for(int i = 1 ; i <= n ; ++i) G[i].clear(), dis[i].clear(), ans[i] = inf;
  }
  void addEdge(int u, int v) {
    G[u].insert(v); G[v].insert(u);
  }
  int dfs(int u, int p) {
    sz[u] = 1;
    for(auto v : G[u]) if(v != p) {
      sz[u] += dfs(v, u);
    }
    return sz[u];
  }
  int centroid(int u, int p, int n) {
    for(auto v : G[u]) if(v != p) {
      if(sz[v] > n / 2) return centroid(v, u, n);
    }
    return u;
  }
  void dfs2(int u, int p, int c, int d) { // build distance
    dis[c][u] = d;
    for(auto v : G[u]) if(v != p) {
      dfs2(v, u, c, d + 1);
    }
  }
  void build(int u, int p) {
    int n = dfs(u, p);
    int c = centroid(u, p, n);
    if(p == -1) p = c;
    pa[c] = p;
    dfs2(c, p, c, 0);

    vector<int> tmp(G[c].begin(), G[c].end());
    for(auto v : tmp) {
      G[c].erase(v); G[v].erase(c);
      build(v, c);
    }
  }
  void modify(int u) {
    for(int v = u ; v != 0 ; v = pa[v]) ans[v] = min(ans[v], dis[v][u]);
  }
  int query(int u) {
    int mn = inf;
    for(int v = u ; v != 0 ; v = pa[v]) mn = min(mn, ans[v] + dis[v][u]);
    return mn;
  }
} cd;

int n, q;

void init() {
  cin >> n >> q;
  cd.init(n);
  for(int i = 0 ; i < n - 1 ; ++i) {
    int a, b; cin >> a >> b; cd.addEdge(a, b);
  }
  cd.build(1, 0);
}
void solve() {
  cd.modify(1);
  int t, u;
  while(q--) {
    cin >> t >> u;
    if(t == 1) cd.modify(u);
    else cout << cd.query(u) << '\n';
  }
}

int main() {
  ios_base::sync_with_stdio(0), cin.tie(0);
  init();
  solve();
}
