/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    double n1, n2, n3;
    char sexo;
    double maior_media = -1, soma_geral = 0, soma_mulheres = 0, soma_homens = 0;
    int cont_alunos = 0, aprovados = 0, final = 0, reprovados = 0, cont_mulheres = 0, cont_homens = 0;
    string genero_maior_media = "";

    while (cin >> n1 >> n2 >> n3 >> sexo) {
        cont_alunos++;
        double media = (n1 + n2 + n3) / 3.0;
        soma_geral += media;

        if (media >= 7) {
            aprovados++;
        } else if (media >= 3) {
            final++;
        } else {
            reprovados++;
        }

        if (sexo == 'M') {
            soma_mulheres += media;
            cont_mulheres++;
            if (media >= maior_media) {
                maior_media = media;
                genero_maior_media = "mulher";
            }
        } else {
            soma_homens += media;
            cont_homens++;
            if (media >= maior_media) {
                maior_media = media;
                genero_maior_media = "homem";
            }
        }
    }

    if (cont_alunos > 0) {
        cout << fixed << setprecision(1);
        cout << "A maior media da turma foi " << maior_media << " e pertence a uma " << genero_maior_media << ".\n";
        cout << "A media geral foi de " << (soma_geral / cont_alunos) << ".\n";
        cout << aprovados << " alunos foram aprovados por media.\n";
        cout << final << " alunos podem fazer o exame final.\n";
        cout << reprovados << " alunos foram reprovados.\n";
        cout << (cont_mulheres > 0 ? (soma_mulheres / cont_mulheres) : 0.0) << " A media das mulheres foi de " << (cont_mulheres > 0 ? (soma_mulheres / cont_mulheres) : 0.0) << ".\n";
        cout << (cont_homens > 0 ? (soma_homens / cont_homens) : 0.0) << " A media dos homens foi de " << (cont_homens > 0 ? (soma_homens / cont_homens) : 0.0) << ".\n";
    }
    return 0;
}
