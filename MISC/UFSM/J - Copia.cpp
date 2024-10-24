#include <bits/stdc++.h>

#define N 1000100
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

long long n, m;
vector<long long> v[N+1];
long long DP[N+1];

long long dp(int i){ // posicao inicial
	if(i == m) return 0;

	if(DP[i] != -1) return DP[i];

	long long ans = 0;
	for(int l = 0; l < n; l++){ // linha
		long long acc = 0;
		long long b = 0;
		for(int j = i; j < m; j++){ // posicao final
			acc += v[l][j];
			if(v[l][j]) acc += b;
			
			ans = max(ans, dp(j+1) + acc);
			
			if(!v[l][j]) b = -1;
			b = min(b+1, 5ll);
		}
	}	

	return DP[i] = ans;
}

void solve(){
	cin >> n >> m;

	for(int i = 0; i < n; i++){
		v[i].push_back(0);
		for(int j = 1; j <= m; j++){
			long long x; cin >> x;
			v[i].push_back(x);
		}
	}

	DP[0] = 0;
	
	for(int j = 1; j <= m; j++){
		for(int l = 0; l < n; l++){ // linha
			long long lastZero = j+1;
			long long acc = 0;
			for(int i = j; i >= 1; i--){ // posicao final
				
				if(v[l][i] == 0){
					long long b = (lastZero-i-1);
					if(b <= 5) b = (b-1) * b / 2ll;
					else b = 10 + (b-5) * 5;
					DP[j] = max(DP[j], DP[i-1] + acc + b);
					acc += b;
					lastZero = i;
				}
				else{
					long long b = (lastZero-i);
					if(b <= 5) b = (b-1) * b / 2ll;
					else b = 10 + (b-5) * 5;
					acc += v[l][i];
					DP[j] = max(DP[j], DP[i-1] + acc + b);
				}
			}
			// cout << "DP[" << j << "]: " << DP[j] << endl;
		}	
	}


	cout << DP[m] << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}