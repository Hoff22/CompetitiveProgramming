#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N];

void solve(int q){
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	int sum = 0;
	for(int i = 0; i < n; i++){
		int mn = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[mn]) mn = j;
		}

		sum += mn - i + 1;
		reverse((a+i), (a+mn+1));
	}
	printf("Case #%d: %d\n", q, sum-1);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}