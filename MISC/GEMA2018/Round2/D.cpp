#include <bits/stdc++.h>

#define N 10
#define MAX 10000000000
#define MOD (1000000000 + 7)
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int n;
string a[N];
map<string, int> m;

int fact(int i){
	if(i == 1) return 1;
	return fact(i-1)*i;
}

int main(){
	
	cin >> n;

	int ans = fact(n);

	for(int i = 0; i < n; i++){
		string s;
		cin >> s;
		a[i] = s;
		m[s]++;
	}

	for(auto i : m){
		ans /= fact(i.second);
	} 

	printf("%d\n", ans);
	
	return 0;
}