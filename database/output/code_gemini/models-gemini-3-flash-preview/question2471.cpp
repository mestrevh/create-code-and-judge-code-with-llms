/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Order {
    string name;
    int time;
    int category;
    int id;
};

bool compareOrders(const Order& a, const Order& b) {
    if (a.category != b.category) return a.category < b.category;
    if (a.time != b.time) return a.time < b.time;
    return a.id < b.id;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M;
    if (!(cin >> M)) return 0;

    long long total_correct = 0;
    long long total_orders = 0;
    vector<string> current_extras;
    vector<string> next_extras;

    for (int m = 1; m <= M; ++m) {
        int P;
        if (!(cin >> P)) break;
        total_orders += P;

        vector<Order> correct_list;
        for (int k = 1; k <= P; ++k) {
            string name;
            cin >> name;
            if (k % 3 == 0) {
                if (m < M) {
                    next_extras.push_back(name);
                }
            } else {
                int t;
                string cat_str;
                cin >> t >> cat_str;
                int cat_id;
                if (cat_str == "Bebida") cat_id = 0;
                else if (cat_str == "Acompanhamento") cat_id = 1;
                else cat_id = 2; // Sobremesa

                correct_list.push_back({name, t, cat_id, k});
                total_correct++;
            }
        }

        sort(correct_list.begin(), correct_list.end(), compareOrders);

        cout << "Mesa " << m << ": ";
        bool first = true;
        for (const auto& o : correct_list) {
            if (!first) cout << ", ";
            cout << o.name;
            first = false;
        }
        for (const auto& extra_name : current_extras) {
            if (!first) cout << ", ";
            cout << extra_name;
            first = false;
        }
        cout << "\n";

        current_extras = next_extras;
        next_extras.clear();
    }

    if (total_orders > 0) {
        double p = (total_correct * 100.0) / (double)total_orders;
        if (p < 70.0) {
            cout << "Eu preciso esquecer o Ross, vou ligar pra ele e falar que eu o superei.\n";
        } else if (p < 85.0) {
            cout << "Not bad, e so um trabalho temporario mesmo.\n";
        } else {
            cout << "That's what I call closure, Ross!\n";
        }
    }

    return 0;
}