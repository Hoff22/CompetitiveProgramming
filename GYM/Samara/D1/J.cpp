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

int pA[101];
int pB[101];

int main(){
	
	int a[4] = {1, 2, 2, 2};
	int b[5] = {3 ,3, 1, 1, 1};

	for(int i = 0; i < 4; i++) pA[a[i]]++;
	for(int i = 0; i < 5; i++) pB[b[i]]++;

	// for(int i = 0; i < 4; i++){
	// 	for(int j = 0; j < 4; j++){
	// 		if(i != j){
	// 			for(int k = 0; k < 4; k++){
	// 				if(k != i and k != j){
	// 					pA[a[i]+a[j]+a[k]]++;
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	// for(int i = 0; i < 5; i++){
	// 	for(int j = 0; j < 5; j++){
	// 		if(i != j){
	// 			for(int k = 0; k < 5; k++){
	// 				if(k != i and k != j){
	// 					pB[b[i]+b[j]+b[k]]++;
	// 				}
	// 			}
	// 		}
	// 	}
	// }

	int va = 0;
	int vb = 0;
	for(int i = 1; i <= 100; i++){
		for(int j = 1; j <= 100; j++){
			if(j > i) va += pA[j] * pB[i];
			else vb += pA[j] * pB[i];
		}
	}

	printf("va: %d  vb: %d\n", va, vb);

    return 0;

}