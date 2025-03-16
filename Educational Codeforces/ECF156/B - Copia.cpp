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

long long sdist(long long ax, long long ay, long long bx, long long by){
	return (ax-bx)*(ax-bx) + (ay-by)*(ay-by);
}

double long dist(long long ax, long long ay, long long bx, long long by){
	return sqrt((ax-bx)*(ax-bx) + (ay-by)*(ay-by));
}

void solve(){
	long long px, py, ax, ay, bx, by;
	cin >> px >> py >> ax >> ay >> bx >> by;

	cout << fixed << setprecision(18);

	long long onlya = max(dist(0,0,ax,ay), dist(px,py,ax,ay));
	long long onlyb = max(dist(0,0,bx,by), dist(px,py,bx,by));

	long long both = max({
		max(dist(0,0,ax,ay), dist(0,0,bx,by)) * 2,
		max(dist(px,py,ax,ay), dist(px,py,bx,by)) * 2,
		dist(ax,ay,bx,by)
	});

	cout << min({onlya, onlyb, both}) << endl;
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