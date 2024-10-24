#include <bits/stdc++.h>

#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

typedef long long ll;

#define N 50

//   1 1 3 1 1 3
// 0 1 2 5 6 7 10
// 0 1 2 0 1 2 0
// 0 . . 1 . . 1 

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int a,b,c;
	cin >> a >> b >> c;

	int cur = 0;

	if(c >= 2){
		cur+=2, c--;
		while(b--) cur += 2;
		cur+=1, c--;
	}

	while(c >= 2){
		c -= 2;
		cur += 3;
	}

	while(a--) cur+=2;

	cout << cur << endl;
}