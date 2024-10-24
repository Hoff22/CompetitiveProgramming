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

long long p10[12];

long long hl(long long a){
	int r = 0;
	while(a){
		a /= 10;
		r++;
	}
	return r;
}

void solve(int q){
	int n;
	long long ans = 0;
	cin >> n;

	long long last = 0;
	for(int i = 0; i < n; i++){
		long long x;
		cin >> x;
		
		if(x == last) {
			x *= 10;
			ans++;
		}
		else if(last > x){
			long long tempL = last;
			long long sum = 0;
			int j = 0;
			int good = 0;
			while(hl(last) > hl(x)){
				good = 1;
				sum += (tempL%10) * p10[j];
				j++;
				tempL /= 10;

				x *= 10;
				ans++;
			}
			//
			1234
			   1
			1000
			 234
			//printf("%lld %lld\n", x, sum);
			if(x < last){
				if(tempL == last or x+sum+1 < last or hl(sum) < hl(sum+1)){
					x *= 10;
					ans++;
				}
				else{
					x += sum+1;
				}
			}
			if(x == last){
				if(good){
					x += 1;
				}
				else{
					x *= 10;
					ans++;
				}
			}

			//printf("%lld\n", x);
		}

		last = x;
	}

	printf("Case #%d: %lld\n",q, ans);
}

int main(){
	
	p10[0] = 1;
	for(int i = 1; i <= 11; i++){
		p10[i] = p10[i-1]*10;
	}

	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}