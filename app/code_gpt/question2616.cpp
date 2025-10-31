/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

struct Connection {
    int ok = 0;
    int loss = 0;
    bool active = false;
};

int main() {
    string line;
    map<string, Connection> connections;

    while (getline(cin, line)) {
        string command;
        istringstream iss(line);
        getline(iss, command, '(');
        command.erase(remove(command.begin(), command.end(), ' '), command.end());

        if (command == "hudpOpen") {
            string key;
            getline(iss, key, ')');
            connections[key].active = true;

        } else if (command == "hudpClose") {
            string key;
            getline(iss, key, ')');
            if (connections[key].active) {
                connections[key].active = false;
            }

        } else if (command == "hudpSend") {
            string key, msg;
            getline(iss, key, ',');
            getline(iss, msg, ')');
            key.erase(remove(key.begin(), key.end(), ' '), key.end());
            if (connections[key].active) {
                connections[key].loss++;
            }

        } else if (command == "ack") {
            string key, msg;
            getline(iss, key, ',');
            getline(iss, msg, ')');
            key.erase(remove(key.begin(), key.end(), ' '), key.end());
            string reverse_key = to_string(stoi(key.substr(0, key.find(':')))) + ":" + to_string(stoi(key.substr(key.find(':') + 1)));
            if (connections[reverse_key].active) {
                connections[reverse_key].ok++;
                connections[reverse_key].loss--;
            }
        }
    }

    vector<pair<string, Connection>> result(connections.begin(), connections.end());
    sort(result.begin(), result.end(), [](const auto &a, const auto &b) {
        return a.first < b.first;
    });

    for (const auto &pair : result) {
        const auto &key = pair.first;
        const auto &conn = pair.second;
        if (conn.active) {
            cout << "\"" << key << "\"" << " : " << conn.ok << " ok : " << conn.loss << " loss" << endl;
        }
    }

    return 0;
}
