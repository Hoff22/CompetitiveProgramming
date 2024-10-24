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

	string s;

	cin >> s;
	int n = s.size();
	vector<int> v(n+1);

	for(int i = 1; i <= n; i++){
		v[i] = (s[i-1] - '0');
	}

	int w, m;
	cin >> w >> m;

	vector<int> r[9];
	vector<int> acc(n+1);

	acc[0] = 0;
	for(int i = 1; i <= n; i++){
		acc[i] = acc[i-1] + v[i];
	}


	int l_, r_;
	l_ = 1;
	r_ = w;
	while(r_ <= n){
		int cur_r = (acc[r_] - acc[l_-1]) % 9;
		r[cur_r].push_back(l_);

		l_++;
		r_++;
	}
	
	// for(int i = 0; i <= n; i++){
	// 	printf("%d\t", i);
	// }
	// printf("\n");
	// for(int i = 0; i <= n; i++){
	// 	printf("%d\t", acc[i]);
	// }
	// printf("\n\n");

	// for(int i = 0; i < 9; i++){
	// 	printf("%d:\n", i);
	// 	for(int j : r[i]){
	// 		printf("\t%d %d\n", j, j+w-1);
	// 	}
	// 	printf("\n\n");
	// }


	while(m--){

		int l, ri, k;
		cin >> l >> ri >> k;

		int cur_r = (acc[ri] - acc[l-1]) % 9;
		//printf("l: %d r: %d cur_r: %d\n", l, ri, cur_r);

		int ansL, ansR;
		ansL = ansR = -1;

		for(int i = 0; i < 9; i++){
			if(r[i].empty()) continue;
			
			for(int j = 0; j < 9; j++){
				if(r[j].empty()) continue;

				if((i * cur_r + j) % 9 == k){
					if(i == j){
						if((ansL == -1 or ansL > r[i][0]) and r[i].size() > 1){
							ansL = r[i][0];
							ansR = r[j][1];
						}
					}
					else{
						if(ansL == -1 or ansL > r[i][0]){
							ansL = r[i][0];
							ansR = r[j][0];
						}
					}
				}
			}
		}

		cout << ansL << " " << ansR << endl;
	}

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