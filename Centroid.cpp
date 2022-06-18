//#pragma GCC optimize("Ofast")
//#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
//#pragma GCC optimize("unroll-loops")

#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace std;
using namespace __gnu_pbds;

template<class T1, class T2>
    using Ordered_Set = tree<T1, null_type, T2,
        rb_tree_tag, tree_order_statistics_node_update>;


using ll = long long;
const ll M = 1e9 + 7;
const int Iinf = 0x3f3f3f3f;
const ll Linf = 0x3f3f3f3f3f3f3f3f;

#define fbo(ind) find_by_order(ind)
#define ook(val) order_of_key(val)

#define All(v) (v).begin(),(v).end()
#define ub(v, k) upper_bound(All(v), k) - v.begin()
#define lb(v, k) lower_bound(All(v), k) - v.begin()

#define watch(x) cerr << (#x) << " is " << (x) << endl
#define TC int tt; cin >> tt; for(int t=1; t<=tt; t++)

#define Rep(i, n) for(__typeof(n) i=0; i<n; i++)
#define Per(i, n) for(__typeof(n) i=n-1; i>=0; i--)
#define Lrep(i, p, q) for(__typeof(q) i=p; i<=q; i++)
#define Perl(i, p, q) for(__typeof(p) i=p; i>=q; i--)

const int dx4[] = { +1, -1, +0, +0 };
const int dy4[] = { +0, +0, +1, -1 };
const int dx8[] = { +0, +0, +1, -1, -1, +1, -1, +1 };
const int dy8[] = { -1, +1, +0, +0, +1, +1, -1, -1 };

template< typename T > using V = vector<T>;
template< typename T > using VV = V<V<T> >;
template< typename T > using MinHeap = priority_queue<T, V<T>, greater<T> >;


template< typename T > inline bool Checkbit(T n, T Pos){
    return n & (1 << Pos);
}
template< typename T > inline T Resetbit(T n, T Pos){
    return n | (1 << Pos);
}
template< typename T > inline T Unsetbit(T n, T Pos){
    return n & ~(1 << Pos);
}
template< typename T > inline T Flipbit(T n, T Pos){
    return n ^ (1 << Pos);
}

template< typename T > inline T Sqr(T x){
    return (x) * (x);
}
template< typename T > inline bool IsPoT(T x){
    return (x != 0 and (x & (x - 1)) == 0);
}

template< typename T > bool Chkmax(T &a, const T b){
    if(a < b){
        a = b;
        return true;
    }
    else return false;
}
template< typename T > bool Chkmin(T &a, const T b){
    if(a > b){
        a = b;
        return true;
    }
    else return false;
}
template< typename T > V<T> Compress(V<T> A){
    sort(all(A));
    A.erase(unique(all(A)), A.end());
    return A;
}

template< typename T > T Powmod(T n, T p, T M){
    n %= M;
    T Res = 1;
    while(p > 0){
        if(p & 1) Res = ((Res%M)*(n%M))%M;
        n = ((n%M)*(n%M))%M;
        p >>= 1;
    }
    return Res;
}
template< typename T > T ModInv(T a, T m){
    return Powmod(a, m-2, m);
}

VV<int> ReadGraph(int n, int m){
    VV<int> edges(n);
    Rep(i, m){
        int u, v;
        cin >> u >> v;
        u--;
        v--;
        edges[u].emplace_back(v);
        edges[v].emplace_back(u);
    }
    return edges;
}

VV<int> ReadTree(int n){
    return ReadGraph(n, n-1);
}


/*

Time Complexity :

*/

V<int> GetCentroid(const VV<int> &edges, int n){
    V<int> centroid;
    V<int> sub(n);

    function<void(int, int)> dfs = [&](int u, int par){
        sub[u] = 1;
        bool isCentroid = true;
        for(auto v: edges[u]){
            if(v != par){
                dfs(v, u);
                sub[u] += sub[v];
                if(sub[v] > n / 2) isCentroid = false;
            }
        }
        if(n - sub[u] > n / 2) isCentroid = false;
        if(isCentroid) centroid.emplace_back(u);
    };
    dfs(0, -1);
    return centroid;
}


class GameOnLeaves{
public:
    void Solve(istream& cin, ostream& cout){


        TC{
            int n;
            cin >> n;

            VV<int> edges = ReadTree(n);
            auto centroids = GetCentroid(edges, n);

            int NoC = centroids.size();
            if(NoC == 1){
                int cen = centroids[0];
                for(auto v: edges[cen]){
                    cout << v + 1 << " " << cen + 1 << '\n';
                    cout << v + 1 << " " << cen + 1 << '\n';
                    break;
                }
            }
            else{
                int cen1 = centroids[0];
                int cen2 = centroids[1];
                int node = 0;
                for(auto v: edges[cen1]){
                    if(v == cen2) continue;
                    cout << cen1 + 1 << " " << v + 1 << '\n';
                    node += v;
                    break;
                }
                cout << cen2 + 1 << " " << node + 1 << '\n';
            }
        }

    }
};



signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL_DEFINE
    auto start_time = clock();
#endif // LOCAL_DEFINE

#ifdef INPUT
    freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
#endif

    GameOnLeaves Problem;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    Problem.Solve(in, out);

#ifdef LOCAL_DEFINE
    auto end_time = clock();
        cerr << "\nTime Elapsed: " << fpre(3) << 1.0 * (end_time - start_time) / CLOCKS_PER_SEC  << " Sec"<< endl;
#endif // LOCAL_DEFINE

    return 0;
}

