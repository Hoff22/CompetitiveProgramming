#include<bits/stdc++.h>

#define N 200000
#define INF 0x3f3f3f3f

using namespace std;
struct pessoa{
	int h;
	int w;
	int i;

	bool operator< (const pessoa b) const{
		return h < b.h;
	}
};

pessoa arr[N+1];
int dp[N+1];
int ans[N+1];


int main(){
	
	int t;
	scanf("%d",&t);

	while(t--){

		int n;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++){
			int h, w;

			scanf("%d %d", &h, &w);

			arr[i] = {max(h,w), min(h,w), i};
		}

		sort(arr+1, arr+1+n);

		dp[1] = 1;
		for(int i = 2; i <= n; i++){
			if(arr[i].w < arr[dp[i-1]].w){
				dp[i] = i;
			}
			else{
				dp[i] = dp[i-1];
			}
		}

		ans[arr[1].i] = -1;
		int lastH = -1;
		for(int i = 2; i <= n; i++){

			if(arr[i].h != arr[i-1].h){
				lastH = i-1;
			}
			if(lastH != -1 and arr[dp[lastH]].w < arr[i].w) {
				ans[arr[i].i] = arr[dp[lastH]].i;
			}
			else ans[arr[i].i] = -1;

		}

		for(int i = 1; i <= n; i++){
			printf("%d ", ans[i]);
		}
		printf("\n");

	}
	

	return 0;
}