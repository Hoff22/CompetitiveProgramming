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
	
	vector<int> a(4);
	for(int i = 0; i < 4; i++){
		scanf("%d", &a[i]);
	}

	do{
		if(a[0]-a[1] == a[2]-a[3]){
			printf("YES\n");
			return 0;
		}

	}while(next_permutation(a.begin(), a.end()));


	printf("NO\n");

    return 0;

}