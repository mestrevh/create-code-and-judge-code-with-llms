/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<string> cores = {"azul", "amarelo", "vermelho"};
    
    if (cores.size() >= 2) {
        cout << cores[1] << endl;
    }

    return 0;
}