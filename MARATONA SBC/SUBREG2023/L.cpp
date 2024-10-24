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
	int k;
	cin >> s >> k;

	vector<multiset<char>> p(k);
	for(int i = 0; i < s.size(); i++){
		p[i%k].insert(s[i]);
	}

	for(int i = 0; i < s.size(); i++){
		if(p[i%k].empty()) continue;
		char c = *p[i%k].begin();
		cout << c;
		p[i%k].erase(p[i%k].lower_bound(c));
	}

	cout << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}