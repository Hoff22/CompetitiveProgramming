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
	
	int n;
	scanf("%d", &n);

	int idx = -1;
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);

		if(idx == -1 and c == '1') idx = i;
	}

	if(idx%2) printf("Aoki\n");
	else printf("Takahashi\n");

    return 0;

}