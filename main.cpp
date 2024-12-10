#include <iostream>
#include "NOTE.h"
#include <stdexcept>

void addNote(NOTE*& notes, int& count, int position) {
    if (position < 0 || position > count) {
        throw std::out_of_range("Invalid position for adding note.");
    }
    NOTE* newNotes = new NOTE[count + 1];
    for (int i = 0; i < position; ++i) {
        newNotes[i] = notes[i];
    }
    std::cin >> newNotes[position];
    for (int i = position; i < count; ++i) {
        newNotes[i + 1] = notes[i];
    }
    delete[] notes;
    notes = newNotes;
    ++count;
}

void deleteNote(NOTE*& notes, int& count, int position) {
    if (position < 0 || position >= count) {
        throw std::out_of_range("Invalid position for deleting note.");
    }
    NOTE* newNotes = new NOTE[count - 1];
    for (int i = 0; i < position; ++i) {
        newNotes[i] = notes[i];
    }
    for (int i = position + 1; i < count; ++i) {
        newNotes[i - 1] = notes[i];
    }
    delete[] notes;
    notes = newNotes;
    --count;
}

void editNote(NOTE*& notes, int count, int position) {
    if (position < 0 || position >= count) {
        throw std::out_of_range("Invalid position for editing note.");
    }
    std::cin >> notes[position];
}

void sortNotes(NOTE*& notes, int count) {
    for (int i = 0; i < count - 1; ++i) {
        for (int j = 0; j < count - i - 1; ++j) {
            if (!NOTE::compareBirthDates(notes[j], notes[j + 1])) {
                NOTE temp = notes[j];
                notes[j] = notes[j + 1];
                notes[j + 1] = temp;
            }
        }
    }
}

void findNoteByPhone(NOTE* notes, int count, const char* phoneNumber) {
    for (int i = 0; i < count; ++i) {
        if (strcmp(notes[i].getPhoneNumber(), phoneNumber) == 0) {
            std::cout << notes[i] << std::endl;
            return;
        }
    }
    std::cout << "No note found with the given phone number." << std::endl;
}

void displayNotes(NOTE* notes, int count) {
    if (count == 0) {
        std::cout << "No notes available." << std::endl;
        return;
    }
    for (int i = 0; i < count; ++i) {
        std::cout << "Note " << i + 1 << ":\n";
        std::cout << notes[i] << std::endl;
    }
}

int main() {
    NOTE* notes = nullptr;
    int count = 0;
    int choice;

    while (true) {
        std::cout << "Menu:\n";
        std::cout << "1. Add Note\n";
        std::cout << "2. Delete Note\n";
        std::cout << "3. Edit Note\n";
        std::cout << "4. Sort Notes\n";
        std::cout << "5. Find Note by Phone Number\n";
        std::cout << "6. Display All Notes\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();

        try {
            if (choice == 1) {
                int position;
                std::cout << "Enter position to add note: ";
                std::cin >> position;
                std::cin.ignore();
                addNote(notes, count, position);
            } else if (choice == 2) {
                int position;
                std::cout << "Enter position to delete note: ";
                std::cin >> position;
                std::cin.ignore();
                deleteNote(notes, count, position);
            } else if (choice == 3) {
                int position;
                std::cout << "Enter position to edit note: ";
                std::cin >> position;
                std::cin.ignore();
                editNote(notes, count, position);
            } else if (choice == 4) {
                sortNotes(notes, count);
            } else if (choice == 5) {
                char phoneNumber[20];
                std::cout << "Enter phone number to find: ";
                std::cin.getline(phoneNumber, 20);
                findNoteByPhone(notes, count, phoneNumber);
            } else if (choice == 6) {
                displayNotes(notes, count);
            } else if (choice == 7) {
                break;
            } else {
                std::cout << "Invalid choice. Please try again." << std::endl;
            }
        } catch (const std::exception& e) {
            std::cerr << "Exception: " << e.what() << std::endl;
        }
    }

    delete[] notes;
    return 0;
}
