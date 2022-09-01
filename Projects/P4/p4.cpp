#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <list>

using namespace std;


uint64_t djb2(string str) {
    const char *ptr = str.c_str();
    uint64_t hash = 5381;
    int c;
    while ((c = *ptr++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash;
}

class Person {
public:
    string id;
    string first;
    string last;
    string email;
    string phone;
    string city;
    string state;
    string postalCode;
};

class PersonList{
    public:
    Person *headPerson;
    PersonList *next;
};

class HashTable 
{
    int size;

public:
    vector<Person> *table;
    HashTable(int size); // Constructor
    int hasherPlus(uint64_t key){return key%size;}
    void insert(Person inserter,string key);
    /*
        i dont think this is necessary at all for this project but template had this
        void deleteItem(int k);

        int hashFunc(int x);

        void displayHash()
    */
};
HashTable::HashTable(int x)
{
    this->size = x;
    table = new vector<Person>[size];
}
void HashTable::insert(Person daPerson,string key)
{
    int index = 0;
    string tempKey = key;
    //Hash them things
    if (tempKey == "Id"){index = hasherPlus(djb2(daPerson.id));}
    else if (tempKey=="FirstName"){index = hasherPlus(djb2(daPerson.first));}
    else if (tempKey=="LastName"){index = hasherPlus(djb2(daPerson.last));}
    else if (tempKey=="Email"){index = hasherPlus(djb2(daPerson.email));}
    else if (tempKey=="Phone"){index = hasherPlus(djb2(daPerson.phone));}
    else if (tempKey=="City"){index = hasherPlus(djb2(daPerson.city));}
    else if (tempKey=="State"){index = hasherPlus(djb2(daPerson.state));}
    else if (tempKey=="PostalCode"){index = hasherPlus(djb2(daPerson.postalCode));}
    //PUT THE HASH IN THE TABLE WOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO
    table[index].push_back(daPerson);
}
/*
void HashTable::displayHash()
{
    //Print Hash?
}
*/
void getVal(istream &is, string &str) {
    char ch;
    string line;

    is >> ch;
    getline(is, line);

    str = ch + line;
}

bool isValidKey(const string &key) {
    string validKeys[8] = { "Id", "FirstName", "LastName", "Email", "Phone", "City", "State", "PostalCode" };
    for (int i = 0; i < 8; i++) {
        if (key == validKeys[i]) {
            return true;
        }
    }
    return false;
}
void printId(int i, HashTable tableThingy);
void printFirst(int i, HashTable tableThingy);
void printLast(int i, HashTable tableThingy);
void printEmail(int i, HashTable tableThingy);
void printPhone(int i, HashTable tableThingy);
void printCity(int i, HashTable tableThingy);
void printState(int i, HashTable tableThingy);
void printPostalCode(int i, HashTable tableThingy);

int main(int argc, char **argv) {
    if (argc != 4) {
        cout<<"Usage: ./a.out filename.txt table_size key"<<endl;
        return 1;
    }
    string filename = argv[1];
    int tableSize = stoi(argv[2]);
    string key = argv[3];

    ifstream file(filename);
    if (!file) {
        cout<<"Unable to open "<< filename <<endl;
        return 2;
    }

    if (!isValidKey(key)) {
        cout<<"Invalid key: "<< key <<endl;
        return 3;
    }
    
    int whichKey = 0;
    string validKeys[8] = { "Id", "FirstName", "LastName", "Email", "Phone", "City", "State", "PostalCode" };
    for (int i = 0; i < 8; i++) {
        if (key == validKeys[i]) {
            whichKey=i;
        }
    }
    
    HashTable tableThingy(tableSize);


    Person *header = new Person();
    // This is an example of how to retreive the tokens from the input file
    // You will need to modify this to fit your needs to build the hash table
    string line, token;
    getline(file, line); // consume header line
    while (getline(file, line)) {
        istringstream iss(line);
        Person temp;
        int count = 0;
        while (getline(iss, token, '\t')) 
        {
            string thing = token;
            if(count==0){temp.id=thing;}
            if(count==1){temp.first=thing;}
            if(count==2){temp.last=thing;}
            if(count==3){temp.email=thing;}
            if(count==4){temp.phone=thing;}
            if(count==5){temp.city=thing;}
            if(count==6){temp.state=thing;}
            if(count==7){temp.postalCode=thing;}
            count++;
        }
        tableThingy.insert(temp,key);
    }
    cout<<"Commands:"<<endl << "\tprint"<<endl << "\tlookup <key>"<<endl << "\tquit"<<endl;
    string cmd, val;
    while (1) {
        cout<<endl << "Enter a command:"<<endl;
        cin >> cmd;
        if (cmd == "quit") {
            break;
        }
        else if (cmd == "print") {
            // print code here
            for (int i=0; i<tableSize; i++) {
                if (tableThingy.table[i].size()!=0) {
                    if (key=="Id") 
                    {
                        printId(i,tableThingy);
                        cout<<endl;
                    }
                    if (key=="FirstName") 
                    {
                        printFirst(i,tableThingy);
                        cout<<endl;
                    }

                    if (key=="LastName") {
                        printLast(i,tableThingy);
                        cout<<endl;
                    }
                    if (key=="Email") {
                        printEmail(i,tableThingy);
                        cout<<endl;
                    }
                    if (key=="Phone") {
                        printPhone(i,tableThingy);
                        cout<<endl;
                    }
                     
                    if (key=="City") {
                        printCity(i,tableThingy);
                        cout<<endl;
                        
                    }
                    if (key=="State") {
                        printState(i,tableThingy);
                        cout<<endl;
                    }
                    if (key=="PostalCode") {
                        printPostalCode(i,tableThingy);
                        cout<<endl;
                    }
                }
            }
        }
        else if (cmd == "lookup") {
            getVal(cin, val);
            string compareMe = val;
            if (key=="Id") {
                //this oens dumb
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].id) {
                            if (!formatted) {
                                // i have to do this right?
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id << ","<< tableThingy.table[i][j].first << ","<< tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
            if (key=="FirstName") {
                // Cophy paste pls worko
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].first) {
                            if (!formatted) {
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id<<","<<tableThingy.table[i][j].first<< ","<<tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
            if (key=="LastName") {
                // Cophy paste pls worko
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].last) {
                            if (!formatted) {
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id << ","<< tableThingy.table[i][j].first << ","<< tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
            if (key=="Email") {
                // Cophy paste pls worko
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].email) {
                            if (!formatted) {
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id << ","<< tableThingy.table[i][j].first << ","<< tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
            if (key=="Phone") {
                // Cophy paste pls worko
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].phone) {
                            if (!formatted) {
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id << ","<< tableThingy.table[i][j].first << ","<< tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
            if (key=="City") {
                // Cophy paste pls worko
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].city) {
                            if (!formatted) {
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id << ","<< tableThingy.table[i][j].first << ","<< tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
            if (key=="State") {
                // Cophy paste pls worko
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].state) {
                            if (!formatted) {
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id << ","<< tableThingy.table[i][j].first << ","<< tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
            if (key=="PostalCode") {
                // Cophy paste pls worko
                bool formatted = false;
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<tableThingy.table[i].size(); j++) {
                        if (compareMe==tableThingy.table[i][j].postalCode) {
                            if (!formatted) {
                                // Outputing format??
                                cout<<"Id,FirstName,LastName,Email,Phone,City,State,PostalCode"<<endl;
                            }
                            cout<<tableThingy.table[i][j].id << ","<< tableThingy.table[i][j].first << ","<< tableThingy.table[i][j].last << ","<< tableThingy.table[i][j].email << ","<< tableThingy.table[i][j].phone << ","<< tableThingy.table[i][j].city << ","<< tableThingy.table[i][j].state << ","<< tableThingy.table[i][j].postalCode <<endl;
                            formatted = true;
                        }
                    }
                }
                if (!formatted) {
                    cout<<"No results"<<endl;
                }
            }
        }
        else {
            getline(cin, val);
            
            cout<<"Invalid command"<<endl;
        }
    }

    return 0;
}

void printId(int i,HashTable tableThingy)
{
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i<< ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
        bool isThere = false;
        for (int k=0; k<vectoid.size(); k++) {
            if (vectoid[k] == tableThingy.table[i][l].id) {
                counterr[k]++;
                isThere = true;break;
            }
        }
        if (!isThere) {
            vectoid.push_back(tableThingy.table[i][l].id);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout <<vectoid[k] << " ("<<counterr[k]<< "), ";
    }
}
void printFirst(int i,HashTable tableThingy)
{
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i << ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
    bool isThere = false;
    for (int k=0; k<vectoid.size(); k++) {
        if (vectoid[k] == tableThingy.table[i][l].first) {
            counterr[k]++;
            isThere = true;break;
        }
    }
        if (!isThere) {
            vectoid.push_back(tableThingy.table[i][l].first);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout<<vectoid[k] << " ("<< counterr[k] << "), ";
    }
}
void printLast(int i, HashTable tableThingy){
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i << ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
        bool isThere = false;
        for (int k=0; k<vectoid.size(); k++) {
            if (vectoid[k] == tableThingy.table[i][l].last) {
                counterr[k]++;
                isThere = true;break;
            }
        }
        if (!isThere) {
            vectoid.push_back(tableThingy.table[i][l].last);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout<<vectoid[k] << " ("<< counterr[k] << "), ";
    }
}
void printEmail(int i, HashTable tableThingy){
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i << ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
        bool isThere = false;
        for (int k=0; k<vectoid.size(); k++) {
            if (vectoid[k] == tableThingy.table[i][l].email) {
                counterr[k]++;
                isThere = true;break;
            }
        }
        if (!isThere) {
            vectoid.push_back(tableThingy.table[i][l].email);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout<<vectoid[k] << " ("<< counterr[k] << "), ";
    }
}
void printPhone(int i, HashTable tableThingy){
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i << ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
        bool isThere = false;
        for (int k=0; k<vectoid.size(); k++) {
            if (vectoid[k] == tableThingy.table[i][l].phone) {
                counterr[k]++;
                isThere = true;break;
            }
        }
        if (!isThere) {
            vectoid.push_back(tableThingy.table[i][l].phone);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout<<vectoid[k] << " ("<< counterr[k] << "), ";
    }
}
void printCity(int i, HashTable tableThingy){
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i << ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
        bool isThere = false;
        for (int k=0; k<vectoid.size(); k++) {
            if (vectoid[k] == tableThingy.table[i][l].city) {
                counterr[k]++;
                isThere = true;break;
            }
        }
        if (!isThere) {
            vectoid.push_back(tableThingy.table[i][l].city);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout<<vectoid[k] << " ("<< counterr[k] << "), ";
    }
}
void printState(int i, HashTable tableThingy){
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i << ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
        bool isThere = false;
        for (int k=0; k<vectoid.size(); k++) {
            if (vectoid[k] == tableThingy.table[i][l].state) {
                counterr[k]++;
                isThere = true;break;
            }
        }
        if (!isThere) {
            vectoid.push_back(tableThingy.table[i][l].state);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout<<vectoid[k] << " ("<< counterr[k] << "), ";
    }

}
void printPostalCode(int i, HashTable tableThingy){
    vector<int>counterr;counterr.resize(0);
    vector<string>vectoid;vectoid.resize(0);
    cout<<i << ": ";
    for (int l=0; l<tableThingy.table[i].size(); l++) {
        bool isThere = false;
        for (int k=0; k<vectoid.size(); k++) {
            if (vectoid[k] == tableThingy.table[i][l].postalCode) {
                counterr[k]++;
                isThere = true;
                break;
            }
        }
        if(!isThere) {
            vectoid.push_back(tableThingy.table[i][l].postalCode);counterr.push_back(1);
            
        }
    }
    // PRINTING TIME!
    for (int k=0; k<vectoid.size(); k++) {
        cout<<vectoid[k] << " ("<< counterr[k] << "), ";
    }
}
