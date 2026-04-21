/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    if (!(cin >> n) || n <= 0) {
        return 0;
    }

    int g_id, m_id;
    double g_peso, m_peso;

    for (int i = 0; i < n; ++i) {
        int cur_id;
        double cur_peso;
        if (!(cin >> cur_id >> cur_peso)) break;

        if (i == 0) {
            g_id = m_id = cur_id;
            g_peso = m_peso = cur_peso;
        } else {
            if (cur_peso > g_peso) {
                g_peso = cur_peso;
                g_id = cur_id;
            }
            if (cur_peso < m_peso) {
                m_peso = cur_peso;
                m_id = cur_id;
            }
        }
    }

    cout << fixed << setprecision(2);
    cout << "Gordo: id: " << g_id << " peso: " << g_peso << "Kg\n";
    cout << "Magro: id: " << m_id << " peso: " << m_peso << "Kg\n";

    return 0;
}