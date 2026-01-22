/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <stack>
#include <stdexcept>

using namespace std;

enum OpCode {
    MOV, ADD, SUB, MUL, DIV, MOD,
    IFEQ, IFNEQ, IFG, IFL, IFGE, IFLE,
    ENDIF, CALL, RET
};

map<string, OpCode> op_map = {
    {"MOV", MOV}, {"ADD", ADD}, {"SUB", SUB}, {"MUL", MUL}, {"DIV", DIV}, {"MOD", MOD},
    {"IFEQ", IFEQ}, {"IFNEQ", IFNEQ}, {"IFG", IFG}, {"IFL", IFL}, {"IFGE", IFGE}, {"IFLE", IFLE},
    {"ENDIF", ENDIF}, {"CALL", CALL}, {"RET", RET}
};

enum ArgType { REG, VAL };

struct Argument {
    ArgType type;
    int value;
};

struct Instruction {
    OpCode op;
    Argument arg1;
    Argument arg2;
    int endif_line;
};

vector<Instruction> program;
map<int, int> memo;

Argument parse_argument(const string& s) {
    if (s[0] == 'R') {
        return {REG, stoi(s.substr(1))};
    } else {
        return {VAL, stoi(s)};
    }
}

int get_value(const Argument& arg, const vector<int>& R) {
    if (arg.type == REG) {
        return R[arg.value];
    }
    return arg.value;
}

int execute(int input_param, set<int>& call_stack);

int run_instance(int input_param, set<int>& call_stack) {
    vector<int> R(10, 0);
    R[0] = input_param;
    int pc = 0;
    
    set<vector<int>> visited_states;
    int instruction_limit = 300000;

    while (pc >= 0 && pc < program.size()) {
        if (--instruction_limit < 0) {
             throw runtime_error("Loop");
        }

        vector<int> state = R;
        state.insert(state.begin(), pc);
        if (visited_states.count(state)) {
            throw runtime_error("Loop");
        }
        visited_states.insert(state);

        const Instruction& instr = program[pc];
        int val1, val2;

        switch (instr.op) {
            case MOV:
                val2 = get_value(instr.arg2, R);
                R[instr.arg1.value] = val2;
                break;
            case ADD:
                val2 = get_value(instr.arg2, R);
                R[instr.arg1.value] = (R[instr.arg1.value] + val2) % 1000;
                break;
            case SUB:
                val2 = get_value(instr.arg2, R);
                R[instr.arg1.value] = (R[instr.arg1.value] - val2 + 1000) % 1000;
                break;
            case MUL:
                val2 = get_value(instr.arg2, R);
                R[instr.arg1.value] = (R[instr.arg1.value] * val2) % 1000;
                break;
            case DIV:
                val2 = get_value(instr.arg2, R);
                if (val2 == 0) R[instr.arg1.value] = 0;
                else R[instr.arg1.value] /= val2;
                break;
            case MOD:
                val2 = get_value(instr.arg2, R);
                if (val2 == 0) R[instr.arg1.value] = 0;
                else R[instr.arg1.value] %= val2;
                break;
            
            case IFEQ: case IFNEQ: case IFG: case IFL: case IFGE: case IFLE: {
                val1 = get_value(instr.arg1, R);
                val2 = get_value(instr.arg2, R);
                bool condition = false;
                if (instr.op == IFEQ) condition = (val1 == val2);
                else if (instr.op == IFNEQ) condition = (val1 != val2);
                else if (instr.op == IFG) condition = (val1 > val2);
                else if (instr.op == IFL) condition = (val1 < val2);
                else if (instr.op == IFGE) condition = (val1 >= val2);
                else if (instr.op == IFLE) condition = (val1 <= val2);
                
                if (!condition) {
                    pc = instr.endif_line;
                }
                break;
            }

            case ENDIF:
                break;

            case CALL:
                val1 = get_value(instr.arg1, R);
                R[9] = execute(val1, call_stack);
                break;

            case RET:
                val1 = get_value(instr.arg1, R);
                return val1;
        }
        pc++;
    }
    return -1;
}

int execute(int input_param, set<int>& call_stack) {
    if (call_stack.count(input_param)) {
        throw runtime_error("Loop");
    }
    if (memo.count(input_param)) {
        return memo[input_param];
    }
    if (call_stack.size() > 1001) {
        throw runtime_error("Loop");
    }

    call_stack.insert(input_param);
    int result = run_instance(input_param, call_stack);
    call_stack.erase(input_param);
    
    memo[input_param] = result;
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int L, N;
    while (cin >> L >> N && (L != 0 || N != 0)) {
        program.assign(L, Instruction());
        string line;
        getline(cin, line);

        for (int i = 0; i < L; ++i) {
            getline(cin, line);
            stringstream ss(line);
            string cmd_str;
            ss >> cmd_str;
            program[i].op = op_map[cmd_str];
            
            if (program[i].op != ENDIF) {
                string args_str;
                if (ss >> args_str) {
                    size_t comma_pos = args_str.find(',');
                    if (comma_pos != string::npos) {
                        program[i].arg1 = parse_argument(args_str.substr(0, comma_pos));
                        program[i].arg2 = parse_argument(args_str.substr(comma_pos + 1));
                    } else {
                        program[i].arg1 = parse_argument(args_str);
                    }
                }
            }
        }

        stack<int> if_stack;
        for (int i = 0; i < L; ++i) {
            OpCode op = program[i].op;
            if (op >= IFEQ && op <= IFLE) {
                if_stack.push(i);
            } else if (op == ENDIF) {
                if (!if_stack.empty()) {
                    program[if_stack.top()].endif_line = i;
                    if_stack.pop();
                }
            }
        }
        
        memo.clear();
        try {
            set<int> initial_call_stack;
            cout << execute(N, initial_call_stack) << "\n";
        } catch (const runtime_error& e) {
            cout << "*\n";
        }
    }

    return 0;
}
