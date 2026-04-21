/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    while (cin >> n) {
        int max_r = -1;
        int min_r = 101;
        string fav_name = "";
        string least_name = "";

        for (int i = 0; i < n; i++) {
            int r;
            if (!(cin >> r)) break;
            
            string name;
            // O uso de ws descarta espaços em branco iniciais (incluindo o \n anterior)
            // e getline captura o nome completo mesmo que contenha espaços.
            getline(cin >> ws, name);
            
            // Converte todos os caracteres do nome para maiúsculo.
            for (char &c : name) {
                c = (char)toupper((unsigned char)c);
            }

            // De acordo com o Teste 1, em caso de empate, o último valor lido 
            // substitui tanto o favorito quanto o menos favorito.
            if (r >= max_r) {
                max_r = r;
                fav_name = name;
            }
            if (r <= min_r) {
                min_r = r;
                least_name = name;
            }
        }

        if (!fav_name.empty()) {
            cout << "O favorito de Joao eh " << fav_name << " com " << max_r << " rating!\n";
            cout << "O que Joao menos gosta eh " << least_name << " com " << min_r << " rating!\n";
        }
    }

    return 0;
}