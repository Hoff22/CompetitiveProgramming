// Esse include tem tudo da biblioteca padrao do c++, STL
#include <bits/stdc++.h>

// lembrando que comentarios com acentos e caracteres tipo o cedilha PODEM dar problema pra compilar

// essa linha evita que tenha que escrever std::cin, std::cout etc.
using namespace std;

int main(){
    // essas duas linhas servem para acelerar o codigo,
    // se usar elas NAO PODE misturar scanf e cin no mesmo codigo
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;      // declarando variavel 't' do tipo 'int'
    cin >> t;   // lendo do input um valor e colocando na variavel 't'

    string s;   // declarando uma string de c++
    cin >> s;   // lendo a string do input
    
    for(int i = 0; i < t; i++){ 
        // printa 'Bom dia (s) (tamanho de s) (i)' e quebra linha          
        cout << "Bom dia " << s << " " << s.size() << " " << i << endl;
        //                                                        ^^^^
        //                                                 versao c++ de '\n'   
    }   

    // printa todos os caracteres de s separados por espaco
    // ex: 
    //  s = rato
    //  r a t o
    for(int i = 0; i < s.size(); i++){
        cout << s[i] << " ";
    }
    cout << endl;

    return 0;
}