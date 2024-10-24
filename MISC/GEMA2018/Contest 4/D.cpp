#include <bits/stdc++.h>

#define N 1000
#define MAX 1000000000
#define INF 0x3f3f3f3f
#define PAR 0
#define IMPAR 1

using namespace std;

int main(){
    
  	int n;
  	double p;

  	scanf("%d %lf", &n, &p);

  	// sum of all terms of pg

  	double a1 = p;
  	double a2 = (1-p) * p * p;
  	double q = a2 / a1;

  	n = (n+1) / 2;

  	double ans = a1 * (pow(q, n) - 1) / (q - 1);

  	if(p == 0) printf("0.0000\n");
  	else printf("%.4lf\n", ans);

  	// n = 5;
  	// b
  	// abb
  	// aabbb



  	// n c
  	// 1 0.5 b
  	// 2 0.5 b
  	// 3 0.625 abb
  	// 4 0.625 abb
  	// 5 0.65625 aabbb
  	//
  	//

    return 0;
}