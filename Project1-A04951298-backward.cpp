#include "Project1-A04951298-backward_chain.h"
#include<fstream>
#include<algorithm>

using namespace std;

Backward_Chaining::Backward_Chaining(){
    //We intialize knowledge base
    ifstream backward_input;
    string l;
    backward_input.open("backward_chaining/Project1-A04951298-backward_knowledge_base.txt");
    int i=10;
    while(!backward_input.eof()){
        getline(backward_input,l);
        backward_knowledge_base.insert(pair<int,string>(i,l));
        i=i+10;
    }
    backward_input.close();

    //We intialize variable list
    backward_input.open("backward_chaining/Project1-A04951298-backward_variable_list.txt");
    while(!backward_input.eof()){
        getline(backward_input,l);
        backward_variable_list.insert(pair<string,string>(l,"NO"));
    }
    backward_input.close();

    //We intialize conclusion list
    backward_input.open("backward_chaining/Project1-A04951298-backward_conclusion_list.txt");
    i=10;
    while(!backward_input.eof()){
        getline(backward_input,l);
        backward_conclusion_list.insert(pair<int,string>(i,l));
        i=i+10;
    }
    backward_input.close();

    //We intialize clause variable list
    backward_input.open("backward_chaining/Project1-A04951298-backward_clause_variable_list.txt");
    i=1;
    while(!backward_input.eof()){
        getline(backward_input,l);
        backward_clause_variable_list.insert(pair<int,string>(i,l));
        i++;
    }
    backward_input.close();

    backward_input.open("backward_chaining/Project1-A04951298-backward_kbase_condition.txt");
    i=1;
    while(!backward_input.eof()){
        getline(backward_input,l);
        backward_kbase_conditions.insert(pair<int,string>(i,l));
        i++;
    }
    backward_input.close();

    backward_input.open("backward_chaining/Project1-A04951298-backward_conclusion_stack.txt");
    i=10;
    while(!backward_input.eof()){
        getline(backward_input,l);
        backward_conclusion_answer_list.insert(pair<int,string>(i,l));
        i=i+10;
    }
    backward_input.close();

    backward_questions.insert(pair<string,string>("attack","Choose from the below options the attack experienced:"));
    backward_questions.insert(pair<string,string>("activeAttack","Is the attack involves manipulating or modifying the network traffic or system settings in order to compromise the security or availability of the targeted system or network?"));
    backward_questions.insert(pair<string,string>("integrityAttack","Is the attack compromising the integrity of data stored on a computer network?"));
    backward_questions.insert(pair<string,string>("maliciousDownloads","Are there an unintentionally downloading and installing software or files that contain harmful code or malicious programs?"));
    backward_questions.insert(pair<string,string>("noUserInteraction","Is there no user interaction?"));
    backward_questions.insert(pair<string,string>("unauthorizedAccessDirectly","Is there an unauthorized access directly?"));
    backward_questions.insert(pair<string,string>("privilegeEscalation","Is there privilege escalation?"));
    backward_questions.insert(pair<string,string>("hidePresenceOnSystem","Is there a hide presence on system?"));
    backward_questions.insert(pair<string,string>("replicateThemselves","Does the network attack replicate itself?"));
    backward_questions.insert(pair<string,string>("spreadToOtherSystems","Does it spread to other systems?"));
    backward_questions.insert(pair<string,string>("networkShares","Is it target to network shares?"));
    backward_questions.insert(pair<string,string>("removableMedia","Was the attack through removable media?"));
    backward_questions.insert(pair<string,string>("instantMessaging","Was the attack through instant messaging?"));
    backward_questions.insert(pair<string,string>("emailAttachment","Was the attack through email attachments?"));
    backward_questions.insert(pair<string,string>("spreadRapidlyAndIndependently","Does it spread rapidly and independently?"));
    backward_questions.insert(pair<string,string>("remote","was it a remote attack?"));
    backward_questions.insert(pair<string,string>("trafficAnalysis","Does it use traffic analysis?"));
    backward_questions.insert(pair<string,string>("availabilityAttack","Does the attack disrupt the availability of a network or computer system, making it inaccessible or unusable for legitimate users?"));
    backward_questions.insert(pair<string,string>("resourcesConsumption","Is there resources consumption?"));
    backward_questions.insert(pair<string,string>("floodingUselessNetworkTraffic","Is there a flooding useless network traffic?"));
    backward_questions.insert(pair<string,string>("oneLocationAttack","Is the attack from on location?"));
    backward_questions.insert(pair<string,string>("resourcesStarvation","Are there resources starvation?"));
    backward_questions.insert(pair<string,string>("disruptionOfPhysicalNetworkComponents","Is there a disruption of physical network components?"));
    backward_questions.insert(pair<string,string>("botsAndZombies","Does the attack use bots and zombies?"));
    backward_questions.insert(pair<string,string>("authenticationAttack","Does the attack attempt to gain unauthorized access to a system or application by exploiting vulnerabilities in the authentication process?"));
    backward_questions.insert(pair<string,string>("systemPerformanceDecrease","Does the system performance decrease?"));
    backward_questions.insert(pair<string,string>("sendUnwantedEmailsInBulk","Does the attack send unwanted emails in bulk?"));
    backward_questions.insert(pair<string,string>("emailsTransfersSlow","Is there slow emails transfers?"));
    backward_questions.insert(pair<string,string>("acquireUsersSensitiveInformation","Does the attack acquire users sensitive information?"));
    backward_questions.insert(pair<string,string>("networkBasedCommunications","Does the attack use network-based communications to deliver the fraudulent messages?"));
    backward_questions.insert(pair<string,string>("stealAnActiveUserSession","Does the attack intercept user's session with a server or website, takes over the session, and gains unauthorized access to the user's account or data?"));
    backward_questions.insert(pair<string,string>("attackConfidenciality","Is there any action or method used to gain unauthorized access to confidential information or to make it available to unauthorized individuals?"));
    backward_questions.insert(pair<string,string>("wirelessNetworkScanner","Does the attack use a wireless network scanner?"));
    backward_questions.insert(pair<string,string>("snifferInstalledOnNetwork","Does the attack use a sniffer installed on network?"));
    backward_questions.insert(pair<string,string>("arpSpoofing","Does the attack involve ARP Spoofing?"));
    backward_questions.insert(pair<string,string>("arpCachePoisong","Does the attack involve ARP Cache Poisong?"));
    backward_questions.insert(pair<string,string>("interceptedAndModifiedNetworkTraffic","Does the attack intercepted and modified network traffic?"));
    backward_questions.insert(pair<string,string>("phoneLines","Is the attack through phone lines?"));
    backward_questions.insert(pair<string,string>("compromisedNetworkDevice","Does it compromised the network device?"));
}

void Backward_Chaining::Question(){
    string res;
    int finalans=1;
    while(!backward_rule_num.empty()){
        finalans=1;
        int num=backward_clause_num.top();
        int crule = backward_rule_num.top(); 
        for(int i=num;i<num+39;i++){
            if(backward_clause_variable_list.at(i)!="p"){    
                string clvariable = backward_clause_variable_list.at(i);
                if(backward_variable_list.find(backward_clause_variable_list.at(i))!=backward_variable_list.end()){
                    if(backward_variable_list[backward_clause_variable_list.at(i)]=="NO"){ 
                        cout<<backward_questions[backward_clause_variable_list.at(i)]<<" -->YES/NO: ";
                        cin>>res;
                        transform(res.begin(), res.end(), res.begin(), ::toupper);
                        if(res=="YES" || res=="NO"){
                            backward_variable_list[backward_clause_variable_list.at(i)]= res;
                        } else {
                            cout<<"The input is wrong:"<<"\n"<<"Please enter only YES or NO \n";
                            cout<<backward_questions[backward_clause_variable_list.at(i)]<<" -->YES/NO: ";
                            cin>>res;
                            transform(res.begin(), res.end(), res.begin(), ::toupper);
                            backward_variable_list[backward_clause_variable_list.at(i)]= res;
                        }
                    }
                    if(backward_variable_list[backward_clause_variable_list.at(i)]==backward_kbase_conditions[i]){
                        finalans=1;
                        continue;
                    } else {
                        finalans=0;
                        conclusion1.insert(pair<int,int>(backward_rule_num.top(),finalans));
                        string found_conclusion = backward_conclusion_list[backward_rule_num.top()];
                        if(found_conclusion != "networkAttack")
                        {
                            conclusion2.insert(pair<string,string>(found_conclusion, "NO"));
                        }
                        backward_rule_num.pop();
                        backward_clause_num.pop();
                        break;       
                    }
                } else {
                    
                    if(conclusion1.find(crule) != conclusion1.end()){
                        backward_clause_num.pop();
                        backward_rule_num.pop();
                       
                        continue;
                    }

                    if((conclusion2.find(clvariable) != conclusion2.end()) && conclusion2.at(clvariable) == "YES") {
                        continue;
                    } else {
                        if((conclusion2.find(clvariable) != conclusion2.end()) && conclusion2.at(clvariable) == "NO"){
                            backward_clause_num.pop();
                            backward_rule_num.pop();
                            string found_conclusion = backward_conclusion_list[crule];
                            if(found_conclusion != "networkAttack") {
                                conclusion2.insert(pair<string,string>(found_conclusion, "NO"));
                            }
                            break;
                        }
                        
                        for (auto itr = backward_conclusion_list.begin(); itr != backward_conclusion_list.end(); itr++){
                            
                            if((clvariable== itr->second) && itr->second!= "networkAttack"){
                                int clause_no = (((itr->first / 10) - 1) * 39) + 1;


                                //clause number = number_variables*(rule/10-1)+1;
                                backward_rule_num.push(itr->first);
                                backward_clause_num.push(clause_no);
                                break;
                            }
                            
                        }
                        break;
                        }
                    }
                } else {

            if(i - num == 38) {
                    string conclusion = backward_conclusion_list.at(backward_rule_num.top());
                    if(conclusion == "networkAttack"){
                        conclusion2.insert(pair<string,string>(conclusion, backward_conclusion_answer_list.at(backward_rule_num.top())));
                    } else {
                        conclusion2.insert(pair<string,string>(conclusion, "YES"));
                    }
                    backward_clause_num.pop();
                    backward_rule_num.pop();
                }
                continue;
            }

            int finished_processing_clause = backward_clause_num.top();
            backward_clause_num.pop();
            finished_processing_clause++;
            backward_clause_num.push(finished_processing_clause);
        }
    }
}
    
string Backward_Chaining::NetworkAttack_BW() {
    int i=10;
    string ans = "";
    while(i<=360) {
        if("networkAttack"==backward_conclusion_list.at(i)){
            backward_rule_num.push(i);
            backward_clause_num.push((((i/10)-1)*39)+1);
            Question();
            if(conclusion2.find("networkAttack") != conclusion2.end()){   
                 ans = conclusion2["networkAttack"];
                if ( ans == "NO" ){
                    cout<<endl;
                    cout<<"The network attack could not be determined:"<<endl;
                    cout<<endl;
                } else {
                    return ans;
                }
                break;
            }
        }

        i=i+10;
    }   

    if(ans==""){
        cout << "---------------------------------------------------------------------------" << endl << endl;
        cout << "Apologize that a rule could not be found to determine the network attack.  " << endl;
        cout << "---------------------------------------------------------------------------" << endl << endl;
    } 
    
    return ans;
    
}

