#include <bits/stdc++.h>

#define N 59
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

string pw2[N+1];

int check(string a, string p){
	int j = 0;
	for(int i = 0; i < a.size(); i++){
		if(a[i] == p[j]){
			j++;
		}
		if(j == p.size()) break;
	}

	return (a.size() - j) + (p.size() - j);
}

void solve(){
	string n;
	cin >> n;

	int ans = INF;
	for(int i = 0; i <= N; i++){
		ans = min(ans, check(n, pw2[i]));
	}

	printf("%d\n", ans);
}

int main(){
	
	int t;
	cin >> t;
	
	long long x = 1;
	pw2[0] = "1";
	for(int i = 1; i <= N; i++){
		x *= 2;
		long long tmp = x;
		while(tmp){
			pw2[i] += '0' + (tmp%10);
			tmp /= 10;
		}
		reverse(pw2[i].begin(), pw2[i].end());
	}

	while(t--){
		solve();
	}
    return 0;

}