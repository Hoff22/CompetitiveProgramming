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

1 2 3 4 5 6
B A B B C C
    B   C
B         C
  A   B

A A B B C C 


B A C A A C

A A A B C C

AAAA B CCC BB

     ^

*/


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    string s;

	cin >> n >> s;
	
	vector<int> pos[3];

	vector<int> used(2*n, 0);

	vector<pair<int,int>> ans;

	for(int i = 0; i < 2*n; i++){
		pos[s[i]-'A'].push_back(i);
	}

	int ABs = (pos[0].size() + pos[1].size() - pos[2].size()) / 2;

	for(int i = 2*n-1; i >= 0; i--){
		// cout << i << ": " << endl;
		// for(auto j : ans){
		// 	cout << j.fi << " " << j.se << endl;
		// }
		// cout << endl;

		if(used[i]){
			continue;
		}

		if(s[i] == 'A'){
			cout << "NO" << endl;
			return 0;
		}

		if(s[i] == 'B'){
			if(pos[0].empty()){
				cout << "NO" << endl;
				return 0;
			}

			ans.push_back({pos[0].back(), i});

			used[pos[0].back()] = 1;
			used[pos[1].back()] = 1;

			pos[0].pop_back();
			pos[1].pop_back();
		
			ABs--;

			continue;
		}

		if(s[i] == 'C'){
			int rA = -1;
			int rB = -1;

			if(!pos[0].empty()){
				rA = pos[0].back();
			}
			if(!pos[1].empty()){
				rB = pos[1].back();
			}

			if(rA == -1 and rB == -1){
				cout << "NO" << endl;
				return 0;
			}

			// cout <<"rA, rB: "<< rA <<" "<< rB << endl;

			if(rA > rB){
				ans.push_back({pos[0].back(), i});

				used[pos[0].back()] = 1;
				used[pos[2].back()] = 1;

				pos[0].pop_back();
				pos[2].pop_back();
			
				continue;
			}
			else{
				// cout <<"ABs: "<< ABs << endl;
				if(ABs){
					// fazemos AB
					if(pos[0].empty()){
						cout << "NO" << endl;
						return 0;
					}

					used[rB] = 1;
					used[pos[0].back()] = 1;

					ans.push_back({pos[0].back(), rB});

					pos[0].pop_back();
					pos[1].pop_back();
					i++;
					ABs--;
				}
				else{
					// fazemos BC
					used[rB] = 1;
					used[pos[2].back()] = 1;

					ans.push_back({rB, pos[2].back()});

					pos[1].pop_back();
					pos[2].pop_back();
				}
			}		
		}
	}

	cout << "YES" << endl;
	for(auto i : ans){
		cout << i.fi+1 << " " << i.se+1 << endl;
	}

    return 0;

}