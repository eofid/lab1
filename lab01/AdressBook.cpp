#include "AdressBook.h"
#include <iostream>

using namespace std;

void AddressBook::addContact() {
    string name;
    string phone;
    string email;
    cout << "������� ���: ";
    cin >> name;
    cout << "������� �������: ";
    cin >> phone;
    cout << "������� email: ";
    cin >> email;

    contacts.emplace_back(name, phone, email);
    cout << "������� ��������!\n";
}

void AddressBook::editContact() {
    string name;
    cout << "������� ��� �������� ��� ��������������: ";
    cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            cout << "�������������� �������� " << contact.name << endl;
            cout << "������� ����� ���: ";
            cin >> contact.name;
            cout << "������� ����� �������: ";
            cin >> contact.phone;
            cout << "������� ����� email: ";
            cin >> contact.email;
            cout << "������� ��������!\n";
            return;
        }
    }
    cout << "������� �� ������!\n";
}

void AddressBook::deleteContact() {
    string name;
    cout << "������� ��� �������� ��� ��������: ";
    cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            cout << "������� ������!\n";
            return;
        }
    }
    cout << "������� �� ������!\n";
}

void AddressBook::searchContact() const {
    string name;
    cout << "������� ��� ��� ������: ";
    cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "���: " << contact.name << endl;
            cout << "�������: " << contact.phone << endl;
            cout << "Email: " << contact.email << endl;
            return;
        }
    }
    cout << "������� �� ������!\n";
}

void AddressBook::displayContacts() const {
    if (contacts.empty()) {
        cout << "�������� ����� �����.\n";
        return;
    }

    for (const auto& contact : contacts) {
        cout << "���: " << contact.name << endl;
        cout << "�������: " << contact.phone << endl;
        cout << "Email: " << contact.email << endl;
        cout << "-------------------\n";
    }
}
