#include<bits/stdc++.h>

#define N 100
#define INF 0x3f3f3f3f

using namespace std;

int w, h, n;

int solve(int w, int h){
	int count = 1;
	while(!(h%2) or !(w%2)){

		if(!(h%2)){
			count *= 2;
			h /= 2;
		}
		if(!(w%2)){
			count *= 2;
			w /= 2;
		}
	}

	return count;
}

int main(){
	
	int t;
	scanf("%d",&t);

	while(t--){
		scanf("%d %d %d", &w, &h, &n);

		if(solve(w, h) >= n){
			printf("YES\n");
		}
		else printf("NO\n");

	}
	

	return 0;
}