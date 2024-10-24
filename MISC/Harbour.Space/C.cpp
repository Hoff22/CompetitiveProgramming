#include <bits/stdc++.h>

#define N 10
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

char s[N+2];
int bestA[N+2];
int bestB[N+2];
int worstA[N+2];
int worstB[N+2];

void solve(){
	for(int i = 1; i <= 10; i++){
		scanf(" %c", &s[i]);
	}

	// for(int i = 1; i <= 10; i++){
	// 	printf("%c", s[i]);
	// }

	// for(int i = 2; i <= 11; i++){
	// 	//printf("%c\n", s[i]);
	// 	if(i%2 == 0){ // team A
	// 		if(s[i] == '1'){
	// 			//printf("entrou\n");
	// 			worstA[i] = worstA[i-2] + 1;
	// 			bestA[i] = bestA[i-2] + 1;
				
	// 			worstB[i] = worstB[i-1];
	// 			bestB[i] = bestB[i-1];
	// 		} 
	// 		else if(s[i] == '0'){
	// 			worstA[i] = worstA[i-2];
	// 			bestA[i] = bestA[i-2];

	// 			worstB[i] = worstB[i-1];
	// 			bestB[i] = bestB[i-1];
	// 		}
	// 		else{
	// 			worstA[i] = worstA[i-2];
	// 			bestA[i] = bestA[i-2] + 1;

	// 			worstB[i] = worstB[i-1];
	// 			bestB[i] = bestB[i-1];
	// 		}
	// 	}
	// 	else{
	// 		if(s[i] == '1'){
	// 			worstB[i] = worstB[i-2] + 1;
	// 			bestB[i] = bestB[i-2] + 1;

	// 			worstA[i] = worstA[i-1];
	// 			bestA[i] = bestA[i-1];
	// 		} 
	// 		else if(s[i] == '0'){
	// 			worstB[i] = worstB[i-2];
	// 			bestB[i] = bestB[i-2];

	// 			worstA[i] = worstA[i-1];
	// 			bestA[i] = bestA[i-1];
	// 		}
	// 		else{
	// 			worstB[i] = worstB[i-2];
	// 			bestB[i] = bestB[i-2] + 1;

	// 			worstA[i] = worstA[i-1];
	// 			bestA[i] = bestA[i-1];
	// 		}
	// 	}

	// 	//printf("wa:%d ba:%d wb:%d bb:%d\n", worstA[i], bestA[i], worstB[i], bestB[i]);
	// }

	for(int i = 1; i <= 10; i++){
		bestA[i] = bestA[i-1];
		worstA[i] = worstA[i-1];
		if(i%2){
			if(s[i] == '1'){
				bestA[i]++;
				worstA[i]++;
			}
			else if(s[i] == '?'){
				bestA[i]++;
			}
		}
	}

	for(int i = 1; i <= 10; i++){
		bestB[i] = bestB[i-1];
		worstB[i] = worstB[i-1];
		if(i%2 == 0){
			if(s[i] == '1'){
				bestB[i]++;
				worstB[i]++;
			}
			else if(s[i] == '?'){
				bestB[i]++;
			}
		}
	}

	int rA = 5;
	int rB = 5;
	for(int i = 1; i <= 10; i++){
		if(i%2) rA--;
		else rB--;
		if(bestA[i] > worstB[i] + rB){
			printf("%d\n", i);
			return;
		}
		if(bestB[i] > worstA[i] + rA){
			printf("%d\n", i);
			return;
		}
	}

	printf("10\n");
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}