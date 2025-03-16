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


void solve(){
	int n;
	scanf("%d", &n);
	vector<long long> a;
	for(int i = 0; i < n+2; i++){
		long long x;
		scanf("%lld", &x);
		a.push_back(x);
	}
	sort(a.begin(), a.end());
	reverse(a.begin(), a.end());

	long long sum = 0;
	for(int i = 1; i < a.size(); i++){
		sum += a[i];
	}

	int good = 0;
	if(sum == a[1]*2){
		good = 1;
	}
	else{
		for(int i = 1; i < a.size(); i++){
			if(sum - a[i] == a[0]){
				good = 1;
				swap(a[i], a[1]);
				break;
			}
		}
	}

	if(good){
		for(int i = 2; i < a.size(); i++){
			printf("%lld ", a[i]);
		}
	}
	else{
		printf("-1");
	}
	printf("\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}