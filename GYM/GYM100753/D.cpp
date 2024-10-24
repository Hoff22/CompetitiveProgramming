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

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	
    vector<int> w;
    vector<int> h;

    vector<int> idx;

    int H, W;
    cin >> W >> H;

    int c;
    cin >> c;

    int id = 0;
    for(int i = 0; i < c; i++){
    	int a, w_, h_;
    	cin >> a >> w_ >> h_;
    	for(int j = 0; j < a; j++){
    		w.push_back(w_);
    		h.push_back(h_);
    		idx.push_back(id++);
    	}
    }

    // int cnt = 0;
    do{
    	
    	for(int r = 0; r < (1<<id); r++){

	    	set<pair<int,int>> p;
	    	p.insert({0,0});
	    	long long cur_area = 0;
	    	int good = 1;

	    	vector<pair<int,int>> pos;

    		for(int k = 0; k < id and cur_area < H*W; k++){

    			int w_ = w[idx[k]];
    			int h_ = h[idx[k]];

    			cur_area += w_ * h_; 

	    		int i, j;
	    		tie(i, j) = *p.begin();
	    		p.erase(p.begin());

	    		if((r>>idx[k]) & 1){ // rotate
	    			swap(w_, h_);
	    		}
	    		
	    		// if(cnt == 1040){
	    		// 	cout << "putting: " << w_ << " " << h_ << " at " << j << " " << i << endl;
	    		// }

	    		if(h_ + i > H){
	    			good = 0;
	    		}
	    		if(w_ + j > W){
	    			good = 0;
	    		}

	    		for(int l = 0; l < k; l++){
	    			int xi = j;
	    			int yi = i;
	    			int xf = j+w_;
	    			int yf = i+h_;

	    			int xi_ = pos[l].se;
	    			int yi_ = pos[l].fi;
	    			int xf_ = pos[l].se + w[idx[l]];
	    			int yf_ = pos[l].fi + h[idx[l]];

	    			if((r>>idx[l]) & 1){ // rotate
		    			xf_ = pos[l].se + h[idx[l]];
		    			yf_ = pos[l].fi + w[idx[l]];
		    		}

	    			if((yi_ <= yi and yi < yf_) or (yi_ <= yf and yf < yf_) or (yi <= yi_ and yf_ < yf)){ // y completly ouy
	    				if((xi_ <= xi and xi < xf_) or (xi_ <= xf and xf < xf_) or (xi <= xi_ and xf_ < xf)){
	    					good = 0;
	    				}
	    				// if(cnt == 1040){
	    				// 	cout << "\tcollision" << endl;
	    				// 	cout << "\t" << xi << " " << yi << " " << xf << " " << yf << endl;
	    				// 	cout << "\t" << xi_ << " " << yi_ << " " << xf_ << " " << yf_ << endl;
	    				// }
	    			}
	    		}

	    		if(!good) break;

	    		if(h_ + i < H) p.insert({h_+i, j});
	    		if(w_ + j < W) p.insert({i, w_+j});

	    		pos.push_back({i,j});
    		}

    		if(cur_area == H*W and good){
    			cout << "yes" << endl;
    			return 0;
    		}
    		// cnt++;
    	}
    }while(next_permutation(idx.begin(), idx.end()));

    cout << "no" << endl;

    return 0;

}