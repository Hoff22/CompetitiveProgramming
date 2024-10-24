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

vector<int> l[26];
string a, b;

bool dfs(int u, int last, int j){
	if(j < 0) return 1;

	for(int v : l[b[j]-'a']){
		if(v < last and (last - v - 1)%2 == 0){
			if(dfs(v, u, j--)) return 1;
		}
	}

	return 0;
}

void solve(){

	cin >> a >> b;

	if(a.size() < b.size()){
		printf("NO\n");
		return;
	}

	if(a == b){
		printf("YES\n");
		return;
	}

	for(int i = 0; i < a.size(); i++){
		l[a[i] - 'a'].push_back(i);
	}

	for(int i = a.size()-1; i >= 0; i--){
		if(a[i] == b[b.size()-1]){
			for(int v : l[b[b.size()-1]-'a']){
				if(dfs(v, i, b.size()-2)){
					printf("YES\n");
					return;
				}
			}
		}
	}

	printf("NO\n");
}
// 14:07 DUAS E SETE ACHO QUE TA CERTO
int main(){
	
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}