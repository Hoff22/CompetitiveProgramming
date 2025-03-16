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
	int n, a, b;
	scanf("%d %d %d", &n, &a, &b);

	int c = max(0, b-a-1);

	int cA = (n-a+1-c-(b>a));
	int cB = (b-c-(a<b));

	int dA = max(0,n/2-cA);
	int dB = max(0,n/2-cB);

	if(dA + dB > c){
		printf("-1\n");
		return;
	}

	set<int> sa;
	set<int> sb;
	set<int> sc;

	for(int i = a; i<= n; i++){
		if((a<i and i<b) or i == b) continue; 
		sa.insert(i);
	}
	for(int i = b; i >= 1; i--){
		if((a<i and i<b) or i == a) continue; 
		sb.insert(i);
	}
	for(int i = a+1; i < b; i++) sc.insert(i);

	for(int i = 1; i <= n/2; i++){
		if(sa.empty()){
			printf("%d ", *sc.begin());
			sc.erase(*sc.begin());
		}
		else{
			printf("%d ", *sa.begin());
			sa.erase(*sa.begin());
		}
	}
	for(int i = 1; i <= n/2; i++){
		if(sb.empty()){
			printf("%d ", *sc.begin());
			sc.erase(*sc.begin());
		}
		else{
			printf("%d ", *sb.begin());
			sb.erase(*sb.begin());
		}
	}


	printf("\n");
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