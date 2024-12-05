#include <bits/stdc++.h>

#define N 200000
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define se second
#define fi first

typedef long long ll;
typedef unsigned long long ull;

using namespace std;

void solve(){
	int n;
	cin >> n;

	if(n%2 and n <= 25){
		cout << -1 << endl;
		return;
	}

	if(n%2 == 0){
		for(int i = 1; i <= n; i+=2){
			cout << i << " " << i << " ";
		}
		cout << endl;
	}
	else{
		int c = 1;
		vector<int> a(n,0);
		a[0] = a[9] = a[25] = c++;

		int i;
		for(i = 1; i < 9; i+=2){
			a[i] = a[i+1] = c++;
		}
		
		a[10] = a[26] = c++;

		for(i = 11; i < 25; i+=2){
			a[i] = a[i+1] = c++;
		}
		
		for(i = 27; i < n; i+=2){
			a[i] = a[i+1] = c++;
		}
		for(int j : a) cout << j << " ";
		cout << endl;
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