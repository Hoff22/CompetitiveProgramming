#include <bits/stdc++.h>

#define N 400
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

char m[N][N];

void solve(){
	int n;
	scanf("%d", &n);

	pair<int,int> p1 = {-1,-1};
	pair<int,int> p2 = {-1,-1};
	int found = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			scanf(" %c", &m[i][j]);
			if(m[i][j] == '*'){
				if(found == 0){
					found = 1;
					p1 = {i,j};
				}
				else{
					p2 = {i,j};
				}
			}
		}
	}

	if(p1.first == p2.first){
		if(p1.first == 0){
			m[p1.first+1][p1.second] = '*';
			m[p2.first+1][p2.second] = '*';
		}
		else{
			m[p1.first-1][p1.second] = '*';
			m[p2.first-1][p2.second] = '*';
		}
	}
	else if(p1.second == p2.second){
		if(p1.second == 0){
			m[p1.first][p1.second+1] = '*';
			m[p2.first][p2.second+1] = '*';
		}
		else{
			m[p1.first][p1.second-1] = '*';
			m[p2.first][p2.second-1] = '*';
		}
	}
	else{
		m[p1.first][p2.second] = '*';
		m[p2.first][p1.second] = '*';
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			printf("%c", m[i][j]);
		}
		printf("\n");
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}