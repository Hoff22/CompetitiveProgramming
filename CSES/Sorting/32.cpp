#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF (1000000000ll * 200000ll)
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

// mandar +20 pra betina

void solve(){
	int n;
	cin >> n;

	vector<int> in(n,0);

	int rem = 1;
	int step = 0;
	while(rem){
		rem = 0;
		for(int i = 0; i < n; i++){
			if(in[i]) continue;
			if(step){
				rem = 1;
				in[i] = 1;
				cout << i+1 << " ";
			}
			step = !step;
		}
	}
	
	for(int i = 0; i < n; i++){
		if(!in[i]){
			cout << i+1 << " ";
		}
	}

	cout << endl;
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