#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;


int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		int ans;
		int idx[N+1] = {0};
		map<int, int> m;
		scanf("%d", &n);

		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);

			idx[x] = i;
			m[x]++;
		}

		ans = -1;

		for(auto x : m){
			if(x.second == 1){
				ans = idx[x.first];
				break;
			}
		}
		printf("%d\n", ans);

	}

    return 0;

}