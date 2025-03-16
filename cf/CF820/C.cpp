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
	vector<vector<int>> p(27,vector<int>());

	string s;
	cin >> s;

	for(int i = 0; i < s.size(); i++){
		//cout << s[i] << " " << s[i] - 'a' + 1 << endl;
		p[s[i] - 'a' + 1].push_back(i);
	}

	vector<int> ans;

	if(s[0] > s[s.size()-1]){
		for(int i = s[0]-'a'+1; i >= s[s.size()-1] - 'a' + 1; i--){
			if(p[i].empty()) continue;
			else{
				for(int j : p[i]){
					ans.push_back(j+1);
				}
			}
		}
	}
	else{
		for(int i = s[0]-'a'+1; i <= s[s.size()-1] - 'a' + 1; i++){
			if(p[i].empty()) continue;
			else{
				for(int j : p[i]){
					ans.push_back(j+1);
				}

			}
		}
	}


	int c = abs(s[0] - s[s.size()-1]);

	cout << c << " " << ans.size() << endl;
	for(int i = 0; i < ans.size(); i++){
		cout << ans[i] << " ";
	}
	cout << endl;

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