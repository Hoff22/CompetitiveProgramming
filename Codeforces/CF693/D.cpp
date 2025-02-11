#include<bits/stdc++.h>

#define N 100
#define INF 0x3f3f3f3f

using namespace std;

int main(){
	
	int t;
	scanf("%d",&t);

	while(t--){
		priority_queue<int> evens;
		priority_queue<int> odds;
		int n;
		long long a, b;
		int round = 0;

		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			int num;
			scanf("%d", &num);

			if(num % 2){
				odds.push(num);
			}
			else evens.push(num);
		}

		a = b = 0;

		while(round < n){
			if(evens.empty()) evens.push(0);
			else if(odds.empty()) odds.push(0);

			if(round % 2){
			// BOB TURN, WANTS ODDS
				if(odds.top() > evens.top()){
					b += odds.top();
					odds.pop();
				}
				else{
					evens.pop();
				}
			}
			else{
			// ALICE TURN. WANTS EVENS
				if(evens.top() > odds.top()){
					a += evens.top();
					evens.pop();
				}
				else{
					odds.pop();
				}
			}

			round++;
		}

		// 2 2 2 2
		// A B A B
      //A: 2 2 4 4
      //B: 0 0 0 0

		if(a > b) printf("Alice\n");
		else if(b > a) printf("Bob\n");
		else printf("Tie\n");

	}
	

	return 0;
}