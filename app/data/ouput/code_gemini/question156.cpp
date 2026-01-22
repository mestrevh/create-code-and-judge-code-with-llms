/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int C, N;
    std::cin >> C >> N;

    std::map<int, int> installed_programs;
    for (int i = 0; i < C; ++i) {
        int program_id, version;
        std::cin >> program_id >> version;
        installed_programs[program_id] = version;
    }

    std::map<int, int> available_programs;
    for (int i = 0; i < N; ++i) {
        int program_id, version;
        std::cin >> program_id >> version;
        if (available_programs.count(program_id) == 0 || version > available_programs[program_id]) {
            available_programs[program_id] = version;
        }
    }

    for (const auto& pair : available_programs) {
        int program_id = pair.first;
        int available_version = pair.second;

        auto it = installed_programs.find(program_id);
        
        if (it == installed_programs.end() || available_version > it->second) {
            std::cout << program_id << " " << available_version << "\n";
        }
    }

    return 0;
}
