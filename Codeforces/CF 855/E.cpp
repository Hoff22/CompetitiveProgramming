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
	int n, k;
	cin >> n >> k;

	string a, b;
	cin >> a >> b;

	if(a == b){
		cout << "YES\n";
		return;
	}

	int cnt[26];
	memset(cnt, 0, sizeof(cnt));

	for(int i = 0; i < n; i++){
		cnt[a[i]-'a']++;
	}
	for(int i = 0; i < n; i++){
		cnt[b[i]-'a']--;
	}

	for(int i = 0; i < 26; i++){
		if(cnt[i] != 0){
			cout << "NO\n";
			return;
		}
	}

	for(int i = 0; i < n; i++){
		if(i + k >= n and i - k < 0){
			if(a[i] != b[i]){
				cout << "NO\n";
				return;
			}
		}
	}

	cout << "YES\n";

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

/*
talant

talant

k = 5
abc d efg

abc d efgh
abh d efgc

ach d efgb
agh d efcb
cbh d efag
fbh d ecag
abh d ecfg





atltna



*/