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
	scanf("%d", &n);

	vector<int> a(n+1);

	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	int lastOdd = -1;
	int lastEven = -1;
	for(int i = 1; i <= n; i++){
		if(a[i] % 2) lastOdd = i;
		if(a[i] % 2 == 0) lastEven = i;
	}

	vector<pair<int,int>> ans;

	if(a[1] % 2){

		for(int i = lastOdd-1; i >= 1; i--){
			if(a[i] % 2){
				ans.push_back({i, lastOdd});
			}
		}

		for(int i = 2; i <= n; i++){
			if(a[i] % 2 == 0){
				ans.push_back({1, i});
			}
		}

	}
	else{
		for(int i = lastEven-1; i >= 1; i--){
			if(a[i] % 2 == 0){
				ans.push_back({i, lastEven});
			}
		}

		for(int i = 2; i <= n; i++){
			if(a[i] % 2){
				ans.push_back({1, i});
			}
		}
	}

	printf("%d\n", (int)ans.size());
	for(auto i : ans){
		printf("%d %d\n", i.fi, i.se);
	}
}

/*
pP = PP 
pi = pp 
iI = II
Ip = II

1 1000 3 0 5

1 1 3 0 5
3 1 3 0 5
3 1 3 3 5
5 1 3 3 5

2 4 9 5
2 4 5 5



*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}