#include <bits/stdc++.h>
 
#define N 100000
#define MAX 10000000000
#define E 0.00000001
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1
 
using namespace std;
 
int p1, p2;
 
pair<int, int> solve(int a, int b){
    if(a > b){
        return {1, abs(a-b)};
    }
    else{
        return {2, abs(a-b)};
    }
}
 
int main(){
	
	cin >> p1 >> p2;
 
	pair<int,int> ans;
	int q1, q2;
 
 
	while(p1 or p2){
		//memset(dp, -1, sizeof(dp));
		ans = solve(p1, p2);
		cout << ans.first << " " << ans.second << endl;
		cout.flush();
 
		if(ans.first == 1){
			p1 -= ans.second;
		}
		else{
			p2 -= ans.second;
		}
 
		if(!p1 and !p2) break;
 
		cin >> q1 >> q2;
 
		if(q1 == 1){
			p1 -= q2;
		}
		else{
			p2 -= q2;
		}
	}
	
 
    return 0;
 
}