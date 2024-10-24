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
	cin >> s;
	int n = s.size();

	map<char,int> cnt;
	for(int i = 0; i < n; i++){
		cnt[s[i]]--;
	}

	set<pair<int,char>> cs;
	for(auto [c, amt] : cnt){
		cs.insert({amt,c});
	}

	char odd = 'a';
	int of = n%2;
	for(auto [amt, c] : cs){
		of -= (-amt)%2;
		if((-amt)%2) odd = c;
	}

	if(of != 0){
		cout << "NO SOLUTION" << endl;
		return;
	}

	string l;
	for(auto [amt, c] : cs){
		for(int i = 0; i < -(amt)/2; i++){
			l.push_back(c);
		}
	}

	string r = l;
	if(n%2) l.push_back(odd);
	reverse(r.begin(), r.end());

	cout << l << r << endl;
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