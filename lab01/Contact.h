#pragma once
#ifndef CONTACT_H
#define CONTACT_H

#include <string>

class Contact {
public:
    std::string name;
    std::string phone;
    std::string email;

    Contact(std::string name, std::string phone, std::string email);
};

#endif // CONTACT_H

