#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int n, x, y, k;
double p;
map<tuple<int,int,int>, double> DP;

double dp(int i, int xp, int yp){
	if(xp < 0 or yp < 0 or xp >= n or yp >= n) return 0;

	//cout << i << " " << xp << " " << yp << endl;

	if(i == 0){
		return (xp == y and yp == x);
	}

	if(DP.count({i,xp,yp})) return DP[{i,xp,yp}];

	if(xp == yp-1){
		return DP[{i,xp,yp}] = (
			dp(i-1, xp+1, yp-1) * p/(n-1) +
			dp(i-1, xp-1, yp) 	* p/(n-1) +
			dp(i-1, xp, yp+1) 	* p/(n-1)
			);
	}
	if(yp == xp-1){
		return DP[{i,xp,yp}] = (
			dp(i-1, xp-1, yp+1) * p/(n-1) +
			dp(i-1, xp+1, yp) 	* p/(n-1) +
			dp(i-1, xp, yp-1) 	* p/(n-1)
			);
	}
	return DP[{i,xp,yp}] = (
		dp(i-1, xp+1, yp) * p/(n-1) +
		dp(i-1, xp-1, yp) * p/(n-1) +
		dp(i-1, xp, yp+1) * p/(n-1) +
		dp(i-1, xp, yp-1) * p/(n-1)
		);
}

double dp(int i, int xp){
	if(xp < 0 or xp >= n) return 0;

	if(i == 0){
		return (xp == x);
	}

	if(DP.count({i,xp,0})) return DP[{i,xp,0}];

	return DP[{i,xp,0}] = (
		dp(i-1, xp+1) * p/(n-1) +
		dp(i-1, xp-1) * p/(n-1) +
		dp(i-1, xp) * p/(n-1)
		);
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	ifstream file("assessment.in");

    int t;

    file >> t;

    for(int ts = 1; ts <= t; ts++){
    	file >> n >> p >> x >> y >> k;
    	
    	cout << fixed << setprecision(5);
    	
    	DP.clear();

    	double ans;
    	if(x==y){
    		ans = dp(k,x);
    	}
    	else{
    		ans = dp(k,x,y);
    	}
    	
		cout << "Case " << ts << ": " << ans << endl;
    	
    }
    return 0;

}