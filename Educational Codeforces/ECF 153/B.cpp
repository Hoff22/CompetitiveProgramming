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
	long long m, k, a, b;
	cin >> m >> k >> a >> b;

	long long usek = min(m/k, b);
	long long useo = min(m - usek*k, a);

	if(usek*k+useo == m){
		cout << 0 << endl;
		return;
	}

	long long mis = m - (usek*k+useo);

	//cout << "mis: " << mis << endl; 

	if(k - (mis%k) <= useo and (mis%k) > 0){
		cout << (mis + (k - (mis%k)))/k << endl;
	}
	else{
		cout << mis/k + (mis%k) << endl;
	}

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