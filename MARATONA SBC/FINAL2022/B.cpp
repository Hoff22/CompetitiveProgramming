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

constexpr int MAX_P = 1000000000;

struct Quad_tree{
	int child[2][2];
	int min_x, max_x;
	int min_y, max_y;
	int size;

	/*
		corner indices order:
		0 | 1
		--+--
		2 | 3
	*/

	Quad_tree(int min_X, int max_X, int min_Y, int max_Y){
		memset(this->child, -1, sizeof(this->child));
		this->size = 0;
		min_x = min_X;
		max_x = max_X;
		min_y = min_Y;
		max_y = max_Y;
	}
};

vector<Quad_tree> qt = {Quad_tree(-MAX_P, MAX_P, -MAX_P, MAX_P)};

// do add_point(0, x, y) to add a point to tree
// O(log(N)) where N is the max coordinate
// return the number of points added to cur
int add_point(int cur, int x, int y){

	if(qt[cur].min_x == qt[cur].max_x and qt[cur].min_y == qt[cur].max_y){
		qt[cur].size++;
		return qt[cur].size;
	}

	int m_x = qt[cur].min_x + (qt[cur].max_x - qt[cur].min_x) / 2;
	int m_y = qt[cur].min_y + (qt[cur].max_y - qt[cur].min_y) / 2;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			int new_min_x;
			int new_max_x;
			int new_min_y;
			int new_max_y;

			if(j%2){
				new_min_x = m_x + 1;
				new_max_x = qt[cur].max_x;
			}
			else{
				new_min_x = qt[cur].min_x;
				new_max_x = m_x;
			}
			if(i%2){
				new_min_y = qt[cur].min_y;
				new_max_y = m_y;
			}
			else{
				new_min_y = m_y+1;
				new_max_y = qt[cur].max_y;
			}

			if(new_min_x <= x and x <= new_max_x and new_min_y <= y and y <= new_max_y){
				// creates child node if it doesn't exist
				if(qt[cur].child[i][j] == -1){
					qt.push_back(Quad_tree(new_min_x, new_max_x, new_min_y, new_max_y));
					qt[cur].child[i][j] = qt.size()-1;
				}

				// goes to node
				return qt[cur].size += add_point(qt[cur].child[i][j], x, y);
			}
		}
	}

	return 0;
}

int query_line(int cur, int a, int b){
	
	// node is completely inside range
	if(qt[cur].max_y < a*qt[cur].min_x + b and qt[cur].max_y < a*qt[cur].max_x + b){
		int amount = qt[cur].size;
		qt[cur].size = 0;
		return amount;
	}

	// node is completely out of range
	if(qt[cur].min_y >= a*qt[cur].min_x + b and qt[cur].min_y >= a*qt[cur].max_x + b){
		return 0;
	}

	int amount = 0;

	for(int i = 0; i < 2; i++){
		for(int j = 0; j < 2; j++){
			if(qt[cur].child[i][j] == -1) continue;
		
			amount += query_line(qt[cur].child[i][j], a, b);

			// erasing child if no points are left in it
			if(qt[qt[cur].child[i][j]].size == 0) qt[cur].child[i][j] = -1;
		}
	}

	// updating amount of avaiable points in node
	qt[cur].size -= amount;

	return amount;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    int n;
    cin >> n;

    for(int i = 0; i < n; i++){
    	int x, y;
    	cin >> x >> y;
    	add_point(0, x, y);
    }

    for(Quad_tree p : qt){
    	cout << p.min_x << " " << p.min_y << " | " << p.max_x << " " << p.max_y << endl; 
    }

    int q;
    cin >> q;
    for(int i = 0; i < q; i++){
    	int a, b;
    	cin >> a >> b;
    	cout << query_line(0, a, b) << " ";
    }
    cout << endl;
	
    return 0;

}