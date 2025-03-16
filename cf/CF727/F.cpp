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

void solve(){
    int n;
    scanf("%d", &n);
    
    int x = 9;
    for(int i = 0; i < n; i++){
        if(i == 0) printf("%d",9);
        else if(i == 1) printf("%d",8);
        else{
        	printf("%d", x % 10);
        	x++;
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