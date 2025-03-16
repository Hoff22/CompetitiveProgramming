#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

mt19937 rng((int) chrono::steady_clock::now().time_since_epoch().count());
const int rand_num = uniform_int_distribution<int>(0, MOD-1)(rng);

vector<long long> h; // hash of prefixes
vector<long long> p; // powers of r (rand_numom value) for range querys of hash

void init(int n){
    p[0] = 1;
    for(int i = 1; i < n; i++){
        p[i] = (p[i-1] * rand_num) % MOD;
    }
}

/* O(N) */
void hash_str(string s){
    int n = s.size();
    h[0] = s[0];
    for(int i = 1; i < n; i++){
        h[i] = (h[i-1] * rand_num + s[i]) % MOD;
    }
}

/* O(1) */
long long sub_hash(int l, int r){
    if(l == 0){
        return h[r];
    }
    long long ans = (h[r] - h[l-1] * p[r-l+1]) % MOD;
    ans += MOD;
    ans %= MOD;

    return ans;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	string a;
    cin >> a;
    int d;
    cin >> d;
    int n = a.size();

    h.resize(n);
    p.resize(n);

    init(n);

    hash_str(a);

    int ans = 0;
    int i = 0;
    while(i < n){
       
        /*

            i = 4
            best_d = 3

            (4 - 6) == (7 - 9) 
            
            abcd abcd .... abcd abxe
                                ^
        
            N/D * D * N/D => N²/D
             V         ^
            
            d = 4

            abcab xyz xyz
            abca bxyz xyz

            abcabxyzxyz
        */

        int best = i+d-1;
        for(int cur_d = 1; cur_d <= d; cur_d++){
            int j = i;

            while(j+2*cur_d-1 < n and sub_hash(j, j+cur_d-1) == sub_hash(j+cur_d, j+2*cur_d-1)){
                j += cur_d;
            }

            j += cur_d;

            while(j < n and a[j] == a[j-cur_d]) j++;

            best = max(best, j);
        }

        ans++;
        i = best;
    }

    cout << ans << endl;

    return 0;

}