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

int freqA[N+1][2];
int freqB[N+1][2];

void solve(){
	int n;
	scanf("%d", &n);
	vector<int> a(n);
	vector<int> b(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		b[i] = a[i];
		freqA[a[i]][0] = freqA[a[i]][1] = 0; 
		freqB[a[i]][0] = freqB[a[i]][1] = 0; 
	}

	sort(b.begin(), b.end());

	for(int i = 0; i < n; i++){
		freqA[a[i]][i%2]++;
		freqB[b[i]][i%2]++;
	}

	for(int x : a){
		if(freqA[x][0] != freqB[x][0] or freqA[x][1] != freqB[x][1]){
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");

	
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}