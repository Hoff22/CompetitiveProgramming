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
	scanf("%d",&n);

	vector<int> v1(n/2);
	vector<int> v2(n/2);
	set<int> s;

	bool good = 1;
	for(int i = 0; i < n/2; i++){
		scanf("%d", &v1[i]);
		if(s.count(v1[i])){
			good = 0;
		}
		s.insert(v1[i]);
	}

	if(!good){
		printf("-1\n");
		return;
	}


	set<int> remain;
	for(int i = 1; i <= n; i++){
		if(s.count(i) == 0) remain.insert(i);
	}

	for(int i = n/2-1; i >= 0; i--){
		set<int>::iterator j = remain.lower_bound(v1[i]);
		if(j == remain.begin()){
			printf("-1\n");
			return;
		}

		j--;

		v2[i] = *j;

		remain.erase(*j);
	}


	// printf("depois:\n");
	for(int i = 0; i < n/2; i++){
		printf("%d ", min(v1[i], v2[i]));
		printf("%d ", max(v1[i], v2[i]));
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