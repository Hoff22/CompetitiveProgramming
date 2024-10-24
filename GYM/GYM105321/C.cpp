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
	vec3 operator-(const vec3& b) {return *this -= b;}
	vec3 operator+(const vec3& b) {return *this += b;}
};

ostream& operator<<(ostream& os, const vec3& p){
	cout << "(" << p.x << "," << p.y << "," << p.z << ")"; 
	    return os;
}

ll dot(vec3 a, vec3 b){
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

ll cross2(vec3 a, vec3 b){
	return a.x*b.y - a.y*b.x;
}

vec3 cross(vec3 a, vec3 b){
	return vec3(a.y*b.z - a.z*b.y, a.z*b.x - a.x*b.z, a.x*b.y - a.y*b.x);
}

void mult(vec3& p, ll f){
	p.x *= f;
	p.y *= f;
	p.z *= f;
}

vec3 sub(vec3 a, vec3 b){
	return vec3(a.x-b.x, a.y-b.y, a.z- b.z);
}

vec3 add(vec3 a, vec3 b){
	return vec3(a.x+b.x, a.y+b.y, a.z+ b.z);
}

bool intersect_triangle(vec3 dir, vec3 origin, vec3 A, vec3 B, vec3 C) { 
	ll t, u, v;
	vec3 n;
	vec3 E1 = B-A;
	vec3 E2 = C-A;
	n = cross(E1,E2);
	ll det = -dot(dir, n);
	vec3 AO  = origin - A;
	vec3 DAO = cross(AO, dir);
	u =  dot(E2,DAO);
	v = -dot(E1,DAO);
	t =  dot(AO,n); 
	// if(det >= 0){
	// 	cout << origin << ": ";
	// 	cout << det << " " << u << " " << v << " " << t << " " << (u+v) << endl;
	// }
	return (det > 0 && t > 0 && u >= 0 && v >= 0 && (u+v) < det);
}

ll orient(vec3 a, vec3 b, vec3 c) {
    return cross2(b-a, c-a);
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

	for(vec3 p : ps){
		bool good = 0;
		vec3 t = p; // + (p-vec3(apex.x, apex.y, 0));
		vec3 d = sun - t;
		for(int i = 0; i < n; i++){
			if(intersect_triangle(d, t, ps[i], ps[(i+1)%n], apex)){
				good = 1;
				break;
			}
		}

		if(good){
			cout << "S\n";
			return; 
		}
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