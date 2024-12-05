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


void solve(){
	int n, k;
	cin >> n >> k;

	if(n == k){
		cout << "YES" << endl;
		vector<int> a;
		for(int i = 1; i <= n; i++) a.push_back(i);
		for(int j = 0; j < k; j++){
			int p = (n-j) % n;
			for(int i = 0; i < n; i++, p++){
				cout << a[p % n] << " ";
			}
			cout << endl;
		}
		return ;
	}

	vector<int> f(11);
	f[0] = 1;
	for(int i = 1; i <= 10; i++){
		f[i] = f[i-1] * i;
	}

	if(k%2 == 0){
		if(n <= 10 and k > 2*n * f[n]){
			cout << "NO" << endl;
			return;
		}

		cout << "YES" << endl;
		
		vector<int> a, b;
		for(int i = 1; i <= n; i++) a.push_back(i);
		for(int i = n; i >= 1; i--) b.push_back(i);
		
		int l = 0;
		for(int j = 0; j < k; j+=2, l++){
			int p = (n-l) % n;
			for(int i = 0; i < n; i++, p++){
				cout << a[p % n] << " ";
			}
			cout << endl;
			p = (n-l) % n;
			for(int i = 0; i < n; i++, p++){
				cout << b[p % n] << " ";
			}
			cout << endl;

			if((l+1 >= n) and n%(l+1) == 0){
				// cout << "perm" << endl;
				l = 0;
				next_permutation(a.begin(), a.end());
				for(int i = 0; i < n; i++) b[i] = n+1-a[i];
			}

		}
		return ;
	}

	cout << "NO" << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}