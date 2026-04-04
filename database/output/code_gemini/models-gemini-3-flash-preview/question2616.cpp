/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <cstdio>

using namespace std;

struct Connection {
    int p1, p2;
    bool operator<(const Connection& other) const {
        if (p1 != other.p1) return p1 < other.p1;
        return p2 < other.p2;
    }
};

struct Stats {
    int ok = 0;
    int loss = 0;
    bool isOpen = false;
    bool everOpened = false;
    map<string, int> pending;
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string line;
    map<Connection, Stats> connections;

    while (getline(cin, line)) {
        while (!line.empty() && (line.back() == '\r' || line.back() == '\n')) {
            line.pop_back();
        }
        if (line.empty()) continue;

        if (line.find("hudpOpen") == 0) {
            size_t f = line.find('"');
            size_t s = line.find('"', f + 1);
            if (f != string::npos && s != string::npos) {
                string pStr = line.substr(f + 1, s - f - 1);
                int p1, p2;
                if (sscanf(pStr.c_str(), "%d:%d", &p1, &p2) == 2) {
                    Connection c = {p1, p2};
                    connections[c].isOpen = true;
                    connections[c].everOpened = true;
                }
            }
        } else if (line.find("hudpClose") == 0) {
            size_t f = line.find('"');
            size_t s = line.find('"', f + 1);
            if (f != string::npos && s != string::npos) {
                string pStr = line.substr(f + 1, s - f - 1);
                int p1, p2;
                if (sscanf(pStr.c_str(), "%d:%d", &p1, &p2) == 2) {
                    Connection c = {p1, p2};
                    if (connections.count(c) && connections[c].isOpen) {
                        for (auto const& p : connections[c].pending) {
                            connections[c].loss += p.second;
                        }
                        connections[c].pending.clear();
                        connections[c].isOpen = false;
                    }
                }
            } else if (line.find("hudpSend") == 0) {
                size_t f = line.find('"');
                size_t s = line.find('"', f + 1);
                if (f != string::npos && s != string::npos) {
                    string pStr = line.substr(f + 1, s - f - 1);
                    int p1, p2;
                    if (sscanf(pStr.c_str(), "%d:%d", &p1, &p2) == 2) {
                        Connection c = {p1, p2};
                        if (connections.count(c) && connections[c].isOpen) {
                            size_t comma = line.find(',', s);
                            if (comma != string::npos) {
                                size_t msgStart = comma + 1;
                                while (msgStart < line.size() && line[msgStart] == ' ') msgStart++;
                                string msg = line.substr(msgStart);
                                if (!msg.empty() && msg.back() == ')') msg.pop_back();
                                connections[c].pending[msg]++;
                            }
                        }
                    }
                }
            } else if (line.find("ack") == 0) {
                size_t f = line.find('"');
                size_t s = line.find('"', f + 1);
                if (f != string::npos && s != string::npos) {
                    string pStr = line.substr(f + 1, s - f - 1);
                    int pA, pB;
                    if (sscanf(pStr.c_str(), "%d:%d", &pA, &pB) == 2) {
                        Connection c = {pB, pA};
                        if (connections.count(c) && connections[c].isOpen) {
                            size_t comma = line.find(',', s);
                            if (comma != string::npos) {
                                size_t msgStart = comma + 1;
                                while (msgStart < line.size() && line[msgStart] == ' ') msgStart++;
                                string msg = line.substr(msgStart);
                                if (!msg.empty() && msg.back() == ')') msg.pop_back();
                                if (connections[c].pending.count(msg) && connections[c].pending[msg] > 0) {
                                    connections[c].pending[msg]--;
                                    connections[c].ok++;
                                }
                            }
                        }
                    }
                }
            }
        }
    }

    for (auto& pair : connections) {
        if (pair.second.isOpen) {
            for (auto const& p : pair.second.pending) {
                pair.second.loss += p.second;
            }
            pair.second.pending.clear();
            pair.second.isOpen = false;
        }
    }

    for (auto const& entry : connections) {
        if (entry.second.everOpened) {
            cout << "\"" << entry.first.p1 << ":" << entry.first.p2 << "\" : "
                 << entry.second.ok << " ok : " << entry.second.loss << " loss" << "\n";
        }
    }

    return 0;
}