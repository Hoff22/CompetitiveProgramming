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

int n, c;
vector<int> p;

bool test(int x){

	

}

void solve(){
	scanf("%d %d", &n, &c);


	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		p.push_back(x);
	}

	sort(p.begin(), p.end());

	int l = 1;
	int r = MAX;

	while(l < r){
		int m = l + (r - l) / 2;


	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}