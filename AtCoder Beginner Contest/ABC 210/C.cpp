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
	
	int n, k;
	scanf("%d %d", &n,  &k);

	vector<int> a(n);

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}

	map<int,int> freq;
	int cur = 0;
	int ans = 0;
	for(int i = 0; i < k; i++){
		freq[a[i]]++;
		if(freq[a[i]] == 1) cur++;
	}

	ans = cur;
	int i = 0;
	for(int j = k; j < n; j++){
		// add
		freq[a[j]]++;
		if(freq[a[j]] == 1) cur++;
		// remove
		freq[a[i]]--;
		if(freq[a[i]] == 0) cur--;
		i++;
		ans = max(ans, cur);
	}

	printf("%d\n", ans);

    return 0;

}