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

	vector<int> b(n);
	for(int i = 0; i < n; i++){
		scanf("%d", &b[i]);
	}

	sort(b.begin(), b.end());
	reverse(b.begin(), b.end());
	
	vector<int> a;
	int j = n-1;
	for(int i = 0; i <= j; i++){
		a.push_back(b[i]);
		if(i!=j)a.push_back(b[j]);
		j--;
	}

	long long sum = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == sum){
			printf("NO\n");
			return;
		}
		sum += a[i];
	}
	printf("YES\n");
	for(int i  =0; i < n; i++){
		printf("%d%c", a[i], " \n"[(i==n-1)]);
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