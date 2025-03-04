#include<bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

int main(){

	int t;
	scanf("%d", &t);

	int n, k;
	while(t--){
		scanf("%d%d", &n, &k);

		int h;
		int l, r;
		for(int i = 0; i < n; i++){
			
			scanf("%d", &h);

			if(!i) l = r = h;

			l = max(l - (k - 1), h)

		}
		
	}

	return 0;
}