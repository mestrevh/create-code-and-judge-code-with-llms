/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    int febre = 0, temperatura_normal = 0;
    int pressao_otima = 0, pressao_normal = 0, pressao_limitrofe = 0, hipertensao = 0, pressao_sistolica = 0, observacao = 0;

    for (int i = 0; i < n; i++) {
        int temperatura, sistolica, diastolica;
        cin >> temperatura >> sistolica >> diastolica;
        
        if (temperatura > 38) {
            febre++;
        } else {
            temperatura_normal++;
        }
        
        if (sistolica < 120 && diastolica < 80) {
            pressao_otima++;
        } else if (sistolica < 130 && diastolica < 85) {
            pressao_normal++;
        } else if (sistolica < 140 && diastolica < 90) {
            pressao_limitrofe++;
        } else if (sistolica >= 140 || diastolica >= 90) {
            hipertensao++;
        }
        
        if (sistolica >= 130 && diastolica <= 80) {
            pressao_sistolica++;
        }
        
        if (sistolica >= 180 || diastolica >= 110) {
            observacao++;
        }
    }

    cout << "febre: " << febre << endl;
    cout << "temperatura normal: " << temperatura_normal << endl;
    cout << "pressao otima: " << pressao_otima << endl;
    cout << "pressao normal: " << pressao_normal << endl;
    cout << "pressao limitrofe: " << pressao_limitrofe << endl;
    cout << "hipertensao: " << hipertensao << endl;
    cout << "pressao sistolica: " << pressao_sistolica << endl;
    cout << "observacao: " << observacao << endl;

    return 0;
}
