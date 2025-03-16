#include <bits/stdc++.h>

#define N 100
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

typedef long long ll;

#define sq(x) ((x)*(ll)(x))

struct pt { // ponto
	int x, y;
	pt(int x_ = 0, int y_ = 0) : x(x_), y(y_) {}
	bool operator < (const pt p) const {
		if (x != p.x) return x < p.x;
		return y < p.y;
	}
	bool operator == (const pt p) const {
		return x == p.x and y == p.y;
	}
	pt operator + (const pt p) const { return pt(x+p.x, y+p.y); }
	pt operator - (const pt p) const { return pt(x-p.x, y-p.y); }
	pt operator * (const int c) const { return pt(x*c, y*c); }
	ll operator * (const pt p) const { return x*(ll)p.x + y*(ll)p.y; }
	ll operator ^ (const pt p) const { return x*(ll)p.y - y*(ll)p.x; }
	friend istream& operator >> (istream& in, pt& p) {
		return in >> p.x >> p.y;
	}
};

ll sarea2(pt p, pt q, pt r) { // 2 * area com sinal
	return (q-p)^(r-q);
}

double polarea(vector<pt>& v) { // 2 * area do poligono
	ll ret = 0;
	for (int i = 0; i < v.size(); i++)
		ret += sarea2(pt(0, 0), v[i], v[(i + 1) % v.size()]);
	return abs(ret) / 2.0;
}

vector<pt> pts;
double DP[N+1][N+1];
bool seen[N+1][N+1];

double dp(int a, int b){
	if(a == b-1) return 0;

	if(seen[a][b]) return DP[a][b];
	seen[a][b] = 1;

	double res = 0x3f3f3f3f3f3f3f3f;

	for(int i = a+1; i < b; i++){
		double asq = sarea2(pts[a], pts[i], pts[b])*sarea2(pts[a], pts[i], pts[b])/4.0;
		res = min(res, dp(a, i) + dp(i, b) + asq);
	}

	return DP[a][b] = res;
}

void solve(){
	int n;
	cin >> n;

	pts.resize(n);

	for(int i = 0; i < n; i++){
		cin >> pts[i].x >> pts[i].y;
	}

	double a = polarea(pts);
	double mu = a / (n-2);
	double mu2 = mu*mu;

	memset(seen, 0, sizeof(seen));

	cout << fixed << setprecision(18) << 1.0/(n-2) * ( dp(0,n-1) - 2*mu*a + (n-2)*mu2 ) << endl;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t = 1;
	
	while(t--){
		solve();
	}
    return 0;

}