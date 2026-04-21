/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

struct Funcionario {
    string nome;
    int idade;
    double salario;
};

static inline string trim(const string& s) {
    size_t a = 0;
    while (a < s.size() && isspace((unsigned char)s[a])) a++;
    size_t b = s.size();
    while (b > a && isspace((unsigned char)s[b - 1])) b--;
    return s.substr(a, b - a);
}

static inline bool tryReadInt(int &x) {
    if (!(cin >> x)) return false;
    return true;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    vector<Funcionario> v;
    int op;
    while (true) {
        if (!tryReadInt(op)) break;

        if (op == 1) {
            string dummy;
            getline(cin, dummy);
            string nome;
            getline(cin, nome);
            nome = trim(nome);
            int idade;
            double salario;
            if (!(cin >> idade)) break;
            if (!(cin >> salario)) break;
            v.push_back({nome, idade, salario});
        } else if (op == 2) {
            cout << "Ordenado por idade:\n";
            vector<Funcionario> a = v;
            sort(a.begin(), a.end(), [](const Funcionario& p, const Funcionario& q){
                if (p.idade != q.idade) return p.idade < q.idade;
                return p.nome < q.nome;
            });
            for (size_t i = 0; i < a.size(); i++) {
                cout << i + 1 << " " << a[i].nome << "\n";
                cout << "      " << a[i].idade << "\n";
                cout.setf(std::ios::fixed); 
                cout << "      " << setprecision(2) << a[i].salario << "\n";
                cout.unsetf(std::ios::fixed);
            }
            cout.flush();
        } else if (op == 3) {
            cout << "Ordenado por salario:\n";
            vector<Funcionario> a = v;
            sort(a.begin(), a.end(), [](const Funcionario& p, const Funcionario& q){
                if (p.salario != q.salario) return p.salario < q.salario;
                if (p.idade != q.idade) return p.idade < q.idade;
                return p.nome < q.nome;
            });
            for (size_t i = 0; i < a.size(); i++) {
                cout << i + 1 << " " << a[i].nome << "\n";
                cout << "      " << a[i].idade << "\n";
                cout.setf(std::ios::fixed);
                cout << "      " << setprecision(2) << a[i].salario << "\n";
                cout.unsetf(std::ios::fixed);
            }
            cout.flush();
        } else {
            cout << "Saindo...";
            return 0;
        }
    }
    return 0;
}