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
VL PN = {2,3,5,7,11,13,17,19,23};
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
#define acm(v, ini) accumulate(all(v),ini)
#define uni(v) vsort(v),(v).erase(unique(all(v)), (v).end())
#define smp(container, element) (container.find(element) != container.end())
#define vp(container, element) (find(all(container),element) != container.end())

#define ub(v,k) upper_bound(all(v), k) - v.begin()
#define lb(v,k) lower_bound(all(v), k) - v.begin()
#define msz(a) memset(a, 0, sizeof(a))
#define msm(a) memset(a, 0xff, sizeof(a))
#define fpre(n) fixed << setprecision(n)
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sea template< typename T
#define tc int tt; cin >> tt; for(int t=1; t<=tt; t++)

#define rep(i,n) for(__typeof(n) i=0; i<n; i++)
#define per(i,n) for(__typeof(n) i=n-1; i>=0; i--)
#define lrep(i,p,q) for(__typeof(q) i=p; i<=q; i++)
#define perl(i,p,q) for(__typeof(p) i=p; i>=q; i--)
#define IT(it,x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define RIT(it,x) for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)

sea > inline bool checkbit(T n, T pos) {return n & (1 << pos);}
sea > inline int setbit(T n, T pos) {return n | (1 << pos);}
sea > inline int resetbit(T n, T pos ) {return n & ~(1 << pos);}
sea > inline int flipbit(T n, T pos) {return n ^ (1 << pos);}

sea > inline T MAX(T a, T b){ return a ^ ((a ^ b) & -(a < b)); }
sea > inline T MIN(T a, T b){ return b ^ ((a ^ b) & -(a < b)); }
sea > void SWAP(T &a, T &b){ a = ((a) ^= (b)),  b = ((b) ^= (a)),  a = ((a) ^= (b)); }
sea > inline T sqr(T x){ return (x) * (x); }
sea > inline bool isPoT(T x){ return (x != 0 && (x&(x - 1)) == 0); }

sea > inline T gcd(T a, T b){ while (b) b ^= a ^= b ^= a %= b; return a; }
sea > T exgcd(T a, T b, T& x, T& y){ if(!b){ x = 1; y = 0;return a;} else{ T g = exgcd(b,a%b,y,x); y -= (a/b)*x; return g;}}
sea > inline T lcm(T a, T b){ return (a / gcd(a,b)) * b; }

sea > inline T mod(T a, T b){ return a >= b ? a % b : a; }
sea > T binpow(T n, T p){ T res = 1; while(p > 0){ if(p & 1) res *= n; n *= n; p >>= 1; } return res;}   /// n^p
sea > T bigmod(T n, T p, T M){ n %= M; T res = 1; while(p > 0){ if(p & 1)res = ((res%M)*(n%M))%M; n = ((n%M)*(n%M))%M; p >>= 1; } return res;}  /// (n^p) % M
sea > T modInv(T a, T m){return bigmod(a, m-2, m);}
sea > T mulmod(T a, T b, T M){ T x = 0, y = a % M; while(b > 0){ if(b&1) x = (x + y) % M; } y = (y << 1) % M; b >>= 1; }  /// (a*b) % M
bool mrpt(const ll n){ if(n<2) return false; if(n%2==0) return n==2; ll s = 0, d = n-1; while(d&1) s++, d/=2;for(auto a: PN){
        if(a > n-2) break; ll x = bigmod(a,d,n); if(x == 1 || x == n-1) continue;
        rep(i,s-1){ x = mulmod(x,x,n); if(x==1) return false; if(x==n-1) goto next_it; } return false; next_it:; }
return true;
}

static inline bool is_digit(char c) { return static_cast<unsigned char>(c - '0') < 10; }
static inline bool is_upper(char c) { return static_cast<unsigned char>(c - 'A') < 26; }
static inline bool is_lower(char c) { return static_cast<unsigned char>(c - 'a') < 26; }

namespace inputt{
    sea > inline void read(T& x){
        bool Negative = false; register int c; x = 0; c = getchar();
        if(c == '-'){ Negative = true; c = getchar(); }
        for(; (c>47 && c<58); c = getchar()) x = (x << 3) + (x << 1) + c -48; if(Negative) x *= -1;
    }
    sea, class... Ts> void read(T& t, Ts&... ts){ read(t); read(ts...); }
}
using namespace inputt;

const int N = 2e5+10;

class wavelet_tree{
public:
	int lo, hi;
	wavelet_tree *l, *r;
	VI b;
	wavelet_tree(int *from, int *to, int x, int y){
		lo = x, hi = y;
		if(lo == hi or from >= to) return;
		int mid = (lo+hi)/2;
		auto f = [mid](int x){ return x <= mid;};
		b.reserve(to-from+1);
		b.pb(0);
		for(auto it = from; it != to; it++)
			b.pb(b.back() + f(*it));
 		auto pivot = stable_partition(from, to, f);
		l = new wavelet_tree(from, pivot, lo, mid);
		r = new wavelet_tree(pivot, to, mid+1, hi);
	}
	//kth smallest element in [l, r]
	int kth(int l, int r, int k){
		if(l > r) return 0;
		if(lo == hi) return lo;
		int inLeft = b[r] - b[l-1];
		int lb = b[l-1]; //amt of nos in first (l-1) nos that go in left
		int rb = b[r]; //amt of nos in first (r) nos that go in left
		if(k <= inLeft) return this->l->kth(lb+1, rb , k);
		return this->r->kth(l-lb, r-rb, k-inLeft);
	}

	//count of nos in [l, r] Less than or equal to k
	int LTE(int l, int r, int k) {
		if(l > r or k < lo) return 0;
		if(hi <= k) return r - l + 1;
		int lb = b[l-1], rb = b[r];
		return this->l->LTE(lb+1, rb, k) + this->r->LTE(l-lb, r-rb, k);
	}

	//count of nos in [l, r] equal to k
	int count(int l, int r, int k) {
		if(l > r or k < lo or k > hi) return 0;
		if(lo == hi) return r - l + 1;
		int lb = b[l-1], rb = b[r], mid = (lo+hi)/2;
		if(k <= mid) return this->l->count(lb+1, rb, k);
		return this->r->count(l-lb, r-rb, k);
	}
	~wavelet_tree(){
		delete l;
		delete r;
	}
};


void input(void){
    //read();
}

int b[N],a[N];

class D2_OptimalSubsequencesHardVersion{
public:
    void solve(istream& cin, ostream& cout){
        VPII VP;
        int n;
        cin >> n;
        lrep(i,1,n){
            cin >> a[i];
            VP.pb({-a[i],i});
        }
        sort(all(VP));
        lrep(i,1,n){ b[i] = VP[i-1].s;}
        wavelet_tree *T = new wavelet_tree(b+1, b+n+1,1,N);
        int m;
        cin >> m;
        rep(i,m){
            int k,p;
            cin >> k >> p;
            cout << a[T->kth(1,k,p)] << endl;
        }
    }
};


signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    #ifdef BAL_AMAR
        freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
    #endif // BAL_AMAR

    #ifdef BAL_AMAR
        auto start_time = clock();
        cerr << fpre(3) << fixed;
    #endif // BAL_AMAR

    D2_OptimalSubsequencesHardVersion Problem;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    Problem.solve(in, out);

    #ifdef BAL_AMAR
        auto end_time = clock();
        cerr << "Time Elapsed: " << fpre(3) << 1.0 * (end_time - start_time) / CLOCKS_PER_SEC  << " Sec"<< endl;
    #endif // BAL_AMAR

    return 0;
}

