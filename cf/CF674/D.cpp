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

map<long long,int> m;

int main(){
	
	int n;
	scanf("%d", &n);

	int ans = 0;
	long long sum = 0;
	
	m[0] = -1;

	int ls = -1;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		sum += x;

		if(m.count(sum)){
			if(ls <= m[sum]+1){
				ls = i;
				ans++;
			}
		}
		
		m[sum] = i;
	}

	printf("%d\n", ans);
    return 0;

}