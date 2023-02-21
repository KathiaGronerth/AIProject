#include <iostream>
#include "Project1-A04951298-backward.cpp"
#include "Project1-A05133812-forward.cpp"

using namespace std;

int main() {
        //Starting the program
        cout<<"----------------------------------------------- \n";
        cout<<"    Program to determine the attack             \n";
        cout<<"----------------------------------------------- \n";
        string networkAttack;
        string prevention;
        //Object uses for backward chaining
        Backward_Chaining bc;
        //Object uses for forward chaining
        Forward_Chaining fc;
        int choice;
        int flag=1;

        while(flag!=0){
                cout<<"Please,enter your option: "<< endl;
                cout<<"1. Determine the type of attack network by selecting the consequences" << endl;  
                cout<<"2. Finish Program \n"<< endl;
                cin>>choice;
                switch (choice){
                                case 1: cout<<"Starting the system to determine the attack ... \n";
                                        cout<<"Enter YES or NO for each question asked.. \n";
                                        networkAttack=bc.NetworkAttack_BW();
                                        cout<<"-------------------------------------------------------\n";
                                        cout<<"The Network Attack is: "<<networkAttack<<"\n";
                                        cout<<"------------------------------------------------------- \n";
                                        cout<<"Starting system to determine preventions for the attack: "<<networkAttack<<"\n";
                                        cout<<"Please, enter YES or NO for each question asked. \n";
                                        prevention=fc.Prevention_FW(networkAttack);
                                        if(prevention!=""){
                                                cout<<"---------------------------------------------------------\n";
                                                cout<<"Recommended possible preventions: "<<prevention<<"       \n";
                                                cout<<"---------------------------------------------------------\n";
                                                cout<<"The program is finished. \n";
                                                flag=0;
                                        } else {
                                                cout<<"----------------------------------------------------------------------\n";
                                                cout<<"Apologize that the preventions could not be determined"<<prevention<<"\n";
                                                cout<<"----------------------------------------------------------------------\n";
                                                cout<<"The program is finished. \n";
                                                flag=0;
                                        }
                                        break;

                        case 2:         flag=0;
                                        break;

                        default:        cout<<"You choose an invalid choice. \n";
                                        flag=0;
                                        break;
                }
        }
        return 0;
}
