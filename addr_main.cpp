#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>

#include "person.h"
#include "csv.h"
#include "sms.h"

using namespace std;

void displayScreen(vector<string> v);
/*
typedef enum Group {
    FAMILY,
    FRIEND,
    COWORKER,
    ETC
};*/



int main(int argc, char** argv) {
    
    vector<pair<string, Person*> > vector_name_;
    unordered_map<int, Person*> map_number_;
    vector<string> menu = {"1. CallHistory", "2. MessageHistory", "3. Contacts"};
    vector<string> contact_menu = {"1. Add Person", "2. Delete Person", "3. Find By Name", "4. Find By Number", "5. Load Data", "6. Save Data"};
    char op;
    do {
        
        displayScreen(menu);
        cout << "quit for (q)" << endl;
        cout << "choose number : ";
       
        cin >> op;
        ifstream msgFile("sms.csv");
        ifstream callFile("call.csv");

        Sms sms;
        //Call call;
        CsvRead read;

        string name;
        int number;
        string group;
        Person p;
        char op_detail;
        switch (op) {
            case '1':
                /*
                while (!callFile.eof()) {
                    call.loadData(read.loadData(msgFile))
                }
                call.displayAll();
                */
                cout << endl;
                break;

            case '2':
                while (!msgFile.eof()) {
                    sms.loadData(read.loadData(msgFile));
                }
                sms.displayAll();
                cout << endl;
                break;

            case '3':
                
                do{
                    displayScreen(contact_menu);
                    cout << "quit for q" << endl;
                    cout << "choose option : ";
                    cin >> op_detail;
                    switch (op_detail) {
                        case '1':
                            cout << "name : ";
                            cin >> name;
                            cout << "number : ";
                            cin >> number;
                            cout << "group : ";
                            cin >> group;
                            
                            
                            p = Person(name, number, group);
                            vector_name_.push_back(make_pair(name, &p));
                            
                            cout << endl;
                            break;
                            
                        case '3':
                            cout << "input : ";
                            cin >> number;
                            p.searchByNumber(&map_number_ , number);
                            cout << endl;
                            break;
                            
                        case '4':
                            //cout << name << " " << group << endl;
                            
                            
                            cout << endl;
                            break;
                        default:
                            break;
                            

                    }
                    
                }while(op_detail!='q');
                
                cout << endl;
                break;

            default:
                break;
        }
    } while(op != 'q');
    
    
	return 0;
}


void displayScreen(vector<string> v){
    vector<string>::iterator it;
    for(it = v.begin() ; it!= v.end(); it++) {
        cout << *it << endl;
    }
    
}
