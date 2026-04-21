/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long total_a = 0, total_b = 0, total_c = 0;
    long long total_white = 0, total_null = 0;
    int section;

    while (cin >> section && section != 0) {
        long long a, b, c, w, n;
        if (!(cin >> a >> b >> c >> w >> n)) break;
        total_a += a;
        total_b += b;
        total_c += c;
        total_white += w;
        total_null += n;
    }

    long long total_validos = total_a + total_b + total_c;
    long long total_votantes = total_validos + total_white + total_null;

    long long max_v = 0;
    string winner_name = "";

    if (total_a > max_v) {
        max_v = total_a;
        winner_name = "A";
    }
    if (total_b > max_v) {
        max_v = total_b;
        winner_name = "B";
    }
    if (total_c > max_v) {
        max_v = total_c;
        winner_name = "C";
    }

    bool valida = (total_validos > (total_white + total_null));
    
    bool segundo_turno = false;
    if (total_validos > 0) {
        if (2 * max_v <= total_validos) {
            segundo_turno = true;
        }
    }

    cout << "Numero de votantes: " << total_votantes << "\n";
    cout << "Total A: " << total_a << "\n";
    cout << "Total B: " << total_b << "\n";
    cout << "Total C: " << total_c << "\n";
    cout << "Brancos: " << total_white << "\n";
    cout << "Nulos: " << total_null << "\n";
    cout << "Validos: " << total_validos << "\n";
    cout << "Candidato mais votado: " << winner_name << "\n";
    cout << "Eleicao valida? " << (valida ? "True" : "False") << "\n";
    cout << "Segundo turno? " << (segundo_turno ? "True" : "False") << endl;

    return 0;
}