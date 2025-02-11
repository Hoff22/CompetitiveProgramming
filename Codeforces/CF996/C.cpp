#include <bits/stdc++.h>

#define N 1000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

ll a[N+1][N+1];

void solve(){
	int n, m;
	cin >> n >> m;

	string s; cin >> s;

	vector<ll> rows(n+1, 0);
	vector<ll> cols(m+1, 0);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cin >> a[i][j];
			rows[i]+=a[i][j];
			cols[j]+=a[i][j];
		}
	}

	vector<pair<int,int>> p;

	auto ch = [&](int i, int j, ll x){
		a[i][j] += x;
		rows[i] += x;
		cols[j] += x;
	};

	int ci = 0, cj = 0;
	for(int i = 0; i < s.size(); i++){
		char c = s[i];
		if(c == 'D'){ // same col
			ch(ci, cj, -rows[ci]);
			ci++;
		}
		if(c == 'R'){ // same row
			ch(ci, cj, -cols[cj]);
			cj++;
		}
	}
	ch(ci, cj, -rows[ci]);

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
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