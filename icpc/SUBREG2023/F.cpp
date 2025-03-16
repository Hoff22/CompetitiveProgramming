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
	long long d, c, r;
	cin >> d >> c >> r;

	queue<long long> a, b;
	for(int i = 0; i < c; i++){
		int x; cin >> x;
		a.push(x);
	}

	for(int i = 0; i < r; i++){
		int x; cin >> x;
		b.push(x);
	}

	int cnt = 0;
	while(a.size() and b.size()){
		if(d >= a.front()){
			d -= a.front();
			a.pop();
		}
		else{
			d += b.front();
			b.pop();
		}
		cnt++;
	}

	while(a.size() and d >= a.front()){
		d -= a.front();
		a.pop();
		cnt++;
	}

	cnt += b.size();

	cout << cnt << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    solve();

    return 0;

}