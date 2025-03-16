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


int dir[4][2] = {
	{1,1},
	{1,-1},
	{-1,1},
	{-1,-1}
};

void solve(){
	int n, m, ii, ij, fi, fj;
	int d;
	string id;

	cin >> n >> m >> ii >> ij >> fi >> fj >> id;

	if(id == "DR") d = 0;
	if(id == "DL") d = 1;
	if(id == "UR") d = 2;
	if(id == "UL") d = 3;

	if(ii == fi and ij == fj){
		cout << 0 << endl;
		return;
	}

	int cnt = 0;
	int cnt_repeat = 0;

	int i, j;
	i = ii;
	j = ij;
	while(true){
		// cout << i << " " << j << " " << d << endl;
		if(cnt > 0){
			int d_ini_i = 0; 
			int d_ini_j = 0;
			if(i-ii != 0){
				d_ini_i = (ii-i) / abs(ii-i);
			}
			if(j-ij != 0){
				d_ini_j = (ij-j) / abs(ij-j);
			}

			// cout <<"\t"<< d_ini_i << " " << d_ini_j << endl;

			if(abs(ii-i) == abs(ij-j) and d_ini_i == dir[d][0] and d_ini_j == dir[d][1]){
				cnt_repeat++;
				if(cnt_repeat > 4){
					cout << -1 << endl;
					break;
				}
			}
		}

		int d_f_i = 0; 
		int d_f_j = 0;
		if(i-fi != 0){
			d_f_i = (fi-i) / abs(fi-i);
		}
		if(j-fj != 0){
			d_f_j = (fj-j) / abs(fj-j);
		}

		if(abs(fi-i) == abs(fj-j) and d_f_i == dir[d][0] and d_f_j == dir[d][1]){
			cout << cnt << endl;
			break;
		}

		if(d == 0){ // 1, 1
			if(n-i < m-j){ // hits floor
				// cout << "hits floor\n";
				j = (j+(n-i));
				i = n;
				d = 2;
			}
			else if(n-i > m-j){ // hits right wall
				// cout << "hits right wall\n";
				i = (i+(m-j));
				j = m;
				d = 1;	
			}
			else{ // hits down right corner
				// cout << "hits corner\n";
				i = n;
				j = m;
				d = 3;
			}
		}
		else if(d == 1){ // 1, -1
			if(n-i < j-1){ // hits floor
				// cout << "hits floor\n";
				j = (j-(n-i));
				i = n;
				d = 3;
			}
			else if(n-i > j-1){ // hits left wall
				// cout << "hits left wall\n";
				i = (i+(j-1));
				j = 1;
				d = 0;	
			}
			else{ // hits down left corner
				// cout << "hits corner\n";
				i = n;
				j = 1;
				d = 2;
			}
		}
		else if(d == 2){ // -1 1
			if(i-1 < m-j){ // hits ceil
				// cout << i << " " << j << " " << d << " hits ceil \n";
				j = (j+(i-1));
				i = 1;
				d = 0;
				// cout << "-> " << i << " " << j << " " << d << endl;
			}
			else if(i-1 > m-j){ // hits right wall
				// cout << "hits right wall\n";
				i = (i-(m-j));
				j = m;
				d = 3;	
			}
			else{ // hits up right corner
				// cout << "hits corner\n";
				i = 1;
				j = m;
				d = 1;
			}
		}
		else{ // -1, -1
			if(i-1 < j-1){ // hits ceil
				// cout << "hits ceil\n";
				j = (j-(i-1));
				i = 1;
				d = 1;
			}
			else if(i-1 > j-1){ // hits left wall
				// cout << "hits left wall\n";
				i = (i-(j-1));
				j = 1;
				d = 2;	
			}
			else{ // hits up left corner
				// cout << "hits corner\n";
				i = 1;
				j = 1;
				d = 0;
			}
		}

		cnt++;
	}
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