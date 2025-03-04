#include<bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

struct Client{

	int id, m;

	bool operator < (const Client b) const{
		return m < b.m;
	}
};

priority_queue<Client> pq;
bool served[500233];

int main(){
	int n, cur = 1, q, m, x = 0;
	scanf("%d", &n);

	while(n--){
		scanf("%d", &q);

		if(q == 1){
			scanf("%d", &m);
			x++;
			pq.push({x, m});
		}
		if(q == 2){
			while(served[cur]) cur++;
			served[cur] = true;
			printf("%d ", cur);
		}
		if(q == 3){
			while(served[pq.top().id]) pq.pop();
			served[pq.top().id] = true;
			printf("%d ", pq.top().id);
			pq.pop();
		}
	} 

	return 0;
}
