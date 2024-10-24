#include <bits/stdc++.h>
 
using namespace std;
 
typedef pair<int, int> pii;
 
 
int main() {
    int n;
    scanf("%d", &n);
 
    pii secoes[n];
    vector<pii> juncoes;
 
    int ganhou = 0;
 
    int last = -2;
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &secoes[i].first, &secoes[i].second);
 
        if (secoes[i].first > secoes[i].second) {
            if (last == -1 && (secoes[i-1].first + secoes[i].first) > (secoes[i-1].second + secoes[i].second) || last == 0) {
                juncoes.push_back({i-1, i});
            }
            last = 1;
            ganhou++;
        } else if (secoes[i].first < secoes[i].second) {
            if (last == 1 && (secoes[i-1].first + secoes[i].first) > (secoes[i-1].second + secoes[i].second) || last == -1 || last == 0) {
                juncoes.push_back({i-1, i});
            }
            last = -1;
        } else{
            if(i == 0){
            	juncoes.push_back({i, i+1});
            }
            else{
            	juncoes.push_back({i-1, i});
            }
            last = 0;
        }
    }
 
    int nSecoes = n;
    int juntados[n] = {0};
    vector<pii> juncoesFeitas;
 
    for (int i = 0; i < juncoes.size() && ganhou <= nSecoes/2; i++) {
        pii juncao = juncoes[i];
 
        if (juntados[juncao.first] || juntados[juncao.second])
            continue;
 
        juntados[juncao.first] = 1;
        juntados[juncao.second] = 1;
        nSecoes--;
        juncoesFeitas.push_back(juncao);
    }
 
    if (ganhou > nSecoes/2) {
        printf("%ld\n", juncoesFeitas.size());
        for (auto juncao: juncoesFeitas) {
            printf("%d %d\n", juncao.first + 1, juncao.second + 1);
        }
    } else {
        printf("-1\n");
    }
 
    return 0;
}