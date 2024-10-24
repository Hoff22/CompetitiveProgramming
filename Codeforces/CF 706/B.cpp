#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD (1e9 + 7);
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

void solve(){
	set<int> s;
	int n, k;
	scanf("%d %d", &n, &k);

	int maxi = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d",&x);
		s.insert(x);
		maxi = max(x, maxi);
	}
	int mex = 0;
	for (set<int>::iterator it=s.begin(); it!=s.end(); ++it){
		if(*it == mex) mex++;
	}


	if(mex > maxi){
		printf("%d\n", (int)s.size() + k);
	}
	else if(mex + 1 == maxi){
		printf("%d\n", (int)s.size());
	}
	else{
		printf("%d\n", (int)s.size() + (!s.count((mex+maxi+1)/2) and k));
	}

}

int main(){
	
	int t;
	scanf("%d", &t);
	while(t--){
		solve();
	}
    return 0;

}