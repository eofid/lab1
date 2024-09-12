#pragma once
#ifndef ADDRESSBOOK_H
#define ADDRESSBOOK_H

#include "Contact.h"
#include <vector>
#include <string>

class AddressBook {
private:
    std::vector<Contact> contacts;

public:
    void addContact();
    void editContact();
    void deleteContact();
    void searchContact() const;
    void displayContacts() const;
};

#endif // ADDRESSBOOK_H

