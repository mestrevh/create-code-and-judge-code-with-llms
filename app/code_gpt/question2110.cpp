/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
using namespace std;

int main() {
    string crimeDelator, crimeDelatado;
    double valorDelator = 0, valorDelatado = 0;

    cin >> crimeDelator;
    if (crimeDelator == "roubo" || crimeDelator == "tráfico") {
        cin >> valorDelator;
    }
    cin >> crimeDelatado;
    if (crimeDelatado == "roubo" || crimeDelatado == "tráfico") {
        cin >> valorDelatado;
    }

    if ((crimeDelator != "roubo" && crimeDelator != "tráfico" && crimeDelator != "homicídio") ||
        (crimeDelatado != "roubo" && crimeDelatado != "tráfico" && crimeDelatado != "homicídio")) {
        cout << "Crime inválido." << endl;
        return 0;
    }

    if (crimeDelator == "homicídio" && crimeDelatado == "homicídio") {
        cout << "Delação concedida." << endl;
    } else if (crimeDelator == "tráfico" && crimeDelatado == "tráfico") {
        if (valorDelatado > 5 * valorDelator)
            cout << "Delação concedida." << endl;
        else
            cout << "Delação rejeitada." << endl;
    } else if (crimeDelator == "roubo" && crimeDelatado == "tráfico") {
        if (valorDelatado > 3 * valorDelator)
            cout << "Delação concedida." << endl;
        else
            cout << "Delação rejeitada." << endl;
    } else if (crimeDelator == "roubo" && crimeDelatado == "roubo") {
        if (valorDelatado > 5 * valorDelator)
            cout << "Delação concedida." << endl;
        else
            cout << "Delação rejeitada." << endl;
    } else if (crimeDelator == "roubo" && crimeDelatado == "homicídio") {
        cout << "Delação concedida." << endl;
    } else if (crimeDelator == "tráfico" && crimeDelatado == "homicídio") {
        cout << "Delação concedida." << endl;
    } else {
        cout << "Delação rejeitada." << endl;
    }

    return 0;
}
