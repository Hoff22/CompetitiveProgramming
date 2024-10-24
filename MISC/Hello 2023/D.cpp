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

	vector<int> a(n);
	vector<int> b(n);

	for(int i = 0; i < n; i++) scanf("%d", &a[i]);
	for(int i = 0; i < n; i++) scanf("%d", &b[i]);

	int m;
	scanf("%d", &m);

	vector<int> x(m);

	for(int i = 0; i < m; i++) scanf("%d", &x[i]);

	for(int i = 0; i < n; i++){
		if(a[i] < b[i]){
			printf("NO\n");
			return;
		}
	}

	map<int,int> cnt;
	stack<int> s;
	vector<int> p(n, 0);

	for(int i = 0; i < n; i++){

		int good = 0;

		while(!s.empty()){
			int y = s.top();
			if(b[y] > b[i]) break;
			if(b[y] == b[i]){
				if(p[y]){
					p[i] = 1;
					good = 1;
				}
				break;
			}
			s.pop();
		}

		if(!good and b[i] != a[i]){
			p[i] = 1;
			cnt[b[i]]++;
		}

		s.push(i);
	}

	for(int i = 0; i < m; i++){
		cnt[x[i]]--;
	}

	for(auto t : cnt){
		if(t.se > 0){
			printf("NO\n");
			return;
		}
	}

	printf("YES\n");

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