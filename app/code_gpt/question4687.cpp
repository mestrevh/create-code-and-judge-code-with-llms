/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <vector>
#include <iomanip>

using namespace std;

class Pilha {
private:
    stack<int> pilha;

public:
    void push(int valor) {
        pilha.push(valor);
    }

    void pop() {
        if (!pilha.empty()) pilha.pop();
    }

    void print() {
        if (pilha.empty()) {
            cout << endl;
            return;
        }
        stack<int> temp = pilha;
        vector<int> valores;
        while (!temp.empty()) {
            valores.push_back(temp.top());
            temp.pop();
        }
        for (int i = valores.size() - 1; i >= 0; --i) {
            cout << valores[i] << (i == 0 ? "" : " ");
        }
        cout << endl;
    }

    void sum() {
        int s = 0;
        stack<int> temp = pilha;
        while (!temp.empty()) {
            s += temp.top();
            temp.pop();
        }
        cout << s << endl;
    }

    void average() {
        if (pilha.empty()) {
            cout << "0.00" << endl;
            return;
        }
        int s = 0, count = 0;
        stack<int> temp = pilha;
        while (!temp.empty()) {
            s += temp.top();
            temp.pop();
            count++;
        }
        cout << fixed << setprecision(2) << static_cast<double>(s) / count << endl;
    }

    void pow() {
        if (pilha.empty()) {
            cout << endl;
            return;
        }
        stack<int> temp = pilha;
        vector<int> valores;
        while (!temp.empty()) {
            valores.push_back(temp.top() * temp.top());
            temp.pop();
        }
        for (int i = valores.size() - 1; i >= 0; --i) {
            cout << valores[i] << (i == 0 ? "" : " ");
        }
        cout << endl;
    }
};

int main() {
    Pilha p;
    string comando;
    int valor;

    while (cin >> comando) {
        if (comando == "push") {
            cin >> valor;
            p.push(valor);
        } else if (comando == "pop") {
            p.pop();
        } else if (comando == "print") {
            p.print();
        } else if (comando == "sum") {
            p.sum();
        } else if (comando == "average") {
            p.average();
        } else if (comando == "pow") {
            p.pow();
        } else if (comando == "exit") {
            break;
        }
    }

    return 0;
}
