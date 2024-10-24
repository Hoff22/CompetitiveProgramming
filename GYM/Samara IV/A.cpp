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

int main(){
	
	int n;
	scanf("%d", &n);
	
	vector<int> left;
	vector<int> right;

	for(int i = 2; i <= n; i++){
		printf("? %d %d", 1, i);
		fflush(stdin);
		char ans;
		scanf(" %c", &c);

		if(c == '<') left.push_back(i);
		else if(c == '>') right.push_back(i);
	}


    return 0;

}