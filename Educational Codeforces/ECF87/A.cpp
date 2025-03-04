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

	vector<int> pr(n+1);

	for(int i = 2; i <= n; i++){
		if(pr[i] == 0){
			printf("%d\n", i);
		}
		int j = i * i;
		if(j <= n){
			while(j <= n){
				pr[j] = 1;
				j += i;
			}
		}
	}
    return 0;

}