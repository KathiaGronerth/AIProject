#include<iostream>
#include<string>
#include <iterator>
#include<map>
#include<stack>

using namespace std;

class Backward_Chaining{
    public:
        map<int,string> backward_knowledge_base;
        map<int,string> backward_kbase_conditions;
        map<int,string> backward_conclusion_list;
        map<int,string> backward_conclusion_answer_list;
        map<int,string> backward_clause_variable_list;
        map<string,string> backward_conclusion_answer;
        map<string,string> backward_variable_list;
        map<string,string> backward_questions;
        stack<int> backward_rule_num;
        stack<int> backward_clause_num;
        map<int, int> conclusion1; 
        map<string, string> conclusion2; 
        Backward_Chaining();
        string NetworkAttack_BW();
        void Question();
};