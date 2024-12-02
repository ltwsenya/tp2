#include <iostream>
#include "NOTE.h"

void addNote(NOTE*& notes, int& count) {
    NOTE* temp = new NOTE[count + 1];
    for (int i = 0; i < count; ++i) {
        temp[i] = notes[i];
    }
    delete[] notes;
    notes = temp;

    std::cout << "Enter last name: ";
    char lastName[256];
    std::cin.getline(lastName, 256);

    std::cout << "Enter first name: ";
    char firstName[256];
    std::cin.getline(firstName, 256);

    std::cout << "Enter phone number: ";
    char phoneNumber[256];
    std::cin.getline(phoneNumber, 256);

    std::cout << "Enter birthday (day month year): ";
    int day, month, year;
    std::cin >> day >> month >> year;
    std::cin.ignore();

    notes[count] = NOTE(lastName, firstName, phoneNumber, day, month, year);
    ++count;
}

void displayNotes(NOTE* notes, int count) {
    for (int i = 0; i < count; ++i) {
        std::cout << notes[i] << std::endl;
    }
}

void searchByPhoneNumber(NOTE* notes, int count) {
    std::cout << "Enter phone number to search: ";
    char phoneNumber[256];
    std::cin.getline(phoneNumber, 256);

    for (int i = 0; i < count; ++i) {
        if (strcmp(notes[i].getPhoneNumber(), phoneNumber) == 0) {
            std::cout << notes[i] << std::endl;
            return;
        }
    }
    std::cout << "No matching record found." << std::endl;
}

void sortNotesByBirthday(NOTE* notes, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            int day1, month1, year1;
            notes[j].getBirthday(day1, month1, year1);
            int day2, month2, year2;
            notes[j + 1].getBirthday(day2, month2, year2);

            if (year1 > year2 || (year1 == year2 && month1 > month2) || (year1 == year2 && month1 == month2 && day1 > day2)) {
                NOTE temp = notes[j];
                notes[j] = notes[j + 1];
                notes[j + 1] = temp;
            }
        }
    }
}

int main() {
    NOTE* notes = nullptr;
    int count = 0;
    int choice;

    do {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add a new note" << std::endl;
        std::cout << "2. Display all notes" << std::endl;
        std::cout << "3. Search by phone number" << std::endl;
        std::cout << "4. Sort notes by birthday" << std::endl;
        std::cout << "5. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                addNote(notes, count);
                break;
            case 2:
                displayNotes(notes, count);
                break;
            case 3:
                searchByPhoneNumber(notes, count);
                break;
            case 4:
                sortNotesByBirthday(notes, count);
                break;
            case 5:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 5);

    delete[] notes;
    return 0;
}
