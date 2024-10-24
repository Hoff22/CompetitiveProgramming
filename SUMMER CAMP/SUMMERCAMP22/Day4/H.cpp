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

long long v[N+1];
long long sufs[N+1];
vector<int> range[N+1];
long long allow[N+1];
long long eraseVal[N+1];
bool marked[N+1];

multiset<int> s;

int main(){

	
	int n, k;
	scanf("%d %d", &n, &k);

	for(int i = 1; i <= n; i++){
		scanf("%lld",(v+i));
		if(v[i] == 0) v[i] = 1;
		else marked[i] = 1;
		sufs[i] = sufs[i-1] + v[i];
	}

	int good = 1;
	for(int i = 1; i <= k; i++){
		int l, r;
		long long w;
		scanf("%d %d %lld", &l, &r, &w);

		range[l].push_back(i);
		range[r].push_back(-i);
		allow[i] = (sufs[r] - sufs[l-1]) - w;
		if(allow[i] < 0) good = 0;
	}

	if(!good){
		printf("Impossible\n");
		return 0;
	}

	int off = 0;
	for(int i = 1; i <= n; i++){
		// add no multiset
		for(int j = 0; j < range[i].size(); j++){
			if(range[i][j] > 0){
				// add
				int id = range[i][j];
				s.insert(allow[id] - off);
				eraseVal[id] = allow[id] - off;
			}
		}
		for(int j = 0; j < range[i-1].size(); j++){
			if(i > 1 and range[i-1][j] < 0){
				// remove
				int id = -range[i-1][j];
				s.erase(s.find(eraseVal[id]));
			}
		}

		if(marked[i]) continue;

		if(s.size() == 0 or *s.begin() + off >= 2){
			v[i] = -1;
			off -= 2;
		}
	}

	for(int i = 1; i <= n; i++){
		printf("%lld ", v[i]);
	}
	printf("\n");
	

    return 0;

}