#include <bits/stdc++.h>

#define N 100000
#define MAX 1000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){
	
	string s;
	cin >> s;

	int last = -1;
	for(int i = 0; i <= s.length(); i++){
		if(last == -1){
			if(s[i] != s[0]){
				cout << s[0] << i;
				last = i;
			}
		}
		else if(s[i] != s[last]){
			cout << s[last] << i - last;
			last = i;
		}
	}

	printf("\n");
	

    return 0;

}