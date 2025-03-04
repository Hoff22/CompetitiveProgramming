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
	set<int> x;
	set<int> y;

	for(int i = 0; i < 3; i++){
		int a, b;
		scanf(" %d %d", &a, &b);
		x.insert(a);
		y.insert(b);
	}

	if(x.size() + y.size() <= 4){
		printf("NO\n");
	}
	else{
		printf("YES\n");
	}

}

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