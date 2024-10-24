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

typedef long double ll;

struct vec3{
	ll x,y,z;
	vec3() : x(0), y(0), z(0) {};
	vec3(ll X, ll Y, ll Z) : x(X), y(Y), z(Z) {};

	vec3 operator*=(const ll f){
		return vec3(this->x * f,this->y * f,this->z * f);
	}
	vec3 operator-=(const vec3& b){
		return vec3(this->x - b.x,this->y - b.y,this->z - b.z);
	}
	vec3 operator+=(const vec3& b){
		return vec3(this->x + b.x,this->y + b.y,this->z + b.z);
	}
	vec3 operator*(const ll b) {return *this *= b;}
	vec3 operator+(const vec3& b) {return *this += b;}
	vec3 operator-(const vec3& b) {return *this -= b;}
};

ostream& operator<<(ostream& os, const vec3& p){
	cout << "(" << p.x << "," << p.y << "," << p.z << ")"; 
	    return os;
}

ll cross(vec3 a, vec3 b){
	return a.x*b.y - a.y*b.x;
}

ll len(vec3 a){
	return sqrtl(a.x*a.x + a.y*a.y + a.z*a.z);
}

ll orient(vec3 a, vec3 b, vec3 c) {
    return cross(b-a, c-a);
}

bool properInter(vec3 a, vec3 b, vec3 c, vec3 d) {
    ll  oa = orient(c,d,a), 
        ob = orient(c,d,b),            
        oc = orient(a,b,c),            
        od = orient(a,b,d);      
    // Proper intersection exists iff opposite signs 
    ll soa = oa < 0 ? -1 : 1; 
    ll sob = ob < 0 ? -1 : 1; 
    ll soc = oc < 0 ? -1 : 1; 
    ll sod = od < 0 ? -1 : 1;
    if(oa == 0) soa = 0;
    if(ob == 0) sob = 0;
    if(oc == 0) soc = 0;
    if(od == 0) sod = 0;
    return (soa*sob < 0 && soc*sod < 0);
} 

void solve(){
	int n;
	cin >> n;
	vec3 apex, sun;
	cin >> apex.x >> apex.y >> apex.z;
	cin >> sun.x >> sun.y >> sun.z;

	// mult(apex, 2);
	// mult(sun, 2);

	vector<vec3> ps(n); 

	for(int i = 0; i < n; i++){
		cin >> ps[i].x >> ps[i].y;
		// mult(ps[i], 2);
	}

	if(apex.z == sun.z){
		cout << "S\n";
		return;
	}

	vec3 sp = apex + ((apex - sun) * (apex.z / (sun.z - apex.z)));


	vec3 far = vec3(-20000,0,0);

	// for(int i = 0; i < n; i++){
	// 	ps[i] = (ps[i] - sp) * 10000;
	// }
	sp = sp-(sp-vec3(apex.x, apex.y, 0))*0.0000001;
	// cout << sp << endl;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		cnt += properInter(sp,far,ps[i], ps[(i+1)%n]);
	}

	if(cnt % 2){
		cout << "N\n";
	}
	else{
		cout << "S\n";
	}
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