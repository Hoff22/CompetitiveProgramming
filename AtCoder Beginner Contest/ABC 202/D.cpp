#include <bits/stdc++.h>

#define N 60
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

vector<char> ans;

long long choose[N+1][N+1];

void pascal(){
   for(int i = 0; i <= N; i++){
      choose[i][0] = 1;
   }
   for(int i = 1; i <= N; i++){
      for(int j = 1; j <= i; j++){
         choose[i][j] = (choose[i-1][j-1] + choose[i-1][j]) /*% MOD*/;
      }
   }
}

int main(){
	
	int a, b;
	long long k;
	scanf("%d %d %lld", &a, &b, &k);

	pascal();

	int n = a+b;

	long long p = choose[a+b][a];
	long long sum = 0;

	int i;
	for(i = 0; i < n; i++){
		if(b and sum + (p - choose[a+b-1][a]) <= k){
			sum += (p - choose[a+b-1][a]);
			p = choose[a+b-1][a];
			b--;
			ans.push_back('b');
			if(sum == k) break;
		}
		else if(a and sum + (p - choose[a+b-1][a-1]) <= k){
			sum += (p - choose[a+b-1][a-1]);
			p = choose[a+b-1][a-1];
			a--;
			ans.push_back('a');
			if(sum == k) break;
		}
	}

	for(i++; i < n; i++){
		if(a){
			a--;
			ans.push_back('a');
		}
		else if(b){
			b--;
			ans.push_back('b');
		}
	}

	for(int j = 0; j < ans.size(); j++){
		printf("%c", ans[j]);
	}
	printf("\n");


    return 0;

}