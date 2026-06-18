#include "../include/LegalPerson.h"

// constructor
LegalPerson ::LegalPerson(int id = 0,
                          string fName = "",
                          string lName = "",
                          string phone = "",
                          string email = "",
                          string address = "",
                          string companyName = "")
    : Contact(id, fName, lName, phone, email, address),
      companyName(companyName) {}

// Overriding the displayInfo method for legal person
string LegalPerson::displayInfo() const
{
    return Contact ::displayInfo() +
           "\n Type: Legal person" +
           "\n Company Name:" + companyName;
}
