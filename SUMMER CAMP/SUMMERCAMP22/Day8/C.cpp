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

ifstream in;
int a[N+1];
int n;
int s, e;

void solve(){

	in >> n;

	for(int i = 1; i <= n; i++){
		char c;
		in >> c;
		if(c == '.') a[i] = 0;
		if(c == '#') a[i] = 1;
		if(c == 'o'){
			a[i] = 2;
		}
		if(c == 's'){
			a[i] = 3;
			s = i;
		}
		if(c == 'e'){
			a[i] = 4;
			e = i;
		}
	}

	int resE = 0;

	for(int i = e+1; i <= n; i++){
		if(a[i] == 2 or a[i] == 3){
			resE += 1;
			if(i-e == 1) resE = INF;
			break;
		}
		if(a[i] == 1) break;
	}
	for(int i = e-1; i >= 1; i--){
		if(a[i] == 2 or a[i] == 3){
			resE += 1;
			if(e-i == 1) resE = INF;
			break;
		}
		if(a[i] == 1) break;
	}

	int resS = 0;

	for(int i = s+1; i <= n; i++){
		if(a[i] == 2 or a[i] == 4){
			resS += 1;
			if(i-s == 1) resS = INF;
			break;
		}
		if(a[i] == 1) break;
	}
	for(int i = s-1; i >= 1; i--){
		if(a[i] == 2 or a[i] == 4){
			resS += 1;
			if(s-i == 1) resS = INF;
			break;
		}
		if(a[i] == 1) break;
	}

	int ans = min(resS, resE);

	if(ans >= INF){
		cout << -1 << endl;
	}
	else{
		cout << ans << endl;
	}
}

int main(){
	
	in.open("tour.in", ifstream::in);	

	int t;
	in >> t;
	
	while(t--){
		solve();
	}

	in.close();

    return 0;

}