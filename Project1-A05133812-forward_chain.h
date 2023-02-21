#include<iostream>
#include<vector>
#include<string>
#include <iterator>
#include<map>
#include<queue>

using namespace std;

class Forward_Chaining{
    public:
        map<int,string> forward_knowledge_base;
        map<string,string> forward_variable_list;
        map<int,string> forward_clause_variable;
        map<int,string> forward_kbase_conditions;
        map<int,string> forward_conclusion_answer_list;
        queue<string> forward_conclusion_queue;
        map<string,string> forward_questions;
        map<int,string *> check;
        Forward_Chaining();
        string Prevention_FW(string p);
};