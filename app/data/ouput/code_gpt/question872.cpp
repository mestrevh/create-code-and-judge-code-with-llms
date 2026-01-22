/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    int T; 
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        vector<string> receitas(N);
        for (int i = 0; i < N; i++) 
            cin >> receitas[i];

        string ingredientes;
        cin >> ingredientes;

        for (auto& receita : receitas) {
            map<char, int> req, disp;
            for (char c : receita) req[c]++;
            for (char c : ingredientes) disp[c]++;
            
            int maxPizzas = INT_MAX;
            for (const auto& [key, value] : req) {
                if (disp[key] == 0) {
                    maxPizzas = 0;
                    break;
                }
                maxPizzas = min(maxPizzas, disp[key] / value);
            }
            cout << maxPizzas << endl;

            for (const auto& [key, value] : req) {
                if (maxPizzas > 0) {
                    disp[key] -= value * maxPizzas;
                }
            }
            ingredientes.clear();
            for (const auto& [key, value] : disp) {
                for (int i = 0; i < value; i++)
                    ingredientes += key;
            }
        }
        cout << endl;
    }
    return 0;
}
