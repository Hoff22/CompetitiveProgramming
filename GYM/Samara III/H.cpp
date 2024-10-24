#include <bits/stdc++.h>

#define N 200000
#define MAX 50
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define INFll 0x3f3f3f3f3f3f3f3fll
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

int a[N+1];
int last[MAX+1];

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 1; i <= n; i++){
		scanf("%d", &a[i]);
	}

	vector<int> ans;
	for(int i = n; i >= 1; i--){
		if(last[a[i]] == 0) ans.push_back(-1);
		else ans.push_back(a[last[a[i]]]);
		for(int j = a[i]-1; j >= 1; j--){
			last[j] = i;
		}
	}

	reverse(ans.begin(), ans.end());

	for(int i : ans){
		printf("%d ", i);
	}
	printf("\n");

    return 0;

}