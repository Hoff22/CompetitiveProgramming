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

vector<int> precalcMasks[12][11];

void solve(){
	int n, mx;
	cin >> n >> mx;

	string a, b;
	cin >> a >> b;

	// cout << a << endl << b << endl;
		
	vector<char> c;
	vector<int> map(26,-1);
	for(int i = 0; i < n; i++){
		if(map[a[i]-'a'] == -1 and a[i] != b[i]){
			c.push_back(a[i]);
			if(map[a[i]-'a'] == -1) map[a[i]-'a'] = c.size()-1;
		}
	}

	if(c.size() <= mx){
		long long best = 0;
		for(int i = 0; i < n; i++){
			best += i+1;
		}
		cout << best << endl;
		return;
	}

	long long best = 0;
	long long cur = 1;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]){
			best += cur;
			cur++;
		}
		else{
			cur = 1;
		}
	}

	for(int m : precalcMasks[(int)c.size()][mx]){

		long long ans = 0;
		cur = 1;
		for(int i = 0; i < n; i++){
			if(a[i] == b[i] or (map[a[i]-'a'] != -1 and (m>>map[a[i]-'a']) & 1)){
				ans += cur;
				cur++;
			}
			else{
				cur = 1;
			}
		}

		best = max(ans, best);
	}


	cout << best << endl;

	// cout << a << endl << b << endl;
}

/*

u j o n
        1 : 4
        2 : 3
        3 : 2
        4 : 1
	
*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int s = 0; s <= 11; s++){
		for(int m = 1; m < (1<<s); m++){
			precalcMasks[s][__builtin_popcount(m)].push_back(m);
		}
	}

	while(t--){
		solve();
	}
    return 0;

}