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
	int n, x;
	cin >> n >> x;
	
	map<int,int> m;
	int l = -1;
	int r = -1;
	for(int i = 1; i <= n; i++){
		int a; cin >> a;
		if(m.count(x-a)) l = m[x-a], r = i;
		m[a] = i;
	}

	if(l == -1){
		cout << "IMPOSSIBLE" << endl;
	}
	else{
		cout << l << " " << r << endl;
	}
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