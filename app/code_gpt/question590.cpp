/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>

class MinMedMax {
    std::priority_queue<int> maxHeap; // Para os menores elementos
    std::priority_queue<int, std::vector<int>, std::greater<int>> minHeap; // Para os maiores elementos
    int count;

public:
    MinMedMax() : count(0) {}

    std::tuple<int, int, int> add(int value) {
        if (maxHeap.empty() || value <= maxHeap.top()) {
            maxHeap.push(value);
        } else {
            minHeap.push(value);
        }
        
        // Balancear heaps
        if (maxHeap.size() > minHeap.size() + 1) {
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        } else if (minHeap.size() > maxHeap.size()) {
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
        
        count++;
        
        int minVal = maxHeap.empty() ? -1 : maxHeap.top();
        int maxVal = minHeap.empty() ? -1 : minHeap.top();
        int median = maxHeap.size() > minHeap.size() ? maxHeap.top() : maxHeap.empty() ? -1 : maxHeap.top();

        return {minVal, median, maxVal};
    }

    int min() {
        return maxHeap.empty() ? -1 : maxHeap.top();
    }

    int max() {
        return minHeap.empty() ? -1 : minHeap.top();
    }

    int med() {
        return maxHeap.size() > minHeap.size() ? maxHeap.top() : (maxHeap.empty() ? -1 : maxHeap.top());
    }

    int res() {
        int tempCount = count;
        maxHeap = std::priority_queue<int>();
        minHeap = std::priority_queue<int, std::vector<int>, std::greater<int>>();
        count = 0;
        return tempCount;
    }
};

int main() {
    MinMedMax collection;
    std::string command;
    
    while (std::getline(std::cin, command)) {
        if (command.substr(0, 4) == "ADD ") {
            int value = std::stoi(command.substr(4));
            auto [minVal, median, maxVal] = collection.add(value);
            std::cout << minVal << " " << median << " " << maxVal << std::endl;
        } else if (command == "MIN") {
            std::cout << collection.min() << std::endl;
        } else if (command == "MAX") {
            std::cout << collection.max() << std::endl;
        } else if (command == "MED") {
            std::cout << collection.med() << std::endl;
        } else if (command == "RES") {
            std::cout << collection.res() << std::endl;
        }
    }
    return 0;
}
