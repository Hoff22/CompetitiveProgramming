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

int rest_days[N+1];

void solve(){
	int n, d;
	scanf("%d %d", &n, &d);

	vector<int> rd_sorted;

	int last = 0;
	for(int i = 0; i < n; i++){
		int x;
		scanf("%d", &x);

		rest_days[i] = x - last - 1;

		rd_sorted.push_back(x - last - 1);

		last = x;
	}

	int last_window = d - last;

	sort(rd_sorted.begin(), rd_sorted.end());

	int ans = INF;
	for(int i = 0; i < n; i++){
		if(rest_days[i] == rd_sorted[0]){

			int new_window = rest_days[i] + rest_days[i+1] + 1;

			if(new_window >= rd_sorted[n-1]){
				// vou usar essa janela
				swap(rd_sorted[0], rd_sorted[n-1]);
				rd_sorted.pop_back(); // tirei a menor janela que eu to modificando

				if(new_window % 2){
					rd_sorted.push_back(window / 2 - 1);
					rd_sorted.push_back(window / 2);
				}
				else{
					rd_sorted.push_back(window / 2);
					rd_sorted.push_back(window / 2);
				}
			}
			else{
				// vou usar a maior janela fodase
				int window = rd_sorted[n-1];

				swap(rd_sorted[0], rd_sorted[n-1]);
				rd_sorted.pop_back(); // tirei a menor janela que eu to modificando

				if(window % 2){
					rd_sorted.push_back(window / 2 - 1);
				}
				else{
					rd_sorted.push_back(window / 2);
				}
			}

			break;
		}
	}
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}