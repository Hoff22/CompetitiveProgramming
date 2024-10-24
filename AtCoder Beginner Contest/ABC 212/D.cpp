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
	
	int q;
	scanf("%d", &q);

	priority_queue<long long> pq;

	long long off = 0;
	for(int i = 0; i < q; i++){
		int op;
		scanf("%d", &op);

		if(op == 1){
			int x;
			scanf("%d", &x);
			pq.push(-(x-off));
		}
		else if(op == 2){
			int x;
			scanf("%d", &x);
			off += x;
		}
		else{
			printf("%lld\n", - pq.top() + off);
			pq.pop();
		}
	}

    return 0;

}