/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Album {
    string artista;
    string titulo;
    int emprestado;
    string estrelas;
    int indice;
};

bool compareAlbuns(const Album& a, const Album& b) {
    if (a.estrelas.length() != b.estrelas.length()) {
        return a.estrelas.length() > b.estrelas.length();
    }
    return a.indice < b.indice;
}

int main() {
    int n;
    cin >> n;

    vector<Album> albuns;
    int indice = 0;

    for (int i = 0; i < n; ++i) {
        string nomeArtista;
        int m;
        cin >> nomeArtista;
        cin >> m;
        for (int j = 0; j < m; ++j) {
            string titulo;
            int emprestado;
            string estrelas;
            cin >> titulo >> emprestado >> estrelas;
            albuns.push_back({nomeArtista, titulo, emprestado, estrelas, indice++});
        }
    }

    int sorteados[3];
    for (int i = 0; i < 3; ++i) {
        cin >> sorteados[i];
    }

    vector<Album> selecionados;
    for (int i = 0; i < 3; ++i) {
        selecionados.push_back(albuns[sorteados[i] - 1]);
    }

    sort(selecionados.begin(), selecionados.end(), compareAlbuns);

    for (const auto& album : selecionados) {
        if (album.emprestado == 1) {
            cout << "Infelizmente " << album.titulo << " ta emprestado:(" << endl;
        } else {
            cout << album.artista << " - " << album.titulo << endl;
        }
    }

    return 0;
}
