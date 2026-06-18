#ifndef CONTACTMANAGER_H
#define CONTACTMANAGER_H

#include <memory>
#include <vector>
#include "Contact.h"
#include "LegalPerson.h"
#include "RealPerson.h"

using namespace std;

class ContactManager
{
private:
    // shared_ptr is a Smart Pointers
    vector<shared_ptr<Contact>> contacts;
    int nextId;

public:
    // constructor
    ContactManager();

    // adding contact
    void addRealPerson(string fName, string lName, string phone,
                       string email, string address,
                       string birthDate, string nationalCode);

    void addLegalPerson(string fName, string lName, string phone,
                        string email, string address,
                        string companyName);

    // searcher
    vector<shared_ptr<Contact>> searchByName(const string &name) const;
    vector<shared_ptr<Contact>> searchByPhone(const string &phone) const;

    // delete the contact
    bool deleteContact(int id);

    // sorting
    void sortByName();

    // showe
    void displayAll() const;

    // getters
    int getCount() const { return contacts.size(); }

    const vector<shared_ptr<Contact>>& getAllContacts() const { return contacts; }

    // saveing and work with file
    void saveToFile(const string &fileanme) const;
    void LoadFromFile(const string &fileanme) ;
};

#endif