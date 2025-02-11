#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

using namespace std;

typedef long long ll;

void solve(){
	int n;
	cin >> n;
	
	vector<int> ans;

	if(n % 2 == 0){
		int k = 1;
		while((k<<1) <= n) k <<= 1;
		ans.push_back(k);

		
	}	


	for(int i = 1; i <= n; i++) s.insert(i);
	for(int i : ans) s.erase(i);

	for(auto i = s.rbegin(); i != s.rend(); i++){
		ans.push_back(*i);
		// cout << "> insert: " << *i << endl;
	}

	reverse(ans.begin(), ans.end());

	int k = 0;
	for(int i = 1; i <= n; i++){
		if(i%2){
			k &= ans[i-1];
		}
		else{
			k |= ans[i-1];
		}
		cout << k << " ";
	}
	cout << endl;

	cout << k << endl;
	for(int i : ans) cout << i << " ";
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