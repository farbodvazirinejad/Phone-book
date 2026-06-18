#include "../include/ContactManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>

using namespace std;

// constructor
ContactManager ::ContactManager() : nextId(1) {}

// ---------------------------------------------------------------------------------------
// adding the person
void ContactManager::addRealPerson(string fName, string lName, string phone,
                                   string email, string address,
                                   string birthDate, string nationalCode)
{
    contacts.push_back(make_shared<RealPerson>(nextId++, fName, lName, phone,
                                               email, address,
                                               birthDate, nationalCode));
}

void ContactManager::addLegalPerson(string fName, string lName, string phone,
                                    string email, string address,
                                    string companyName)
{
    contacts.push_back(make_shared<LegalPerson>(nextId++, fName, lName, phone,
                                                email, address,
                                                companyName));
}

// ---------------------------------------------------------------------------------------
// search by name
vector<shared_ptr<Contact>> ContactManager::searchByName(const string &name) const
{
    vector<shared_ptr<Contact>> result; // This is and empty vector

    // change all to lowercase
    string searchT = name;
    for (char &c : searchT)
    {
        c = tolower(c);
    }

    // check all of contacts
    for (const auto &contact : contacts)
    {
        string fullName = contact->getFullName();
        for (char &c : fullName)
        {
            c = tolower(c);
        }

        if (fullName.find(searchT) != string ::npos) // nops is means not find
        {
            result.push_back(contact);
        }
    }
    return result;
}

// ---------------------------------------------------------------------------------------
// search by phone number
vector<shared_ptr<Contact>> ContactManager ::searchByPhone(const string &phone) const
{
    vector<shared_ptr<Contact>> result;

    for (const auto contact : contacts)
    {
        string contactphone = contact->getPhoneNumber();
        if (contactphone.find(phone) != string::npos)
        {
            result.push_back(contact);
        }
    }
    return result;
}

// ---------------------------------------------------------------------------------------
// delete the contact
bool ContactManager ::deleteContact(int id)
{
    for (int i = 0; i < contacts.size(); i++)
    {
        if (contacts[i]->getId() == id)
        {
            contacts.erase(contacts.begin() + i);
            return true;
        }
    }
    return false;
}

// ---------------------------------------------------------------------------------------
// sorting
void ContactManager::sortByName()
{
    for (int i = 0; i < contacts.size() - 1; i++)
    {
        for (int j = 0; j < contacts.size() - (i + 1); j++)
        {
            if (contacts[j]->getFullName() > contacts[j + 1]->getFullName())
            {
                swap(contacts[j], contacts[j + 1]);
            }
        }
    }
}

void ContactManager::displayAll() const
{
    if (contacts.empty())
    {
        cout << "No contacts added!!" << endl;
        return;
    }

    cout << "\n Contact List (" << contacts.size() << " contacts):" << endl;

    for (const auto &contact : contacts)
    {
        cout << contact->displayInfo() << endl;
    }
}
// ذخیره در فایل (بعداً تکمیل می‌شود)
// بارگذاری از فایل (بعداً تکمیل می‌شود)
