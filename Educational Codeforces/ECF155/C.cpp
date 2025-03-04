#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 998244353
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int n;
string s;

void solve(){
	cin >> s;
	n = s.size();

	vector<long long> a;

	for(int i = 0; i < n; i++){
		if(i == 0 or s[i] != s[i-1]){
			a.push_back(1);
		}
		else{
			a.back()++;
		}
	}

	long long ans1, cnt1;
	ans1 = 0;
	cnt1 = 1;
	for(int i = 0; i < a.size(); i++){
		cnt1 *= a[i];
		cnt1 %= MOD;
		ans1 += a[i]-1;
	}
	
	for(int i = ans1; i >= 1; i--){
		cnt1 *= i;
		cnt1 %= MOD;
	}

	cout << ans1 << " " << cnt1 << endl;
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