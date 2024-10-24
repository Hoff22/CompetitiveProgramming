#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

#define N 1000

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	map<tuple<string, int, int>, vector<int>> pos;

	int n;
	cin >> n;

	vector<string> s(n);
	for(int i = 0; i < n; i++){
		cin >> s[i];
		for(int j = 0; j < i; j++){

			if(s[i].size() != s[j].size()) continue;

			int good = 0;
			string group = "";
			int id = 0;
			for(int k = 0; k < s[i].size()-1; k++){
				if(s[i][k] != s[j][k]){
					if(group == ""){
						if(s[i][k+1] == s[j][k+1]){
							good = 0;
							break;
						}
						else{
							good = 1;
							string a = "";
							string b = "";
							a += s[i][k];
							a += s[i][k+1];
							a += s[j][k];
							a += s[j][k+1];

							b += s[j][k];
							b += s[j][k+1];
							b += s[i][k];
							b += s[i][k+1];
						
							group = min(a,b);
							id = k;
							k++;
						}
					}
					else{
						good = 0;
						break;
					}
				}
			}

			if(good){
				pos[{group, id, (int)s[i].size()}].push_back(i);
				pos[{group, id, (int)s[i].size()}].push_back(j);
				
				string ra = "";

				if(make_tuple(group, (int)s[i].size()-id-2, (int)s[i].size()) != make_tuple(group, id, (int)s[i].size())){
					pos[{group, (int)s[i].size()-id-2, (int)s[i].size()}].push_back(i);
					pos[{group, (int)s[i].size()-id-2, (int)s[i].size()}].push_back(j);
				}
			}

		}
	}

	set<pair<int,int>> ans;

	for(auto p : pos){
		if(p.second.size() == 2){
			if(p.second[0] > p.second[1]){
				swap(p.second[0], p.second[1]);
				ans.insert({p.second[0], p.second[1]});
			}
		}
	}

	cout << ans.size() << endl;

	return 0;

}