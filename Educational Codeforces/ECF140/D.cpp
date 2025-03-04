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

	for(int i  =0; i < n; i++){
		char c;
		scanf(" %c", &c);

		a[i] = (c=='1');
	}

	int l = 1;
	int r = 1;
	int m = 1;

	for(int i = 0; i < n; i++) m *= 2;


	for(int i = 0; i < n; i++){
		if(!a[i]){
			r *= 2;
		}
		else{
			l *= 2;
		}
	} 

	for(int i = l; i <= m-r+1; i++){
		printf("%d ", i);
	}
	printf("\n");
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}