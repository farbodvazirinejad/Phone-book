#include "../include/Contact.h"
#include <iostream>
#include <cctype>  // for using isdigit() funtion
#include <iomanip> // only for formating the date

using namespace std;

// Constructor

Contact ::Contact(int id, string fName, string lName, string phone,
                  string email, string address)
    : id(id), firstName(fName), lastName(lName),
      phoneNumber(phone), email(email), address(address) {}

//------------------------------------------------------------------------
// check Validation of user input

void Contact ::setPhoneNumber(string phone)
{
    if (validatePhoneNumber(phone))
    {
        phoneNumber = phone;
    }
    else
    {
        throw invalid_argument("The phone number is invalid!");
    }
}

void Contact::setEmail(string email)
{
    if (validateEmail(email))
    {
        this->email = email; // "this->" for the same name of variable
    }
    else
    {
        throw invalid_argument("Email is invalid!");
    }
}

//------------------------------------------------------------------------
// genetal methods
string Contact::getFullName() const
{
    return firstName + " " + lastName;
}

string Contact::displayInfo() const
{
    return "ID: " + to_string(id) +
           "\n Name: " + getFullName() +
           "\n Phone Number: " + phoneNumber +
           "\n Email: " + email +
           "\n Address: " + address;
}

//------------------------------------------------------------------------
//static mathods for Validation

bool Contact::validatePhoneNumber(const string& phone)
{
    if(phone.empty())
    {
        cerr << "The Phone number box is empty!!" <<endl;
        return false;
    }

    if (phone.length() != 11)
    {
        cerr << "The phone number must be 11 digits!" << endl;
        return false;
    }
    
    for (char c : phone)
    {
        if (!isdigit(c))
        {
            cerr << "The phone number must only contain numbers!" << endl;
            return false;
        }
    }

    return true;

}