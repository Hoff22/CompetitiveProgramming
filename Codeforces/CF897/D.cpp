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

/*

2 3 5 3 4

1,2,3,5,4,!





*/

void solve(){
	int n, k;
	cin >> n >> k;

	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	vector<int> s(n+1, 0);
	vector<int> good(n+1, 0);

	for(int i = 1; i <= n; i++){
		if((a[i] == i and k!=1) or (k==1 and a[i] != i)){
			cout << "NO" << endl;
			return;
		}

		if(s[i]) continue;
 
		int cur,cnt,f;
		cur = f = i;
		cnt = 1;
		while(!s[cur]){
			s[cur] = cnt;
			cur = a[cur];
			cnt++;
		}	
 
		if((cnt-s[cur])!=k and !good[cur]){
			cout << "NO" << endl;
			return;
		}
		cur = f;
		while(!good[cur]){
			good[cur] = 1;
			cur = a[cur];
		}
	}

	cout << "YES" << endl;
}
// 223413237
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