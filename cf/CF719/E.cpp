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


void solve(){
	int n;
	scanf("%d", &n);

	vector<int> pos;
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		if(c == '*')pos.push_back(i);
	}

	if(pos.size()== 0){
		printf("0\n");
		return;
	}

	int mid = (pos.size()-1)/2;
	int l = pos[mid];
	int r = pos[mid];

	long long ans = 0;
	//printf("m: %d\n", mid);
	for(int i = mid; i < pos.size(); i++){
		ans += pos[i] - r;
		r++;
	}
	for(int i = mid; i >= 0; i--){
		ans += l - pos[i];
		l--;
	}

	printf("%lld\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}