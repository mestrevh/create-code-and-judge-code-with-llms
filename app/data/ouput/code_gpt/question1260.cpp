/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int main() {
    int N;
    cin >> N;
    cin.ignore(); // Ignora o caractere de nova linha após N
    
    vector<string> livros(N);
    
    for (int i = 0; i < N; ++i) {
        getline(cin, livros[i]);
    }
    
    sort(livros.begin(), livros.end(), [](const string& a, const string& b) {
        size_t posA = a.find('#'), posB = b.find('#');
        return stoi(a.substr(posA + 1)) < stoi(b.substr(posB + 1));
    });
    
    for (const auto& livro : livros) {
        cout << livro << endl;
    }
    
    return 0;
}
