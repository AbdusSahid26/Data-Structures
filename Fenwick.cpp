#include<bits/stdc++.h>
using namespace std;
/*
class fenwick{
public:

  vector<int> fenw;
  int n;

  fenwick(int n) : n(n){
    fenw.resize(n);
  }

  void modify(int x, int v){
    while (x < n){
      fenw[x] += v;
      x |= x + 1;
    }
  }

  int query(int x){
    int res = 0;
    while(x >= 0){
      res += fenw[x];
      x = (x & (x + 1)) - 1;
    }
    return res;
  }
};
*/

template<class t>
struct BIT{
	vc<t> buf;
	int s;
	BIT(int n=0){init(n);}
	void init(int n){buf.assign(s=n,0);}
	void add(int i,t v){
		for(;i<s;i+=(i+1)&(-i-1))
			buf[i]+=v;
	}
	t get(int i){
		t res=0;
		for(;i>=0;i-=(i+1)&(-i-1))
			res+=buf[i];
		return res;
	}
	t sum(int b,int e){
		return get(e-1)-get(b-1);
	}
	int kth(int k){
		int res=0;
		for(int i=topbit(s);i>=0;i--){
			int w=res+(1<<i);
			if(w<=s&&buf[w-1]<=k){
				k-=buf[w-1];
				res=w;
			}
		}
		return res;
	}
	//yukicoder No.1024
	int kth_helper(int k,int i){
		return kth(k+get(i-1));
	}
};




template <class T> class fw{
private:
    vector<T> fen;
    T N;
public:
    fw(T N) : N(N){
        fen.assign(N + 1, 0);
    }
    T Query(T l, T r){
        return Query(r) - Query(l - 1);
    }
    void Modify(T x, T val){
        for( ; x <= N; x += (x & (-x)))
            fen[x] += val;                   /// x = index & val = value
    }
    T Query(T x){
        T Res = 0;
        for( ; x > 0; x -= (x & (-x)))
            Res += fen[x];
        return Res;
    }
};


int main(){

     int n; cin >> n;
     fw<int> fen(n);
     vector<int> v(n);
     for(int i = 1; i <= n; i++){
           cin >> v[i];
           fen.Modify(i, v[i]);
     }
     cout << "Sum of 1st 5 element " << fen.Query(5) << endl;
     cout << "Sum between index 1-3 is " << fen.Query(1, 3) << endl;
     return 0;
}
