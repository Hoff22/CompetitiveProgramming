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

/*

2 3 4 3 2

2 3 4   
      3 2


5 3 4 3 5

5 3 4 2 1
4 2 1 3 5

5 3 4 2 1
4 2 1 3 5

5 3 4 3 5

1 1

1
1

*/

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> v(n+1, 0);

	bool good = 1;
	set<int> seen;
	for(int i = 1; i<=n; i++){
		scanf("%d", &v[i]);
		if(seen.count(v[i])) good = 0;
		seen.insert(v[i]);
	}

	if(good){
		printf("YES\n");
		for(int i = 1; i <= n; i++){
			printf("%d%c", i, " \n"[i==n]);
		}
		for(int i = 1; i <= n; i++){
			printf("%d%c", i, " \n"[i==n]);
		}
		return;
	}

	set<int> a;
	set<int> b;
	set<int> n_a;
	set<int> n_b;

	for(int i = 1; i <= n; i++){
		n_a.insert(i);
		n_b.insert(i);
	}

	vector<int> ans_a(n+1, -1);
	vector<int> ans_b(n+1, -1);

	for(int i = 1; i <= n; i++){
		if(a.count(v[i])){
			if(b.count(v[i])){
				printf("NO\n");
				return;
			}
			else{
				b.insert(v[i]);
				n_b.erase(v[i]);

				ans_b[i] = v[i];
			}
		}
		else{
			if(a.count(v[i])){
				printf("NO\n");
				return;
			}
			else{
				a.insert(v[i]);
				n_a.erase(v[i]);

				ans_a[i] = v[i];
			}
			
		}
	}

	for(int i = 1; i <= n; i++){
		if(ans_b[i] == -1){
			//printf("a[i] : %d\n", ans_a[i]);

			auto j = upper_bound(n_b.begin(), n_b.end(), v[i]);
			if(j == n_b.begin()){
				// deu ruim
				printf("NO\n");
				return;
			}
			//printf("j: %d\n", *j);
			j--;
			b.insert(*j);
			n_b.erase(*j);

			ans_b[i] = *j;
		}
		else{
			auto j = upper_bound(n_a.begin(), n_a.end(), v[i]);
			if(j == n_a.begin()){
				// deu ruim
				printf("NO\n");
				return;
			}
			j--;
			a.insert(*j);
			n_a.erase(*j);

			ans_a[i] = *j;
		}
	}

	printf("YES\n");
	for(int i = 1; i <= n; i++){
		printf("%d%c", ans_a[i], " \n"[i==(n)]);
	}
	for(int i = 1; i <= n; i++){
		printf("%d%c", ans_b[i], " \n"[i==(n)]);
	}
	return;
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