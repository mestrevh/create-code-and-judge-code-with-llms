/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n)) return 0;

    map<string, long long> stockMap;
    vector<string> order;
    map<string, bool> isRegistered;

    string dummyLine;
    getline(cin, dummyLine);

    for (int i = 0; i < n; ++i) {
        string cmd;
        if (!(cin >> cmd)) break;
        getline(cin, dummyLine); 

        if (cmd == "CADASTRO") {
            string productName;
            if (!getline(cin, productName)) break;
            if (!productName.empty() && productName.back() == '\r') productName.pop_back();
            
            if (isRegistered[productName]) {
                cout << "Produto já cadastrado" << endl;
            } else {
                isRegistered[productName] = true;
                order.push_back(productName);
                stockMap[productName] = 0;
                cout << "Produto cadastrado com sucesso" << endl;
            }
        } else if (cmd == "ESTOQUE") {
            string productName;
            if (!getline(cin, productName)) break;
            if (!productName.empty() && productName.back() == '\r') productName.pop_back();
            
            long long quantity;
            bool qtyRead = false;
            if (cin >> quantity) {
                qtyRead = true;
                getline(cin, dummyLine);
            }
            
            if (qtyRead && quantity < 0) {
                cout << "Comando inválido" << endl;
            } else if (!isRegistered[productName]) {
                cout << "Produto não foi cadastrado" << endl;
            } else if (qtyRead) {
                stockMap[productName] += quantity;
                cout << "Estoque realizado com sucesso" << endl;
            }
        } else if (cmd == "VENDA") {
            string productName;
            if (!getline(cin, productName)) break;
            if (!productName.empty() && productName.back() == '\r') productName.pop_back();
            
            long long quantity;
            bool qtyRead = false;
            if (cin >> quantity) {
                qtyRead = true;
                getline(cin, dummyLine);
            }
            
            if (qtyRead && quantity < 0) {
                cout << "Comando inválido" << endl;
            } else if (!isRegistered[productName]) {
                cout << "Produto não foi cadastrado" << endl;
            } else if (qtyRead) {
                if (stockMap[productName] < quantity) {
                    cout << "Não há estoque para a venda" << endl;
                } else {
                    stockMap[productName] -= quantity;
                    cout << "Venda realizada com sucesso" << endl;
                }
            }
        } else {
            cout << "Comando inválido" << endl;
        }
    }

    for (size_t i = 0; i < order.size(); ++i) {
        cout << order[i] << ": " << stockMap[order[i]] << endl;
    }

    return 0;
}