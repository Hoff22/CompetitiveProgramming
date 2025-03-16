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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	long long a, b;
	cin >> a >> b;

	long long ans = 0;
	long long temp = 1;
	for(int i = 0; i < a; i++){
		temp *= b;
	}
	ans += temp;
	temp = 1;
	for(int i = 0; i < b; i++){
		temp *= a;
	}
	ans+=temp;

	cout << ans << endl;
    return 0;

}