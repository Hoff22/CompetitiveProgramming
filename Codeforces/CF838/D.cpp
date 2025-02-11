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

	vector<int> ga(n+1);
	vector<int> gb(n+1);

	if(n == 2){
		printf("! 1 2\n");
		fflush(stdout);

		int ans;
		scanf("%d", &ans);

		if(ans == -1){
			exit(0);
		}
		else{
			return;
		}
	}

	bool difOneL = 0;
	bool difOneR = 0;
	int l;
	int r = n;
	int m = (n+1)/2;
	for(l = 2; l <= (n+1)/2; l++){
		printf("? 1 %d\n", l);
		fflush(stdout);

		scanf("%d", &ga[l]);
		if(ga[l] != 1){
			difOneL = 1;
		}
		else{
			r = l;
		}
		if(ga[l] == -1){
			exit(0);
		}
	}

	for(int k = n; k >= (n+1)/2; k--){
		if(k == r) continue;

		printf("? %d %d\n", r, k);
		fflush(stdout);

		scanf("%d", &gb[k]);
		if(gb[k] != 1){
			difOneR = 1;
		}
		else{
			m = k;
		}
		if(gb[k] == -1){
			exit(0);
		}
	}

	// for(int i : ga){
	// 	printf("%d ", i);
	// }
	// printf("\n");
	// for(int i : gb){
	// 	printf("%d ", i);
	// }
	// printf("\n");

	for(int i = 2; i <= n; i++){
		if(i == m) continue;
		if(i == r) continue;

		printf("? %d %d\n", m, i);
		fflush(stdout);
		int a;
		scanf("%d", &a);

		if(i < (n+1)/2){
			if(ga[i] > 1 and a > 1){
				printf("! %d %d\n", m, i);

				fflush(stdout);

				int ans;
				scanf("%d", &ans);

				if(ans == -1){
					exit(0);
				}
				else{
					return;
				}
			}
		}
		else if(i > (n+1)/2){
			if(gb[i] > 1 and a > 1){
				printf("! %d %d\n", m, i);

				fflush(stdout);

				int ans;
				scanf("%d", &ans);

				if(ans == -1){
					exit(0);
				}
				else{
					return;
				}
			}
		}
	}

	printf("! %d 1\n", (n+1)/2);

	fflush(stdout);

	int ans;
	scanf("%d", &ans);

	if(ans == -1){
		exit(0);
	}
	else{
		return;
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