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
	map<int,int> cnt;
	vector<int> a(n);

	for(int i = 0; i < n; i++){
		int x;
		cin >> x;
		cnt[x]++;
		a[i] = x;
	}

	if(cnt[0] <= (n+1)/2){
		cout << 0 << endl;
	}
	else{
		if(n-cnt[0] == cnt[1] and cnt[1] > 0){
			cout << 2 << endl;
		} 
		else{
			cout << 1 << endl;
		}
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