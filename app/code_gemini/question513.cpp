/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <stack>
#include <queue>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int t;
    std::cin >> t;
    for (int case_num = 1; case_num <= t; ++case_num) {
        int n;
        std::cin >> n;

        std::stack<int> s;
        std::queue<int> q;

        bool is_stack = true;
        bool is_queue = true;

        for (int i = 0; i < n; ++i) {
            int op, val;
            std::cin >> op >> val;

            if (op == 1) {
                if (is_stack) {
                    s.push(val);
                }
                if (is_queue) {
                    q.push(val);
                }
            } else {
                if (is_stack) {
                    if (s.empty() || s.top() != val) {
                        is_stack = false;
                    } else {
                        s.pop();
                    }
                }
                if (is_queue) {
                    if (q.empty() || q.front() != val) {
                        is_queue = false;
                    } else {
                        q.pop();
                    }
                }
            }
        }

        std::cout << "caso " << case_num << ": ";
        if (is_stack && is_queue) {
            std::cout << "ambas\n";
        } else if (is_stack) {
            std::cout << "pilha\n";
        } else if (is_queue) {
            std::cout << "fila\n";
        } else {
            std::cout << "nenhuma\n";
        }
    }
    return 0;
}
