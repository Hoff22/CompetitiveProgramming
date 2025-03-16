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

char a[N+1];

int main(){
	
	int n;
	scanf("%d", &n);

	int wt, bk;
	wt = bk = 0;
	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		if(c == 'W'){
			a[i] = 1;
			wt++;	
		} 
		else{
			bk++;
		}
	}

	if((wt % 2) and (bk % 2)){
		printf("-1\n");
		return 0;
	}
	if(bk == 0 or wt == 0){
		printf("0\n");
		return 0;
	}

	vector<int> ans;

	int last = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == 0){
			if(last < i){
				for(int j = i-1; j >= last; j--){
					ans.push_back(j + 1);
				}
			}
			last++;
		}
	}
	
	if(bk % 2 == 0){
		for(int i = 0; i < bk; i+=2){
			ans.push_back(i + 1);
		}
	}
	else{
		for(int i = bk; i < n; i+=2){
			ans.push_back(i + 1);
		}
	}

	printf("%d\n", (int)ans.size());
	if(ans.size()){
		for(int i = 0; i < ans.size(); i++){
			printf("%d ", ans[i]);
		}
		printf("\n");
	}
    
    return 0;

}