/*
Código criado pelo Gemini Pro 1.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

int main() {
    int m, l, n;
    cin >> m >> l >> n;

    map<int, int> points = {{1, 25}, {2, 18}, {3, 15}, {4, 12}, {5, 10}, {6, 8}, {7, 6}, {8, 4}, {9, 2}, {10, 1}};

    vector<string> races_ahead;
    for (int i = 0; i < n; ++i) {
        string race_name;
        int m_pos, l_pos;
        cin >> race_name >> m_pos >> l_pos;

        if (m_pos <= 10) {
            m += points[m_pos];
        }
        if (l_pos <= 10) {
            l += points[l_pos];
        }

        if (l_pos < m_pos) {
            races_ahead.push_back(race_name);
        }

    }
    
    if (m > l || (m == l && races_ahead.empty())) {
        cout << "O vencedor e Marquinhos com " << m - l << " pontos a mais, ficando a frente em ";
        
    } else if (l > m ) {
        cout << "O vencedor e Luis com " << l - m << " pontos a mais, ficando a frente em ";

        for (size_t i = 0; i < races_ahead.size(); ++i) {
            cout << races_ahead[i];
            if (i < races_ahead.size() - 1) {
                cout << "/";
            }
        }
        cout << "/";
    } else {
      cout << "O vencedor e Marquinhos com " << m - l << " pontos a mais, ficando a frente em ";
    }

    cout << endl;

    return 0;
}
