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

	multiset<int> s;
	for(int k = 1; k <= n; k++){
		s.insert(a[k]);

		while(*(s.begin()) < s.size()){
			s.erase(s.lower_bound(*(s.begin())));
		}

		cout << s.size() << " ";
	}
	cout << endl;
}

/*
1 * 3 / 1*2 = 1.5

2      5      7       12       13

2 * 5 * 7 * 12 * 13 / 5! = 91
5 * 7 * 12 * 13 / 4!     = 227.5
7 * 12 * 13 / 3!         = 182
12 * 13 / 2!             = 78
13 / 1!                  = 13


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