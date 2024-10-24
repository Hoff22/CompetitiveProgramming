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
	vector<int> a(n);

	for(int i = 0; i < n; i++) cin >> a[i];

	int idx = -1;
	for(int i = 0; i < n; i++){
		int good = 0;
		for(int j = 0; j < n; j++){
			if(i == j) continue;
			if(a[j] % a[i]) good = 1;
		}
		if(good){
			idx = i;
			break;
		}
	}

	if(idx == -1){
		cout << -1 << endl;
		return;
	}

	vector<int> b;
	vector<int> c;

	for(int i = 0; i < n; i++){
		if(a[i] % a[idx] == 0) c.push_back(a[i]);
		else b.push_back(a[i]);
	}

	cout << b.size() << " " << c.size() << endl;
	for(int i : b) cout << i << " ";
	cout << endl;
	for(int i : c) cout << i << " ";
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