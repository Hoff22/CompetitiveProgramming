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

	set<int> s;
	vector<int> ans;

	bool good = 1;

	int last = -1;
	for(int i = 0; i < n; i++){
		int x;
		cin >> x;

		if(last != x){
			if(s.count(x)) good = 0;
			s.insert(x);

			ans.push_back(x);
			last = x;
		}
	}

	if(good){
		for(int i : ans){
			cout << i << " ";
		}
		cout << endl;
	}
	else{
		cout << "IMPOSSIBLE" << endl;
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;

}