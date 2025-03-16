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
	int l ,r, x, a, b;
	cin >> l >> r >> x >> a >> b;

	if(a == b){
		cout << 0 << endl;
		return;
	}
	if(abs(a-b) >= x){
		cout << 1 << endl;
		return;
	}

	// 1 full direita
	// 2 full esquerda
	// 3 b

	vector<int> p;
	p.push_back(1);
	p.push_back(2);
	p.push_back(3);

	int ans = 4;
	do{

		bool good = 1;
		int cur = 0;
		int curA = a;
		for(int i = 0; i < 3; i++){
			//cout << curA << endl;
			cur++;
			if(p[i] == 1){
				if(r-curA < x) good = 0;
				else{
					curA = r;
				}
			}
			if(p[i] == 2){
				if(curA-l < x) good = 0;
				else{
					curA = l;
				}
			}
			if(p[i] == 3){
				if(abs(curA-b) < x) good = 0;
				else{
					break;
				}
			}
		}

		if(good) {
			ans = min(ans, cur);
			//cout << "good "<< cur <<"\n";
		}

	}while(next_permutation(p.begin(), p.end()));

	if(ans == 4){
		cout << -1 << endl;
		return;
	}

	cout << ans << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}