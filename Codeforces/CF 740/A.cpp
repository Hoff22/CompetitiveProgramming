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

	vector<int> a(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	vector<int> b = a;
	sort(b.begin(), b.end());

	int i = 0;
	while(a != b){
		for(int j = 0; j < n-1; j++){
			if(j%2 == i%2 and a[j] > a[j+1]){
				swap(a[j], a[j+1]);
			}
		}
		i++;
	}

	printf("%d\n", i);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}