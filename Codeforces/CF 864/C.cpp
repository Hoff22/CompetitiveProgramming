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
	long long n, m;
	cin >> n >> m;

	long long r;

	cout << "? " << 1ll << " "  << 1ll << endl;
	cout.flush();

	cin >> r;

	long long rx = min(r+1, m);
	long long ry = min(r+1, n);

	// cout << lx << "- " << rx << "  " << ly << "- " << ry << endl;
	cout << "? " << ry << " " << rx << endl;
	
	cout.flush();

	cin >> r;
	
	int px, py;

	px = max(1ll, rx-r);	
	py = max(1ll, ry-r);

	cout << "? " << ry << " " << px << endl;
	
	cout.flush();

	cin >> r;	

	if(r == 0){
		cout << "! " << ry << " " << px << endl;
	}
	else{
		cout << "! " << py << " " << rx << endl;
	}

	cout.flush();


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