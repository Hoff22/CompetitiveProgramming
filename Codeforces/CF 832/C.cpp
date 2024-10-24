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

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> v(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &v[i]);
	}

	v[0] -= 1;

	int mnA = 1;
	int mnB = 0;
	for(int i = 1; i < n; i++){
		if(v[mnA] > v[i]) mnA = i;
	}


	for(int i = 0; i < n; i++){
		if(i == mnA) continue;
		if(v[mnB] > v[i]) mnB = i;
	}



	if(v[mnA] <= v[mnB]){
		printf("Alice\n");
	}
	else{
		printf("Bob\n");
	}

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}