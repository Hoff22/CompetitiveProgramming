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
	int n, ans1, ans2;
	cin >> n;
	vector<int> x(n+1);
	vector<int> ou(n+1,0);
	for(int i = 1; i <= n; i++){
		cin >> x[i];
		ou[x[i]]++;
	}

	for(int i = 1; i <= n; i++){
		for(int j = 1; j <= n; j++){
			if(i == j) continue;
			if(abs(x[i]-x[j]) > n/2){

				cout << "? " << i << " " << j << endl;
				cin >> ans1;
				if(ans1 < abs(x[i]-x[j]) or ans1 == 0){
					cout << "! A" << endl;
				}
				else{
					cout << "? " << j << " " << i << endl;
					cin >> ans2;
					if(ans1 != ans2){
						cout << "! A" << endl;
					}
					else{
						cout << "! B" << endl;
					}
				}

				return;
			}
		}
	}

	for(int i = 1; i <= n; i++){
		if(ou[i] == 0){
			cout << "? " << i << " " << (i == 1 ? 2 : 1) << endl;
			cin >> ans1;
			if(ans1 == 0){
				cout << "! A" << endl;
			}
			else{
				cout << "! B" << endl;
			}
			return;
		}
	}

	while(true){}
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