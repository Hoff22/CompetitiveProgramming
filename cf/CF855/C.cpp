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

	vector<long long> a(n);

	priority_queue<long long> pq;
	for(int i = 0; i < n; i++) pq.push(0);

	long long ans = 0;
	for(int i = 0; i < n; i++){
		cin >> a[i];

		if(a[i] == 0){
			ans += pq.top();
			pq.pop();
		}
		else{
			pq.push(a[i]);
		}
	}

	cout << ans << endl;

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


/*

1 4 5 0 3 3 0 0

0: -
1: 5 4 1
2: 3 3
3: -

5 4 3 3 1
3 2 5 6 1



*/