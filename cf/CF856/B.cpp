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

	vector<int> a(n);

	for(int i = 0; i < n; i++){
		cin >> a[i];
	}

	if(n == 1){
		cout << a[0] << endl;
		return;
	}

	if(a[0] == 1) a[0]++;

	for(int i = 1; i < n; i++){
		if(a[i] == 1) a[i]++;
		if(a[i] % a[i-1] == 0) a[i]++;
	}

	for(int i = 0; i < n; i++){
		cout << a[i] << " ";
	}
	cout << endl;
}


/*

2 4 3 6

3 4 3 7


1 2 3

2 2 3

2 3 3

2 3 4

*/
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