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

int sim(int la, int lb, int turn, vector<int> &a, vector<int> &b){
	if(turn % 2){
		int r = 1;
		for(int i = max(lb,0); i < b.size(); i++){
			if(la == -1 or a[la] < b[i]){
				r = min(r, sim(la+1, i, turn+1, a, b));
			}
		}
		return r;
	}
	else{
		int r = 0;
		for(int i = max(la,0); i < a.size(); i++){
			if(lb == -1 or a[i] > b[lb]){
				r = max(r, sim(i, lb+1, turn+1, a, b));
			}
		}
		return r;
	}
}

void solve(){
	int n, m;
	scanf("%d", &n);

	vector<int> a(n);
	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	
	scanf("%d", &m);

	vector<int> b(m);
	for(int i = 0; i < m; i++) scanf("%d", &b[i]);

	sort(a.begin(), a.end());
	sort(b.begin(), b.end());

	if(sim(-1,-1,0,a,b)) printf("Alice\n");
	else printf("Bob\n");
	if(sim(-1,-1,1,a,b)) printf("Alice\n");
	else printf("Bob\n");
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