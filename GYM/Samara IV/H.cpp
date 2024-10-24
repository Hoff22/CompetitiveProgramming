#include <bits/stdc++.h>

#define N 500000
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

int closing[N+1];

int main(){
	
	string s;
	cin >> s;

	int sum = 0;
	for(int i = s.length()-1; i >= 0; i--){
		if(s[i] == ')'){
			sum++;
		} 
		closing[i] = sum;
	}

	int enter = 0;
	for(int i = 0; i < s.length(); i++){
		if(s[i] == '(') enter++;
		if(s[i] == ')') enter--;
		if(s[i] == '?'){
			if(enter < closing[i]){
				s[i] = '(';
				enter++;
			}
			else{
				s[i] = ')';
				enter--;
			}
		}
		if(enter < 0){
			cout << "Impossible\n";
			return 0;
		}
	}

	if(enter){
		cout << "Impossible\n";
	}
	else{
		cout << s << endl;
	}

    return 0;

}