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

	vector<int> a;

	int d = 9;
	int sum = 0;
	while(sum != n){
		if(n-sum < d){
			a.push_back(n-sum);
			break;
		}
		else{
			sum += d;
			a.push_back(d);
		}
		d--;
	}

	reverse(a.begin(),a.end());
	for(int i = 0; i < a.size(); i++) printf("%d", a[i]);
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