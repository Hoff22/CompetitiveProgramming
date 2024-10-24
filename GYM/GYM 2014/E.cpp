#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int main(){
	
	int n, r;
	scanf("%d %d", &n, &r);

	vector<int> a(r+1);
	for(int i = 1; i <= r; i++){
		scanf("%d", &a[i]);
	}

	if(n == r){
		printf("*\n");
		return 0;
	}

	sort(a.begin(), a.end());

	int j = 1;
	for(int i = 1; i <= n; i++){
		if(a[j] == i) j++;
		else printf("%d ", i);
	}

	printf("\n");
	
    return 0;

}