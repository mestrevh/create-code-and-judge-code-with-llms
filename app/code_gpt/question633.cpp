/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <unordered_map>
#include <cstdlib>

using namespace std;

struct File {
    string name;
    int size;
};

class Disk {
    vector<File> files;
    int totalSize;
    int usedSize;
    
    void optimize() {
        vector<File> temp;
        for (const auto& f : files) {
            temp.push_back(f);
        }
        files = temp;
        usedSize = 0;
    }

    int parseSize(const string& sizeStr) {
        int size = 0;
        if (sizeStr.back() == 'b') return 0; // ignore Kb/Mb/Gb
        stringstream ss(sizeStr.substr(0, sizeStr.size() - 2));
        ss >> size;
        string unit = sizeStr.substr(sizeStr.size() - 2);
        if (unit == "Kb") size *= 1;
        else if (unit == "Mb") size *= 1024;
        else if (unit == "Gb") size *= 1024 * 1024;
        return size;
    }

public:
    Disk(int capacity) : totalSize(capacity), usedSize(0) {}

    bool insert(const string& name, int size) {
        if (usedSize + size > totalSize) {
            optimize();
            if (usedSize + size > totalSize) return false;
        }
        files.push_back({name, size});
        usedSize += size;
        return true;
    }

    void remove(const string& name) {
        for (auto it = files.begin(); it != files.end(); ++it) {
            if (it->name == name) {
                usedSize -= it->size;
                files.erase(it);
                break;
            }
        }
    }

    string state() {
        if (files.empty()) return "[ ][ ][ ][ ][ ][ ][ ][ ]";
        int blocks = totalSize / 8;
        vector<int> freeBlocks(8, blocks);
        for (const auto& file : files) {
            int blockIndex = file.size / blocks;
            freeBlocks[blockIndex] -= file.size / (blocks);
        }

        string result;
        for (int i = 0; i < 8; ++i) {
            double percent = (double(freeBlocks[i]) / double(blocks)) * 100;
            if (percent > 75) result += "[ ]";
            else if (percent > 25) result += "[-]";
            else result += "[#]";
        }
        return result;
    }
};

int main() {
    string line;
    while (getline(cin, line)) {
        int n = stoi(line);
        if (n == 0) break;
        getline(cin, line);
        int capacity = Disk::parseSize(line);
        Disk disk(capacity);
        bool errorOccurred = false;

        for (int i = 0; i < n; ++i) {
            getline(cin, line);
            istringstream iss(line);
            string cmd, name;
            iss >> cmd;
            if (cmd == "insere") {
                iss >> name;
                string sizeStr;
                iss >> sizeStr;
                int size = disk.parseSize(sizeStr);
                if (!disk.insert(name, size)) {
                    errorOccurred = true;
                    break;
                }
            } else if (cmd == "remove") {
                iss >> name;
                disk.remove(name);
            } else if (cmd == "otimiza") {
                disk.optimize();
            }
        }

        if (errorOccurred) {
            cout << "ERRO: disco cheio" << endl;
        } else {
            cout << disk.state() << endl;
        }
    }
    return 0;
}
