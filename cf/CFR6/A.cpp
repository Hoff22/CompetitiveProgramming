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
	
    int n;
    cin >> n;

    while(n--){
    	string s;
    	cin >> s;

    	int sum = 0;
    	int z = 0;
    	int eve = 0;
    	for(int i = 0; i < s.size(); i++){
    		sum += (s[i] - '0');
    		z += (s[i] == '0');
    		eve += ((s[i] - '0') % 2 == 0 and (s[i] != '0'));
    	}

    	if(sum % 3 == 0 and ((z > 0 and eve > 0) or (z > 1))){
    		cout << "red\n";
    	}
    	else{
    		cout << "cyan\n";
    	}


    }

    return 0;

}