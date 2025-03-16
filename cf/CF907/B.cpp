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

long long p[31];

void solve(){
	int n, q;
	cin >> n >> q;

	vector<long long> a(n), b(q);

	vector<int> freq(31, 0);
	for(int i = 0; i < n; i++) cin >> a[i];
	for(int i = 0; i < q; i++){
		cin >> b[i];
	}

	vector<long long> t(31);
	for(int i = 1; i <= 30; i++) t[i] = p[i];

	for(int i = 1; i <= 30; i++){
		long long temp = 0;
		for(int j = 0; j < q; j++){
			if((t[i] + temp) % p[b[j]] == 0){
				temp += p[b[j]-1];
			}
		}
		t[i] = temp;
	}

	for(int i = 0; i < n; i++){
		int k = 0;
		for(int d = 1; d <= 30; d++){
			if(a[i] % p[d] == 0) k = d;
		}

		a[i] += t[k];
	}

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;

	p[0] = 1;
	for(int i = 1; i <= 30; i++){
		p[i] = p[i-1] * 2ll;
	}
	
	while(t--){
		solve();
	}
    return 0;

}