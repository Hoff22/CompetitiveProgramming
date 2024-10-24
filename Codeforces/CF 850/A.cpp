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
	long long n;
	scanf("%lld", &n);

	long long wA,bA,wB,bB;
	wA=bA=wB=bB=0;

	wA = 1;
	long long i = 2;
	long long p = 1;
	long long sf = 1;
	long long t = n;
	n--;
	while(n > 0){
		long long cur = min(t, (sf + i + (i+1)));
		// printf("i: %lld | %lld %lld %lld %lld\n", i, wA, bA, wB, bB);
		// printf("cur: %lld\n", cur);
		// printf("sf: %lld\n\n", sf);
		if(p == 1){
			bB += (cur/2)-(sf/2);
			wB += (cur - sf) - ((cur/2)-(sf/2));
		}
		else{
			bA += (cur/2)-(sf/2);
			wA += (cur - sf) - ((cur/2)-(sf/2));	
		}

		n -= (i+i+1);
		p *= -1;
		i += 2;
		sf = cur;
	}

	printf("%lld %lld\n", wA+ bA, wB+ bB);
}

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