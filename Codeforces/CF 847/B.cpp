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
	int n, r, s;
	scanf("%d %d %d" , &n, &s, &r);

	int sum = (s-r);
	vector<int> a(n, 1);
	a[0] = (s-r);
	sum += n-1;

	while(sum != s){
		for(int i = 0; i < a.size(); i++){
			if(a[i] < (s-r)){
				a[i]++;
				sum++;
				break;
			}
		}
	}

	for(int i : a){
		printf("%d ", i);
	}
	printf("\n");

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