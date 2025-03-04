#include<bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

int n;
vector<int> a;
int seen[N+1];

int main(){

	scanf("%d", &n);

	for(int i = 0; i < n; i++){
		int num;
		scanf("%d", &num);

		a.push_back((num));
	}

	sort(a.begin(), a.end());

	int count = 1;
	
	for(int i = 1; i < n; i++){
		if(a[i] == a[i-1]) count++;
		else {
			seen[i-1] = true;
			continue;
		}
		for(int j = i-1; j >= 0; j--){
			if(!seen[j] and a[i] > a[j]){
				seen[j] = true;
				count--;
				break;
			}
		}
	}
// 86 86 86 86 86 89 89 89 89 89;
//             1        
	printf("%d\n", count);
}