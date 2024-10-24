#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){
		int a, b, k;
		vector<pair<int,int>> pairs;
		map<int, int> bois;
		map<int, int> girls;

		long long ans = 0;
		

		scanf("%d %d %d", &a, &b, &k);

		for(int i = 0; i < k; i++){
			int x;
			scanf("%d", &x);

			pairs.push_back({x, 0});
			bois[x]++;
		}
		for(int i = 0; i < k; i++){
			int x;
			scanf("%d", &x);

			pairs[i].second = x;
			girls[x]++;
		}

		for(int i = 0; i < k; i++){
			int boy = pairs[i].first;
			int girl = pairs[i].second;

			ans += k - (girls[girl]) - (bois[boy]) + 1;
		}

		printf("%lld\n", ans/2);
	}
	

    return 0;

}

		// 1 2
		// 1 3
		// 2 2
		// 3 4
		//
		// b 1 2 3
		//   2 1 1
		//
		// g 2 3 4
		//   2 1 1