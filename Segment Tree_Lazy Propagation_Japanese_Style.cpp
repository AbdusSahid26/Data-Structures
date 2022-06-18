#include<bits/stdc++.h>
using namespace std;

/// Problem   : Minimum value in a range
///               http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236696
///                http://judge.u-aizu.ac.jp/onlinejudge/review.jsp?rid=2236726
/// blog link :http://tsutaj.hatenablog.com/entry/2017/03/30/224339

/// submission : minimum query--->   https://codeforces.com/contest/1295/submission/95368924

struct lazySegmentTree{
private:
    int n;
    vector<long long> node;
    vector<long long> lazy;
public:
    lazySegmentTree(){
        int sz = 2e5 + 10; /// input constraint.
        n = 1 << (32 - __builtin_clz(sz - 1)); /// n = 1; while(n < sz) n *= 2;
        node.resize(2 * n - 1, 0);
        lazy.resize(2 * n - 1, 0);

        for(int i=0; i<sz; i++) node[i + n - 1] = 0;
        for(int i=n - 2; i>=0; i--) node[i] = node[2 * i + 1] + node[2 * i + 2];
    }

    void pushDown(int k, int l, int r){
        if(lazy[k] != 0){
            node[k] += lazy[k];
            if(r - l > 1){
                lazy[2 * k + 1] += lazy[k];
                lazy[2 * k + 2] += lazy[k];
            }
            lazy[k] = 0;
        }
    }
    void update(int a, int b, long long x, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        pushDown(k, l, r);
        if(b <= l or r <= a) return;
        if(a <= l and r <= b){
            lazy[k] += x;
            pushDown(k, l, r);
        }
        else{
            int mid = (l + r) >> 1;
            update(a, b, x, 2 * k + 1, l, mid);
            update(a, b, x, 2 * k + 2, mid, r);
            node[k] = min(node[2 * k + 1], node[2 * k + 2]);
        }
    }
    long long query(int a, int b, int k = 0, int l = 0, int r = -1){
        if(r < 0) r = n;
        pushDown(k, l, r);
        if(b <= l or r <= a) return 1e18;
        if(a <= l and r <= b) return node[k];
        int mid = (l + r) >> 1;
        return min(query(a, b, 2 * k + 1, l, mid), query(a, b, 2 * k + 2, mid, r));
    }
};
lazySegmentTree seg;


int main(){
    int n, q;
    cin >> n >> q;
    for(int i=0; i<q; i++){
        int t;
        cin >> t;
        if(t == 0){
            int s, t, x;
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        }
        else{
            int s, t;
            cin >> s >> t;
            cout << seg.query(s, t + 1) << endl;
        }
    }

    return 0;
}
