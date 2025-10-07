/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Smartphone {
    string modelo;
    int memoriaMB;
    double processadorMHz;
    int cameraMPix;
    int bateriamAh;
};

int cadastraSmartphone(int qnt_cadastrada, Smartphone phone[10]) {
    if (qnt_cadastrada < 10) {
        cout << "Modelo: ";
        cin.ignore();
        getline(cin, phone[qnt_cadastrada].modelo);
        cout << "Memoria (GB): ";
        cin >> phone[qnt_cadastrada].memoriaMB;
        cout << "Processador (MHz): ";
        cin >> phone[qnt_cadastrada].processadorMHz;
        cout << "Camera (MP): ";
        cin >> phone[qnt_cadastrada].cameraMPix;
        cout << "Bateria (mAh): ";
        cin >> phone[qnt_cadastrada].bateriamAh;
        return qnt_cadastrada + 1;
    }
    return qnt_cadastrada;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone reqMin, Smartphone phone[10]) {
    int encontrados = 0;
    for (int i = 0; i < qnt_cadastrada; i++) {
        if (phone[i].memoriaMB >= reqMin.memoriaMB &&
            phone[i].processadorMHz >= reqMin.processadorMHz &&
            phone[i].cameraMPix >= reqMin.cameraMPix &&
            phone[i].bateriamAh >= reqMin.bateria) {
            cout << "Modelo: " << phone[i].modelo << endl;
            cout << "Memoria: " << phone[i].memoriaMB << "GB" << endl;
            cout << "Processador: " << fixed << setprecision(2) << phone[i].processadorMHz << "Ghz" << endl;
            cout << "Camera: " << phone[i].cameraMPix << ".00MPixels" << endl;
            cout << "Bateria: " << phone[i].bateriamAh << ".00mA" << endl << endl;
            encontrados++;
        }
    }
    return encontrados;
}

int main() {
    Smartphone phones[10];
    int qnt_cadastrada = 0;
    
    char opcao;
    do {
        cout << "Deseja adicionar um smartphone? (s/n): ";
        cin >> opcao;
        if (opcao == 's') {
            qnt_cadastrada = cadastraSmartphone(qnt_cadastrada, phones);
        }
    } while (opcao == 's' && qnt_cadastrada < 10);

    Smartphone reqMin;
    cout << "Digite os requisitos minimos:\n";
    cout << "Memoria (GB): ";
    cin >> reqMin.memoriaMB;
    cout << "Processador (MHz): ";
    cin >> reqMin.processadorMHz;
    cout << "Camera (MP): ";
    cin >> reqMin.cameraMPix;
    cout << "Bateria (mAh): ";
    cin >> reqMin.bateria;

    int encontrados = pesquisaSmartphones(qnt_cadastrada, reqMin, phones);
    cout << endl << encontrados << " smartphones encontrados." << endl;

    return 0;
}
