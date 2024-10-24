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

	sort(rd_sorted.begin(), rd_sorted.end());

	int last_wind = d - last;

	int countds = 0;
	int countss = 0;

	for(int i = 0; i < n; i++){
		if(rest_days[i] == rd_sorted[0] and rest_days[i+1] == rd_sorted[0]){
			countds++;
		}
		if(rest_days[i] == rd_sorted[0]){
			countss++;
		}
	}

	if(countss == 1){
		int ans1 = 0;
		int ans2 = 0;
		int can_use_last_wind = 1;
		for(int i = 0; i < n; i++){
			if(rest_days[i] == rd_sorted[0]){
				int new_wind;

				if(i == n-1){
					new_wind = rest_days[i] + last_wind + 1;
					can_use_last_wind = 0;
				} 
				else{
					new_wind  = rest_days[i] + rest_days[i+1] + 1;
				}

				if(new_wind > rd_sorted[n-1]){
					ans1 = new_wind;
				}
				else{
					ans1 = rd_sorted[n-1];
				}
			}
		}

		for(int i = 0; i < n; i++){
			if(rest_days[i+1] == rd_sorted[0]){
				int new_wind;

				if(i == n-1){
					new_wind = rest_days[i] + last_wind + 1;
					can_use_last_wind = 0;
				} 
				else{
					new_wind  = rest_days[i] + rest_days[i+1] + 1;
				}

				if(new_wind > rd_sorted[n-1]){
					ans2 = new_wind;
				}
				else{
					ans2 = rd_sorted[n-1];
				}
			}
		}

		int ans = max(ans1, ans2);

		if(ans <= last_wind and can_use_last_wind){
			rd_sorted.push_back(last_wind / 2);
		}
		else if(ans % 2){
			rd_sorted.push_back(ans / 2);
		}
		else{
			rd_sorted.push_back(ans / 2 - 1);
		}

		swap(rd_sorted[0], rd_sorted[n]);
		rd_sorted.pop_back();
	}
	else if(countss == 2 and countds == 1){
		for(int i = 0; i < n; i++){
			if(rest_days[i] == rd_sorted[0] and rest_days[i+1] == rd_sorted[0]){
				int new_wind;

				new_wind  = rest_days[i] + rest_days[i+1] + 1;

				int ans = 0;
				if(new_wind > rd_sorted[n-1]){
					ans = new_wind;
				}
				else{
					ans = rd_sorted[n-1];
					rd_sorted.push_back(new_wind);
				}

				if(ans <= last_wind){
					rd_sorted.push_back(last_wind / 2);
					rd_sorted.push_back(new_wind);
				}
				else if(ans % 2){
					rd_sorted.push_back(ans / 2);
				}
				else{
					rd_sorted.push_back(ans / 2 - 1);
				}


				rd_sorted.erase(rd_sorted.begin(), rd_sorted.begin() + 2);
			}
		}
	}
	else{
		printf("%d\n", rd_sorted[0]);
		return;
	}

	sort(rd_sorted.begin(), rd_sorted.end());

	printf("%d\n", rd_sorted[0]);

	// if(countds > 1){
	// 	printf("%d\n", rd_sorted[0]);
	// 	return;
	// }

	// if(countss == 2 and countds != 1){
	// 	printf("%d\n", rd_sorted[0]);
	// 	return;	
	// }
	// if(countss > 2){
	// 	printf("%d\n", rd_sorted[0]);
	// 	return;	
	// }

	
}

int main(){
	
	int t;
	scanf("%d", &t);
	
	while(t--){
		solve();
	}
    return 0;

}