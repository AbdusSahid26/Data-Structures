/*

     _____________    _____________    _____________	          _____________    _____________
    (  ___________)  |  _________  )  (___________  )	         (___________  )  (  ___________)
    ( (		     | |         | )	          | )            	     ) )  ( (
    ( (___________   | |_________| )   ___________| )	          ___________) )  ( (___________
    (___________  )  |  ___________)  |  _________  )            (  ___________)  (  _________  )
                ) )  | |	      | |         | )  	         ( (              ( (         ) )
     ___________) )  | |___________   | |_________| )   ______   ( (___________   ( (_________) )
    (_____________)  |_____________)  |_____________)  (______)  (_____________)  (_____________)



    Name  : Abdus Sahid

    Topcoder handle : sea_26
    Codechef handle : sea_26

    Practice makes a man perfect.
    Don't lose faith.

*/

#pragma GCC optimize("03")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;


template <typename T>
      using ordered_set = tree<T, null_type, less<T>,
          rb_tree_tag, tree_order_statistics_node_update>;


using ll = long long;
using ld = long double;

typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef pair<int, ll> PIL;
typedef pair<ll, ll> PLL;

typedef vector<PII> VPII;
typedef vector<PLL> VPLL;
typedef vector<int> VI;
typedef vector<VI> VVI;
typedef vector<string> VS;
typedef vector<char> VC;
typedef vector<ll> VL;
typedef vector<VL> VVL;

typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<PII, int> MPIII;
typedef map<string, int> MSI;

typedef ordered_set<int> OSI;
typedef ordered_set<ll> OSL;
typedef unordered_map<ll,ll> UOML;

typedef multiset<PLI> MSPLI;
typedef priority_queue<int> PQI;

const int M = 1e9 + 7;
const ll FFTM = 998244353;
const ld eps = 1e-9;
const ld PI = acos(-1.0);
// const double pi = atan2(0, -1);
// const double PI = 4 * atan(1);
// const double pi = 2*cos(0.0);

const int iinf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

#define mp make_pair
#define eb emplace_back
#define pf push_front
#define pb push_back
#define ppb pop_back()
#define ep emplace
#define fbo(ind) find_by_order(ind);
#define ook(val) order_of_key(val);
#define f first
#define s second
#define sz size()

#define bp(n) __builtin_popcount(n)
#define bclz(n) __builtin_clzll(n)
#define bctz(n) __builtin_ctzll(n)
#define bip(n) __builtin_parity(n)

#define all(v) (v).begin(),(v).end()
#define rall(v) (v).rbegin(),(v).rend()
#define rvs(v) sort(all(v),greater<int>())
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))
#define ita(v) iota(all(v), 0)
#define acm(v, ini) accumulate(all(v),ini)
#define uni(v) vsort(v),(v).erase(unique(all(v)), (v).end())
#define smp(container, element) (container.find(element) != container.end())
#define vp(container, element) (FIND(all(container),element) != container.end())

#define ub upper_bound
#define lb lower_bound
#define cr(n) cbrt(n)
#define msz(a) memset(a, 0, sizeof(a))
#define msm(a) memset(a, 0xff, sizeof(a))
#define fpre(n) fixed << setprecision(n)
#define sea template< typename T
#define tc int tt; cin >> tt; for(int t=1; t<=tt; t++)

#define rep(i,n) for(__typeof(n) i=0; i<n; i++)
#define per(i,n) for(__typeof(n) i=n-1; i>=0; i--)
#define lrep(i,p,q) for(__typeof(q) i=p; i<=q; i++)
#define perl(i,p,q) for(__typeof(p) i=p; i>=q; i--)
#define IT(it,x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define RIT(it,x) for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)

#define boost ios_base::sync_with_stdio(false); cin.tie(nullptr); cout.tie(nullptr);


sea > inline T MAX(T a, T b){ return a ^ ((a ^ b) & -(a < b)); }
sea > inline T MIN(T a, T b){ return b ^ ((a ^ b) & -(a < b)); }
sea > void SWAP(T &a, T &b){ a = ((a) ^= (b)),  b = ((b) ^= (a)),  a = ((a) ^= (b)); }
sea > inline T sqr(T x){ return (x) * (x); }
sea > inline bool isPoT(T x){ return (x != 0 && (x&(x - 1)) == 0); }

sea > inline T gcd(T a, T b){ while (b) b ^= a ^= b ^= a %= b; return a; }
sea > T exgcd(T a, T b, T& x, T& y){ if(!b){ x = 1; y = 0;return a;} else{ T g = exgcd(b,a%b,y,x); y -= (a/b)*x; return g;}}
sea > inline T lcm(T a, T b){ return (a / gcd(a,b)) * b; }

sea > inline T mod(T a, T b){ return a >= b ? a % b : a; }
sea > T binpow(T n, T p){ T res = 1; while(p > 0){ if(p & 1) res *= n; n *= n; p >>= 1; } return res;}
sea > T bigmod(T n, T p, T M){ n %= M; T res = 1; while(p > 0){ if(p & 1)res = ((res%M) * (n % M)) % M; n = ((n%M) * (n%M))%M; p >>= 1; } return res;}
sea > T modInv(T a, T m){return bigmod(a, m-2, m);}


void Time(){ cout << "\nTime Elapsed = " << fpre(7) << double(clock()) / CLOCKS_PER_SEC  << " Sec"<< endl; exit(0);}

///

DSU on String
https://codeforces.com/contest/1263/submission/66002564

///


template<class T> class UnionFind{
private:
    vector<int> par, rank, siz;
    T N;
public:
    UnionFind(T N) : N(N){
        par.assign(N, 0);
 //       rank.assign(N, 0);
        siz.assign(N, 1);
        for(int i=0; i<N; i++){
            par[i] = i;
        }
    }
    inline T find(T x){
        return par[x] == x ? x : par[x] = find(par[x]);
    }
    bool isSame(T x, T y){
        return find(x) == find(y);
    }
    void unite(T x, T y){
        if(!isSame(x, y)){
            x = find(x);
            y = find(y);
//            if(rank[x] < rank[y]) swap(x, y);
//            par[y] = x;
//            if(rank[x] == rank[y]) rank[x]++;
            if(siz[x] < siz[y]) swap(x, y);
            par[y] = x;
            siz[x] += siz[y];
        }
    }
    inline T getSize(T x){
        return siz[find(x)];
    }
};


/// Find, IsSame, Unite, Size each operation is O(1)
/// Time Complexity : o(alpha(n)) -> that is inverse ackermann function
/// Union by size / Union by rank both works without path compression O(log n) times
/// Union by rank tree is based on depth of tree.

class UF{
private:
    V<int> Par, Rank, Siz;
public:
    UF(int N){
        Par.assign(N, 0); /// Par -> stores a reference to its immediate ancestor in the tree.
        Rank.assign(N, 0);
        //Siz.assign(N, 1);
        Rep(i, N) Par[i] = i;  /// At first i is the ancestor of i.
    }
    inline int Find(int x){ return Par[x] == x ? x : Par[x] = Find(Par[x]); } /// TC : O(log n) per call on average.
    bool IsSame(int x, int y){ return Find(x) == Find(y); }
    void Unite(int x, int y){
        if(!IsSame(x, y)){
            x = Find(x);
            y = Find(y);
            if(Rank[x] < Rank[y]) Swap(x, y);
            Par[y] = x;
            if(Rank[x] == Rank[y]) Rank[x]++;
//            if(Siz[x] < Siz[y]) Swap(x, y);
//            Par[y] = x;
//            Siz[x] += Siz[y];
        }
    }
//    inline int Size(int x){ return Siz[Find(x)]; }
};


/*

class UF{
public:
    VI par, rank, siz;
    UF(int N){
        par.assign(N,0);
        rank.assign(N,0);
        //siz.assign(N, 1);
        rep(i,N) par[i] = i;
    }
    inline int find(int x){ return  par[x] == x ? x : par[x] = find(par[x]); }
    bool issame(int x, int y){ return find(x) == find(y); }
    void unite(int x, int y){
        if(!issame(x, y)){
            x = find(x); y = find(y);
            if(rank[x] < rank[y]) SWAP(x,y);
            par[y] = x;
            if(rank[x] == rank[y]) rank[x]++;
//            if(siz[x] < siz[y]) SWAP(x, y);
//            par[y] = x;
//            siz[x] += siz[y];
        }
        //int size(int x){ return siz[find(x)]; }
    }
};
*/

/*
struct UF{
//Problem : Connected Component
public:
	VI par, rank, siz;
	void ini(int N){
        par.assign(N,0);
        //rank.assign(N,0);
        siz.assign(N, 1);
        rep(i,N) par[i] = i;
	}
	inline int find(int x){ return  par[x] == x ? x : par[x] = find(par[x]); }
	bool issame(int x, int y){ return find(x) == find(y); }
	void unite(int x, int y){
	    if(!issame(x, y)){
            x = find(x); y = find(y);
//            if(rank[x] < rank[y]) SWAP(x,y);
//            par[y] = x;
//            if(rank[x] == rank[y]) rank[x]++;
            if(siz[x] < siz[y]) SWAP(x, y);
            par[y] = x;
            siz[x] += siz[y];
	    }
	}
	int size(int x){ return siz[find(x)]; }
};

UF SU;
*/


class D_RoadsnotonlyinBerland{
public:
    void solve(istream& cin, ostream& cout) {
        int n;
        cin >> n;
        UF SU(n);
        int m = n-1;

        VPII broken;
        rep(i,m){
            int u, v;
            cin >> u >> v;
            u--;
            v--;
            if(SU.issame(u,v)) broken.pb(mp(u,v));
            else SU.unite(u,v);
        }
        VPII construct;
        rep(i,n){
            rep(j,i){
                if(!SU.issame(j,i)){
                    construct.pb(mp(j,i));
                    SU.unite(j,i);
                }
            }
        }

        int ln = broken.sz;
        cout << ln << endl;
        rep(i,ln)
            cout << broken[i].f+1 << " " << broken[i].s+1 << " " << construct[i].f+1 << " " << construct[i].s+1 << endl;

    }
};


int main() {

    boost
    D_RoadsnotonlyinBerland Problem;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    Problem.solve(in, out);
	//Time()
    return 0;
}
