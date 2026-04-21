/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

struct Smartphone {
    string modelo;
    int memoriaMB;
    double processadorMHz;
    double cameraMPix;
    double bateria;
};

int cadastraSmartphone(int qnt_cadastrada, Smartphone phone[10]) {
    if (qnt_cadastrada >= 10) return qnt_cadastrada;
    
    cin >> ws;
    getline(cin, phone[qnt_cadastrada].modelo);
    cin >> phone[qnt_cadastrada].memoriaMB;
    cin >> phone[qnt_cadastrada].processadorMHz;
    cin >> phone[qnt_cadastrada].cameraMPix;
    cin >> phone[qnt_cadastrada].bateria;
    
    return qnt_cadastrada + 1;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone reqMin, Smartphone phone[10]) {
    int count = 0;
    for (int i = 0; i < qnt_cadastrada; ++i) {
        if (phone[i].memoriaMB >= reqMin.memoriaMB &&
            phone[i].processadorMHz >= reqMin.processadorMHz &&
            phone[i].cameraMPix >= reqMin.cameraMPix &&
            phone[i].bateria >= reqMin.bateria) {
            
            cout << "Modelo: " << phone[i].modelo << "\n";
            cout << "Memoria: " << phone[i].memoriaMB << "GB\n";
            cout << fixed << setprecision(2);
            cout << "Processador: " << phone[i].processadorMHz << "Ghz\n";
            cout << "Camera: " << phone[i].cameraMPix << "MPixels\n";
            cout << "Bateria: " << phone[i].bateria << "mA\n\n";
            count++;
        }
    }
    return count;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Smartphone phones[10];
    int count_phones = 0;
    char choice;

    while (cin >> choice && (choice == 's' || choice == 'S')) {
        count_phones = cadastraSmartphone(count_phones, phones);
    }

    Smartphone reqMin;
    if (cin >> reqMin.memoriaMB >> reqMin.processadorMHz >> reqMin.cameraMPix >> reqMin.bateria) {
        int found = pesquisaSmartphones(count_phones, reqMin, phones);
        cout << found << " smartphones encontrados." << endl;
    }

    return 0;
}