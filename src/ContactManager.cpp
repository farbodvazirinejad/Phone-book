#include "../include/ContactManager.h"
#include <iostream>
#include <algorithm>
#include <fstream>
#include <string>
#include <sstream>

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

    for (const auto& contact : contacts)
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

// ---------------------------------------------------------------------------------------
// show all contact

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

// ---------------------------------------------------------------------------------------
// save file in CSV file
void ContactManager::saveToCSV(const string &filename) const
{
    ofstream file(filename);

    if (!file.is_open())
    {
        cerr << "Error: Cannot open file " << filename << " for writing!" << endl;
        return;
    }

    // header of CSV file
    file << "ID,FirstName,LastName,Phone,Email,Address,Type,BirthDate,NationalCode,CompanyName" << endl;

    // add general info of contact to the file
    for (const auto &contact : contacts)
    {
        file << contact->getId() << ','
             << contact->getFirstName() << ','
             << contact->getLastName() << ','
             << contact->getPhoneNumber() << ','
             << contact->getEmail() << ','
             << contact->getAddress() << ',';

        // add unique info of legan and real contact
        if (dynamic_cast<RealPerson *>(contact.get()))
        {
            auto *real = (RealPerson *)contact.get();
            file << "Real," << real->getBirthDate() << ',' << real->getNationalCode() << ',';
        }
        else
        {
            auto *Legal = (LegalPerson *)contact.get();
            file << "Legal,,," << Legal->getCompanyName();
        }
        file << endl;
        cout << "Data saved successfully" << endl; 
    }
    file.close();
    cout << "Data saved successfully" << endl; 
}

// ---------------------------------------------------------------------------------------
// load contact data
void ContactManager::loadFromCSV(const string &filename)
{
    ifstream file(filename);

    if (!file.is_open())
    {
        cout << "No saved data found." << endl;
        return;
    }

    string line;
    bool isHeader = true;

    while (getline(file, line))
    {
        // skip header line
        if (isHeader)
        {
            isHeader = false;
            continue;
        }

        if (line.empty())
            continue;

        // Line-by-line review
        stringstream ss(line);
        string token;
        vector<string> tokens;

        while (getline(ss, token, ','))
        {
            tokens.push_back(token);
        }

        // check the token number
        if (tokens.size() < 10)
        {
            cerr << "Skipping invalid line: " << line << endl;
            continue;
        }

        // Information extraction
        int id = stoi(tokens[0]); // stoi is string to integer in <string> library
        string fName = tokens[1];
        string lName = tokens[2];
        string phone = tokens[3];
        string email = tokens[4];
        string address = tokens[5];
        string type = tokens[6];
        string birth = tokens[7];
        string national = tokens[8];
        string companyName = tokens[9];

        // cread contact
        if (type == "Real")
        {
            contacts.push_back(make_shared<RealPerson>(id, fName, lName, phone, email, address, birth, national));
        }
        else if (type == "Legal")
        {
            contacts.push_back(make_shared<LegalPerson>(id, fName, lName, phone, email, address, companyName));
        }

        else 
        {
            cerr << "Unknown type: " << type << endl;
            continue;
        }
        // update nextId
        if (id >= nextId)
        {
            nextId = id + 1;
        }
    }

    file.close();
    cout << "Data loaded successfully." << endl;
}
