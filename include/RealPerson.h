// Include Guard
#ifndef REALPERSON_H
#define REALPERSON_H

#include "Contact.h"

class RealPerson : public Contact
{
private:
    string birthDate;
    string nationalCode;

public:
    // Constructor
    RealPerson(int id = 0,
               string fName = "",
               string lName = "",
               string phone = "",
               string email = "",
               string address = "",
               string birthDate = "",
               string nationalCode = "");

    // getter function
    string getBirthDate() const { return birthDate; }
    string getNationalCode() const { return nationalCode; }

    // setter funtion
    void setBirthDate(string date) { birthDate = date; }
    void setNationalCode(string code) { nationalCode = code; }

    //Overriding the displayInfo method
    string displayInfo() const override;
};

#endif