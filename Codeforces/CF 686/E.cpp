#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;



int main(){
	
	int n;
	scanf("%d", &n);

	vector<int> v;
	int last = -1;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);
		v.push_back(x);

		if(x >= 0){
			if(i-last > 1){
				sort(v.begin()+last+1, v.end()-1);
				reverse(v.begin()+last+1, v.end()-1);
			}
			last = i;
		}
	}

	int ans = 0;
	long long life = 0;

	for(int i = 0; i < n; i++){
		if(life+v[i] >= 0){
			life += v[i];
			ans++;
		}
	}

	printf("%d\n", ans);


    return 0;

}