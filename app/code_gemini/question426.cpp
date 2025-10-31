/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <queue>
#include <set>
#include <utility>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int n1, n2;
    while (std::cin >> n1 >> n2) {
        std::vector<std::string> setA(n1);
        for (int i = 0; i < n1; ++i) {
            std::cin >> setA[i];
        }

        std::vector<std::string> setB(n2);
        for (int i = 0; i < n2; ++i) {
            std::cin >> setB[i];
        }

        std::queue<std::pair<std::string, int>> q;
        std::set<std::pair<std::string, int>> visited;

        for (const auto& a : setA) {
            if (visited.find({a, 0}) == visited.end()) {
                q.push({a, 0});
                visited.insert({a, 0});
            }
        }
        for (const auto& b : setB) {
            if (visited.find({b, 1}) == visited.end()) {
                q.push({b, 1});
                visited.insert({b, 1});
            }
        }

        bool found = false;
        while (!q.empty() && !found) {
            std::pair<std::string, int> curr = q.front();
            q.pop();
            std::string s = curr.first;
            int side = curr.second;

            if (side == 0) { // Suffix from A, match with B
                for (const auto& b : setB) {
                    if (s.length() > b.length() && s.rfind(b, 0) == 0) {
                        std::string s_new = s.substr(b.length());
                        if (visited.find({s_new, 0}) == visited.end()) {
                            q.push({s_new, 0});
                            visited.insert({s_new, 0});
                        }
                    } else if (b.length() > s.length() && b.rfind(s, 0) == 0) {
                        std::string s_new = b.substr(s.length());
                        if (visited.find({s_new, 1}) == visited.end()) {
                            q.push({s_new, 1});
                            visited.insert({s_new, 1});
                        }
                    } else if (s == b) {
                        found = true;
                        break;
                    }
                }
            } else { // Suffix from B, match with A
                for (const auto& a : setA) {
                    if (s.length() > a.length() && s.rfind(a, 0) == 0) {
                        std::string s_new = s.substr(a.length());
                        if (visited.find({s_new, 1}) == visited.end()) {
                            q.push({s_new, 1});
                            visited.insert({s_new, 1});
                        }
                    } else if (a.length() > s.length() && a.rfind(s, 0) == 0) {
                        std::string s_new = a.substr(s.length());
                        if (visited.find({s_new, 0}) == visited.end()) {
                            q.push({s_new, 0});
                            visited.insert({s_new, 0});
                        }
                    } else if (s == a) {
                        found = true;
                        break;
                    }
                }
            }
        }

        if (found) {
            std::cout << "S\n";
        } else {
            std::cout << "N\n";
        }
    }

    return 0;
}
