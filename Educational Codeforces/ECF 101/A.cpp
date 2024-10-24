#include<bits/stdc++.h>

#define N 100
#define INF 0x3f3f3f3f

using namespace std;
string s;

int main(){

	int t;
	cin >> t;

	while(t--){
		cin >> s;

		int i;
		int openINDEX = 0;
		int closeINDEX = 0;
		int count = 0;
		for(i = 0; i < s.length(); i++){
			if(s[i] == ')'){
				closeINDEX = i;
			}
			if(s[i] == '('){
				openINDEX = i;
			}
			if(s[i] == '?'){
				count++;
			}
		}

		if(count % 2 == 0 or count == 0){
			if(openINDEX < closeINDEX) printf("YES\n");
			else{
				if(closeINDEX != 0 and openINDEX != s.length() - 1) printf("YES\n");
				else printf("NO\n");
			}

		}
		else printf("NO\n");
		
	}


	return 0;
}