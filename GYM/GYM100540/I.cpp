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

string m[10] = {".*.**.","*.....","**....","*..*..","*..**.","*...*.","**.*..","**.**.","**..*.",".*.*.."};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
	while(true){
	    int n;
	    cin >> n;

	    if(n == 0) break;

	    string c;
	    cin >> c;

	    if(c == "S"){
	    	string s;
	    	cin >> s;

    		for(int j = 0; j < 3; j++){
	    		for(int i = 0; i < s.size(); i++){
		    		int d = (s[i]-'0');
	    			cout << m[d][j] << m[d][j+3] << " ";
	    		}
	    		cout << endl;
    		}
	    }
	    else{
	    	string s[3];
	    	for(int k = 0; k < 3; k++){
	    		for(int i = 0; i < n; i++){
	    			string x;
	    			cin >> x;
	    			s[k] += x;
	    		}
	    	}

	    	vector<string> mess;
    		string cur = "";
	    	for(int i = 0; i < 2*n; i++){
	    		cur += s[0][i];
	    		cur += s[1][i];
	    		cur += s[2][i];
	    		if(i%2){
	    			mess.push_back(cur);
	    			cur = "";
	    		}	
	    	}

	    	for(string d : mess){
	    		for(int i = 0; i < 10 ; i++){
	    			if(m[i] == d){
	    				cout << i;
	    				break;
	    			}
	    		}
	    	}

	    	cout << endl;
	    }
	}

    return 0;

}