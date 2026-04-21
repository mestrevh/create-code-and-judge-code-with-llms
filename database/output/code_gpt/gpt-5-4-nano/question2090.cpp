/*
Código criado pelo gpt-5.4-nano
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    if (!(cin >> N)) return 0;
    string line;
    getline(cin, line);

    unordered_map<string, long long> food;
    vector<string> order;
    vector<string> currentOrder;

    long long totalCook = 0;

    auto printHeader = [&]() {
        long long X = (long long)food.size();
        if (X == 7) {
            cout << "teoria da branca de neve: porque só ter um se eu posso ter sete.\n\n";
        } else {
            cout << "\nEstao na casa " << X << " anoes:\n";
            for (const auto& name : currentOrder) cout << name << "\n";
            cout << totalCook << "\n";
        }
    };

    long long linesRead = 0;
    while (linesRead < N && getline(cin, line)) {
        if (line.empty()) continue;
        linesRead++;

        if (line.rfind("ENTROU:", 0) == 0) {
            string name = line.substr(7);
            long long a;
            string aLine;
            getline(cin, aLine);
            while (aLine.size() == 0 && cin) getline(cin, aLine);
            a = stoll(aLine);

            if (food.count(name)) {
                cout << name << " ja estava em casa.\n";
            } else {
                food[name] = a;
                order.push_back(name);
                currentOrder.push_back(name);
                totalCook += a;
                cout << name << " entrou e gostaria de " << a << "g de comida.\n";
            }
        } else if (line.rfind("SAIU:", 0) == 0) {
            string name = line.substr(5);
            if (!food.count(name)) {
                cout << name << " nao estava na casa.\n";
            } else {
                food.erase(name);
                cout << name << " saiu de casa.\n";
                currentOrder.erase(remove(currentOrder.begin(), currentOrder.end(), name), currentOrder.end());
            }
        }
    }

    if ((long long)food.size() != 7) {
        cout << "\nEstao na casa " << food.size() << " anoes:\n";
        for (const auto& name : currentOrder) cout << name << "\n";
        cout << totalCook << "\n";
    } else {
        cout << "\nteoria da branca de neve: porque só ter um se eu posso ter sete.\n";
        cout << "\nEstao na casa 7 anoes:\n";
        for (const auto& name : currentOrder) cout << name << "\n";
        cout << totalCook << "\n";
    }

    return 0;
}