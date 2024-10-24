#include <bits/stdc++.h>

#define N 20
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

constexpr int QUEENS = 8;

int a[8][8];

void paint(int y, int x, int amt){
	for(int i = 0; i < 8; i++){
		a[i][x] += amt;
	}
	for(int j = 0; j < 8; j++){
		a[y][j] += amt;
	}
	int j = x - min(x,y);
	for(int i = y - min(x,y); i < 8 and j < 8; i++, j++){
		a[i][j] += amt;
	}
	j = x + min(7-x,y);
	for(int i = y - min(7-x,y); (i < 8) and (j >= 0); i++, j--){
		a[i][j] += amt;
	}
	a[y][x] -= 3*amt;
}

long long bt(int i, int j, int q){
	if(i == 8){
		return (q == QUEENS);
	}

	long long res = 0;

	int ni, nj;
	if(j == 7){
		ni = i+1; nj = 0;
	}
	else{
		ni = i; nj = j+1;
	}

	if(a[i][j] != 0 or q == QUEENS) res = bt(ni, nj, q);
	else{
		paint(i, j, 1);
		res += bt(ni, nj, q+1);
		paint(i, j, -1);
		res += bt(ni, nj, q);
	}
	return res;
}

void solve(){
	for(int i = 0; i < 8; i++){
		for(int j = 0; j < 8; j++){
			char c;
			cin >> c;
			if(c == '*') a[i][j] = 1;
		}
	}

	cout << bt(0,0,0) << endl;	
}

int main(){	
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}