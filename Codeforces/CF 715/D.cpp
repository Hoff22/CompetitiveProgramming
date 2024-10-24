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


void solve(){
	int n;
	cin >> n;
	
	string s[3];
	int count[3][2];

	for(int i = 0 ; i < 3; i++){
		cin >> s[i];
		for(int j = 0; j < s[0].length(); j++){
			if(s[i][j] == '0') count[i][0]++;
			if(s[i][j] == '1') count[i][1]++;
		}
	}

	vector<char> ans;
	for(int i = 0 ; i < 3; i++){
		for(int j = 0; j < 3; j++){
			if(j == i) continue;
			if((count[i][0] >= n and count[j][0] >= n) or (count[i][1] >= n and count[j][1] >= n)){
				for(int k = 0; k < s[i].length(); k++) ans.push_back(s[i][k]);

				int q = 0;
				for(int k = 0; k < s[j].length(); k++){
					if(ans[q] != s[j][k]) ans.insert(ans.begin()+q, s[j][k]);
					q++;
				}
				cout << "si: " << s[i] << endl;
				cout << "sj: " << s[j] << endl;
				for(int k = 0; k < ans.size(); k++) cout << ans[k];
				cout << endl;
				return;
			}
		}
	}

}

// 1101
// 0010

int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}