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
    Don't give up until the last second.

    Topcoder handle : sea_26
    Codechef handle : sea_26

    Practice makes a man perfect.

*/

#pragma GCC optimize("03")
#include <bits/stdc++.h>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;


template< typename T>
using Ordered_Set = tree<int, null_type, T,
        rb_tree_tag, tree_order_statistics_node_update>;


using ll = long long;
using ld = long double;

typedef pair<int, int> PII;
typedef pair<ll, int> PLI;
typedef pair<int, ll> PIL;
typedef pair<ll, ll> PLL;

typedef map<int, int> MII;
typedef map<ll, ll> MLL;
typedef map<PII, int> MPIII;
typedef map<string, int> MSI;

const ll M = 1e9 + 7;
const ll M2 = 998244353;
const int Iinf = 0x3f3f3f3f;
const ll Linf = 0x3f3f3f3f3f3f3f3f;
const ld PI = acos(-1.0);
// const double pi = atan2(0, -1);
// const double PI = 4 * atan(1);
// const double pi = 2*cos(0.0);

#define mp make_pair
#define eb emplace_back
#define pf push_front
#define pb push_back
#define ppb pop_back()
#define fbo(ind) find_by_order(ind)
#define ook(val) order_of_key(val)
#define f first
#define s second
#define sz size()

#define bp(n) __builtin_popcount(n)
#define bclz(n) __builtin_clzll(n)
#define bctz(n) __builtin_ctzll(n)
#define bip(n) __builtin_parity(n)

#define All(v) (v).begin(),(v).end()
#define Rall(v) (v).rbegin(),(v).rend()
#define rvs(v) sort(all(v),greater<int>())
#define mnv(v) *min_element(all(v))
#define mxv(v) *max_element(all(v))
#define acm(v, ini) accumulate(all(v),ini)
#define smp(container, element) (container.find(element) != container.end())
#define vp(container, element) (find(all(container),element) != container.end())

#define ub(v, k) upper_bound(all(v), k) - v.begin()
#define lb(v, k) lower_bound(all(v), k) - v.begin()
#define msz(a) memset(a, 0, sizeof(a))
#define msm(a) memset(a, 0xff, sizeof(a))
#define fpre(n) fixed << setprecision(n)
#define watch(x) cerr << (#x) << " is " << (x) << endl
#define sea template< typename T
#define tc int tt; cin >> tt; for(int t=1; t<=tt; t++)

#define Rep(i, n) for(__typeof(n) i=0; i<n; i++)
#define Per(i, n) for(__typeof(n) i=n-1; i>=0; i--)
#define Lrep(i, p, q) for(__typeof(q) i=p; i<=q; i++)
#define Perl(i, p, q) for(__typeof(p) i=p; i>=q; i--)
#define IT(it, x) for(__typeof((x).begin()) it = (x).begin(); it != (x).end(); it++)
#define RIT(it, x) for(__typeof((x).rbegin()) it = (x).rbegin(); it != (x).rend(); it++)

const int dx4[] = { +1, -1, +0, +0 };
const int dy4[] = { +0, +0, +1, -1 };
const int dx8[] = { +0, +0, +1, -1, -1, +1, -1, +1 };
const int dy8[] = { -1, +1, +0, +0, +1, +1, -1, -1 };

sea > using V = vector<T>;
sea > using VV = vector<vector<T> >;
sea > using MinHeap = priority_queue<T, vector<T>, greater<T> >;

sea > inline bool Checkbit(T n, T Pos){ return n & (1 << Pos); }
sea > inline int Resetbit(T n, T Pos){ return n | (1 << Pos); }
sea > inline int Unsetbit(T n, T Pos){ return n & ~(1 << Pos); }
sea > inline int Flipbit(T n, T Pos){ return n ^ (1 << Pos); }

sea > inline T Max(T a, T b){ return a ^ ((a ^ b) & -(a < b)); }
sea > inline T Min(T a, T b){ return b ^ ((a ^ b) & -(a < b)); }
sea > inline void Swap(T &a, T &b){ a = ((a) ^= (b)),  b = ((b) ^= (a)),  a = ((a) ^= (b)); }
sea > inline T Sqr(T x){ return (x) * (x); }
sea > inline bool IsPoT(T x){ return (x != 0 and (x&(x - 1)) == 0); }

sea > bool Chkmax(T &a, const T b){ if(a < b){a = b; return true;} else return false; }
sea > bool Chkmin(T &a, const T b){ if(a > b){a = b; return true;} else return false; }
sea > V<T> compress(V<T> A){ sort(all(A)); A.erase(unique(all(A)), A.end()); return A;}

sea > T Gcd(T a, T b){ while(b) b ^= a ^= b ^= a %= b; return a; }
sea > T Exgcd(T a, T b, T& x, T& y){ if(!b){ x = 1; y = 0;return a;} else{ T g = Exgcd(b, a%b, y, x); y -= (a/b)*x; return g;}}
sea > inline T Lcm(T a, T b){ return (a / Gcd(a, b)) * b; }

sea > T Powmod(T n, T p, T M){ n %= M; T Res = 1; while(p > 0){ if(p & 1) Res = ((Res%M)*(n%M))%M; n = ((n%M)*(n%M))%M; p >>= 1; } return Res;}  /// (n^p) % M
sea > T ModInv(T a, T m){ return Powmod(a, m-2, m); }
sea > T Mulmod(T a, T b, T M){ T x = 0, y = a % M; while(b > 0){ if(b&1) x = (x + y) % M; } y = (y << 1) % M; b >>= 1; }  /// (a*b) % M

static inline bool Is_digit(char c){ return static_cast<unsigned char>(c - '0') < 10; }
static inline bool Is_upper(char c){ return static_cast<unsigned char>(c - 'A') < 26; }
static inline bool Is_lower(char c){ return static_cast<unsigned char>(c - 'a') < 26; }

namespace Input{
    sea > inline void read(T& x){
        bool Negative = false; register int c; x = 0; c = getchar();
        if(c == '-'){ Negative = true; c = getchar(); }
        for(; (c > 47 and c < 58); c = getchar()) x = (x << 3) + (x << 1) + c - 48; if(Negative) x *= -1;
    }
    sea, class... Ts> void read(T& t, Ts&... ts){ read(t); read(ts...); }
    sea > istream &operator>>(istream &is, vector<T> &vec){ for(auto &v : vec) is >> v; return is; }
}
using namespace Input;

inline void Add(int &a, int b){ a += b; if(a >= M) a -= M;}
inline void Sub(int &a, int b){ a -= b; if(a < 0) a += M;}
inline int Mul(int a, int b){ return (int)((long long) a * b % M);}


void ReadInput(void){
    //read();
}

/*

https://codeforces.com/contest/840/submission/70734953
https://codeforces.com/contest/617/submission/70746384

*/

/// Time Complexity : 0((N+Q).Sqrt(N))

const int N = 3e5 + 10;
const int Block_Size = 700;
int Array[N], Res[N], Freq[N];

struct Query{
    int l;
    int r;
    int k;
    int idx;
    bool operator < (const Query &p){
        if(l / Block_Size != p.l / Block_Size){
            return l < p.l;
        }
        return ((l / Block_Size) & 1 ? (r  < p.r) : (r > p.r));  /// Odd block = ascending & Even block descending order. This will minimize the movement of right pointer.
    }
}Data[N];

inline void Add(int idx){
    Freq[Array[idx]]++;
}

inline void Remove(int idx){
    Freq[Array[idx]]--;
}

random_device rd;
mt19937 ran(rd());

int Get_Answer(int l, int r, int k){
    uniform_int_distribution<int> Range(l, r);
    int Mn = (r - l + 1) / k;
    int Tot = Iinf;
    Lrep(i, 0, 64){
        int Val = Array[Range(ran)];
        if(Freq[Val] > Mn) Tot = Min(Tot, Val);
    }
    return (Tot != Iinf ? Tot : -1);
}


class Destiny{
public:
    void Solve(istream& cin, ostream& cout){
        ReadInput();

        int n, qu;
        cin >> n >> qu;
        Rep(i, n) cin >> Array[i];
        Rep(i, qu){
            cin >> Data[i].l >> Data[i].r;
            Data[i].l--;
            Data[i].r--;
            Data[i].idx = i;
        }

        sort(Data, Data + qu);
        int cur_l = 0;
        int cur_r = -1;

        Rep(i, qu){
            auto q = Data[i];
            while(cur_l > q.l){
                cur_l--;
                Add(cur_l);
            }
            while(cur_r < q.r){
                cur_r++;
                Add(cur_r);
            }
            while(cur_l < q.l){
                Remove(cur_l);
                cur_l++;
            }
            while(cur_r > q.r){
                Remove(cur_r);
                cur_r--;
            }
            Res[q.idx] = Get_Answer(q.l, q.r, q.k);
        }
        Rep(i, qu) cout << Res[i] << endl;
        cout << endl;
    }
};



signed main(){

    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

#ifdef LOCAL_DEFINE
    auto start_time = clock();
#endif // LOCAL_DEFINE

#ifdef LOCAL_DEFINE
    freopen("input.txt", "r", stdin);
        //freopen("output.txt", "w", stdout);
#endif // LOCAL_DEFINE

    Destiny Problem;
    std::istream& in(std::cin);
    std::ostream& out(std::cout);
    Problem.Solve(in, out);

#ifdef LOCAL_DEFINE
    auto end_time = clock();
        cerr << "\nTime Elapsed: " << fpre(3) << 1.0 * (end_time - start_time) / CLOCKS_PER_SEC  << " Sec"<< endl;
#endif // LOCAL_DEFINE

    return 0;
}

