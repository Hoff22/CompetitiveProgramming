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

// int count(int a){
// 	if(a == 1) return 1;
// 	return 2 * count(a-1) + 1;
// }

int mex(int a, int b){
	set<int> s = {1,2,3};
	s.erase(a); s.erase(b);
	return *s.begin();
}

void moves(int a, int to, int from){
	if(a == 1){
		cout << from << " " << to << endl;
		return;
	}

	moves(a-1, mex(to, from), from);
	cout << from << " " << to << endl;
	moves(a-1, to, mex(to, from));
}

void solve(){
	int n;
	cin >> n;

	cout << (1<<n)-1 << endl;
	moves(n, 3, 1);
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