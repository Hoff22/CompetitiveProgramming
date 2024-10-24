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

vector<long long> f(11);


int main(){
	
	f[1] = 1;
	for(int i = 2; i <= 10; i++){
		f[i] = f[i-1] * i;
	}

	int n;
	scanf("%d", &n);
	
	int cnt = 0;
	while(n > 0){
		n -= *(upper_bound(f.begin(), f.end(), n)-1);
		cnt++;
		//printf("%d\n", n);
	}
	printf("%d\n", cnt);

    return 0;

}