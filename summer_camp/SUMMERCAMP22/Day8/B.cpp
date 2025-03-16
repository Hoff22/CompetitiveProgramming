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

ifstream in; //RIDICULO

void solve(){
	int n;
	in >> n;

	char a[N+1];
	char b[N+1];

	for(int i = 0; i < n; i++){
		in >> a[i];
	}
	for(int i = 0; i < n; i++){
		in >> b[i];
	}

	int caso0 = 0;
	int caso1 = 0;
	int cnt = 0;
	for(int i = 0; i < n; i++){
		if(a[i] == b[i]){
			if(a[i] == '1'){
				caso1++;
			}
			else if(a[i] == '0'){
				caso0++;
			}
		}
		else{
			cnt++;
		}
	}

	cout << cnt + min(caso0, caso1)*2 << endl;
}

int main(){
	
	in.open("hamming.in", ifstream::in);	

	int t;
	in >> t;
	
	while(t--){
		solve();
	}

	in.close();
    return 0;

}