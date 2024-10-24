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
	string s;
	long long p;
	cin >> s >> p;

	long long n = (long long)s.size();

	vector<pair<char,long long>> a(n);
	for(long long i = 0; i < n; i++){
		a[i] = {s[i], i};
	}

	sort(a.begin(), a.end());

	vector<char> curs(n, ' ');
	long long cur = (n*n+n)/2;
	long long sz = 1;
	while(cur-sz >= p and sz <= n){
		cur -= sz;
		sz++;
	}

	for(int j = 0; j < sz; j++){
		curs[a[j].se] = a[j].fi;
	}
	
	// cout << "sz: " << sz << endl;
	// cout << "cur: " << cur << endl;
	// for(char i : curs) cout << i;
	// cout << endl;

	for(int j = n-1; j >= 0; j--){
		if(curs[j] == ' ') continue;

		if(cur == p){
			cout << curs[j];
			break;
		}
		cur--;
	}
}

/*

b a d e r

a b d e r
1 0 2 3 4

a ad ade ader bader  

*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}

	cout << endl;

    return 0;

}