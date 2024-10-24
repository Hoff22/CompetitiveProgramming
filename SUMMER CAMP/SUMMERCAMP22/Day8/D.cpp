#include <bits/stdc++.h>

#define N 500
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

ifstream in; //RIDICULO
int n, m;
long long qnt[N+1];
// int Prefqnt[N+1];
int a[N+1][N+1];
// int b[N+1];
long long ans[N+1];
pair<long long,int> b_idx[N+1];

pair<int,int> findRange(int j){
	int l, r;
	l = r = j;
	//cout <<"\t<<"<< j << endl;
	for(int i = n-1; i >= 0; i--){
		if(l > 0 and a[i][l-1] != 0) l = l-1;
		if(r < m-1 and a[i][r+1] != 0) r = r+1;
		//cout << l << " " << r << endl;
	}

	return {l,r};
}

void solve(){
	in >> n >> m;

	memset(ans, 0, sizeof(ans));
	memset(b_idx, 0, sizeof(b_idx));

	for(int i = 0; i < m; i++){
		in >> qnt[i];
	}

	for(int i = 0; i < n; i++){
		for(int j = 0; j < m; j++){
			char c;
			in >> c;

			if(c == '.') a[i][j] = 0;
			else a[i][j] = 1;
		}
	}

	for(int i = 0; i < m; i++){
		long long x;
		in >> x;
		b_idx[i] = {x, i};
	}

	sort(b_idx, b_idx+m+1);
	reverse(b_idx, b_idx+m+1);

	pair<int,int> f;

	for(int i = 0; i < m; i++){
		f = findRange(b_idx[i].se);
		//cout << f.fi <<" "<< f.se <<" "<< b_idx[i].se << endl;

		for(int j = f.fi; j <= f.se; j++){
			ans[j] = max(ans[j], b_idx[i].fi);
		}
	}

	long long ans2 = 0;
	long long cur = 0;
	for(int i = 0; i < m; i++){
		cur += qnt[i];
		if(i == m-1 or ans[i] != ans[i+1]){
			ans2 += ans[i] * cur;
			cur = 0; 
		}
	}

	// for(int i = 0; i < m; i++){
	// 	cout << ans[i] << " ";
	// }
	// cout << endl;

	cout << ans2 << endl;
}

int main(){
	
	in.open("balls.in", ifstream::in);	

	int t;
	in >> t;
	
	while(t--){
		solve();
	}

	in.close();

    return 0;

}