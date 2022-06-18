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


/*

source : https://github.com/mpfeifer1/Reference/blob/master/searchbuckets.cpp

*/

#pragma GCC optimize("03")
#include <bits/stdc++.h>

using namespace std;

using ll = long long;
using ld = long double;

const ll M = 998244353;


/// search_buckets provides two operations on an array:
/// 1) set array[i] = x
/// 2) count how many i in [start, end) satisfy array[i] < value
/// Both operations take sqrt(N log N) time. Amazingly, because of the cache efficiency this is faster than the
/// (log N)^2 algorithm until N = 2-5 million.


template<typename T> struct Search_Buckets{
    /// values are just the values in order. buckets are sorted in segments of BUCKET_SIZE (last segment may be smaller)

    int N, BUCKET_SIZE;
    vector<T> Values, Buckets;
    Search_Buckets(const vector<T> &Initial = {}){
        Init(Initial);
    }
    int Get_Bucket_End(int Bucket_Start) const{
        return min(Bucket_Start + BUCKET_SIZE, N);
    }
    void Init(const vector<T> &Initial){
        Values = Buckets = Initial;
        N = Values.size();
        BUCKET_SIZE = 3 * sqrt(N * log(N + 1)) + 1;
        for(int Start = 0; Start < N; Start += BUCKET_SIZE)
            sort(Buckets.begin() + Start, Buckets.begin() + Get_Bucket_End(Start));
    }
    int Bucket_Less_Than(int Bucket_Start, T Value) const{
        auto Begin = Buckets.begin() + Bucket_Start;
        auto End = Buckets.begin() + Get_Bucket_End(Bucket_Start);
        return lower_bound(Begin, End, Value) - Begin;
    }
    int Less_Than(int Start, int End, T Value) const{
        int Count = 0;
        int Bucket_Start = Start - Start % BUCKET_SIZE;
        int Bucket_End = min(Get_Bucket_End(Bucket_Start), End);
        if(Start - Bucket_Start < Bucket_End - Start){
            while(Start > Bucket_Start)
                Count -= Values[--Start] < Value;
        }
        else{
            while(Start < Bucket_End)
                Count += Values[Start++] < Value;
        }
        if(Start == End) return Count;
        Bucket_Start = End - End % BUCKET_SIZE;
        Bucket_End = Get_Bucket_End(Bucket_Start);

        if(End - Bucket_Start < Bucket_End - End){
            while(End > Bucket_Start)
                Count += Values[--End] < Value;
        }
        else{
            while(End < Bucket_End)
                Count -= Values[End++] < Value;
        }
        while(Start < End and Get_Bucket_End(Start) <= End){
            Count += Bucket_Less_Than(Start, Value);
            Start = Get_Bucket_End(Start);
        }
        assert(Start == End);
        return Count;
    }
    int Prefix_Less_Than(int n, T Value) const{
        return Less_Than(0, n, Value);
    }
    void Modify(int Index, T Value){
        int Bucket_Start = Index - Index % BUCKET_SIZE;
        int Old_pos = Bucket_Start + Bucket_Less_Than(Bucket_Start, Values[Index]);
        int New_pos = Bucket_Start + Bucket_Less_Than(Bucket_Start, Value);
        if(Old_pos < New_pos){
            copy(Buckets.begin() + Old_pos + 1, Buckets.begin() + New_pos, Buckets.begin() + Old_pos);
            New_pos--;
        }
        else{
            copy_backward(Buckets.begin() + New_pos, Buckets.begin() + Old_pos, Buckets.begin() + Old_pos + 1);
        }
        Buckets[New_pos] = Value;
        Values[Index] = Value;
    }
};

/*
class CommonDivisor{
public:
    void Solve(istream& cin, ostream& cout){
        ReadInput();

        /// https://codeforces.com/problemset/problem/1093/E

        int n, m;
        cin >> n >> m;
        vector<int> First(n);
        vector<int> Second(n);
        vector<int> Location(n+1);

        for(int i=0; i<n; i++){
            cin >> First[i];
            Location[First[i]] = i;
        }
        for(int &x: Second){
            cin >> x;
            x = Location[x];
        }
        Search_Buckets<int> Bucket(Second);

        for(int i=0; i<m; i++){
            int Query;
            cin >> Query;
            if(Query == 1){
                int La, Ra, Lb, Rb;
                cin >> La >> Ra >> Lb >> Rb;
                --La;
                --Lb;
                cout << Bucket.Less_Than(Lb, Rb, Ra) - Bucket.Less_Than(Lb, Rb, La) << endl;
            }
            else if(Query == 2){
                int x, y;
                cin >> x >> y;
                --x;
                --y;
                Bucket.Modify(x, Second[y]);
                Bucket.Modify(y, Second[x]);
                swap(Second[x], Second[y]);
            }
        }
    }
};
*/

int main() {
    vector<int> v = {1,2,3,4};

    // Initialize a search_buckets list named buckets
    Search_Buckets<int> buckets(v);

    // Count how many in [l,r) are less than t
    int l = 0; int r = 2; int t = 2;
    buckets.Less_Than(l,r,t);

    // buckets[x] = y
    x = 1; y = 3;
    buckets.Modify(x, y);
}

