#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define MOD 1000000007
#define PAR 0
#define IMPAR 1

using namespace std;

long long factMOD(int x){
	if(x == 1) return 1; 
	return (x * factMOD(x-1)) % MOD;
}

long long quick_power(int a, int b){
	long long ans = 1;

	while(b){
		if(b & 1){
			ans = 1ll * ans * a % MOD;
		}
		
		a = 1ll * a * a % MOD;
		
		b >>= 1;
	}

	return ans;
}

long long choose(int n, int k){
	return factMOD(n) * quick_power(factMOD(k), MOD - 2) % MOD * quick_power(factMOD(n - k), MOD - 2) % MOD;
}

int main(){
	
	int t;
	scanf("%d", &t);

	while(t--){

		int n, k;
		scanf("%d %d", &n, &k);

		map<int,int> count;
		vector<int> v;

		for(int i = 0; i < n; i++){

			int x;
			scanf("%d", &x);

			count[x]++;
			if(count[x] == 1){
				v.push_back(x);
			}
		}

		sort(v.begin(), v.end());

		long long ans = 1;
		for(int i = (int)v.size() - 1; i >= 0 and k > 0; i--){
			if(k >= count[v[i]]){
				//ans *= 1;
				k -= count[v[i]];
			}
			else{
				ans = choose(count[v[i]], k);
				break;
			}
		}

		printf("%lld\n", ans);

	}
	

    return 0;

}