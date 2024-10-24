#include <bits/stdc++.h>

using namespace std;

int main (int argc,char *argv[]){

	srand(atoi(argv[1]));

	cout << 1 << endl;

	int arr[20];

	int n = rand() % 10 + 1;
	cout << n << endl;
	set<int> s;
	for(int i = 1; i <= n; i++){
		int x = rand() % 100 + 1;;
		while(s.count(x)){
			x = rand() % 100 + 1;
		}
		arr[i] = x;
		s.insert(x);
	}
	for(int i = 1; i <= n; i++){
		swap(arr[rand() % n + 1], arr[rand() % n + 1]);
	}
	for(int i = 1; i <= n; i++){
		cout << arr[i] << " ";
	}
	cout << endl;

}