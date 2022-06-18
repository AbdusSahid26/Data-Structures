/*

Tourist
problem : https://codeforces.com/contest/1208/problem/E

*/

template <typename T, class F = function<T(const T&, const T&)>>
class SparseTable {
 public:
  int n;
  vector<vector<T>> mat;
  F func;

  SparseTable(const vector<T>& a, const F& f) : func(f) {
    n = static_cast<int>(a.size());
    int max_log = 32 - __builtin_clz(n);
    mat.resize(max_log);
    mat[0] = a;
    for (int j = 1; j < max_log; j++) {
      mat[j].resize(n - (1 << j) + 1);
      for (int i = 0; i <= n - (1 << j); i++) {
        mat[j][i] = func(mat[j - 1][i], mat[j - 1][i + (1 << (j - 1))]);
      }
    }
  }

  T get(int from, int to) const {
    assert(0 <= from && from <= to && to <= n - 1);
    int lg = 32 - __builtin_clz(to - from + 1) - 1;
    return func(mat[lg][from], mat[lg][to - (1 << lg) + 1]);
  }
};


************************************************



const int Max = 10000005;
int ST[24][Max];
int A[Max];

void Compute_ST(int N){
    for (int i=0; i<N; i++) ST[0][i] = i;

    for (int k = 1; (1 << k)<=N; k++){
        for (int i=0; i+(1<<k)<=N; i++){
            int x = ST[k-1][i];
            int y = ST[k-1][i+((1<<k)-1)];
            ST[k][i]=A[x]<=A[y]?x:y;
        }
    }
}

int RMQ(int i, int j){
    int k = log2(j-i+1);
    int x = ST[k][i];
    int y = ST[k][j-(1<<k)+1];
    return A[x] <= A[y] ? x : y;
}

int main(){
    int N, Q;

    cin >> N >> Q;

    for(int i=0; i<N; i++) cin >> A[i];

    Compute_ST(N);

    while(Q--){
        int x,y;
        cin >> x >> y;
        --x,--y;
        cout << A[RMQ(x,y)] << endl;
    }
    //Time();
    return 0;
}
