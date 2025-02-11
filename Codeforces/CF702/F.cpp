#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

map<int,int> cnt;
int a[N];

int check(int c){
	int ans = 0;
	for(auto i : cnt){
		if(i.second < c) ans += i.second;
		else ans += i.second - c;
	}
	return ans;
}

void solve(){
	int n;
	scanf("%d", &n);

	cnt.clear();

	int r = 0;
	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
		r = max(r, cnt[a[i]]);
	}

	int l = 0;
	//printf("r:%d\n", r);
	int c1;
	int c2;

	while(l < r){
		c1 = (l+r) / 2;
		c2 = c1+1;

		//printf("%d %d\n", c1, c2);
		if(check(c1) >= check(c2)){
			l = c1+1;
		}
		else{
			r = c2-1;
		}
	}

	int ans = 0;
	for(auto i : cnt){
		if(i.second < l) ans += i.second;
		else ans += i.second - l;
	}
	printf("%d\n", ans);
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}