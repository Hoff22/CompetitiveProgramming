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

void solve(){
	string n;
	cin >> n;

	int zero = -1;
	int five = -1;

	reverse(n.begin(), n.begin()+n.size());

	for(int i = 0; i < n.size(); i++){
		if(n[i] == '0') {
			if(zero == -1) zero = i;
			else{
				cout << zero + (i-zero-1) << endl;		
				return;
			}
		}
		if(n[i] == '5'){
			if(five == -1){
				five = i;
			}
			if(zero != -1){
				cout << zero + (i-zero-1) << endl;		
				return;
			}
		}

		//cout << zero << " " << five << endl;

		if((n[i] == '7' or n[i] == '2') and five != -1){
			cout << five + (i-five-1) << endl;		
			return;
		}
	}
}

int main(){
	
	int t;
	
	cin >> t;	
	while(t--){
		solve();
	}
    return 0;

}