/*
Código criado pelo GPT 4o-mini
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <unordered_map>
#include <functional>
#include <stdexcept>

using namespace std;

class SimpleLang {
    vector<string> program;
    vector<int> regs;
    int instructionPointer;
    
    void MOV(int &op1, int op2) {
        op1 = op2 % 1000;
    }
    
    void ADD(int &op1, int op2) {
        op1 = (op1 + op2) % 1000;
    }
    
    void SUB(int &op1, int op2) {
        op1 = (op1 - op2 + 1000) % 1000;
    }
    
    void MUL(int &op1, int op2) {
        op1 = (op1 * op2) % 1000;
    }
    
    void DIV(int &op1, int op2) {
        if (op2 == 0) op1 = 0;
        else op1 = op1 / op2;
    }
    
    void MOD(int &op1, int op2) {
        if (op2 == 0) op1 = 0;
        else op1 = op1 % op2;
    }
    
    bool evaluateCondition(const string &cmd, int op1, int op2) {
        if (cmd == "IFEQ") return op1 == op2;
        if (cmd == "IFNEQ") return op1 != op2;
        if (cmd == "IFG") return op1 > op2;
        if (cmd == "IFL") return op1 < op2;
        if (cmd == "IFGE") return op1 >= op2;
        if (cmd == "IFLE") return op1 <= op2;
        throw runtime_error("Invalid command");
    }

    int parseOperand(const string &operand) {
        if (operand[0] == 'R') return regs[operand[1] - '0'];
        return stoi(operand);
    }
    
public:
    SimpleLang(const vector<string> &prog, int input) : program(prog), instructionPointer(0) {
        regs.resize(10, 0);
        regs[0] = input;
    }

    int run() {
        vector<int> callStack;
        while (instructionPointer < program.size()) {
            string line = program[instructionPointer];
            stringstream ss(line);
            string command;
            ss >> command;

            if (command == "MOV") {
                string op1, op2;
                ss >> op1 >> op2;
                MOV(regs[op1[1] - '0'], parseOperand(op2));
            } else if (command == "ADD") {
                string op1, op2;
                ss >> op1 >> op2;
                ADD(regs[op1[1] - '0'], parseOperand(op2));
            } else if (command == "SUB") {
                string op1, op2;
                ss >> op1 >> op2;
                SUB(regs[op1[1] - '0'], parseOperand(op2));
            } else if (command == "MUL") {
                string op1, op2;
                ss >> op1 >> op2;
                MUL(regs[op1[1] - '0'], parseOperand(op2));
            } else if (command == "DIV") {
                string op1, op2;
                ss >> op1 >> op2;
                DIV(regs[op1[1] - '0'], parseOperand(op2));
            } else if (command == "MOD") {
                string op1, op2;
                ss >> op1 >> op2;
                MOD(regs[op1[1] - '0'], parseOperand(op2));
            } else if (command == "IFEQ" || command == "IFNEQ" || command == "IFG" || 
                       command == "IFL" || command == "IFGE" || command == "IFLE") {
                string op1, op2;
                ss >> op1 >> op2;
                int a = parseOperand(op1);
                int b = parseOperand(op2);
                if (!evaluateCondition(command, a, b)) {
                    // Skip to ENDIF
                    int depth = 1;
                    while (depth > 0 && ++instructionPointer < program.size()) {
                        if (program[instructionPointer].find("ENDIF") != string::npos) depth--;
                        else if (program[instructionPointer].find(command) != string::npos) depth++;
                    }
                }
            } else if (command == "CALL") {
                string op;
                ss >> op;
                callStack.push_back(instructionPointer);
                instructionPointer = 0;
                regs[0] = parseOperand(op);
                continue;
            } else if (command == "RET") {
                int retVal = parseOperand(ss.str().substr(4));
                if (callStack.empty()) return retVal;
                instructionPointer = callStack.back();
                callStack.pop_back();
                regs[9] = retVal;
                continue;
            }
            instructionPointer++;
        }
        return regs[9];
    }
};

int main() {
    int L, N;
    while (cin >> L >> N, L || N) {
        vector<string> program(L);
        cin.ignore();
        for (int i = 0; i < L; i++) {
            getline(cin, program[i]);
        }
        SimpleLang lang(program, N);
        int result = lang.run();
        if (result == -1) cout << "*\n";
        else cout << result << "\n";
    }
    return 0;
}
