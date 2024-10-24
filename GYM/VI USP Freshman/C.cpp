#include <bits/stdc++.h>

#define N 100
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int q, n;
int m[130];

int check(int mask, vector<int> d){

	int cur = 0;
	int i = 0;
	int bit = 1;
	while(mask > 0){
		if(mask & 1){
			//printf("\t%d, %d, %d\n", mask,bit,  m[bit]);

			int x = m[bit];
			//printf("\t%d %d %d\n",i,mask, x);
			if(x == 0){
				if(d[0] == 0) return 0;
				else d[0]--;
			}
			while(x){

				if(d[x%10] == 0) return 0;
				else d[x%10]--;

				x/=10;
			}
			cur++;
		}
		bit <<= 1;
		mask >>= 1;
		i++;
	}

	return cur;
}
// k o b u s
int main(){
	
	scanf("%d %d", &q, &n);

	for(int i = 0; i < q; i++){
		int x;
		scanf("%d", &x);
		m[(1<<i)] = x; 
	}

	vector<int> a(10);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a[x]++;
	}

	int best = 0;
	int ans = 0;
	for(int mask = 1; mask <= (1<<q)-1; mask++){
		vector<int> d(10);
		d = a;
		
		//printf("%d\n", mask);
		int cur = check(mask, d);
		if(cur > ans){
			ans = cur;
			best = mask; 
			//printf("%d %d\n", ans, mask);
		}
	}

	printf("%d\n", ans);
	if(ans){
		int j = 0;
		while(best){
			if(best&1)printf("%d ", m[(1<<j)]);
			best >>= 1;
			j++;
		}
		printf("\n");
	}

	return 0;
}