#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N];

// int test(int l, int r){
// 	if(min(l, r) * 2 >= max(l, r)){
// 		return 0;
// 	}
// 	int x = (l + r) / 2;

// 	return 1 + test(l, x) + test(x, r);
// }
// // 
void solve(){
	int n;
	scanf("%d", &n);

	int ans = 0;

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	for(int i = 0; i < n-1; i++){
		int l = min(a[i], a[i+1]);
		int r = max(a[i], a[i+1]);

		while(l * 2 < r){
			l *= 2;
			ans++;
		}
		//ans += test(l, r);
	}

	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}