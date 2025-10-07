/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() {
    double hora_atual, tempo_trajeto;
    int vagas_atuais;

    cin >> hora_atual >> tempo_trajeto >> vagas_atuais;

    double hora_chegada = hora_atual + (tempo_trajeto / 60.0);

    if (hora_atual < 8.0 || hora_atual > 20.0 || hora_chegada < 8.0 || hora_chegada > 20.0) {
        cout << "ulaM esta dormindo" << endl;
        return 0;
    }

    int vagas_perdidas = 0;

    if (hora_atual < 12.0) {
        double tempo_ate_12 = (12.0 - hora_atual) * 60.0;
        if (tempo_ate_12 > tempo_trajeto) {
            vagas_perdidas += ceil(tempo_trajeto / 5.0);
        } else {
            vagas_perdidas += ceil(tempo_ate_12 / 5.0);
            tempo_trajeto -= tempo_ate_12;
            if (hora_chegada <= 16.0) {
                vagas_perdidas += ceil(tempo_trajeto / 4.0);
             } else {
                 double tempo_ate_16 = (16.0 - 12.0) * 60.0;
                 if(tempo_ate_16 > tempo_trajeto){
                    vagas_perdidas += ceil(tempo_trajeto / 4.0);
                 } else {
                    vagas_perdidas += ceil(tempo_ate_16 / 4.0);
                    tempo_trajeto -= tempo_ate_16;
                    vagas_perdidas += ceil(tempo_trajeto / 2.0);

                 }

             }
        }
    } else if (hora_atual < 16.0) {
         double tempo_ate_16 = (16.0 - hora_atual) * 60.0;
        if (tempo_ate_16 > tempo_trajeto) {
            vagas_perdidas += ceil(tempo_trajeto / 4.0);
        } else {
            vagas_perdidas += ceil(tempo_ate_16 / 4.0);
            tempo_trajeto -= tempo_ate_16;
            vagas_perdidas += ceil(tempo_trajeto / 2.0);
        }
    }
     else {
        vagas_perdidas += ceil(tempo_trajeto / 2.0);
    }


    if (vagas_atuais - vagas_perdidas >= 1) {
        cout << "possui vaga para olecraM" << endl;
    } else {
        cout << "nao tera vaga" << endl;
    }

    return 0;
}
