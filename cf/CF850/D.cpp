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
	int m;
	scanf("%d", &m);

	vector<vector<int>> a(m+1, vector<int>(3,0));

	for(int i = 1; i <= m; i++){
		char c[3];
		scanf(" %c%c%c", &c[0], &c[1], &c[2]);

		for(int j = 0; j < 3; j++){
			if(c[j] == 'w'){
				a[i][0]++;
			}
			if(c[j] == 'i'){
				a[i][1]++;
			}
			if(c[j] == 'n'){
				a[i][2]++;
			}
		}
	}

	vector<vector<vector<set<int>>>> v(4, vector<vector<set<int>>>(4, vector<set<int>>(4, set<int>())));

	for(int i = 1; i <= m; i++){
		v[a[i][0]][a[i][1]][a[i][2]].insert(i);
		//ops.push_back({{, i, a}[i{][0], }}a[i][1], a[i][2]);
	}


	vector<pair<pair<int,char>,pair<int,char>>> ops;


	for(int i = 1; i <= m; i++){
		if(a[i][0] == 3){
			if(v[0][0][3].size()){
				int j = *v[0][0][3].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][0]--;
				a[j][0]++;

				a[j][2]--;
				a[i][2]++;

				ops.push_back({{i, 'w'}, {j, 'n'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[0][3][0].size()){
				int j = *v[0][3][0].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][0]--;
				a[j][0]++;

				a[j][1]--;
				a[i][1]++;

				ops.push_back({{i, 'w'}, {j, 'i'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[0][1][2].size()){
				int j = *v[0][1][2].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][0]--;
				a[j][0]++;

				a[j][2]--;
				a[i][2]++;

				ops.push_back({{i, 'w'}, {j, 'n'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[0][2][1].size()){
				int j = *v[0][2][1].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][0]--;
				a[j][0]++;

				a[j][1]--;
				a[i][1]++;

				ops.push_back({{i, 'w'}, {j, 'i'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
		}
		else if(a[i][1] == 3){
			if(v[0][0][3].size()){
				int j = *v[0][0][3].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][1]--;
				a[j][1]++;
				a[j][2]--;
				a[i][2]++;

				ops.push_back({{i, 'i'}, {j, 'n'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[3][0][0].size()){
				int j = *v[3][0][0].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][1]--;
				a[j][1]++;
				a[j][0]--;
				a[i][0]++;

				ops.push_back({{i, 'i'}, {j, 'w'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[1][0][2].size()){
				int j = *v[1][0][2].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][1]--;
				a[j][1]++;
				a[j][2]--;
				a[i][2]++;

				ops.push_back({{i, 'i'}, {j, 'n'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[2][0][1].size()){
				int j = *v[2][0][1].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][1]--;
				a[j][1]++;
				a[j][0]--;
				a[i][0]++;

				ops.push_back({{i, 'i'}, {j, 'w'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
		}
		else if(a[i][2] == 3){
			if(v[3][0][0].size()){
				int j = *v[3][0][0].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][2]--;
				a[j][2]++;
				a[j][0]--;
				a[i][0]++;

				ops.push_back({{i, 'n'}, {j, 'w'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[0][3][0].size()){
				int j = *v[0][3][0].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][2]--;
				a[j][2]++;
				a[j][1]--;
				a[i][1]++;

				ops.push_back({{i, 'n'}, {j, 'i'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[1][2][0].size()){
				int j = *v[1][2][0].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][2]--;
				a[j][2]++;
				a[j][1]--;
				a[i][1]++;

				ops.push_back({{i, 'n'}, {j, 'i'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
			else if(v[2][1][0].size()){
				int j = *v[2][1][0].begin();

				v[a[i][0]][a[i][1]][a[i][2]].erase(i);
				v[a[j][0]][a[j][1]][a[j][2]].erase(j);

				a[i][2]--;
				a[j][2]++;
				a[j][0]--;
				a[i][0]++;

				ops.push_back({{i, 'n'}, {j, 'w'}});

				v[a[i][0]][a[i][1]][a[i][2]].insert(i);
				v[a[j][0]][a[j][1]][a[j][2]].insert(j);
			}
		}
	}



for(int i = 1; i <= m; i++){
		if(a[i][0] == 1){ // 1 X X
			if(a[i][1] == 2){ // 1 2 0
				if(v[1][0][2].size()){
					int j = *v[1][0][2].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][1]--;
					a[j][1]++;
					a[j][2]--;
					a[i][2]++;

					ops.push_back({{i, 'i'}, {j, 'n'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
				else{
					int j = *v[2][0][1].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][1]--;
					a[j][1]++;
					a[j][0]--;
					a[i][0]++;

					ops.push_back({{i, 'i'}, {j, 'w'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
			}
			if(a[i][2] == 2){ // 1 0 2
				if(v[1][2][0].size()){
					int j = *v[1][2][0].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][2]--;
					a[j][2]++;
					a[j][1]--;
					a[i][1]++;

					ops.push_back({{i, 'n'}, {j, 'i'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
				else{
					int j = *v[2][1][0].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][2]--;
					a[j][2]++;
					a[j][0]--;
					a[i][0]++;

					ops.push_back({{i, 'n'}, {j, 'w'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
			}
		}
		else if(a[i][1] == 1){
			if(a[i][0] == 2){ // 2 1 0
				if(v[0][1][2].size()){
					int j = *v[0][1][2].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][0]--;
					a[j][0]++;
					a[j][2]--;
					a[i][2]++;

					ops.push_back({{i, 'w'}, {j, 'n'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
				else{
					int j = *v[0][2][1].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][0]--;
					a[j][0]++;
					a[j][1]--;
					a[i][1]++;

					ops.push_back({{i, 'w'}, {j, 'i'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
			}
			if(a[i][2] == 2){ // 0 1 2
				if(v[2][1][0].size()){
					int j = *v[2][1][0].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][2]--;
					a[j][2]++;
					a[j][0]--;
					a[i][0]++;

					ops.push_back({{i, 'n'}, {j, 'w'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
				else{
					int j = *v[1][2][0].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][2]--;
					a[j][2]++;
					a[j][1]--;
					a[i][1]++;

					ops.push_back({{i, 'n'}, {j, 'i'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
			}
		}
		else if(a[i][2] == 1){
			if(a[i][0] == 2){ // 2 0 1
				if(v[0][2][1].size()){
					int j = *v[0][2][1].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][0]--;
					a[j][0]++;
					a[j][1]--;
					a[i][1]++;

					ops.push_back({{i, 'w'}, {j, 'i'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
				else{
					int j = *v[0][1][2].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][0]--;
					a[j][0]++;
					a[j][2]--;
					a[i][2]++;

					ops.push_back({{i, 'w'}, {j, 'n'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
			}
			if(a[i][1] == 2){ // 0 2 1
				if(v[2][0][1].size()){
					int j = *v[2][0][1].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][1]--;
					a[j][1]++;
					a[j][0]--;
					a[i][0]++;

					ops.push_back({{i, 'i'}, {j, 'w'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
				else{
					int j = *v[1][0][2].begin();

					v[a[i][0]][a[i][1]][a[i][2]].erase(i);
					v[a[j][0]][a[j][1]][a[j][2]].erase(j);

					a[i][1]--;
					a[j][1]++;
					a[j][2]--;
					a[i][2]++;

					ops.push_back({{i, 'i'}, {j, 'n'}});

					v[a[i][0]][a[i][1]][a[i][2]].insert(i);
					v[a[j][0]][a[j][1]][a[j][2]].insert(j);
				}
			}
		}
	}

	printf("%d\n", (int)ops.size());
	for(auto op : ops){
		printf("%d %c %d %c\n", op.fi.fi,op.fi.se, op.se.fi, op.se.se);
	}

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