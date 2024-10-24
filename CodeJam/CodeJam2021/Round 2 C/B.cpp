#include <bits/stdc++.h>

#define N 200000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define PAR 0
#define IMPAR 1

using namespace std;

string n;
// 1 2 3 4 5

int check(int x){
	char last = '0';
	for(int i = 0; i < n.length()-x; i+=x){
		if(n[i] < last){
			return 0;
		}
		last = n[i];
	}
	return 1;
}

void solve(int q){
	cin >> n;
	
	int go = 1;
	while(go){
		for(int i = 1; i <= n.length()/2; i++){
			string last = n.substr(0,i);
			int good = 1;
			for(int j = 0; j < n.length()-i; j+=i){
				if(last >= n.substr(j, i)){
					good = 0;
					break;
				}

				last = n.substr(j, i);
			}
			if(good){
				go = 0;
				break;
			}
		}

		int add = 1;
		int j = n.length()-1;
		while(add and j >= 0){
			n[j] += 1;
			if(n[j] <= '9'){
				add = 0;
			}
			else{
				n[j] = '0';
			}
			j--;
		}
		if(add){
			string temp = "1";
			temp += n;
			n = temp;
		}
	}

	cout << "Case " << q << ": " << n << endl;
}

int main(){
	
	int t;
	cin >> t;
	
	for (int i = 1; i <= t; i++){
		solve(i);
	}
    return 0;

}