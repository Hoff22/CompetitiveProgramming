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
	vector<int> p(n+1);
	vector<int> a(n+1);
	for(int i = 1; i <= n; i++) scanf("%d", &a[i]);

	int ans = n/2;
	int idxL = 0;
	int idxR = 0;
	
	if(n%2){
		for(int i = 1; i <= n; i++){
			if(a[i] == (n+1)/2) idxL = i;
			if(a[i] == (n+1)/2) idxR = i;
		}
	}
	else{
		for(int i = 1; i <= n; i++){
			if(a[i] == n/2  ) idxL = i;
			if(a[i] == n/2+1) idxR = i;
		}	
	}

	int l = 0;
	int r = 0;
	
	if(n%2){
		l = (n+1)/2;
		r = (n+1)/2;
	}
	else{
		l = n/2;
		r = n/2 + 1;
	}

	if(idxL > idxR){
		printf("%d\n", ans);
		return;
	}

	for(;l >= 1 or r <= n;){

		while(idxR <= n and a[idxR] != r) idxR++;
		while(idxL >= 1 and a[idxL] != l) idxL--;

		if(idxL >= 1 and idxR <= n and a[idxR] == r and a[idxL] == l) ans -= (r!=l);
		else{
			break;
		}

		l--;
		r++;
	}

	//printf("%d %d\n", l, r);

	printf("%d\n", ans);
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