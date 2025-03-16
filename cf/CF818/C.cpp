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

	vector<int> a(n),b(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	for(int i = 0; i < n; i++){
		if(a[i] == b[i]) continue;
		if(a[i] > b[i]){
			printf("no\n");
			return;
		}
		if(b[i] > b[(i+1)%n]+1){
			printf("no\n");
			return;
		}
	}
	printf("yes\n");
}

/*

  1 2 3 4 5
  5 9 8 7 6
  1 2 3 4 5
  1 2 3 4 5
  5 9 8 7 6



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