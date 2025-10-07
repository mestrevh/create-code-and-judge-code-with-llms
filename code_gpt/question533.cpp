/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>

class HashSet {
private:
    std::vector<std::list<int>> table;
    int size;
    int count;

    int hash(int k) {
        return k % size;
    }

    void rehash() {
        std::vector<int> elements;
        for (const auto& lst : table) {
            for (int elem : lst) {
                elements.push_back(elem);
            }
        }
        size = 2 * size - 1;
        table.clear();
        table.resize(size);
        count = 0;
        for (int elem : elements) {
            add(elem);
        }
    }

public:
    HashSet() : size(7), count(0) {
        table.resize(size);
    }

    bool add(int k) {
        int index = hash(k);
        int comparisons = 0;
        for (int elem : table[index]) {
            if (elem == k) {
                std::cout << i << " 0 " << comparisons << std::endl;
                return false;
            }
            comparisons++;
        }
        table[index].push_front(k);
        count++;
        if (count / static_cast<double>(size) >= 0.75) {
            rehash();
        }
        std::cout << i << " 1 " << comparisons << std::endl;
        return true;
    }

    bool del(int k) {
        int index = hash(k);
        int comparisons = 0;
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (*it == k) {
                table[index].erase(it);
                count--;
                std::cout << i << " 1 " << comparisons << std::endl;
                return true;
            }
            comparisons++;
        }
        std::cout << i << " 0 " << comparisons << std::endl;
        return false;
    }

    bool has(int k) {
        int index = hash(k);
        int comparisons = 0;
        for (int elem : table[index]) {
            if (elem == k) {
                std::cout << i << " 1 " << comparisons << std::endl;
                return true;
            }
            comparisons++;
        }
        std::cout << i << " 0 " << comparisons << std::endl;
        return false;
    }

    void prt() {
        int maxLength = 0;
        for (const auto& lst : table) {
            maxLength = std::max(maxLength, (int)lst.size());
        }
        std::cout << i << " " << size << " " << count << " " << maxLength << std::endl;
    }
};

int main() {
    HashSet hashSet;
    std::string command;
    int value, i = 0;

    while (std::cin >> command) {
        if (command == "ADD") {
            std::cin >> value;
            hashSet.add(value);
        } else if (command == "DEL") {
            std::cin >> value;
            hashSet.del(value);
        } else if (command == "HAS") {
            std::cin >> value;
            hashSet.has(value);
        } else if (command == "PRT") {
            hashSet.prt();
        }
        i++;
    }
    return 0;
}
