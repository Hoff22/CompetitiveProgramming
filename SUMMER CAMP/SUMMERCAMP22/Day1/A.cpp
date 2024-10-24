#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = n+1; i <= 10000; i++){
		int d[10] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};

		int a = i;
		int good = 1;
		while(a){
			if(d[a%10]) good = 0;
			d[a%10] = 1;
			a /= 10;
		}

		if(good){
			printf("%d\n", i);
			break;
		}
	}

    return 0;

}