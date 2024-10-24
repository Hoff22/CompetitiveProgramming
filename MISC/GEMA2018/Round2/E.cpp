#include <bits/stdc++.h>

#define N 100000
#define MAX 100000000
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n, k;
int a[N];

int checker(int x){
	int cur = 0;
	for(int i = 0; i < k-1; i++){

		int l, r;
		int mid;
		l = cur;
		r = n-1;

		while(l < r){
			mid = (l + r + 1) / 2;

			if(a[mid] - a[cur] <= x){
				l = mid;
			}
			else{
				r = mid - 1;
			}
		}

		cur = l;
	}

	return (a[n-1] - a[cur] <= x);
}

int main(){
	
	scanf("%d %d", &n, &k);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int l, r;
	int mid;

	l = 0;
	r = MAX;

	while(l < r){
		mid = (l + r) / 2;

		if(checker(mid)){
			r = mid;
		}
		else{
			l = mid + 1;
		}
	}

	printf("%d\n", l);
	
	return 0;
}