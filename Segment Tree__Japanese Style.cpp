#include<bits/stdc++.h>
using namespace std;



blog link    : http://tsutaj.hatenablog.com/entry/2017/03/29/204841
problem link : https://codeforces.com/contest/1348/submission/78737032
               https://codeforces.com/contest/1348/submission/78747749


struct Seguki{
    using T = int;
    int N;
    vector<T> data;
    T id = pair<int, int>(INF, INF);
    T funct(T &a, T &b){
        return min(a, b);
    }

    Seguki(int n){
//        N = 1;
//        while(n > N) N <<= 1;

        /// The number of nodes in the bottom row is the size of the original array that is at least 2 powers -> let this be n.
        /// The number of nodes required for the entire segment tree is 2n-1
        N = 1 << (32 - __builtin_clz(n - 1));  // O(1);
        data = vector<T> (2*N - 1, id);
    }

    Seguki(int n, vector<T> &v){
        N = 1 << (32 - __builtin_clz(n - 1));
        data = vector<T> (2*N - 1, id);
        Rep(i, n){
            data[i + N - 1] = v[i]; /// bottom node
        }
        Perl(i, N-2, 0){
            data[i] = funct(data[2*i + 1], data[2*i + 2]);
        }
    }
    Seguki(){}

    void update(int pos, T val){
        pos += N - 1;  /// Access the bottom node
        data[pos] = val;
        while(k > 0){
            /// After updating the bottom node, go up to the parent node
            pos = (pos - 1) >> 1;
            data[k] = funct(data[2*pos + 1], data[2*pos + 2]);
        }
    }

    T query(int a, int b, int k, int l, int r){
        /// Answer the minimum value of the elements in the request interval [a, b)
        /// k := index of the node where you are
        /// The target interval is [l, r)
        if(r <= a or b <= l) return id; /// Request section and target section don't intersect.
        if(a <= l and r <= b) return data[k]; /// The request interval completely covers the target interval and use the target interval to calculate the answer.
        else{
            /// Request section covers a part of the target interval, so search for children
            /// left = left children and right = right children
            /// The new target section is a half of the current target section thing
            T left = query(a, b, 2*k + 1, l, (l + r) >> 1);
            T right = query(a, b, 2*k + 2, (l + r) >> 1, r);
            return funct(left, right);
        }
    }

    T value(int k){ /// value of node k
        return data[k + N - 1];
    }
    T get(int a, int b){ /// value from node: a to b
        return query(a, b, 0, 0, N);
    }
};
