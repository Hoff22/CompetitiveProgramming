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
#define r first
#define c second

using namespace std;

void solve(){
	
	int n;
	vector<pair<int,int>> a;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		a.push_back({x,0});
	}
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		a[i].c = x;
	}

	sort(a.begin(), a.end());

	pair<int,int> cur = {1,1};

	int dist = 0;
	for(int i = 0; i < n; i++){
		pair<int,int> next = a[i];

		if((next.r - next.c)%2 == (cur.r - cur.c)%2){
			if((next.r - next.c)%2 == 0 and (next.r - next.c) == (cur.r - cur.c)) dist += next.r - cur.r;
			else dist += ((next.r - next.c) - (cur.r - cur.c)) / 2;
		}
		else{
			if((cur.r - cur.c)%2){
				dist += 1;
			}

			dist += ((next.r - next.c) - (cur.r - cur.c)) / 2;
		}
		
		cur = next;
	}

	printf("%d\n", dist);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}