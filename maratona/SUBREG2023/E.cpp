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

int t(int n){
	int cur = 0;
	while(n){
		cur += n%10;
		n/=10;
	}
	return cur;
}

void solve(){
	int n, k;
	cin >> n >> k;

	vector<int> freq(1000000,0);

	for(int i = 0; i < n; i++){
		int x; cin >> x;
		freq[x]++;
	}

	for(int i = 1000000; i >= 0; i--){
		if(!freq[i]) continue;

		if(k <= freq[i]){
			cout << t(i) << endl;
			return;
		}

		k -= freq[i];
		freq[i-t(i)] += freq[i];
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}