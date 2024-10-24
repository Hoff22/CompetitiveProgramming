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

	int l, r;
	l = r = 0;

	for(int i = 0; i < s.length(); i++){
		if(s[i] == 'A') r++;
		else l++;
	}

	if(s[0] != 'B' and s[s.length()-1] != 'A' and l == r){
		printf("Sim\n");
	}
	else printf("Nao\n");
	

    return 0;

}