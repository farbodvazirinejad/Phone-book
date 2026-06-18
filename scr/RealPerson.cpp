#include "../include/RealPerson.h"

// constructor
RealPerson ::RealPerson(int id = 0,
                        string fName = "",
                        string lName = "",
                        string phone = "",
                        string email = "",
                        string address = "",
                        string birthDate = "",
                        string nationalCode = "")
    : Contact(id, fName, lName, phone, email, address),
      birthDate(birthDate), nationalCode(nationalCode) {}

// Overriding the displayInfo method
string RealPerson ::displayInfo() const
{
    return Contact::displayInfo() +
           "\n Type: Real Person" +
           "\n Birt Date: " + birthDate  +
           "\n National Code: " + nationalCode;
}

