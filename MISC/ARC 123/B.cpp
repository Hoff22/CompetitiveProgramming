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

int main(){
	
	int n;
	scanf("%d", &n);

	vector<int> a(n);
	vector<int> b(n);
	vector<int> c(n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);
	for(int i = 0; i < n; i++) scanf("%d", &c[i]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
	sort(c.begin(), c.end());

	int i,j,k;
	i = j = k = 0;

	int ans = 0;
	for(; i < n; i++){
		j = upper_bound(b.begin()+j,b.end(), a[i]) - b.begin();
		if(j == n) break;
		k = upper_bound(c.begin()+k,c.end(), b[j]) - c.begin();
		if(k == n) break;
		//printf("%d %d %d\n", a[i], b[j], c[k]);
		ans++;
		j++;
		k++;
	}

	printf("%d\n", ans);

    return 0;

}