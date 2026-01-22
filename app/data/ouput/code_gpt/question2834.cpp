/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <set>

struct Participant {
    std::string name;
    bool wantsToBeFriend;
};

bool compare(const Participant &a, const Participant &b) {
    if (a.wantsToBeFriend != b.wantsToBeFriend)
        return a.wantsToBeFriend > b.wantsToBeFriend;
    return a.name < b.name;
}

int main() {
    std::vector<Participant> participants;
    std::set<std::string> seenNames;
    std::string line;

    while (std::getline(std::cin, line) && line != "FIM") {
        std::string name = line.substr(0, line.find(' '));
        std::string option = line.substr(line.find(' ') + 1);
        bool wantsToBeFriend = (option == "YES");
        
        if (wantsToBeFriend) {
            if (seenNames.find(name) == seenNames.end()) {
                participants.push_back({name, wantsToBeFriend});
                seenNames.insert(name);
            }
        } else {
            if (seenNames.find(name) == seenNames.end()) {
                participants.push_back({name, wantsToBeFriend});
                seenNames.insert(name);
            }
        }
    }

    std::sort(participants.begin(), participants.end(), compare);

    for (const auto &participant : participants) {
        std::cout << participant.name << std::endl;
    }

    std::string winner;
    int maxLength = -1;

    for (const auto &participant : participants) {
        if (participant.wantsToBeFriend) {
            if (participant.name.length() > maxLength) {
                winner = participant.name;
                maxLength = participant.name.length();
            }
        }
    }

    std::cout << std::endl << "Amigo do Habay:" << std::endl;
    std::cout << winner << std::endl;

    return 0;
}
