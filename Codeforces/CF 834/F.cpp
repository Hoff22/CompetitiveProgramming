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

	long long n, p;
	scanf("%lld %lld", &n, &p);

	vector<long long> a(n);
	set<long long> s;


	for(int i = 0; i < n; i++){
		scanf("%lld", &a[i]);
		s.insert(a[i]);
	}

	long long mx = p-1;
	while(s.count(mx)){
		mx--;
	}

	if(mx < 0) mx = 0;

	long long mn = 0;
	while(s.count(mn)){
		mn++;
	}

	if(mn >= p) mn = p-1;

	if(mx < mn){
		printf("0\n");
		return;
	}

	// mn = primeiro que nao ta
	// mx = ultimo que nao ta

	if(a[n-1] <= mn){
		printf("%lld\n", mx - a[n-1]);
	}
	else{
		if(a[n-1] < mx){
			long long dist = (p - a[n-1]);
			
			long long c = 1;
			int i = n-2;
			while(c and i >= 0){
				a[i] = (a[i] + 1) % p;
				s.insert(a[i]);
				
				if(a[i] == 0) c = 1;
				else c = 0;
				i--;
			}
			if(c) s.insert(1);

			mn = max(a[n-1]-1, 0ll) ;
			while(s.count(mn)){
				mn--;
			}

			if(mn < 0) mn = 0;

			printf("%lld\n", dist + mn);
		}
		else{
			long long dist = (p - a[n-1]);
				
			long long c = 1;
			int i = n-2;
			while(c and i >= 0){
				a[i] = (a[i] + 1) % p;
				s.insert(a[i]);
				
				if(a[i] == 0) c = 1;
				else c = 0;
				i--;
			}
			if(c) s.insert(1);

			mx = p-1;
			while(s.count(mx)){
				mx--;
			}

			if(mx < 0) mx = 0;

			printf("%lld\n", dist + mx);
		}
	}
	
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