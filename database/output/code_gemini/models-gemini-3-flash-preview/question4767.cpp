/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    double horario_atual, tempo_trajeto;
    int vagas_iniciais;

    if (!(cin >> horario_atual >> tempo_trajeto >> vagas_iniciais)) return 0;

    double start_m = horario_atual * 60.0;
    double end_m = start_m + tempo_trajeto;
    double arrival_h = end_m / 60.0;

    // A saída/chegada deve estar no intervalo de 8h às 20h (inclusive).
    // Usamos um pequeno epsilon para lidar com imprecisões de ponto flutuante.
    if (horario_atual < 8.0 - 1e-9 || horario_atual > 20.0 + 1e-9 || arrival_h > 20.0 + 1e-9) {
        cout << "ulaM esta dormindo" << endl;
    } else {
        double vagas_perdidas = 0.0;

        // Intervalo 1: 08:00 às 12:00 (480 min a 720 min) - 1 vaga a cada 5 min (taxa 1/5)
        double s1 = max(start_m, 480.0);
        double e1 = min(end_m, 720.0);
        if (e1 > s1) {
            vagas_perdidas += (e1 - s1) / 5.0;
        }

        // Intervalo 2: 12:00 às 16:00 (720 min a 960 min) - 1 vaga a cada 4 min (taxa 1/4)
        double s2 = max(start_m, 720.0);
        double e2 = min(end_m, 960.0);
        if (e2 > s2) {
            vagas_perdidas += (e2 - s2) / 4.0;
        }

        // Intervalo 3: 16:00 às 20:00 (960 min a 1200 min) - 1 vaga a cada 2 min (taxa 1/2)
        double s3 = max(start_m, 960.0);
        double e3 = min(end_m, 1200.0);
        if (e3 > s3) {
            vagas_perdidas += (e3 - s3) / 2.0;
        }

        // A redução é progressiva, então calculamos o total de vagas perdidas 
        // e arredondamos para baixo para obter o número inteiro de vagas que saíram.
        int perdidas_int = (int)floor(vagas_perdidas + 1e-9);
        int vagas_restantes = vagas_iniciais - perdidas_int;

        if (vagas_restantes >= 1) {
            cout << "possui vaga para olecraM" << endl;
        } else {
            cout << "nao tera vaga" << endl;
        }
    }

    return 0;
}