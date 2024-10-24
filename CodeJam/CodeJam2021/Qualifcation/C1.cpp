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

//int a[N];
int n, c;

int check(vector<int> a){

	int sum = 0;
	for(int i = 0; i < n; i++){
		int mn = i;
		for(int j = i; j < n; j++){
			if(a[j] < a[mn]) mn = j;
		}

		sum += mn - i + 1;
		reverse(a.begin()+i, a.begin()+mn+1);
	}

	return sum-1;
}

vector<int> solve(int i, set<int> seen, vector<int> v){
	if(i >= n){
		if(check(v) == c) return v;
		v.clear();
		return v;
	}

	for(int j = 1; j <= n; j++){
		if(!seen.count(j)){
			seen.insert(j);
			v.push_back(j);
			
			vector<int> ans = solve(i+1, seen, v);

			if(ans.size() == n){
				return ans;
			}

			seen.erase(j);
			v.pop_back();
		}
	}
	v.clear();
	return v;
}


void run(int q){
	scanf("%d%d", &n,&c);

	set<int> s;
	vector<int> v;
	vector<int> ans = solve(0, s, v);

	printf("Case #%d: ", q);
	if(ans.size() != n){
		printf("IMPOSSIBLE\n");
	}
	else{
		for(int i = 0; i < n; i++){
			printf("%d", ans[i]);
			if(i != n-1) printf(" ");
			else printf("\n");
		}
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	for(int i = 1; i <= t; i++){
		run(i);
	}
    return 0;

}