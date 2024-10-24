#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define E 0.00000001
#define MOD 1000000007
#define INF 0x3f3f3f3f
#define LEFT(x) (2 * x)
#define RIGHT(x) (2 * x + 1)
#define se second
#define fi first

using namespace std;
	
string k = "bkosuacdefghijlmnpqrtvwxyz";

bool comp(string a, string b){
	for(int i = 0; i < min(a.length(), b.length()); i++){
		if(a[i] == b[i]) continue;
		for(int j = 0; j < k.length(); j++){
			if(a[i] == k[j]) return true;
			if(b[i] == k[j]) return false;
		}
	}
	return (a.length() < b.length());
}
// k o b u s
int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	cin >> n;

	string a[N+1];

	for(int i = 0; i < n; i++) cin >> a[i];

	a[n] = "kobus";
	do{
		sort(a, (a+n+1), comp);

		if(a[0] == "kobus"){
			cout << k << endl;
			return 0;
		}
	}while(next_permutation(k.begin(), k.begin()+5));

	cout << "sem chance" << endl;

	return 0;
}

/*
J
I
D
B
A E G
C
F
H
*/
