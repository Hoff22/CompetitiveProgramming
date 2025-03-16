#include<bits/stdc++.h>

#define N 100
#define INF 0x3f3f3f3f

using namespace std;

int t;
int n;
string s;
string twtw = "2020";

int main(){
	
	cin >> t;

	while(t--){
		cin >> n;
		cin >> s;

		bool ok = false;
		for(int i = 0; i < n; i++){
			for(int j = i; j < n; j++){
				int count = 0;
				int l, r;

				for(l = 0; l < i; l++){
					if(s[l] == twtw[count]) count++;
					else break;
				}

				for(r = j+1; r < n; r++){
					if(s[r] == twtw[count]) count++;
					else break;
				}

				if(count == 4 and r == n and l == i){
					ok = true;
				}
			}
			if(ok) break;
		}

		int count = 0;
		for(int i = 0; i < n; i++){
			if(s[i] == twtw[count]) count++;
			else break;
		}

		if(count == 4) ok = true;

		if(ok) printf("YES\n");
		else printf("NO\n");

	}

	return 0;
}