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

int main(){
	int n;
	scanf("%d", &n);

	vector<int> ans;
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n; j++){
			int x;
			scanf("%d", &x);

			if(i == j){
				for(int y = 1; y*y <= x; y++){
					if(y*y == x){
						ans.push_back(y);
						break;
					}
				}
			}
		}
	}

	for(int i : ans){
		printf("%d ", i);
	}
	printf("\n");
    return 0;

}