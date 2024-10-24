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

	vector<string> ns = {"0","1"};

	for(int i = 0; i < n-1; i++){
		int k = ns.size();
		for(int j = k-1; j >= 0; j--){
			ns.push_back(ns[j]);
		}
		for(int j = 0; j < k; j++){
			ns[j].push_back('0');
			ns[k+j].push_back('1');
		}
	}

	for(string s : ns) cout << s << endl;
}

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}