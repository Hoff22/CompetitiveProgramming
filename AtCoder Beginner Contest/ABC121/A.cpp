#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){
	
	int n;
	scanf("%d", &n);
	vector<pair<int,int>> X;
	vector<pair<int,int>> Y;

	for(int i = 0; i < n; i++){
		int x, y;
		scanf("%d %d", &x, &y);

		X.push_back({x,i});
		Y.push_back({y,i});
	}

	sort(X.begin(), X.end());
	sort(Y.begin(), Y.end());

	while(X.size() > 4){
		X.erase(X.begin()+(X.size()/2));
		Y.erase(Y.begin()+(Y.size()/2));
	}

	n = X.size();

	int best = 0;
	int ans = 0;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){

			int dmx = max(abs(X[i].first - X[j].first), abs(Y[i].first - Y[j].first));
			int dmn = min(abs(X[i].first - X[j].first), abs(Y[i].first - Y[j].first));

			if(best < dmx){
				ans = best;
				best = dmx;
			}
			else if(best > dmx and ans < dmx){
				ans = dmx;
			}
			if(ans < dmn){
				ans = dmn;
			}
		}
	}
	
	printf("%d\n", ans);

    return 0;

}