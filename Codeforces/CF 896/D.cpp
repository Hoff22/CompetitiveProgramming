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

vector<int> g[N+1];
long long v[N+1];
long long p2[32];

void solve(){
	int n;
	cin >> n;

	long long mn = INF;
	long long x= 0;

	for(int i = 0; i < n; i++){
		cin >> v[i];
		mn = min(mn, v[i]);
		x ^= v[i];
	}

	sort(v, v+n+1);

	vector<int> freq(31, 0);

	for(int i = 0; i < n; i++){
		for(int j = 0; j <= 30; j++){
			if((v[i]>>j) & 1) freq[j]++;			
		}
	}

	int l = 0;
	int r = 1000000000;
	int ans = 0;

	while(l<=r){
		int m = l + (r-l)/2;

		vector<int> freq(31, 0);
		for(int i = 0; i < n; i++){
			int sum = (m | v[i]) ^ m;
			int sub = (m & v[i]) ^ m;

			for(int j = 0; j <= 30; j++){
				freq[j] += (sum>>j) & 1;
				freq[j] -= (sub>>j) & 1;
			}
		}

		int good = 1;
		for(int i = 0; i <= 30; i++) if(freq[i] != 0) good = 0;

		if(good){
			
		}
	}

	cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	p2[0] = 1;
	for(int i = 1; i <= 30; i++){
		p2[i] = p2[i-1] * 2ll;
	}

	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}