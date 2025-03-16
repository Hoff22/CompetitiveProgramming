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

	vector<int> x(n);
	vector<int> y(n);
	
	for(int i = 0 ; i < n; i++){
		scanf("%d", &x[i]);
	}
	for(int i = 0 ; i < n; i++){
		scanf("%d", &y[i]);
	}

	vector<int> pos;
	vector<int> neg;


	for(int i = 0; i < n; i++){
		int z =  y[i] - x[i];
		if(z < 0){
			neg.push_back(z);
		}
		else{
			pos.push_back(z);
		}
	}

	sort(pos.begin(), pos.end());
	sort(neg.begin(), neg.end());

	reverse(pos.begin(), pos.end());

	int ans = 0;
	int i;
	int l = 0;
	for(i = 0 ; i < pos.size(); i++){
		int r = neg.size();

		while(l < r){
			int m = (l+r) / 2;

			if(pos[i] + neg[m] >= 0){
				r = m;
			}
			else{
				l = m+1;
			}
		}

		if(r == neg.size()){
			// cringe
			break;
		}
		else{
			ans++;
			l++;
		}
	}

	printf("%d\n", ans + ((int)pos.size() - i) / 2);

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