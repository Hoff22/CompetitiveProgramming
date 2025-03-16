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

int a[4];

int main(){
	
	for(int i = 0; i < 4; i++){
		char c;
		scanf(" %c",  &c);

		a[i] = c - '0';
	}
	int equal = 1;
	for(int i = 0; i < 3; i++){
		if(a[i+1] != a[i]){
			equal = 0;
			break;
		}
	}

	int seq = 1;
	for(int i = 0; i < 3; i++){
		if((a[i]+1)%10 != a[i+1]){
			seq = 0;
			break;
		}
	}
	if(!seq and !equal){
		printf("Strong\n");
	}
	else{
		printf("Weak\n");
	}
    return 0;

}