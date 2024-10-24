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

vector<string> a = {
	"tourist","3858",
"ksun48","3679",
"Benq","3658",
"Um_nik","3648",
"apiad","3638",
"Stonefeang","3630",
"ecnerwala","3613",
"mnbvmar","3555",
"newbiedmy","3516",
"semiexp","3481"
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    for(int i = 0; i < a.size(); i+=2){
    	if(s == a[i]){
    		cout << a[i+1] << endl;
    		break;
    	}
    }


    return 0;

}