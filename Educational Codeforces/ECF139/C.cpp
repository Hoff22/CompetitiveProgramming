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
	string a, b;
	cin >> n >> a >> b;

	// 1 == a
	// 0 == b;

	int good = 1;

	int cur = 1;
	for(int i = 0; i < n; i++){
		if(cur == 1){ // to no a
			if(a[i] == 'W'){
				good = 0;
				break;
			}
			if(b[i] == 'B'){
				cur = 0;
			}
		}
		else{ // to no b
			if(b[i] == 'W'){
				good = 0;
				break;
			}
			if(a[i] == 'B'){
				cur = 1;
			}
		}
	}

	if(good){
		printf("YES\n");
		return;
	}

	good = 1;

	cur = 0;
	for(int i = 0; i < n; i++){
		if(cur == 1){ // to no a
			if(a[i] == 'W'){
				good = 0;
				break;
			}
			if(b[i] == 'B'){
				cur = 0;
			}
		}
		else{ // to no b
			if(b[i] == 'W'){
				good = 0;
				break;
			}
			if(a[i] == 'B'){
				cur = 1;
			}
		}
	}

	if(good){
		printf("YES\n");
		return;
	}

	printf("NO\n");

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