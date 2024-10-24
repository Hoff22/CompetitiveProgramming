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

	map<int,int> cnt;

	vector<int> a(n+1);
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}


	int cur = 0;
	int ans = 0;

	int last = 0;

	for(auto i : cnt){
		int x = i.fi;
		int qnt = i.se;

		if(x - 1 == last){
			if(qnt >= cur){
				ans += (qnt-cur);
			}
			cur = qnt;
		}
		else{
			ans += qnt;
			cur = qnt;
		}

		last = x;
	}

	//ans += cur;

	printf("%d\n", ans);

}

/*


2 2 3 4 4

2:2 3:1 4:2



1 2 2 3 3 4

       2 2 3 4 4
cur    1 2 1 
reps   0 0 2



2 2 2 2 2 2


1 2     3     4

    2 2   3 3 

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