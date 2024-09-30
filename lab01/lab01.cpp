#include <iostream>
#include "AdressBook.h"

using namespace std;

void showMenu() {
    cout << "1. �������� �������\n";
    cout << "2. ������������� �������\n";
    cout << "3. ������� �������\n";
    cout << "4. ����� ��������\n";
    cout << "5. ������� ��� ��������\n";
    cout << "6. �����\n";
    cout << "�������� �����: ";
}

int main() {
    setlocale(LC_ALL, "rus");
    AddressBook addressBook;
    int choice;

    do {
        showMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            addressBook.addContact();
            break;
        case 2:
            addressBook.editContact();
            break;
        case 3:
            addressBook.deleteContact();
            break;
        case 4:
            addressBook.searchContact();
            break;
        case 5:
            addressBook.displayContacts();
            break;
        case 6:
            cout << "����� �� ���������...\n";
            break;
        default:
            cout << "�������� �����, ���������� �����.\n";
        }
    } while (choice != 6);

    return 0;
}