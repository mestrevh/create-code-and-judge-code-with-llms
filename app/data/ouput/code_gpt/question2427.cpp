/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, string> estacoes = {
        {"01", "A-91, Meguro"},
        {"02", "B-82, Shirokanedai"},
        {"03", "C-73, Shirkane-Takanawa"},
        {"04", "D-64, Mita"},
        {"05", "E-55, Shiba-Koen"},
        {"06", "F-46, Oniramon"},
        {"07", "G-37, Uchi-Saiwaicho"},
        {"08", "H-28, Hibiva"},
        {"09", "I-19, Otemachi"},
        {"10", "J-50, Jimbocho"},
        {"11", "K-41, Siudobashi"},
        {"12", "L-32, Kasuga"},
        {"13", "M-23, Hakusan"},
        {"14", "N-14, Sengoku"},
        {"15", "O-65, Sugamo"},
        {"16", "P-76, Nishi-Sugamo"},
        {"17", "Q-87, Shin- Itabashi"},
        {"18", "R-98, Itabashe-Kuyakushomae"},
        {"19", "S-09, Itabashi-Honcho"},
        {"20", "T-26, Motohasunuma"},
        {"21", "U-27, Shimura-Sakaue"},
        {"22", "V-28, Shimura-Sanchome"},
        {"23", "W-29, Hasune"},
        {"24", "X-20, Nishidai"},
        {"25", "Y-21, Takashimadeira"},
        {"26", "Z-22, Shin-Takashimadaira"}
    };

    string entrada;
    cin >> entrada;
    string numero = entrada.substr(0, 2);
    string info = estacoes[numero];
    
    cout << "Nós estamos indo para estação " << info.substr(0, 6) << ", cujo nome é " << info.substr(8) << "." << endl;

    return 0;
}
