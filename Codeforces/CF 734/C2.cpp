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

int freq[N+1][5];
int ans[5][5];
int r[5];

void solve(){
	int n;
	cin >> n;

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		
		for(int j = 0; j < s.size(); j++){
			freq[i][s[j]-'a']++;
		}
	}

	for(int i = 0; i < 5; i++) ans[0][i] = ans[1][i] = ans[2][i] = ans[3][i] = ans[4][i] = 0;

	r[0] = r[1] = r[2] = r[3] = r[4] = 0;

	for(int i = 0; i < 5; i++){
		for(int s = 0; s < n; s++){
			r[i]++;
			int good = 1;
			for(int c = 0; c < 5; c++){ // ADD
				ans[i][c] += freq[s][c];
				if(i != c and ans[i][i] <= ans[i][c]) good = 0; 
			}

			if(!good){
				r[i]--;
				for(int c = 0; c < 5; c++){ // REMOVE
					ans[i][c] -= freq[s][c];
				}
			}
		}
	}

	printf("%d\n", *max_element(r, r+5));
}

int main(){
	
	int t;
	cin >> t;	
	while(t--){
		solve();
	}
    return 0;

}