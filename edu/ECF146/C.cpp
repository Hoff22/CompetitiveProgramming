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
	int n, a, b;
	cin >> n >> a >> b;

	vector<pair<long long,int>> v(n);

	for(int i = 0; i < n; i++){
		cin >> v[i].fi;
		v[i].se = i+1;
	}

	sort(v.begin(), v.end());
	reverse(v.begin(), v.end());

	vector<int> a_ans;
	vector<int> b_ans;

	long long pa = 1;
	long long pb = 1;
	for(int i = 0; i < n; i++){
		if(pa * v[i].fi * a < pb * v[i].fi * b){
			a_ans.push_back(v[i].se);
			pa++;
		}
		else{
			b_ans.push_back(v[i].se);
			pb++;
		}
	}

	cout << a_ans.size() << " ";
	for(int i : a_ans) cout << i << " ";
	cout << endl
;
	cout << b_ans.size() << " ";
	for(int i : b_ans) cout << i << " ";
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