#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	int n;
	cin >> n;
	map<int,int> fa, fb;
	for(int i = 0; i < n; i++){
		int x;cin >> x;
		fa[x]++;
	}
	for(int i = 0; i < n; i++){
		int x;cin >> x;
		fb[x]++;
	}

	if(fa.size() > 1 and fb.size() > 1){
		cout << "YES" << endl;
	}
	else{
		if(fa.size() > 2 or fb.size() > 2){
			cout << "YES" << endl;
		}
		else{
			cout << "NO" << endl;
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