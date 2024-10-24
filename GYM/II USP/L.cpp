#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1];

int main(){
	
	int n;
	scanf("%d", &n);

	int ans = 0;
	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
		if(a[i] > a[ans]) ans = i;
	}

	for(int i = 1; i <= n; i++){
		if(i != ans and a[i] == a[ans]){
			printf("-1\n");
			return 0;
		} 
	}

	printf("%d\n", ans);
	

    return 0;

}