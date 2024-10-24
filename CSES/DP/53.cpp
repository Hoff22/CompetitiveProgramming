#include <bits/stdc++.h>
 
#define N 100
#define M 1000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first
 
using namespace std;
 
typedef long long ll;
 
int n, x;
int DP[M+1];
int c[N+1];
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	cin >> n >> x;
	for(int i = 0; i < n; i++){
		cin >> c[i];
	}
 
	sort(c, c+n);
 
	memset(DP, 0x3f, sizeof(DP));
 
	DP[0] = 0;
 
	for(int k = 1; k <= x; k++){
		for(int i = 0; i < n and k-c[i] >= 0; i++){
			DP[k] = min(DP[k-c[i]]+1, DP[k]);
		}
	}
 
	if(DP[x] == INF){
		cout << -1 << endl;
	}
	else cout << DP[x] << endl;
 
	return 0;
}