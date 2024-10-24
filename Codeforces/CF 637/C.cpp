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

	vector<int> a(n+1);

	for(int i = 1; i <= n; i++){
		cin >> a[i];
	}

	for(int i = 1; i < n; i++){
		if(a[i+1] - a[i] > 1){
			cout << "No\n";
			return;
		}
	}

	cout << "Yes\n";
}


/*
if 1 is the first number, the permutation must be in order

_ _ _ _ _

1 2 3 4 5
1 1 1 1 1

_ _ 1 _ _

1 2 4 4 5
1 1 0 2 1

_ _ 1 2 _

1 2 5 5 5
1 1 0 0 3

_ _ 1 2 3

1 2 x x x
1 1 0 0 0


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