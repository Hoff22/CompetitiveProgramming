#include <bits/stdc++.h>
 
using namespace std;

int main() {

	int n;
	cin >> n;

	vector<int> w;

	int score[5] = {0,0,0,0,0};
	int dp[21][21];
	int ans = 0;

	for(int q = 0; q < n; q++){
		string t;
		cin >> t;

		t = " "+t;

		int cur[5] = {0,0,0,0,0};
		int mn = t.size();

		for(int k = 0; k < 5; k++){
			string s;
			cin >> s;

			s = " "+s;


			for(int i = 0; i <= s.size(); i++){
				dp[i][0] = i;
			}
			for(int i = 0; i <= t.size(); i++){
				dp[0][i] = i;
			}

			for(int i = 1; i <= s.size(); i++){
				for(int j = 1; j <= t.size(); j++){
					if(s[i-1] == t[j-1]){
						dp[i][j] = dp[i-1][j-1];
					}
					else{
						dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]}) + 1;
					}
				}
			}
			
			cur[k] = dp[s.size()][t.size()];
			mn = min(mn, cur[k]);
		}

		for(int k = 0; k < 5; k++){
			if(cur[k] == mn) score[k] += 5 + 5 * (mn == 0);
			ans = max(ans, score[k]);
		}
	}

	for(int k = 0; k < 5; k++){
		if(score[k] == ans) w.push_back(k+1);
	}

	cout << fixed << setprecision(1);
	cout << 1.0*ans/10 << endl;
	for(int i = 0; i < w.size(); i++){
		cout << w[i] << " \n"[i==(w.size()-1)];
	}

	return 0;
}