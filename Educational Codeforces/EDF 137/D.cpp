#include <bits/stdc++.h>

#define N 200000
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

void solve(){


}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int n;
	scanf("%d", &n);

	vector<int> a;
	bool d = false;

	for(int i = 0; i < n; i++){
		char c;
		scanf(" %c", &c);
		if(c == '1') d = true;
		if(d) a.push_back((c == '1'));
	}

	n = a.size();

	if(n == 0){
		printf("0\n");
		return 0;
	}

	vector<vector<int>> subs;

	int i;
	for(i = 0; a[i] != 0; i++){
		vector<int> temp;
		for(int j = 0; j < i; j++) temp.push_back(a[j]); 
		for(int j = 0; j < n - i; j++){
			temp.push_back(a[j]);
		}

		subs.push_back(temp);
	}

	vector<int> temp;
	for(int j = 0; j < i; j++) temp.push_back(a[j]); 
	for(int j = 0; j < n - i; j++){
		temp.push_back(a[j]);
	}
	subs.push_back(temp);

	vector<int> ans;
/*
	for(int k =0; k < subs.size(); k++){
		for(int b : subs[k]){
			printf("%d", b);
		}
		printf("\n");
	}
*/
	for(int b = 0; b < n; b++){

		bool found = 0;
		for(int k = 1; k < subs.size(); k++){
			if(subs[k][b]) found = 1;
		}

		if(found and (subs[0][b] == 0)){
			for(int k = 1; k < subs.size(); k++){
				if(subs[k][b] == 0){
					subs.erase(subs.begin()+k);
					k--;
				}
			}
		}

		ans.push_back(subs[0][b] | found);
	}
	for(int b = 0; b < n; b++){
		printf("%d", ans[b]);
	}
	printf("\n");

    return 0;

}