#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>

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

class Hash {
    int BUCKET;    // No. of buckets
public:
    // Pointer to an array containing buckets
    vector<Person> *table;

    Hash(int V);  // Constructor
 
    // inserts a key into hash table
    void insertItem(Person person, string key);
 
    // deletes a key from hash table
    //void deleteItem(int key);

    int h(uint64_t key) {
        return key % BUCKET;
    }
 
    // hash function to map values to key
    /*int hashFunction(int x) {
        return (x % BUCKET);
    }*/
 
    void displayHash();
};

Hash::Hash(int b)
{
    this->BUCKET = b;
    table = new vector<Person>[BUCKET];
}
 
void Hash::insertItem(Person person, string key)
{
    int index = 0;
    if (key == "Id") {
        index = h(djb2(person.id));
    }
    else if (key == "FirstName") {
        index = h(djb2(person.first));
    }
    else if (key == "LastName") {
        index = h(djb2(person.last));
    }
    else if (key == "Email") {
        index = h(djb2(person.email));
    }
    else if (key == "Phone") {
        index = h(djb2(person.phone));
    }
    else if (key == "City") {
        index = h(djb2(person.city));
    }
    else if (key == "State") {
        index = h(djb2(person.state));
    }
    else if (key == "PostalCode") { //(key == "PostalCode")
        index = h(djb2(person.postalCode));
    }
    //index = h(djb2(person.state));
    table[index].push_back(person);
}

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

int main(int argc, char **argv) {
    if (argc != 4) {
        cout << "Usage: ./a.out filename.txt table_size key" << endl;
        return 1;
    }

    string filename = argv[1];
    int tableSize = stoi(argv[2]);
    string key = argv[3];

    ifstream file(filename);
    if (!file) {
        cout << "Unable to open " << filename << endl;
        return 2;
    }

    if (!isValidKey(key)) {
        cout << "Invalid key: " << key << endl;
        return 3;
    }

    Hash h(tableSize);
    // This is an example of how to retreive the tokens from the input file
    // You will need to modify this to fit your needs to build the hash table
    string line, strTemp;
    getline(file, line); // consume header line
    while (getline(file, line)) {
        istringstream iss(line);
        Person temp;

        getline(iss, strTemp, '\t');
        temp.id = strTemp;
        getline(iss, strTemp, '\t');
        temp.first = strTemp;
        getline(iss, strTemp, '\t');
        temp.last = strTemp;
        getline(iss, strTemp, '\t');
        temp.email = strTemp;
        getline(iss, strTemp, '\t');
        temp.phone = strTemp;
        getline(iss, strTemp, '\t');
        temp.city = strTemp;
        getline(iss, strTemp, '\t');
        temp.state = strTemp;
        getline(iss, strTemp, '\t');
        temp.postalCode = strTemp;
        
        h.insertItem(temp, key);

        //cout << temp.id << " " << temp.last;
        //cout << endl;
    }

    cout << "Commands:" << endl << "\tprint" << endl << "\tlookup <key>" << endl << "\tquit" << endl;
    string cmd, val;
    while (1) {
        cout << endl << "Enter a command:" << endl;
        cin >> cmd;
        if (cmd == "quit") {
            break;
        }
        else if (cmd == "print") {
            // print code here
            for (int i=0; i<tableSize; i++) {
                if (h.table[i].size() != 0) {
                    if (key == "State") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].state) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].state);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                    if (key == "Id") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].id) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].id);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                    if (key == "FirstName") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].first) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].first);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                    if (key == "LastName") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].last) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].last);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                    if (key == "Email") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].email) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].email);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                    if (key == "Phone") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].phone) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].phone);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                    if (key == "City") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].city) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].city);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                    if (key == "PostalCode") {
                        vector<string> vect(0);
                        vector<int> count(0);
                        cout << i << ": ";
                        for (int j=0; j<h.table[i].size(); j++) {
                            bool found = false;
                            for (int k=0; k<vect.size(); k++) {
                                if (vect[k] == h.table[i][j].postalCode) {
                                    count[k]++;
                                    found = true;
                                    break;
                                }
                            }
                            if (found == false) {
                                vect.push_back(h.table[i][j].postalCode);
                                count.push_back(1);
                            }
                        }
                        for (int k=0; k<vect.size(); k++) {
                            cout << vect[k] << " (" << count[k] << "), ";
                        }
                        cout << endl;
                    }
                }
            }
        }
        else if (cmd == "lookup") {
            getVal(cin, val);
            if (key == "State") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].state) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
            if (key == "Id") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].id) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
            if (key == "FirstName") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].first) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
            if (key == "LastName") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].last) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
            if (key == "Email") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].email) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
            if (key == "Phone") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].phone) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
            if (key == "City") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].city) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
            if (key == "PostalCode") {
                bool found = false;
                // lookup code here
                for (int i=0; i<tableSize; i++) {
                    for (int j=0; j<h.table[i].size(); j++) {
                        if (val == h.table[i][j].postalCode) {
                            if (found == false) {
                                cout << "Id,FirstName,LastName,Email,Phone,City,State,PostalCode" << endl;
                            }
                            cout << h.table[i][j].id << "," << h.table[i][j].first << "," << h.table[i][j].last << "," << h.table[i][j].email << "," << h.table[i][j].phone << "," << h.table[i][j].city << "," << h.table[i][j].state << "," << h.table[i][j].postalCode << endl;
                            found = true;
                        }
                    }
                }
                if (found == false) {
                    cout << "No results" << endl;
                }
            }
        }
        else {
            getline(cin, val);
            cout << "Invalid command" << endl;
        }
    }

    return 0;
}
