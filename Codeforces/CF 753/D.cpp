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

int cntB[N+1];
int cntR[N+1];

void solve(){
	int n;
	scanf("%d", &n);


	vector<int> v(n);

	vector<int> r;
	vector<int> b;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v[i] = x;
	}
	for(int i = 0; i < n; i++){
		char x;
		scanf(" %c", &x);
		if(x == 'R') r.push_back(v[i]);
		else b.push_back(v[i]);
	}
	r.push_back(INF);
	sort(r.begin(), r.end());
	sort(b.begin(), b.end());

	for(int i = 1; i <= n; i++){
		int j = (int)(lower_bound(b.begin(), b.end(), i) - b.begin());
		cntB[i] = b.size() - j;

		j = (int)(upper_bound(r.begin(), r.end(), i) - r.begin());
		cntR[i] = j;
	}
	
	vector<int> left(n+1);

	int cur = 0;
	cntR[n+1] = cntR[n]; 
	for(int i = n; i >= 1; i--){
		if(cntR[i] != cntR[i+1]){
			cur = max(0,cur - (cntR[i+1] - cntR[i]));
		}
		if(cur >= cntR[i]){
			left[i] = 1;
		}
		cur++;
	}

	int uB = 0;
	for(int i = n; i >= 1; i--){
		if(left[i]){
			if(cntB[i] - uB > 0){
				uB++;
			}
			else{
				printf("NO\n");
				return;
			}
		}
	}
	
	printf("YES\n");
}


int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}