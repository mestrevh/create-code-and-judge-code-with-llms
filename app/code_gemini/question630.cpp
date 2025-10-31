/*
Código criado pelo Gemini Pro 2.5
Estudo para TCC (Victor Hugo Silva Ângelo - UFAL)
*/
#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <algorithm>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int N, M;
    while (std::cin >> N >> M && (N != 0 || M != 0)) {
        std::map<std::string, int> name_to_id;
        std::vector<std::string> id_to_name;
        std::vector<int> subject_priority;
        std::vector<std::vector<int>> adj;
        std::vector<int> in_degree;

        int next_id = 0;
        int next_priority = 0;

        auto get_or_create_id = [&](const std::string& name) -> int {
            if (name_to_id.find(name) == name_to_id.end()) {
                name_to_id[name] = next_id;
                id_to_name.push_back(name);
                subject_priority.push_back(next_priority++);
                adj.emplace_back();
                in_degree.push_back(0);
                return next_id++;
            }
            return name_to_id.at(name);
        };

        for (int i = 0; i < N; ++i) {
            std::string advanced_name;
            int k;
            std::cin >> advanced_name >> k;
            int advanced_id = get_or_create_id(advanced_name);
            in_degree[advanced_id] = k;

            for (int j = 0; j < k; ++j) {
                std::string prereq_name;
                std::cin >> prereq_name;
                int prereq_id = get_or_create_id(prereq_name);
                adj[prereq_id].push_back(advanced_id);
            }
        }

        int total_subjects = next_id;
        int completed_subjects = 0;
        std::vector<bool> taken(total_subjects, false);
        std::vector<std::vector<std::string>> semester_plan;

        while (completed_subjects < total_subjects) {
            std::vector<int> available_ids;
            for (int i = 0; i < total_subjects; ++i) {
                if (in_degree[i] == 0 && !taken[i]) {
                    available_ids.push_back(i);
                }
            }

            std::sort(available_ids.begin(), available_ids.end(), [&](int a, int b) {
                return subject_priority[a] < subject_priority[b];
            });

            int num_to_take = std::min((int)available_ids.size(), M);
            
            std::vector<std::string> semester_subjects_names;
            std::vector<int> taken_this_semester_ids;

            for (int i = 0; i < num_to_take; ++i) {
                int id_to_take = available_ids[i];
                taken_this_semester_ids.push_back(id_to_take);
                semester_subjects_names.push_back(id_to_name[id_to_take]);
            }
            
            for(int id_to_take : taken_this_semester_ids){
                taken[id_to_take] = true;
                completed_subjects++;
                 for (int successor_id : adj[id_to_take]) {
                    in_degree[successor_id]--;
                }
            }

            std::sort(semester_subjects_names.begin(), semester_subjects_names.end());
            semester_plan.push_back(semester_subjects_names);
        }

        std::cout << "Formatura em " << semester_plan.size() << " semestres" << std::endl;
        for (size_t i = 0; i < semester_plan.size(); ++i) {
            std::cout << "Semestre " << i + 1 << " :";
            for (const std::string& s : semester_plan[i]) {
                std::cout << " " << s;
            }
            std::cout << std::endl;
        }
    }

    return 0;
}
