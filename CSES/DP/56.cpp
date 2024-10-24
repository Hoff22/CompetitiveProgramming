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
 
int DP[M+1];
 
vector<int> digits(int a){
	vector<int> r;
	while(a){
		r.push_back(a%10);
		a /= 10;
	}
	return r;
}
 
int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
 
	int n;
	cin >> n;
 
	//sort(c, c+n);
 
	memset(DP, 0x3f, sizeof(DP));
 
	DP[0] = 0;
 
	for(int i = 1; i <= n; i++){
		for(int d : digits(i)){
			if(i-d < 0) continue;
			DP[i] = min(DP[i-d]+1, DP[i]);
		}
	}
 
	cout << DP[n] << endl;
 
	return 0;
}