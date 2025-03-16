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
	int n;
	cin >> n;

	string s;
	cin >> s;

	vector<int> ans(n+1, 0);

	int wrong = 0;
	for(int i = 0; i < s.size()/2; i++){
		if(s[i] != s[n-i-1]) wrong++;
	}

	for(int i = wrong; i <= n-wrong; i+=1+(s.size()%2 == 0)){
		ans[i] = 1;
	}

	for(int i : ans) cout << i;
	cout << endl;
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