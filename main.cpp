#include <iostream>
#include <algorithm>
#include "NOTE.h"

void addNote(NOTE*& notes, int& count) {
    NOTE* temp = new NOTE[count + 1];
    for (int i = 0; i < count; ++i) {
        temp[i] = notes[i];
    }
    delete[] notes;
    notes = temp;
    std::cin >> notes[count];
    ++count;
}

void sortNotes(NOTE* notes, int count) {
    std::sort(notes, notes + count);
}

void findByPhoneNumber(NOTE* notes, int count, const char* phoneNumber) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(notes[i].getPhoneNumber(), phoneNumber) == 0) {
            std::cout << notes[i] << std::endl;
            return;
        }
    }
    std::cout << "No record found with the given phone number." << std::endl;
}

int main() {
    NOTE* notes = nullptr;
    int count = 0;
    int choice;

    do {
        std::cout << "1. Add Note\n2. Sort Notes\n3. Find by Phone Number\n4. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        switch (choice) {
            case 1:
                addNote(notes, count);
                break;
            case 2:
                sortNotes(notes, count);
                break;
            case 3: {
                char phoneNumber[256];
                std::cout << "Enter Phone Number to search: ";
                std::cin.getline(phoneNumber, 256);
                findByPhoneNumber(notes, count, phoneNumber);
                break;
            }
            case 4:
                std::cout << "Exiting..." << std::endl;
                break;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    } while (choice != 4);

    delete[] notes;
    return 0;
}
