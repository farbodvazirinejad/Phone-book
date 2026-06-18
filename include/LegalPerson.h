#ifndef LEGALPERSON_H
#define LEGALPERSON_H

#include "Contact.h"

class LegalPerson : public Contact
{
private:
    string companyName;

public:
    LegalPerson(int id = 0,
                string fName = "",
                string lName = "",
                string phone = "",
                string email = "",
                string address = "",
                string companyName = "");

    // getter
    string getCompanyName() const { return companyName; }

    // setter
    void setCompanyName(string name) { companyName = name; }

    //Overriding the displayInfo method for legal person
    string displayInfo() const override;

};

#endif