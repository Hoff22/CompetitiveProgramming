#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){

	int t;
	scanf("%d", &t);

	while(t--){
		// log(10^9) * 
		int n, m;
		//int ans = INF;
		int v[200000];
		vector<int> ones;
		vector<int> twos;

		ones.push_back(0);
		twos.push_back(0);

		scanf("%d %d", &n, &m);

		for(int i = 1; i <= n; i++){
			scanf("%d", &v[i]);
		}

		for(int i = 1; i <= n; i++){
			int x;
			scanf("%d", &x);

			if(x == 1){
				ones.push_back(v[i]);
			}
			else{
				twos.push_back(v[i]);
			}
		}

		sort(ones.begin(), ones.end());
		sort(twos.begin(), twos.end());
		reverse(ones.begin(), ones.end());
		reverse(twos.begin(), twos.end());

		for(int i = 1; i <= twos.size(); i++){
			twos[i] += twos[i-1];
		}
		for(int i = 1; i <= ones.size(); i++){
			ones[i] += ones[i-1];
		}


		int x1 = (int)ones.size()-1;
		int x2 = (int)twos.size()-1;

		for(int i = 0; i < ones.size()-1; i++){
			// amount left >= m - ones[i];

			int l = 0;
			int r = twos.size() - 2;
			int mid;

			while(l < r){
				mid = (r + l) / 2;
					
				if(m - ones[i] <= 0){
					l = -1;
					break;
				}

				if(twos[mid] >= m - ones[i]){
					r = mid;
				}
				else{
					l = mid + 1;
				}
			}

			if((i + 1) + (l + 1) * 2 < x1 + 2 * x2 and twos[l] + ones[i] >= m){
				x1 = i + 1;
				x2 = l + 1;
			}
		}


		if(ones[ones.size()-1] + twos[twos.size()-1] >= m) printf("%d\n", x1 + 2 * x2);
		else printf("-1\n");

	}
	// ordena a lista dos 1 e dos 2 por ordem de a;
	// sempre pega o maior entre as duas até chegar a M;
	// se o maior for da lista dos 2, testa se a soma do atual com prox da lista 1 não é melhor;
    return 0;

}

// 2 2
// 3 1
//
// 4 
//
//
//