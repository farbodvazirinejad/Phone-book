// Include Guard
#ifndef CONTACT_H
#define CONTACT_H

#include <string>
#include <ctime>
#include <stdexcept> // for using invalid_argument

using namespace std;

// create Contact class
class Contact
{
private:
    int id;
    string firstName;
    string lastName;
    string phoneNumber;
    string email;
    string address;

public:
    // Constructor
    Contact(int id = 0,
            string fName = "",
            string lName = "",
            string phone = "",
            string email = "",
            string address = "");

    virtual ~Contact() {}

    int getId() const { return id; }
    string getFirstName() const { return firstName; }
    string getLastName() const { return lastName; }
    string getPhoneNumber() const { return phoneNumber; }
    string getEmail() const { return email; }
    string getAddress() const { return address; }

    void setPhoneNumber(string phone);
    void setEmail(string email);

    string getFullName() const;
    virtual string displayInfo() const;

    static bool validatePhoneNumber(const string &phone); // string& don't copy variable
    static bool validateEmail(const string &email);
};

#endif