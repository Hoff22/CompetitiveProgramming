#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;


map<int, int> cnt;
bool cmp(int a, int b){
	if(cnt[a] == 1 and cnt[b] == 1){
		return (a <= b);
	}
	else if (cnt[a] > cnt[b]){
		return 1;
	}
	else if(cnt[a] < cnt[b]){
		return 0;
	}
	return (a <= b);
}
int main(){
	// 1 5 7
	// 1 9 10 11 20 
	int n;
	scanf("%d", &n);
	vector<int> a(n);

	cnt.clear();

	for(int i = 0; i < n ;i++){
		scanf("%d", &a[i]);
		cnt[a[i]]++;
	}

	sort(a.begin(), a.end(), cmp);

	int mx = 0;
	int mn = INF;

	long long ans = 0;
	for(int i = 0; i < n ; i++){
		mx = max(a[i], mx);
		mn = min(a[i], mn);

		ans += (mx - mn);
	}

	printf("%lld\n", ans);

    return 0;

}// 3 3 3 6 6 1
 // 0 0 0 3 3 5

//	3 3 6 3 6 1
//	0 0 3 3 3 5 

// 1000000000 943872923 889921234 6589 104 69