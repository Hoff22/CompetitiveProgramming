#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;

vector<int> a;
vector<int> b;

void printfV(vector<int> k){
	for(int i = 0; i < k.size(); i++){
		printf("%d ", k[i]);
	}
	printf("\n");
}

vector<int> fold(vector<int> cur, int i){
	int s = max(i, (int)cur.size()-i);
	vector<int> vl(s,0), vr(s,0);

	for(int j = 0; j < i; j++){
		vl[s-j-1] = cur[i-j-1];
	}
	for(int j = i; j < cur.size(); j++){
		vr[s-(j-i)-1] = cur[j];
	}
	//printfV(vl);
	//printfV(vr);

	vector<int> vnext(s,0);

	for(int j = 0; j < s; j++){
		vnext[j] = vr[j] + vl[j];
	}

	//printfV(vnext);
	return vnext;
}

bool dfs(vector<int> cur){
	if(cur.size() == b.size()){
		if(cur == b) return 1;
		reverse(cur.begin(), cur.end());
		if(cur == b) return 1;
		return 0;
	}

	for(int i = 1; i < cur.size(); i++){
		if(dfs(fold(cur, i))) return 1;
	}

	return 0;
}

int main(){
	
	int n;
	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		a.push_back(x);
	}
	
	int m;
	scanf("%d", &m);

	for(int i = 0; i < m; i++){
		int x;
		scanf("%d", &x);
		b.push_back(x);
	}

	// printfV(a);
	// fold(a, 2);

	if(dfs(a)) printf("S\n");
	else printf("N\n");

    return 0;

}