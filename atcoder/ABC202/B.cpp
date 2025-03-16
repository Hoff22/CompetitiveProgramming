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


int main(){
	
	string s;

	cin >> s;

	reverse(s.begin(), s.end());

	for(int i = 0; i < s.length(); i++){
		if(s[i] == '9') s[i] = '6';
		else if(s[i] == '6') s[i] = '9';
	}

	cout << s << endl;

    return 0;

}