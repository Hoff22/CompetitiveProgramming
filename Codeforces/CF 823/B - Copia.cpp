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

int n;
vector<double> p; 
vector<double> g; 

double eval(double x){

	double mxt = *max_element(g.begin(), g.end());

	double ans = mxt;
	for(int i = 0; i < n; i++){
		double d = abs(p[i] - x);
		double ft = mxt - g[i];
		ans = max(ans, mxt+d-ft);
	}

	return ans;
}

void solve(){
	scanf("%d", &n);

	p.assign(n, 0.0);
	g.assign(n, 0.0);

	for(int i = 0; i < n; i++){
		scanf("%lf", &p[i]);
	}

	for(int i = 0; i < n; i++){
		scanf("%lf", &g[i]);
	}

	double l = *min_element(p.begin(), p.end());
	double r = *max_element(p.begin(), p.end());

	while(r - l > 0.00000001){
		double m1 = l + (r - l) / 2;
		double m2 = m1 + 0.000000001;

		//printf("%.18lf %.18lf\n", l,r);
		//printf("%.18lf %.18lf\n", eval(m1),eval(m2));

		if(eval(m1) - eval(m2) > 0.0){
			//printf("->\n");
			// direita
			l = m2;
		}
		else{
			//printf("<-\n");
			r = m1;
		}
	}

	printf("%.18lf\n", l);

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