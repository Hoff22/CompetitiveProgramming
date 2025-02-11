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

	vector<int> a(n);

	int sum = 0;
	for(int i = 0; i  < n; i++){
		scanf("%d", &a[i]);
		sum += a[i];
	}

	int best = 0;
	int second = 0;
	int worst = 0;
	for(int i = 0; i < n-1; i++){
		if(a[i] == -1 and a[i+1] == -1)best = 1;
		if(a[i] == 1 and a[i+1] == -1)second = 1;
		if(a[i] == -1 and a[i+1] == 1)second = 1;
		if(a[i] == 1 and a[i+1] == 1)worst = 1;
	}

	if(best){
		printf("%d\n",sum + 4);
	}
	else if(second){
		printf("%d\n", sum);
	}
	else if(worst){
		printf("%d\n", sum-4);
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