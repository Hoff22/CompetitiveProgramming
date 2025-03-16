#include<bits/stdc++.h>

#define N 100
#define INF 0x3f3f3f3f

using namespace std;

int n;

int main(){
		
	int t;
	scanf("%d",&t);

	while(t--){
		int ones, twos;
		int a, b;
		int candy;
		scanf("%d", &n);

		ones = twos = 0;
		a = b = 0;

		for(int i = 0; i < n; i++){
			scanf("%d", &candy);
			if(candy == 1) ones++;
			else twos++;
		}

		for(int i = 0; i < twos; i++){
			if(a <= b) a += 2;
			else b += 2;
		}

		for(int i = 0; i < ones; i++){
			if(a <= b) a += 1;
			else b += 1;
		}

		if(a == b){
			printf("YES\n");
		}
		else printf("NO\n");
	}

	return 0;
}