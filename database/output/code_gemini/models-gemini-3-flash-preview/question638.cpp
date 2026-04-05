/*
Código criado pelo models/gemini-3-flash-preview
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <sstream>

using namespace std;

struct Command {
    string name;
    string op1, op2;
    int target;
};

int L, N;
Command cmds[105];
int memo[1005];
bool visiting[1005];

int getValue(const string& op, int regs[]) {
    if (op.empty()) return 0;
    if (op[0] == 'R') {
        int idx = op[1] - '0';
        return regs[idx];
    }
    return stoi(op);
}

int eval(int n) {
    if (n < 0 || n >= 1000) n = (n % 1000 + 1000) % 1000;
    if (visiting[n]) return -2;
    if (memo[n] != -1) return memo[n];

    visiting[n] = true;
    int regs[10] = {0};
    regs[0] = n;
    int pc = 0;
    int result = -1;

    while (pc < L) {
        Command &c = cmds[pc];
        if (c.name == "MOV") {
            regs[c.op1[1] - '0'] = getValue(c.op2, regs);
            pc++;
        } else if (c.name == "ADD") {
            int r = c.op1[1] - '0';
            regs[r] = (regs[r] + getValue(c.op2, regs)) % 1000;
            pc++;
        } else if (c.name == "SUB") {
            int r = c.op1[1] - '0';
            regs[r] = (regs[r] - getValue(c.op2, regs) + 1000) % 1000;
            pc++;
        } else if (c.name == "MUL") {
            int r = c.op1[1] - '0';
            regs[r] = (regs[r] * getValue(c.op2, regs)) % 1000;
            pc++;
        } else if (c.name == "DIV") {
            int r = c.op1[1] - '0';
            int v2 = getValue(c.op2, regs);
            if (v2 == 0) regs[r] = 0;
            else regs[r] /= v2;
            pc++;
        } else if (c.name == "MOD") {
            int r = c.op1[1] - '0';
            int v2 = getValue(c.op2, regs);
            if (v2 == 0) regs[r] = 0;
            else regs[r] %= v2;
            pc++;
        } else if (c.name.size() >= 2 && c.name.substr(0, 2) == "IF") {
            int v1 = getValue(c.op1, regs);
            int v2 = getValue(c.op2, regs);
            bool cond = false;
            if (c.name == "IFEQ") cond = (v1 == v2);
            else if (c.name == "IFNEQ") cond = (v1 != v2);
            else if (c.name == "IFG") cond = (v1 > v2);
            else if (c.name == "IFL") cond = (v1 < v2);
            else if (c.name == "IFGE") cond = (v1 >= v2);
            else if (c.name == "IFLE") cond = (v1 <= v2);
            
            if (cond) pc++;
            else pc = c.target;
        } else if (c.name == "ENDIF") {
            pc++;
        } else if (c.name == "CALL") {
            int arg = getValue(c.op1, regs);
            int res = eval(arg);
            if (res == -2) {
                result = -2;
                break;
            }
            regs[9] = res;
            pc++;
        } else if (c.name == "RET") {
            result = getValue(c.op1, regs);
            break;
        } else {
            pc++;
        }
    }

    visiting[n] = false;
    return memo[n] = result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    while (cin >> L >> N && (L != 0 || N != 0)) {
        for (int i = 0; i < L; ++i) {
            cin >> cmds[i].name;
            if (cmds[i].name == "ENDIF") {
                cmds[i].op1 = "";
                cmds[i].op2 = "";
            } else {
                string ops;
                cin >> ops;
                size_t comma = ops.find(',');
                if (comma != string::npos) {
                    cmds[i].op1 = ops.substr(0, comma);
                    cmds[i].op2 = ops.substr(comma + 1);
                } else {
                    cmds[i].op1 = ops;
                    cmds[i].op2 = "";
                }
            }
        }

        stack<int> s;
        for (int i = 0; i < L; ++i) {
            if (cmds[i].name.size() >= 2 && cmds[i].name.substr(0, 2) == "IF") {
                s.push(i);
            } else if (cmds[i].name == "ENDIF") {
                if (!s.empty()) {
                    int open_idx = s.top();
                    s.pop();
                    cmds[open_idx].target = i + 1;
                }
            }
        }

        for (int i = 0; i < 1005; ++i) {
            memo[i] = -1;
            visiting[i] = false;
        }

        int final_ans = eval(N);
        if (final_ans == -2) {
            cout << "*\n";
        } else {
            cout << final_ans << "\n";
        }
    }

    return 0;
}