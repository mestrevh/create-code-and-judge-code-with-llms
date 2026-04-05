/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

/**
 * Funcao para imprimir o estado atual do array seguindo o padrao de espacamento.
 */
void printArray(const vector<int>& arr) {
    if (arr.empty()) return;
    for (size_t i = 0; i < arr.size(); ++i) {
        cout << arr[i] << (i == arr.size() - 1 ? "" : " ");
    }
    cout << endl;
}

/**
 * Implementacao do Selection Sort conforme solicitado.
 * O array original eh impresso uma vez, e depois o array eh impresso
 * a cada troca (quando um elemento eh movido para sua posicao final).
 */
void selectionSortSteps(vector<int>& arr) {
    if (arr.empty()) return;
    
    int n = static_cast<int>(arr.size());
    printArray(arr); // Exibe o array original

    for (int i = 0; i < n - 1; ++i) {
        int min_idx = i;
        for (int j = i + 1; j < n; ++j) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        
        // Se o menor elemento nao esta na posicao correta, realiza a troca e exibe
        if (min_idx != i) {
            swap(arr[i], arr[min_idx]);
            printArray(arr);
        }
    }
}

int main() {
    // Otimizacao de I/O para maratona de programacao
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    vector<int> arr;
    int val;
    
    // Leitura do array de tamanho variado ate o fim da entrada (EOF)
    while (cin >> val) {
        arr.push_back(val);
    }

    if (!arr.empty()) {
        selectionSortSteps(arr);
    }

    return 0;
}