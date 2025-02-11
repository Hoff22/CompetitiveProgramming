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

int a[2][2];

bool test(){
	return (a[0][0] < a[0][1] and a[1][0] < a[1][1] and a[0][0] < a[1][0] and a[0][1] < a[1][1]);
}

void solve(){

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			scanf("%d", &a[i][j]);
		}
	}

	int temp;

	if(test()){
		printf("YES\n");
		return;
	}

	temp = a[0][0];
	a[0][0] = a[1][0];
	a[1][0] = a[1][1];
	a[1][1] = a[0][1];
	a[0][1] = temp;

	if(test()){
		printf("YES\n");
		return;
	}

	temp = a[0][0];
	a[0][0] = a[1][0];
	a[1][0] = a[1][1];
	a[1][1] = a[0][1];
	a[0][1] = temp;
	if(test()){
		printf("YES\n");
		return;
	}

	temp = a[0][0];
	a[0][0] = a[1][0];
	a[1][0] = a[1][1];
	a[1][1] = a[0][1];
	a[0][1] = temp;
	if(test()){
		printf("YES\n");
		return;
	}

	temp = a[0][0];
	a[0][0] = a[1][0];
	a[1][0] = a[1][1];
	a[1][1] = a[0][1];
	a[0][1] = temp;

	if(test()){
		printf("YES\n");
		return;
	}

	printf("NO\n");
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