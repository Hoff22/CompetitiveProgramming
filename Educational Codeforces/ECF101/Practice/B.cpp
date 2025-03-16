#include <bits/stdc++.h>

#define N 100000
#define K 18
#define INF 0x3f3f3f3f

using namespace std;

long long n;
bool seen[10];

int main(){

	int t;

	cin >> t;

	while(t--){

		cin >> n;

		int i = 0;
		while(i < 10){
			memset(seen, 0, sizeof(seen));

			long long temp = n;

			while(temp){ //O(18)
				seen[temp % 10] = true;
				temp /= 10;
			}

			// for(i = 1; i < 10; i++){ //O(18)
			// 	printf("%d ", seen[i]);
			// }

			for(i = 1; i < 10; i++){ //O(18)
				if(seen[i]){
					if(n % i != 0) break;
				}
			}

			n++;
		}

		printf("%lld\n", n - 1);
	}


	return 0;
}