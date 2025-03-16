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

int main(){
	
	vector<int> a(3);
	scanf("%d%d%d", &a[0], &a[1], &a[2]);

	do{
		if(a[0] - a[1] == a[1] - a[2]){
			printf("Yes\n");
			return 0;
		}
	}while(next_permutation(a.begin(), a.end()));

	printf("No\n");

    return 0;

}