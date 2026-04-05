/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Smartphone {
    string modelo;
    double memoriaMB;
    double processadorMHz;
    double cameraMPix;
    double bateria;
};

int cadastraSmartphone(int qnt_cadastrada, Smartphone phone[10]) {
    if (qnt_cadastrada >= 10) return qnt_cadastrada;
    Smartphone s;
    cin >> ws;
    getline(cin, s.modelo);
    cin >> s.memoriaMB;
    cin >> s.processadorMHz;
    cin >> s.cameraMPix;
    cin >> s.bateria;
    phone[qnt_cadastrada] = s;
    return qnt_cadastrada + 1;
}

int pesquisaSmartphones(int qnt_cadastrada, Smartphone reqMin, Smartphone phone[10]) {
    int found = 0;
    for (int i = 0; i < qnt_cadastrada; i++) {
        if (phone[i].memoriaMB >= reqMin.memoriaMB &&
            phone[i].processadorMHz >= reqMin.processadorMHz &&
            phone[i].cameraMPix >= reqMin.cameraMPix &&
            phone[i].bateria >= reqMin.bateria) {
            found++;
            cout << "Modelo: " << phone[i].modelo << "\n";
            cout << "Memoria: " << fixed << setprecision(0) << phone[i].memoriaMB << "GB\n";
            if (floor(phone[i].processadorMHz) == phone[i].processadorMHz) {
                cout << "Processador: " << fixed << setprecision(0) << phone[i].processadorMHz << "Ghz\n";
            } else {
                cout << "Processador: " << fixed << setprecision(2) << phone[i].processadorMHz << "Ghz\n";
            }
            cout << "Camera: " << fixed << setprecision(2) << phone[i].cameraMPix << "MPixels\n";
            cout << "Bateria: " << fixed << setprecision(2) << phone[i].bateria << "mA\n";
            if (found < 1e9) cout << "\n";
        }
    }
    if (found > 0) {
        string s;
    }
    if (found > 0) {
        cout << "\n";
    }
    return found;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Smartphone phone[10];
    int qnt = 0;

    char resp;
    while (cin >> resp) {
        if (resp != 's') break;
        qnt = cadastraSmartphone(qnt, phone);
    }

    Smartphone req;
    req.modelo = "";
    cin >> req.memoriaMB;
    cin >> req.processadorMHz;
    cin >> req.cameraMPix;
    cin >> req.bateria;

    vector<int> idx;
    for (int i = 0; i < qnt; i++) {
        if (phone[i].memoriaMB >= req.memoriaMB &&
            phone[i].processadorMHz >= req.processadorMHz &&
            phone[i].cameraMPix >= req.cameraMPix &&
            phone[i].bateria >= req.bateria) {
            idx.push_back(i);
        }
    }

    for (size_t k = 0; k < idx.size(); k++) {
        int i = idx[k];
        cout << "Modelo: " << phone[i].modelo << "\n";
        cout << "Memoria: " << fixed << setprecision(0) << phone[i].memoriaMB << "GB\n";
        cout << "Processador: " << fixed << setprecision(2) << phone[i].processadorMHz << "Ghz\n";
        cout << "Camera: " << fixed << setprecision(2) << phone[i].cameraMPix << "MPixels\n";
        cout << "Bateria: " << fixed << setprecision(2) << phone[i].bateria << "mA\n";
        if (k + 1 < idx.size()) cout << "\n";
        else cout << "\n";
    }

    cout << idx.size() << " smartphones encontrados.\n";
    return 0;
}