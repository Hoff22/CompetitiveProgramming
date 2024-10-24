#include <bits/stdc++.h>

#define N 1000000
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

int a[N+1];
int b[N+1];

void solve(){
	string s;
	cin >> s;

	a[0] = b[0] = 0;
	for(int i = 1; i <= n; i++){
		a[i] = a[i-1];
		b[i] = b[i-1];

		if(s[i-1] == '(' or s[i-1] == ')') a[i]++;
		if(s[i-1] == '[' or s[i-1] == ']') b[i]++;
	}

	int q; 

	cin >> q;

	for(q--){
		int l, r;
		cin >> l >> r;

		int m = (l + r) / 2;
	
		
	}

}

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}