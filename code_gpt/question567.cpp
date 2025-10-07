/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <sstream>
#include <deque>
#include <stack>
#include <iomanip>

using namespace std;

class Structure {
public:
    virtual void add(int value) = 0;
    virtual bool del() = 0;
    virtual void split(Structure*& next) = 0;
    virtual void merge(Structure* other) = 0;
    virtual void transform(bool toStack) = 0;
    virtual bool empty() const = 0;
    virtual int top() const = 0;
};

class Queue : public Structure {
    deque<int> q;
public:
    void add(int value) override { q.push_back(value); }
    bool del() override { if (!q.empty()) { q.pop_front(); return true; } return false; }
    void split(Structure*& next) override {
        size_t n = q.size();
        next = new Queue();
        for (size_t i = (n + 1) / 2; i < n; ++i) next->add(q[i]);
        q.erase(q.begin() + (n + 1) / 2, q.end());
    }
    void merge(Structure* other) override {
        Queue* o = dynamic_cast<Queue*>(other);
        if (o) {
            q.insert(q.end(), o->q.begin(), o->q.end());
        }
    }
    void transform(bool) override {
        // No-op
    }
    bool empty() const override { return q.empty(); }
    int top() const override { return empty() ? 0 : q.front(); }
};

class Stack : public Structure {
    stack<int> s;
public:
    void add(int value) override { s.push(value); }
    bool del() override { if (!s.empty()) { s.pop(); return true; } return false; }
    void split(Structure*& next) override {
        next = new Stack();
        vector<int> values;
        while (!s.empty()) {
            values.push_back(s.top());
            s.pop();
        }
        size_t n = values.size();
        for (size_t i = (n + 1) / 2; i < n; ++i) static_cast<Stack*>(next)->add(values[n - 1 - i]);
        for (size_t i = 0; i <= (n - 1) / 2; ++i) add(values[n - 1 - i]);
    }
    void merge(Structure* other) override {
        Stack* o = dynamic_cast<Stack*>(other);
        if (o) {
            stack<int> temp;
            while (!o->s.empty()) {
                temp.push(o->s.top());
                o->s.pop();
            }
            while (!temp.empty()) {
                s.push(temp.top());
                temp.pop();
            }
        }
    }
    void transform(bool toQueue) override {
        if (toQueue) {
            Queue* q = new Queue();
            stack<int> temp;
            while (!s.empty()) { temp.push(s.top()); s.pop(); }
            while (!temp.empty()) { q->add(temp.top()); temp.pop(); }
            while (!q->empty()) { add(q->top()); q->del(); }
            delete q;
        }
    }
    bool empty() const override { return s.empty(); }
    int top() const override { return empty() ? 0 : s.top(); }
};

int main() {
    string line;
    int caseNum = 0;
    while (getline(cin, line)) {
        if (line.empty()) continue;
        vector<Structure*> structures(1, new Queue());
        while (line != "END") {
            stringstream ss(line);
            string cmd;
            ss >> cmd;
            if (cmd == "ADD") {
                int i, v;
                ss >> i >> v;
                structures[i]->add(v);
            } else if (cmd == "DEL") {
                int i;
                ss >> i;
                structures[i]->del();
            } else if (cmd == "SPL") {
                int i;
                ss >> i;
                Structure* next;
                structures[i]->split(next);
                structures.push_back(next);
            } else if (cmd == "MER") {
                int i, j;
                ss >> i >> j;
                structures[i]->merge(structures[j]);
                delete structures[j];
                structures.erase(structures.begin() + j);
            } else if (cmd == "TRA") {
                int i;
                ss >> i;
                structures[i]->transform(true);
            }
            getline(cin, line);
        }

        cout << "caso " << caseNum++ << ":";
        for (size_t i = 0; i < structures.size(); ++i) {
            cout << " " << (structures[i]->empty() ? '?' : structures[i]->top());
        }
        cout << "\n\n";

        for (auto s : structures) delete s;
    }
    return 0;
}
