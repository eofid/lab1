#include <iostream>
#include <vector>
#include <string>
#include <locale>

using namespace std;

class Contact {
public:
    string name;
    string phone;
    string email;

    Contact(const string& name, const string& phone, const string& email)
        : name(name), phone(phone), email(email) {}
};

class AddressBook {
private:
    vector<Contact> contacts;

public:
    // Функция для добавления нового контакта
    void addContact(const Contact& contact) {
        contacts.push_back(contact);
        cout << "Контакт добавлен!\n";
    }

    // Функция для редактирования существующего контакта
    void editContact(const string& name) {
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

    // Функция для удаления контакта
    void deleteContact(const string& name) {
        for (auto it = contacts.begin(); it != contacts.end(); ++it) {
            if (it->name == name) {
                contacts.erase(it);
                cout << "Контакт удален!\n";
                return;
            }
        }
        cout << "Контакт не найден!\n";
    }

    // Функция для поиска контакта по критерию
    void searchContact(const string& name) const {
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

    // Функция для отображения всех контактов
    void displayContacts() const {
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
};

void showMenu() {
    cout << "1. Добавить контакт\n";
    cout << "2. Редактировать контакт\n";
    cout << "3. Удалить контакт\n";
    cout << "4. Поиск контакта\n";
    cout << "5. Вывести все контакты\n";
    cout << "6. Выход\n";
    cout << "Выберите опцию: ";
}

int main() {
    setlocale(LC_ALL,"rus");
    AddressBook addressBook;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, phone, email;
            cout << "Введите имя: ";
            cin >> name;
            cout << "Введите телефон: ";
            cin >> phone;
            cout << "Введите email: ";
            cin >> email;
            addressBook.addContact(Contact(name, phone, email));
            break;
        }
        case 2: {
            string name;
            cout << "Введите имя контакта для редактирования: ";
            cin >> name;
            addressBook.editContact(name);
            break;
        }
        case 3: {
            string name;
            cout << "Введите имя контакта для удаления: ";
            cin >> name;
            addressBook.deleteContact(name);
            break;
        }
        case 4: {
            string name;
            cout << "Введите имя для поиска: ";
            cin >> name;
            addressBook.searchContact(name);
            break;
        }
        case 5:
            addressBook.displayContacts();
            break;
        case 6:
            cout << "Выход из программы...\n";
            break;
        default:
            cout << "Неверный выбор, попробуйте снова.\n";
        }
    } while (choice != 6);

    return 0;
}