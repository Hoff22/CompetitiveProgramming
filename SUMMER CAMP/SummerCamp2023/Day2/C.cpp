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

map<long long, long long> cnt;

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

	int n;
	scanf("%d", &n);

	vector<long long> s(n);
	for(int i = 0; i < n; i++){
		scanf("%lld", &s[i]);
	}

	for(int f = 0; f < n; f++){
		for(int e = 0; e < n; e++){
			for(int d = 0; d < n; d++){
				if(s[d] == 0) continue;
				cnt[(s[f] + s[e]) * s[d]]++;
			}
		}
	}

	long long ans = 0;

	for(int a = 0; a < n; a++){
		for(int b = 0; b < n; b++){
			for(int c = 0; c < n; c++){
				ans += cnt[s[a] * s[b] + s[c]];
			}
		}
	}
	printf("%lld\n", ans);

    return 0;

}