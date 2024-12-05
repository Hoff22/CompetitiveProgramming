#include <bits/stdc++.h> // Esse include tem tudo da biblioteca padrao do c++, STL

// lembrando que comentarios com acentos e caracteres tipo o cedilha PODEM dar problema pra compilar

using namespace std; // essa linha evita que tenha que escrever std::cin, std::cout etc.

int main(){
	ios_base::sync_with_stdio(false); // essas duas linhas servem para acelerar o codigo,
    cin.tie(NULL);					  // se usar elas NAO PODE misturar scanf e cin no mesmo codigo

	int t;		// declarando variavel 't' do tipo 'int'
	cin >> t;	// lendo do input um valor e colocando na variavel 't'
	
	for(int i = 0; i < t; i++){				
		cout << "Bom dia " << i << endl;	// printa 'Bom dia (i)' e quebra linha
		//                         ^^^^
		//               versao c++ de escrever '\n'   
	}

    return 0;
}