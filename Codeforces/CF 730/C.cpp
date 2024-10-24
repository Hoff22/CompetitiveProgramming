#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define SCALE (10e+6)
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int c, m, p, v;

long double dfs(int C, int M){

	long double r = (SCALE-C-M)/SCALE;
	//printf("%lld %lld\n", C, M);
	if(C > 0){
		if(C > v){
			if(M > 0){
				r += (C/SCALE)*(1+dfs(C-v, M+v/2));
			}
			else{
				r += (C/SCALE)*(1+dfs(C-v, 0));
			}
		}
		else{
			if(M > 0){
				r += (C/SCALE)*(1+dfs(0, M+C/2));
			}
			else{
				r += (C/SCALE)*(1+dfs(0, 0));
			}
		}
	}
	if(M > 0){
		if(M > v){
			if(C > 0){
				r += (M/SCALE)*(1+dfs(C+v/2, M-v));
			}
			else{
				r += (M/SCALE)*(1+dfs(0, M-v));
			}
		}
		else{
			if(C > 0){
				r += (M/SCALE)*(1+dfs(C+M/2, 0));
			}
			else{
				r += (M/SCALE)*(1+dfs(0, 0));
			}
		}
	}

	return r;
}


int main(){
	
	int t;
	cin >> t;
	
	while(t--){

		long double tc, tm, tp, tv;
		cin >> tc >> tm >> tp >> tv;

		c = round(tc*SCALE);
		m = round(tm*SCALE);
		p = round(tp*SCALE);
		v = round(tv*SCALE);


		cout << setprecision(12) << fixed << dfs(c, m) << endl;
	}
    return 0;

}