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
	vector<int> code(26);
	for(int i = 0; i < 26; i++){
		cin >> code[i];
	}

	cin >> n;

	bool good = 1;

	set<long long> s;
	for(int i = 0; i < n; i++){
		string str;
		cin >> str;

		long long cur = 0;
		long long p = 1;
		for(int j = 0; j < str.size(); j++){
			cur += p * (code[str[j] - 'A']);
			p *= 10;
		}

		if(s.count(cur)){
			good = 0;
		}

		s.insert(cur);
	}

	if(!good){
		cout << "YES\n";
	}
	else{
		cout << "NO\n";
	}

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	for(int i = 1; i <= t; i++){
		cout << "Case #" << i << ": ";
		solve();
	}
    return 0;

}