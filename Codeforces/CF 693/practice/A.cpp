#include<bits/stdc++.h>

#define N 100
#define INF 0x3f3f3f3f

using namespace std;
deque<int> q;

int main(){
		
	int t;
	scanf("%d", &t);

	while(t--){
		int n;
		int a;
		scanf("%d", &n);

		for(int i = 0; i < n; i++){
			scanf("%d", &a);
			q.push_back(a);
		}

		while(!q.empty()){
			printf("%d ", q.front());
			q.pop_front();
			if(!q.empty()){
				printf("%d ", q.back());
				q.pop_back();
			}
		}


	}

	return 0;
}