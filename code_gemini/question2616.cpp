/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <set>
#include <utility>
#include <cctype>
#include <algorithm>

struct ConnectionData {
    bool isOpen = false;
    int ackedCount = 0;
    std::multiset<std::string> pendingMessages;
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    std::map<std::pair<int, int>, ConnectionData> connections;
    std::string line;

    while (std::getline(std::cin, line)) {
        if (line.empty()) {
            continue;
        }

        size_t open_paren = line.find('(');
        if (open_paren == std::string::npos) continue;
        std::string cmd = line.substr(0, open_paren);

        size_t first_quote = line.find('"');
        if (first_quote == std::string::npos) continue;
        size_t colon = line.find(':', first_quote);
        if (colon == std::string::npos) continue;
        size_t second_quote = line.find('"', colon);
        if (second_quote == std::string::npos) continue;

        int p1 = std::stoi(line.substr(first_quote + 1, colon - (first_quote + 1)));
        int p2 = std::stoi(line.substr(colon + 1, second_quote - (colon + 1)));
        
        if (cmd == "hudpOpen") {
            connections[{p1, p2}].isOpen = true;
        } else if (cmd == "hudpClose") {
            auto it = connections.find({p1, p2});
            if (it != connections.end() && it->second.isOpen) {
                it->second.isOpen = false;
            }
        } else if (cmd == "hudpSend") {
            size_t comma = line.find(',');
            if (comma == std::string::npos) continue;
            size_t last_paren = line.rfind(')');
            if (last_paren == std::string::npos) continue;
            
            size_t msg_start = comma + 1;
            while (msg_start < line.length() && isspace(line[msg_start])) {
                msg_start++;
            }
            std::string msg = line.substr(msg_start, last_paren - msg_start);
            
            auto it = connections.find({p1, p2});
            if (it != connections.end() && it->second.isOpen) {
                it->second.pendingMessages.insert(msg);
            }
        } else if (cmd == "ack") {
            std::swap(p1, p2);

            size_t comma = line.find(',');
            if (comma == std::string::npos) continue;
            size_t last_paren = line.rfind(')');
            if (last_paren == std::string::npos) continue;

            size_t msg_start = comma + 1;
            while (msg_start < line.length() && isspace(line[msg_start])) {
                msg_start++;
            }
            std::string msg = line.substr(msg_start, last_paren - msg_start);

            auto conn_it = connections.find({p1, p2});
            if (conn_it != connections.end() && conn_it->second.isOpen) {
                auto msg_it = conn_it->second.pendingMessages.find(msg);
                if (msg_it != conn_it->second.pendingMessages.end()) {
                    conn_it->second.ackedCount++;
                    conn_it->second.pendingMessages.erase(msg_it);
                }
            }
        }
    }

    for (const auto& pair : connections) {
        int p1 = pair.first.first;
        int p2 = pair.first.second;
        const auto& data = pair.second;

        std::cout << "\"" << p1 << ":" << p2 << "\" : " << data.ackedCount << " ok : " << data.pendingMessages.size() << " loss\n";
    }

    return 0;
}
