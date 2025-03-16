#include <bits/stdc++.h>

#define N 100
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a;
	vector<int> b;
	int seen[N+1];
	memset(seen, 0 , sizeof(seen));

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		if(seen[x]){
			b.push_back(x);
		}
		else{
			a.push_back(x);
		}

		seen[x]++;
	}

	sort(a.begin(), a.end());

	for(int i = 0; i < b.size(); i++){
		a.push_back(b[i]);
	}

	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}