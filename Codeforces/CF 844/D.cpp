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

void solve(){
	int n;
	scanf("%d", &n);

	vector<long long> a(n);

	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
	}

	int ans = 0;
	for(int i = 0; i < n; i++){
		map<long long, int> cnt;

		for(int j = i+1; j < n; j++){

			long long dif = a[j] - a[i];
			//printf("%lld - %lld : \n", a[i], a[j]);
			for(int d = 1; d * d <= dif; d++){

				if(dif % d == 0){

					long long div1 = d;
					long long div2 = dif/d;
					//printf("\t d : %lld * %lld\n", div1, div2);
					

					if((div2-div1) % 2 == 0){

						long long y = (div2 - div1)/2;
						if(y * y < a[i]) continue;

						cnt[(y * y) - a[i]]++;
						ans = max(ans, cnt[(y * y) - a[i]]);
						//printf("\tcontou %lld\n", (y*y)-a[i]);
						//break;
					}
				}
			}
		}
	}


	printf("%d\n", ans + 1);

}

/*

						2  5  10  17  50
				4 7 12 19 52
			



*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}