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

vector<int> l;
vector<int> r;
int n, t;

int main(){
	
	scanf("%d %d", &n, &t);

	l.push_back(0);
	r.push_back(0);
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		if(x < 0){
			l.push_back(-x);
		}
		else{
			r.push_back(x);
		}
	}

	sort(l.begin(), l.end());
	sort(r.begin(), r.end());

	int ans = 0;
	for(int i = 0; i < l.size(); i++){
		if(l[i] > t/2) break;
		int j = upper_bound(r.begin(), r.end(), t-(2*l[i])) - r.begin() - 1;
		//printf("%d %d\n", i, j);
		if(l[i] + r[j] <= t) ans = max(ans, j+i);		
	}

	for(int i = 0; i < r.size(); i++){
		if(r[i] > t/2) break;
		int j = upper_bound(l.begin(), l.end(), t-(2*r[i])) - l.begin() - 1;
		//printf("%d %d\n", i, j);
		if(r[i] + l[j] <= t) ans = max(ans, j+i);		
	}

	printf("%d\n", ans);

    return 0;

}