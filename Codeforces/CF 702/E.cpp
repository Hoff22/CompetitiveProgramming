#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int a[N+1];
vector<int> b;
vector<long long> sums;
map<int, int> cnt;
map<int, int> win;
int n;


void solve(){
	int ans = 0;
	scanf("%d", &n);

	b.clear();
	sums.clear();
	cnt.clear();
	win.clear();

	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d", &x);
		a[i] = x;
		if(!cnt[x]) b.push_back(x); 
		cnt[x]++;
	}

	sort(b.begin(), b.end());

	long long sum = 0;
	for(int i = 0; i < b.size(); i++){
		sum += b[i] * 1ll * cnt[b[i]];
		sums.push_back(sum);
	}



	//int acc = 0;
	for(int i = 0; i < b.size(); i++){
		int cur = i;

		while(cur < b.size() - 1){
			int l = i;
			int r = b.size() - 1;
			int m = 0;
			while(l < r){
				m = (l + r + 1) / 2;

				if(sums[cur] < b[m]){
					r = m - 1;
				}
				else{
					l = m;
				}
			}

			if(cur == l){
				break;
			}
			cur = l;
		}

		if(cur == b.size() - 1){
			win[b[i]]++;
			ans += cnt[b[i]];
		}
	}
	printf("%d\n", ans);

	for(int i = 1; i <= n; i++){
		if(win[a[i]]) printf("%d ", i);
	}

	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		solve();
	}
	

    return 0;

}