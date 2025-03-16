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

// 1 hour tle
// ..

void solve(){
	int n;
	scanf("%d", &n);

	vector<int> a;
	a.push_back(0);
	for(int i = 1; i <= n; i++){
		int x;
		scanf("%d",&x);

		a.push_back(x);
	}

	set<int> leftA;
	for(int i = 1; i <= n; i++) leftA.insert(i);
	for(int i = 1; i <= n; i++) if(a[i] != a[i-1]) leftA.erase(a[i]);
	for(int i = 1; i <= n; i++){
		if(a[i] != a[i-1]){
			printf("%d ", a[i]);
		}
		else{
			auto it = leftA.begin();

			printf("%d ", *it);
			leftA.erase(it);
		}
	}
	printf("\n");
	
	//vector<int> asnb;
	set<int> left;
	for(int i = 1; i <= n; i++) left.insert(i);

	for(int i = 1; i <= n; i++) if(a[i] != a[i-1]) left.erase(a[i]);

	int lastplaced = -1;
	for(int i = 1; i <= n; i++){
		if(a[i] != a[i-1]) {
			printf("%d ", a[i]);
			lastplaced = a[i];
		}
		else{

			auto it = --left.lower_bound(lastplaced);
			printf("%d ", *it);

			left.erase(it);
		}
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