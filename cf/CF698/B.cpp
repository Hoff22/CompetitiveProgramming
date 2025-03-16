#include <bits/stdc++.h>

#define N 10000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n, k;
	int a[N];
	int seen[10];

	cin >> n >> k;

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}
	
	for(int i = 0; i < n; i++){

		int idx = 0;
		while(a[i] > 0){
			memset(seen, 0, sizeof(seen));

			int temp = a[i];
			//cout << a[i] << endl;
			while(temp > 0){
				if(idx > 0 and temp % 10 > k){
					cout << "YES" << endl;
					break;
				}

				if(seen[temp % 10]){
					temp = 0;
					break;
				}

				if(temp % 10 == k){
					cout << "YES" << endl;
					break;
				}

				seen[temp % 10] = 1;

				temp -= k;
			}

			if(temp > 0) break;

			a[i] /= 10;
			idx++;
		}
		if(a[i] <= 0) cout << "NO" << endl;
	}
}

int main(){
	
	int t;
	cin >> t;

	while(t--){
		solve();
	}
	

    return 0;

}