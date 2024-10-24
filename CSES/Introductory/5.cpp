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
	int n;
	cin >> n;
	if(n > 1 and n < 4) cout << "NO SOLUTION" << endl;
	else{
		if(n == 4){
			cout << "3 1 4 2" << endl;
			return;
		}
		for(int i = 1; i <= n; i+=2) cout << i << " ";
		for(int i = 2; i <= n; i+=2) cout << i << " ";
		cout << endl;
	}
}

/*
1 2 3 4 5 

3 1 4 2

1 3 2


*/

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