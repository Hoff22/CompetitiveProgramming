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

	map<char, int> cntF;
	map<char, int> cntS;
	map<pair<char,char>, int> cnt;

	long long ans = 0;
	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		// ans += n - (cntF[s[0]] + cntS[s[1]]); // todo mundo que tem total diferente
		// ans += cnt[{s[0], s[1]}]; // todo mundo que tem total igual
		ans += (cntF[s[0]] + cntS[s[1]]) - cnt[{s[0], s[1]}]*2;
		cntF[s[0]]++;
		cntS[s[1]]++;
		cnt[{s[0], s[1]}]++;
	}

	printf("%lld\n", ans);
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