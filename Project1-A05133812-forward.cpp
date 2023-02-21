#include "Project1-A05133812-forward_chain.h"
#include<fstream>
#include<algorithm>

using namespace std;

Forward_Chaining::Forward_Chaining(){
    //We initialize the knowledge base
    ifstream file_input;
    string l;
    file_input.open("forward_chaining/Project1-A05133812-forward_knowledge_base.txt");
    int i=10;
    while(!file_input.eof()){
        getline(file_input,l);
        forward_knowledge_base.insert(pair<int,string>(i,l));
        i=i+10;
    }
    file_input.close();

    //We initialize the variable list
    file_input.open("forward_chaining/Project1-A05133812-forward_variable_list.txt");
    while(!file_input.eof()){
        getline(file_input,l);
        forward_variable_list.insert(pair<string,string>(l,"NI"));
    }
    file_input.close();


    //We initialize the clause variable list
    file_input.open("forward_chaining/Project1-A05133812-forward_clause_variable.txt");
    i=1;
    while(!file_input.eof()){
        getline(file_input,l);
        forward_clause_variable.insert(pair<int,string>(i,l));
        i++;
    }
    file_input.close();

    file_input.open("forward_chaining/Project1-A05133812-forward_clause_variable.txt");
    i=10;
    while(!file_input.eof()){
        string arr[11];
        for(int j=0;j<11;j++){
            getline(file_input,l);
            if(l!="p"){
                arr[j]=l; 
            } 
        }
        check.insert(pair<int,string*>(i,arr));
        i=i+10;
    }
    file_input.close();
    file_input.open("forward_chaining/Project1-A05133812-forward_kbase_condition.txt");
    i=1;
    while(!file_input.eof()){
        getline(file_input,l);
        forward_kbase_conditions.insert(pair<int,string>(i,l));
        i++;
    }
    file_input.close();

    file_input.open("forward_chaining/Project1-A05133812-forward_conclusion_queue.txt");
    i=10;
    while(!file_input.eof()){
        getline(file_input,l);
        forward_conclusion_answer_list.insert(pair<int,string>(i,l));
        i=i+10;
    }
    //close the file
    file_input.close();

    forward_questions.insert(pair<string,string>("antidote","Is antidote available for the attack?"));
    
}


string Forward_Chaining::Prevention_FW(string prevention){
    int flag=0,f=1;
    int i=1,count=1;;
    string ans = "";
    forward_variable_list["networkAttack"]=prevention;
    if(prevention!="Apologize that a rule could not be found."){
        forward_conclusion_queue.push("networkAttack");
        int k,num=1,j,rule;
        while(i<=110){
        k=0;
           for(j=num;j<num+1;j++){
               if(forward_clause_variable.at(j)!="p"){
                    rule=(((i / 1) + 1) * 10);
                    if(forward_variable_list.at(forward_clause_variable.at(j))=="NO"){
                        string res;
                        cout<<forward_questions[forward_clause_variable.at(j)]<<" -->YES/NO: ";
                        cin>>res;
                        transform(res.begin(), res.end(), res.begin(), ::toupper);
                        if(res=="YES" || res=="NO"){
                            forward_variable_list[forward_clause_variable.at(j)]= res;
                        } else {
                            cout<<"Wrong input detected:"<<"\n"<<"Please enter only YES or NO \n";
                            cout<<forward_questions[forward_clause_variable.at(j)]<<" -->YES/NO: ";
                            cin>>res;
                            transform(res.begin(), res.end(), res.begin(), ::toupper);
                            forward_variable_list[forward_clause_variable.at(j)]= res;
                        }
                    }
                    
                    if(forward_variable_list[forward_clause_variable.at(j)]==forward_kbase_conditions[j]){
                        flag=1;
                        k++;
                    } else {
                        flag=0;
                        break;
                    }
                }
           }   
           if(flag==1){
               ans=forward_conclusion_answer_list[rule];
               forward_conclusion_queue.empty();
               break;
           }
            num=num+1;
            i=i+1;
        }
    return ans;

    } else {
        ans="Apologize that a prevention could not be determined for the given network attack";
        return ans;
    }
    
}

