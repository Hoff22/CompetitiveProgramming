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

vector<pair<int,int>> s;
int gapL(int i){
	if(i == 0 or i == s.size()-1){
		return (s[i].second - s[i].first - 1);
	}
	return (s[i].second - s[i].first) / 2;
}

void solve(int q){
	int n, k;
	scanf("%d %d", &n, &k);

	vector<int> a(n);
	s.clear();

	for(int i = 0; i < n; i++){
		scanf("%d", &a[i]);
	}
	sort(a.begin(), a.end());

	int last = 0;
	for(int i = 0; i < n; i++){
		s.push_back({last, a[i]});
		last = a[i];
	}
	s.push_back({last, k+1});


	int ans = 0;
	for(int i = 0; i < s.size(); i++){
		for(int j = 0; j < s.size(); j++){
			if(i == j){
				ans = max(ans, (s[i].second - s[i].first - 1));
			}
			else{
				ans = max(ans, gapL(i)+gapL(j));
			}
		}
	}

	printf("Case #%d: %lf\n",q, 1.0*ans/k);
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for (int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}