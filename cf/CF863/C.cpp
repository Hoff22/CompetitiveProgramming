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

void solve()
{
    	int n;
 
	cin >> n;
 
	vector<int> b(n-1);
	vector<int> a1;
 
	for(int i = 0; i < n-1; i++){
		cin >> b[i];
	}
 
	a1.push_back(b[0]);
	int lgood = 0;
	for(int i = 1; i < b.size(); i++){
		if(b[i] > a1.back() and !lgood){
			a1.push_back(a1.back());
			a1.push_back(b[i]);
			lgood = 1;
		}
		else{
			if(b[i] == a1.back() and i < b.size()-1){
				a1.push_back(b[i+1]);
				lgood = 1;
				continue;
			}
			else a1.push_back(b[i]);
			if(b[i] < a1.back()) lgood = 0;
		}
	}
 
	if(!lgood) a1.push_back(a1.back());

    for(int i : a1){
    	cout << i << " ";
    }
    cout << endl;
}

/*

2 5 4



2 2 4



*/

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t;
	cin >> t;
	
	while(t--){
		solve();
	}
    return 0;

}