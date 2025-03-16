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

int main(){

	int n, m;
	scanf("%d %d", &n, &m);

	vector<int> a(n);
	vector<int> b(m);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	
	for(int i = 0; i < m; i++){
		scanf("%d", &b[i]);
	}

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());
		
	int ans = INF;
	for(int i = 0; i < n; i++){

		int j = (int)(lower_bound(b.begin(), b.end(), a[i]) - b.begin());

		if(j == m) j--;
		if(j == 0) j++;
		int dif = min(abs(b[j] - a[i]), abs(b[j-1] - a[i]));

		ans = min(ans, dif);
	}

	printf("%d\n", ans);

    return 0;

}