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

typedef long long ll;

struct Point {
    double x, y;

    /* O(1) - Cross product. */
    double operator^(const Point &b) const {
        return this->x * b.y - this->y * b.x;
    }
    Point operator-(const Point &b) const {
    	Point r;
    	r.x = this->x - b.x;
    	r.y = this->y - b.y;
        return r;
    }
    Point operator+(const Point &b) const {
    	Point r;
    	r.x = this->x + b.x;
    	r.y = this->y + b.y;
        return r;
    }
    Point operator*(const double s) const {
    	Point r;
    	r.x = this->x * s;
    	r.y = this->y * s;
        return r;
    }
};

/* O(N) - Computes the area of a convex or non-convex polygon, being it simple or self-intersecting.
   Expects a polygon either in clockwise or in counter-clockwise order. */
double shoelace(const vector<Point> &p) {
    double ans = 0;

    for (int i = 0; i < p.size(); i++) {
        ans += p[i] ^ p[(i + 1) % p.size()];
    }

    return abs(ans) / 2.0;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    double a;
    int n;

    cin >> a >> n;

    vector<Point> points; 

    for(int i = 0; i < n; i++){
    	double x, y;
    	cin >> x >> y;
    	points.push_back({x,y});
    }

    double total = shoelace(points);
    double total_tris = 0.0;
    for (int i = 0; i < points.size(); i++) {
        vector<Point> tri(3);
		tri[0] = points[i];
        tri[1] = points[(i+1)%points.size()];
        tri[2] = points[(i-1+points.size())%points.size()];

    	// cout << tri[0].x <<","<< tri[0].y << " " << tri[1].x <<","<< tri[1].y << " " << tri[2].x <<","<< tri[2].y << endl;

        total_tris += shoelace(tri);
    }

    ll l = 2ll*MAX;
    ll r = 1000ll*MAX;
    ll ans = 0;

    cout << fixed << setprecision(18);

    //cout << "total: " << total << endl;

    while(l <= r){
    	ll m = l + (r - l) / 2;

    	double cur = total_tris * (1.0*MAX/m) * (1.0*MAX/m);

	    // cout << "l: " << l << " r: " << r << endl;
    	// cout << "\tm: " << m << " cur: " << cur << endl;

    	// cout << "\t(total-cur)/total: " << (total-cur)/total << endl;
	    
	    if((total-cur)/total <= a){
	    	ans = m;
	    	l = m+1;
	    }
	    else{
	    	r = m-1;
	    }
    }

    cout << 1.0*ans/MAX << endl;

    return 0;

}