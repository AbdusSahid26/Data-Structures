#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#define mp make_pair
using namespace std;
using namespace __gnu_pbds;
typedef pair<int, int> pii;
typedef tree<pii, null_type, less<pii>, rb_tree_tag, tree_order_statistics_node_update> OST;

const int N = 100001;

OST bit[N];

void insert(int x, int y)
{
    for(int i = x; i < N; i += i & -i)
        bit[i].insert(mp(y, x));
}

void remove(int x, int y)
{
    for(int i = x; i < N; i += i & -i)
        bit[i].erase(mp(y, x));
}

int query(int x, int y)
{
    int ans = 0;
    for(int i = x; i > 0; i -= i & -i)
        ans += bit[i].order_of_key(mp(y+1, 0));
    return ans;
}
//Time complexity : O(Qlog2(N))
//Space complexity : O(Qlog(N))
//https://codeforces.com/blog/entry/52094
