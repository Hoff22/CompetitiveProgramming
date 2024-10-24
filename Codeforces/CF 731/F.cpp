#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define fi first
#define se second


using namespace std;

int t;
int freq[MAX+1];
int freqfreq[N+1];
int seenfreq[MAX+1];
vector<int> facts[MAX+1];

void initFacts(){
	for(int i = 2; i <= MAX; i++){
		if(facts[i].size() == 0){
			for(int j = i; j <= MAX; j+=i){
				facts[j].push_back(i);
			}			
		}
	}
}

bool gcdGood(int n){
	return (freqfreq[n] > 0);
}

void add(int x){
	for(int f : facts[x]){ // ADD
		if(seenfreq[f] != t) freq[f] = 0;
		seenfreq[f] = t;
		
		freqfreq[freq[f]]--;
		freq[f]++;
		freqfreq[freq[f]]++;
	}
}

void remove(int x){
	for(int f : facts[x]){ // REMOVE
		if(seenfreq[f] != t) freq[f] = 0;
		seenfreq[f] = t;
	
		freqfreq[freq[f]]--;
		freq[f]--;
		freqfreq[freq[f]]++;
	}
}

void solve(){
	
	int n;
	scanf("%d", &n);
	vector<int> a;

	memset(freqfreq, 0, sizeof(int)*(n+1));

	int k = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a.push_back(x);
		k = __gcd(k,x);
	}

	for(int i = 0; i < n; i++) a[i] /= k;
	for(int i = 0; i < n; i++) a.push_back(a[i]);

	int ans = 0;
	for(int i = 0, j = 0; i < 2*n; i++){
		add(a[i]);
		for(; j <= i; j++){
			if(gcdGood(i-j+1)) break;
			remove(a[j]);
		}
		ans = max(ans, i-j+1);
		if(ans == n) break;
	}
	
	printf("%d\n", ans);

}

int main(){
	
	scanf("%d", &t);
	
	initFacts();
	//facts[1].push_back(1);

	while(t--){
		solve();
	}
    return 0;

}