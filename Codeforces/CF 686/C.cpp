#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;
int a[N];
int last[N+1];
int cuts[N+1];

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		int ans;
		int n;
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			int x;
			scanf("%d", &x);
			a[i] = x;
			last[a[i]] = -1;
			cuts[a[i]] = 0;
		}

		for(int i = 0; i < n; i++){
			if(i - last[a[i]] > 1){
				cuts[a[i]]++;
			}
			last[a[i]] = i;
		}

		ans = INF;
		for(int i = 0; i < n; i++){
			ans = min(ans, cuts[a[i]] + (a[i] != a[n-1]));
		}

		printf("%d\n", ans);
	}

    return 0;

}