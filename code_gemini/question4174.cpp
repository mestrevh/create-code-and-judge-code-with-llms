/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n;
    std::cin >> n;
    
    std::vector<int> garage(n, -1);

    char action;
    int k, v;
    while (std::cin >> action >> k >> v) {
        if (k == -1 && v == -1) {
            break;
        }

        if (action == 'i') {
            if (v >= 0 && v < n && garage[v] == -1) {
                garage[v] = k;
            } else {
                if (v >= 0 && v < n) {
                    std::cout << "Not empty\n";
                }
                int next_spot = -1;
                for (int i = 1; i <= n; ++i) {
                    int current_pos = (v + i) % n;
                    if (garage[current_pos] == -1) {
                        next_spot = current_pos;
                        break;
                    }
                }
                if (next_spot != -1) {
                    garage[next_spot] = k;
                } else {
                    std::cout << "FULL\n";
                }
            }
        } else if (action == 'r') {
             if (v < 0 || v >= n || garage[v] != k) {
                std::cout << "Not Found\n";
            } else {
                garage[v] = -1;
            }
        } else if (action == 'm') {
            int m_new;
            std::cin >> m_new;

            if (v < 0 || v >= n || garage[v] != k) {
                std::cout << "Not Found\n";
            } else {
                garage[v] = -1; 

                if (m_new >= 0 && m_new < n && garage[m_new] == -1) {
                    garage[m_new] = k;
                } else {
                    if (m_new >= 0 && m_new < n) {
                        std::cout << "Not empty\n";
                    }
                    int next_spot = -1;
                    for (int i = 1; i <= n; ++i) {
                        int current_pos = (m_new + i) % n;
                        if (garage[current_pos] == -1) {
                            next_spot = current_pos;
                            break;
                        }
                    }
                    if (next_spot != -1) {
                        garage[next_spot] = k;
                    } else {
                        std::cout << "FULL\n";
                    }
                }
            }
        }
    }

    for (int i = 0; i < n; ++i) {
        if (garage[i] != -1) {
            std::cout << "Vaga " << i << " -> " << garage[i] << "\n";
        }
    }

    return 0;
}
