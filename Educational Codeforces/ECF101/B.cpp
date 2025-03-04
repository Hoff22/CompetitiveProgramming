#include<bits/stdc++.h>

#define N 100000
#define INF 0x3f3f3f3f

using namespace std;

vector<int> red;
vector<int> blue;
int r, b;

int lisRED(){
		
	int ans = 0;
	for(int i = 1; i <= red.size(); i++){
		int sum = 0;
		for(int j = 0; j < i; j++){
			sum += red[j];
		}
		ans = max(ans, sum);
	}

	return ans;
}

int lisBLUE(){
	
	int ans = 0;
	for(int i = 1; i <= blue.size(); i++){
		int sum = 0;
		for(int j = 0; j < i; j++){
			sum += blue[j];
		}
		ans = max(ans, sum);
	}

	return ans;
}

int main(){

	int t;
	scanf("%d", &t);

	while(t--){
		red.clear();
		blue.clear();

		scanf("%d", &r);
		int n;
		for(int i = 0; i < r; i++){
			scanf("%d", &n);
			red.push_back(n);
		}

		scanf("%d", &b);
		for(int i = 0; i < b; i++){
			scanf("%d", &n);
			blue.push_back(n);
		}

		if(lisRED() <= 0 or lisBLUE() <= 0){
			printf("%d\n", max(lisRED(), lisBLUE()));
		}
		else{
			printf("%d\n", lisRED() + lisBLUE() );
		}

	}
	

	return 0;
}