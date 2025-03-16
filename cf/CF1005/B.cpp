#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

#define LEFT(x) (2*x)
#define RIGHT(x) (2*x+1)

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	int n;
	cin >> n;


	vector<int> freq(n+1,0);
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
		freq[a[i]]++;
	}

	for(int i = 1; i <= n; i++){
		a[i] = (freq[a[i]] == 1);
	}

	pair<int,int> ans = {0,-1};

	int last = 1;
	for(int i = 1; i <= n; i++){
		if(!a[i]) last = i+1;
		else{
			if(ans.se - ans.fi < i-last){
				ans = {last, i};
			}
		}
	}
	if(ans.se - ans.fi < 0){
		cout << 0 << endl;
	}
	else{
		cout << ans.fi << " " << ans.se << endl;
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