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

	int arr[N+1];

	for(int i = 0; i < n; i++){
		cin >> arr[i];
	}

	int sumL[N+1];
	int sumR[N+1];

	sumL[0] = arr[0];
	sumR[n-1] = arr[n-1];
	for(int i = 1; i < n; i++){
		sumL[i] = sumL[i-1] + arr[i]; 
		sumR[(n-i-1)] = sumR[(n-i-1)+1] + arr[(n-i-1)]; 
	}

	// for(int i = 0; i < n; i++){
	// 	cout << sumL[i] << " ";
	// }
	// cout << endl;
	// for(int i = 0; i < n; i++){
	// 	cout << sumR[i] << " ";
	// }
	// cout << endl;

	// set<int> s;
	// for(int i = 0; i < n; i++){
	// 	s.insert(sumL[i]);
	// }

	int ans = INT_MAX;
	map<int,int> last;
	for(int i = 0; i < n; i++){
		if(last.count(sumR[i])){
			ans = min(ans, i - last[sumR[i]] - 1);
			last[sumR[i]] = i;
		}
		last[sumL[i]] = i;
	}

	if(ans == INT_MAX){
		printf("0\n");
		return;
	}
	printf("%d\n", n - ans);
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