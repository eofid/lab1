#include "AdressBook.h"
#include <iostream>

using namespace std;

void AddressBook::addContact() {
    string name;
    string phone;
    string email;
    cout << "Введите имя: ";
    cin >> name;
    cout << "Введите телефон: ";
    cin >> phone;
    cout << "Введите email: ";
    cin >> email;

    contacts.emplace_back(name, phone, email);
    cout << "Контакт добавлен!\n";
}

void AddressBook::editContact() {
    string name;
    cout << "Введите имя контакта для редактирования: ";
    cin >> name;

    for (auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Редактирование контакта " << contact.name << endl;
            cout << "Введите новое имя: ";
            cin >> contact.name;
            cout << "Введите новый телефон: ";
            cin >> contact.phone;
            cout << "Введите новый email: ";
            cin >> contact.email;
            cout << "Контакт обновлен!\n";
            return;
        }
    }
    cout << "Контакт не найден!\n";
}

void AddressBook::deleteContact() {
    string name;
    cout << "Введите имя контакта для удаления: ";
    cin >> name;

    for (auto it = contacts.begin(); it != contacts.end(); ++it) {
        if (it->name == name) {
            contacts.erase(it);
            cout << "Контакт удален!\n";
            return;
        }
    }
    cout << "Контакт не найден!\n";
}

void AddressBook::searchContact() const {
    string name;
    cout << "Введите имя для поиска: ";
    cin >> name;

    for (const auto& contact : contacts) {
        if (contact.name == name) {
            cout << "Имя: " << contact.name << endl;
            cout << "Телефон: " << contact.phone << endl;
            cout << "Email: " << contact.email << endl;
            return;
        }
    }
    cout << "Контакт не найден!\n";
}

void AddressBook::displayContacts() const {
    if (contacts.empty()) {
        cout << "Адресная книга пуста.\n";
        return;
    }

    for (const auto& contact : contacts) {
        cout << "Имя: " << contact.name << endl;
        cout << "Телефон: " << contact.phone << endl;
        cout << "Email: " << contact.email << endl;
        cout << "-------------------\n";
    }
}
