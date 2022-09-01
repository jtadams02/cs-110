#include <iostream>
#include <string>

#include "p3.h"

using namespace std;

Info::Info() {
    this->name = "No Name Set";
    this->value = "No Value Set";
    this->next = nullptr;
}

Info::Info(std::string name, std::string value, Info *next) {
    this->name = name;
    this->value = value;
    this->next = next;
}

Contact::Contact() {
    this->first = "No First Set";
    this->last = "No Last Set";
    this->next = nullptr;
    this->headInfoList = nullptr;
}

Contact::Contact(std::string first, std::string last, Contact *next) {
    this->first = first;
    this->last = last;
    this->next = next;
    this->headInfoList = nullptr;
}

ContactList::ContactList() {
    this->headContactList = nullptr;
    this->count = 0;
}

int ContactList::getCount() {
    return this->count;
}

// print the specified contact and its information
// 1. return false and print nothing if the contact is not in the list
// 2. otherwise return true and print the contact
bool ContactList::printContact(std::ostream &os, std::string first, std::string last) {
    //Searches to make sure contact is in list
    bool doesHave = search(first,last);
    if(doesHave)
    {
        //Logically should return contact that it finds and then prints it with its info
        Contact* curNode = headContactList->next;
        Contact* foundNode = new Contact();
        while(curNode!=nullptr)
        {
            if(curNode->first==first && curNode->last==last)
            {
                foundNode = curNode;
            }
            curNode = curNode->next;
        }

        os << "Contact Name: " << foundNode->first << " " << foundNode->last << endl;
        if(foundNode->headInfoList->next!=nullptr)
        {
            Info *curNode = foundNode->headInfoList->next;
            if(curNode->next==nullptr)
            {
                os << "    " << curNode->name << " | " << curNode->value << endl;
            }
            while(curNode!=nullptr)
            {
                os << "    " << curNode->name << " | " << curNode->value << endl;
                curNode = curNode->next;
            }
        }
        return true;
    }
    return false;
}

// print all contacts and their information
// print nothing if the list is empty
void ContactList::print(std::ostream &os) {
    if(count == 0){return;}
    //Creates copy of List
    Contact* curNode = headContactList->next;
    //Should loop through until its null
    while(curNode!=nullptr)
    {
        cout << "Contact Name: " << curNode->first << " " << curNode->last << endl;
        if(curNode->headInfoList!=nullptr)
        {
            if(curNode->headInfoList->next!=nullptr)
            {
                Info *infoNode = curNode->headInfoList->next;
                while(infoNode!=nullptr)
                {
                    cout << "    " << infoNode->name << " | " << infoNode->value << endl;
                    infoNode = infoNode->next;
                }
            }
            }
            curNode = curNode->next;
        }
    }
// add a contact to the back of the list
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the back of the list
// - do not forget to update count
bool ContactList::addContact(std::string first, std::string last) {
    bool doesHave = search(first,last);
    if(!doesHave)
    {
        cout << "\nNo Matching contacts, beginning creation" << endl;
        Contact* curNode = new Contact();
        curNode->first = first;
        curNode->last = last;
        curNode->next = nullptr;
        curNode->headInfoList = nullptr;
        //If First is Empty
        cout << "New Contact temp-made, Looking where to put new contact" << endl;
        if(headContactList==nullptr)
        {
            cout << "Initializing headContactList and adding new Contact to next" << endl;

            Contact *newHead = new Contact();
            cout << "Node newHead created, trying to append now" << endl;
            headContactList = newHead;
            headContactList->next = curNode;
            cout << "Successfully added Contact ot headContactlist->next, adding to counter" << endl;
            count++;
            return true;
        } else{
        //Create temp Contact which will go to end of current contact list
        //Once at end, adds curNode to the end
        Contact* temp = headContactList->next;
        while(temp->next!=nullptr)
        {
            temp = temp->next;
        }
        temp->next = curNode;
        count++;
        cout << "Contact Added at End" << endl;
        return true;
        }
    }

    return false;
}

// add info to the back of a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the back of the contact's list and return true
bool ContactList::addInfo(std::string first, std::string last, std::string infoName, std::string infoVal) {
    cout << "Adding Info" << endl;
    bool doesHave = search(first,last);
    cout << "Searching for Contact that matches" << endl;
    if(doesHave)
    {
        cout << "Contact found, now looking for Info" << endl;
        //bool doesHaveInfo = searchInfo(first,last,infoName,infoVal);
        cout << "Info searched!" << endl;
        if(true){
            cout << "Info not present, adding info to List" << endl;
            Contact* curNode = headContactList->next;
            Contact* foundNode = new Contact();
            while(curNode!=nullptr)
            {
                if(curNode->first==first && curNode->last==last)
                {
                    foundNode = curNode;
                }
                curNode = curNode->next;
            }

            Info *newNode = new Info();
            newNode->name = infoName;
            newNode->value = infoVal;
            newNode->next = nullptr;

            if(foundNode->headInfoList==nullptr)
            {
                cout << "headInfoList empty, initializing..." << endl;
                Info* headNode = new Info();
                headNode->next = newNode;
                foundNode->headInfoList = headNode;
                cout << "headInfoList initialized, empty but points to newNode" << endl;
                return true;
            }else {
                Info* temp = foundNode->headInfoList->next;
                while(temp!=nullptr)
                {
                    if(temp->name==infoName)
                    {
                        cout << "infoName exists, updating value" << endl;
                        temp->value=infoVal;
                        return true;
                        
                    }
                    temp = temp->next;
                }
                temp->next = newNode;
                cout << "Info added at tail" << endl;
                return true;
            }
        }
        return false;
    }
    return false;
}

// add a contact to the list in ascending order by last name
//     if last names are equal, then order by first name ascending
// 1. return false and do nothing if the contact is already in the list
// 2. otherwise return true and add the contact to the list
// - do not forget to update count
// - compare strings with the built-in comparison operators: <, >, ==, etc.
// - a compare method/function is recommended
bool ContactList::addContactOrdered(std::string first, std::string last) {
    bool doesHave = search(first,last);
    if(!doesHave)
    {
        cout << "Contact List does not have a match, begin comparing" << endl;
        Contact* curNode = new Contact();
        curNode->first = first;
        curNode->last = last;
        curNode->next = nullptr;
        curNode->headInfoList = nullptr;
        cout << "New Contact created, looking where to palce" << endl;
        //If First is Empty
        if(headContactList==nullptr)
        {
            cout << "Contact List is empty, initalizing head" << endl;
            Contact* newHead = new Contact();
            headContactList = newHead;
            headContactList->next = curNode;
            count++;
            cout << "Contact head intialized, no alphabetical conversions needed" << endl;
            return true;
        } else 
        if(headContactList!=nullptr)
        {
            if(headContactList->next==nullptr)
            {
                cout << "Contact head is initialized, however next is null, adding curNode" << endl;
                headContactList->next = curNode;
                count++;
                cout << "Added to head, no alphabetical comparisons needed" << endl;
                return true;
            } else if (headContactList->next!=nullptr)
            {
                cout << "Contact head is initialized and next has a value, comparison time" << endl;
                Contact* startNode = headContactList->next;
                if(last<=startNode->last)
                {
                    cout << "New Last is less/equal than first" << endl;
                    if(last==startNode->last)
                    {
                        cout << "Contact last equals the last of the start, comparing first names now" << endl;
                        if(first<=startNode->first)
                        {
                            cout <<"New Contact first name comes first, throwing it first" << endl;
                            headContactList->next = curNode;
                            curNode->next = startNode;
                            count++;
                            return true;
                        } else{
                            cout <<"New Contact name does not come first, throwing it after first" << endl;
                            curNode->next = startNode->next;
                            startNode->next = curNode;
                            count++;
                            return true;
                        }
                    } 
                    cout <<"New Contact last name comes first, throwing it first" << endl;
                            headContactList->next = curNode;
                            curNode->next = startNode;
                            count++;
                            return true;
                } else if(last>startNode->last)
                {
                    cout<<"New Contact last name does not come before first, time to search through everything"<<endl;
                    if(startNode->next!=nullptr)
                    {
                        Contact* compareNode = startNode->next;
                        if(compareNode->next==nullptr)
                        {
                            if(last<=compareNode->last)
                            {
                                cout << "New Last is less/equal than first" << endl;
                                if(last==compareNode->last)
                                {
                                    cout << "New Last is equal to second, checking first" <<endl;
                                    if(first<=compareNode->first)
                                    {
                                        cout << "New First is less than second first, throwing it before" << endl;
                                        startNode->next = curNode;
                                        curNode->next = compareNode;
                                        count++;
                                        return true;
                                    } else {
                                        cout << "New first does not come first, throwing it after" <<endl;
                                        curNode->next = compareNode->next;
                                        compareNode->next = curNode;
                                        count++;
                                        return true;
                                    }
                                }
                                cout << "New Last is just less, throwing it first" << endl;
                                startNode->next = curNode;
                                curNode->next = compareNode;
                                count++;
                                return true;
                            } 
                        }

                        while(compareNode->next!=nullptr)
                        {
                            Contact* tempCompare = compareNode->next;
                            if(last<=tempCompare->last)
                            {
                                cout << "New Last is less/equal than first" << endl;
                                if(last==tempCompare->last)
                                {
                                    cout << "New Last is equal to second, checking first" <<endl;
                                    if(first<=tempCompare->first)
                                    {
                                        cout << "New First is less than second first, throwing it before" << endl;
                                        curNode->next = compareNode->next;
                                        compareNode->next = curNode;
                                        count++;
                                        return true;
                                    } else {
                                        cout << "New first does not come first, throwing it after" <<endl;
                                        curNode->next = tempCompare->next;
                                        compareNode->next = curNode;
                                        count++;
                                        return true;
                                    }
                                }
                                cout << "New Last is just less, throwing it first" << endl;
                                curNode->next = compareNode->next;
                                compareNode->next = curNode;
                                count++;
                                return true;
                            } else { 
                            compareNode = compareNode->next;
                            }
                        }
                    } else {
                        cout << "There is nothing after first value, dropping newContact after first" << endl;
                        startNode->next = curNode;
                        count++;
                        return true;
                    }
                }
            } 
        }
    }
    return false;
}

// add info to a contact's info list in ascending order by infoName
// 1. return false and do nothing if the contact is not in the list
// 2. if the infoName is already in the info list, update the infoValue and return true
// 3. otherwise add the info to the contact's list and return true
bool ContactList::addInfoOrdered(std::string first, std::string last, std::string infoName, std::string infoVal) 
{
    bool doesHave = search(first,last);
    if(doesHave)
    {
        Contact* curNode = headContactList->next;
        Contact* foundNode = new Contact();
        while(curNode!=nullptr)
            {
                if(curNode->first==first && curNode->last==last)
                {
                    foundNode = curNode;
                }
                curNode = curNode->next;
            }
        Info *newNode = new Info();
            newNode->name = infoName;
            newNode->value = infoVal;
            newNode->next = nullptr;
        Info *tempInfo = foundNode->headInfoList;
        if(tempInfo==nullptr)
        {
            cout << "Info is empty, initializing head" << endl;
            Info* newHead = new Info();
            newHead->next = newNode;
            foundNode->headInfoList = newHead;
            cout << "head initialized, no comparisons needed" << endl;
            return true;
        } else if(tempInfo!=nullptr)
        {
            if(tempInfo->next==nullptr)
            {
                cout << "head initialized but no data, no comparison neede" << endl;
                tempInfo->next = newNode;
                return true;
            } else {
                Info* prevNode = tempInfo;
                Info* loopNode = tempInfo->next;
                while(loopNode!=nullptr)
                {
                    if(infoName<=loopNode->name)
                    {
                        cout << "Info is less/equal than current value" << endl;
                        if(infoName==loopNode->name)
                        {
                            cout <<"infoNames are the same, updating value" << endl;
                            loopNode->value = infoVal;
                            return true;
                        } else {
                            cout << "Info is just less than current value" << endl;
                            prevNode->next = newNode;
                            newNode->next = loopNode;
                            return true;
                        }
                    }
                    prevNode = prevNode->next;
                    loopNode = loopNode->next;
                }
                cout << "No info matches, adding to end" << endl;
                prevNode->next = newNode;
                return true;
            }

        }


    } 
    cout << "Contact does not exist" << endl;
    return false;
}

// remove the contact and its info from the list
// 1. return false and do nothing if the contact is not in the list
// 2. otherwise return true and remove the contact and its info
// - do not forget to update count
bool ContactList::removeContact(std::string first, std::string last) {
    bool doesHave = search(first,last);
    if(doesHave)
    {
        cout << "Contact exists, moving on to Deletion" << endl;
        Contact* curNode = headContactList->next;
        if(curNode->first==first && curNode->last==last)
        {
            cout << "Deleting at the head, updating count" << endl;
            headContactList->next = curNode->next;
            count--;
            return true;
        } else {
        while(curNode!=nullptr)
        {
            Contact* followNode = curNode->next;
            if(followNode->first==first && followNode->last==last)
            {
                curNode->next = followNode->next;
                cout << "Skipping over matching Contact, updating count" << endl;
                count--;
                return true;
            }
            curNode = curNode->next;
        }
        }
    }
    return false;
}

// remove the info from a contact's info list
// 1. return false and do nothing if the contact is not in the list
// 2. return false and do nothing if the info is not in the contact's info list
// 3. otherwise return true and remove the info from the contact's list
bool ContactList::removeInfo(std::string first, std::string last, std::string infoName) {
    bool doesHave = search(first,last);
    if(doesHave)
    {
        cout << "Contact exists, moving on to find Info" << endl;

        //Getting specified Contact
        Contact* curNode = headContactList->next;
        Contact* foundNode = new Contact();
        while(curNode!=nullptr)
        {
            if(curNode->first==first && curNode->last==last)
            {
                foundNode = curNode;
            }
            curNode = curNode->next;
        }
        cout << "Should have grabbed Contact requested" << endl;
        //Should have grabbed contact, now to search info
        //Returns false if no info is present
        if(foundNode->headInfoList==nullptr){cout<<"No Info Present"<<endl;return false;}else{
        //Now searches through linked list
            cout << "Selected Contact, now creating Info tempNode" << endl;
            Info* temp = foundNode->headInfoList->next;
            if(temp->next==nullptr)
            {
                if(temp->name==infoName)
                {
                    cout << "info located at head with nothing following" << endl;
                    foundNode->headInfoList = temp->next;
                    return true;
                } else {cout<<"info does not match"<<endl;return false;}
            } else {
                if(temp->name==infoName)
                {
                    cout << "info located at head with more following" << endl;
                    foundNode->headInfoList->next = temp->next;
                    return true;
                }
            while(temp->next!=nullptr)
            {
                Info* followNode = temp->next;
                cout << "Created followNode for Info stream" << endl;
                if(followNode->name==infoName)
                {
                    cout<<"InfoName Found! Removing"<<endl;
                    temp->next = followNode->next;
                    return true;
                }
                temp = temp->next;
            }}
        }
    }
    return false;
}

// destroy the list by removing all contacts and their infos
ContactList::~ContactList() 
{
    Contact* curNode = headContactList;
    Contact* tempNode = headContactList;
    while(curNode!=nullptr)
    {
        tempNode = curNode->next;
        free(curNode);
        curNode = tempNode;
    }
}

// deep copy the source list
// - do not forget to update count
ContactList::ContactList(const ContactList &src) 
{
    Contact* modNode = src.headContactList;
        headContactList = modNode;
        count = src.count;
}

// remove all contacts and their info then deep copy the source list
// - do not forget to update count
const ContactList &ContactList::operator=(const ContactList &src) {
    if (this != &src) {
        Contact* curNode = headContactList;
        Contact* tempNode = headContactList;
        while(curNode!=nullptr)
        {
            tempNode = curNode->next;
            free(curNode);
            curNode = tempNode;
        }
        //Contact List should be destroyed
        Contact* modNode = src.headContactList;
        headContactList = modNode;
        count = src.count;
    }
    return *this;
}


bool ContactList::search(string first, string last)
{
    //Creates Node to use for search
    cout << "Starting Search" << endl;
    if(headContactList==nullptr){cout<<"Head is empty"<<endl;return false;}else
    {
    Contact *curNode = headContactList->next;
    cout << "Created search Contact curNode" << endl;
    //Loops through list until end
    while(curNode!=nullptr)
    {
        //Checks if the values are the same and returns true if they are, if not contiues loop
        if(curNode->first==first && curNode->last==last)
        {
            return true;
        }
        curNode = curNode->next;
    }
    }
    return false; 
}

bool ContactList::searchInfo(std::string first, std::string last, std::string infoName, std::string infoVal)
{
    Contact* curNode = headContactList->next;
    Contact* foundNode = new Contact();
    bool isMatched = false;
    while(curNode!=nullptr)
    {
        if(curNode->first==first && curNode->last==last)
        {
            foundNode = curNode;
            isMatched = true;
        }
        curNode = curNode->next;
    }
    cout << "Grabbed a Node" << endl;
    if(isMatched)
    {
        Info* infoList = foundNode->headInfoList;
        cout << "Created infoList" << endl;
        if(infoList == nullptr)
        {
            cout << "No Info Exists" << endl;
            return false;
        }else{
            while(infoList!=nullptr)
            {
                if(infoList->name == infoName && infoList->value== infoVal)
                {
                    cout << "Info has a Match" << endl;
                    return true;
                }
                infoList = infoList->next;
            }
        }
    }
    return false;
    
}

