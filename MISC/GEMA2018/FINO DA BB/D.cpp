#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

bool query(int x, int y){
	string ans;
	cout << 1 << ' ' << x << ' ' << y << endl;
	fflush(stdout);

	cin >> ans;

	// ta pra esquerda
	if(ans == "TAK") return true;
	// ta pra direita
	else return false;
}

int search(int l, int r){
	int m;
	if (l == r) return l;

	while(l < r){
		m = (r + l) / 2;
		if(query(m, m+1)){
			r = m;
		}
		else{
			l = m+1;
		}
	}

	return l;
}

int main(){
	
	int n, k;
	int a1, a2;

	cin >> n >> k;

	a1 = search(1, n);
	// printf("%d\n", a1);
	a2 = search(1, max(a1-1, 1));
	// printf("%d\n", a2);
	
	if(a1 != a2 and query(a2, a1)){
		cout << 2 << ' ' << a1 << ' ' << a2 << endl;
	}
	else {
		int a3 = search(a1+1, n);
		cout << 2 << ' ' << a1 << ' ' << a3 << endl;
	}
	return 0;
}

// 4 3 - 0.75 seg
// 5 2 - 0.20 seg
// 6 1 - 0.16 seg + (0.2 * 5) = 1 + 1 - 1.2 = 0.8

// 4 2.2 - 0.55 seg
// 5 0.0 - 0.00 seg
// 6 0.8 - 0.13 seg