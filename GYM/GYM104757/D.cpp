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

int main(){
	
	ios::sync_with_stdio(false);
	cin.tie(NULL);

	int sum = 0;
	int n, k;
	for(int i = 0; i < 5; i++){
		int x, y;
		cin >> x >> y;
		sum += x*y;
	}

	sum /= 5;

	cin >> n >> k;

	cout << (sum * n) / k << endl;

   return 0;

}