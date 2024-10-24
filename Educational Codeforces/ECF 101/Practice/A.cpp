#include<bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

int main(){

	int n, t;
	string s;

	scanf("%d", &t);

	while(t--){
		cin >> n;
		cin >> s;

		int count = 0;
		for(int i = n-1; i >= 0; i--){
			if(s[i] == ')') count++;
			else break;
		}

		if(count > n - count) printf("Yes\n");
		else printf("No\n");
	}

	return 0;
}