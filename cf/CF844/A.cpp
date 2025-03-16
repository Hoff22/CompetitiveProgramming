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
	int w, d, h;
	scanf("%d %d %d", &w, &d, &h);
	int a, b, f, g;
	scanf("%d %d %d %d", &a, &b, &f, &g);

	int ai = (w-a);
	int fi = (w-f);
	int bi = (d-b);
	int gi = (d-g);

	printf("%d\n",h + min({
		a + f + abs(b-g),
		b + g + abs(a-f),
		ai + fi + abs(b-g),
		bi + gi + abs(a-f)}));
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}