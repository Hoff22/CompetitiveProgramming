#include<bits/stdc++.h>

#define N 100
#define INF 0x3f3f3f3f

using namespace std;

int x, t;
priority_queue<int> ans;

int main(){
	
	scanf("%d", &t);
	long long pow10[10];
	pow10[0] = 1;
	for(int i = 1 ; i < 10; i++){
		pow10[i] = pow10[i-1]*10;
	}

	while(t--){
		scanf("%d", &x);

		if(x > 45) printf("-1\n");
		else if(x < 10) printf("%d\n", x);
		else{


			int start = 10;
			while(x > 0 and start--){
				if(start <= x){
					x -= start;
					ans.push(start);
				}
			}

			if(x != 0) printf("-1\n");
			else{
				int last = 0;
				int i = 0;
				while(!ans.empty()){
					last += ans.top() * pow10[i];
					ans.pop();
					i++;
				}
				printf("%d\n", last);
			}

		}
	}

	return 0;
}