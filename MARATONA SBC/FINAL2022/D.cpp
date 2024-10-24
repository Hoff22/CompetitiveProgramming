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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n, h, w;
    cin >> n >> h >> w;

    for(int i = 0; i < 2*n; i+=2){
    	string a, b;
    	cin >> a >> b;

    	if(a == "Y" or w == 0){
    		cout << "Y ";
    		h--;
    		w++;
    	}
    	else{
    		cout << "N ";
    	}

    	if(b == "Y" or h == 0){
    		cout << "Y ";
    		w--;
    		h++;
    	}
    	else{
    		cout << "N ";
    	}

    	cout << endl;
    }


    return 0;

}