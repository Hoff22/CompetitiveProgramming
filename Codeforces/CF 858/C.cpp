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
	long long n;
	cin >> n;

	if(n==1){
		long long a, b;
		cin >> a >> b;
		cout << min(abs(a-b), abs(a) + abs(b)) << endl;
		return;
	}

	if(n%2){
		long long ans = 0;
		for(int i = 0; i < 2*n; i++){
			int x; cin>>x;
			ans += abs(x);
		}
		cout << ans << endl;
	}
	else{
		vector<int> a(2*n);
		for(int i = 0; i < 2*n; i++){
			cin >> a[i];
		}

		long long ans1 = 0;
		for(int i = 0; i < 2*n; i++){
			ans1 += abs(-1ll-a[i]);
		}

		long long tans1 = INF;
		for(int i = 0; i < 2*n; i++){
			tans1 = min(tans1, ans1 - (abs(-1-a[i])) + (abs(n-a[i])));
		}

		long long ans3 = 0;
		for(int i = 0; i < 2*n; i++){
			ans3 += abs(a[i]);
		}

		if(n == 2){
			long long ans2 = 0;
			for(int i = 0; i < 4; i++){
				ans2 += abs(2-a[i]);
			}

			cout << min({ans2, tans1, ans3}) << endl;
		}
		else{
			cout << min(tans1, ans3) << endl;
		}

	}
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

/*

A * B * C  ==  D

-2 -2 -2 -2   2 2


3 1 0 0  -3 -1 0 0

-3 -2 -1 0 1 2 3 4

         1 0 1 2 3
 2  1  0  
    1  -1  1  -1


-1  1  -1  1  -1  1 


*/