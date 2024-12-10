#include "NOTE.h"
#include <iostream>
#include <cstring>
#include <stdexcept>

NOTE::NOTE() {
    lastName = new char[1];
    firstName = new char[1];
    phoneNumber = new char[1];
    birthDate = new int[3];
    std::cout << "Default constructor called for NOTE object." << std::endl;
}

NOTE::NOTE(const char* lastName, const char* firstName, const char* phoneNumber, int day, int month, int year) {
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
    this->phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy(this->phoneNumber, phoneNumber);
    this->birthDate = new int[3];
    this->birthDate[0] = day;
    this->birthDate[1] = month;
    this->birthDate[2] = year;
    std::cout << "Parameterized constructor called for NOTE object." << std::endl;
}

NOTE::NOTE(const NOTE& other) {
    lastName = new char[strlen(other.lastName) + 1];
    strcpy(lastName, other.lastName);
    firstName = new char[strlen(other.firstName) + 1];
    strcpy(firstName, other.firstName);
    phoneNumber = new char[strlen(other.phoneNumber) + 1];
    strcpy(phoneNumber, other.phoneNumber);
    birthDate = new int[3];
    birthDate[0] = other.birthDate[0];
    birthDate[1] = other.birthDate[1];
    birthDate[2] = other.birthDate[2];
    std::cout << "Copy constructor called for NOTE object." << std::endl;
}

NOTE::~NOTE() {
    delete[] lastName;
    delete[] firstName;
    delete[] phoneNumber;
    delete[] birthDate;
    std::cout << "Destructor called for NOTE object." << std::endl;
}

void NOTE::setLastName(const char* lastName) {
    delete[] this->lastName;
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);
}

void NOTE::setFirstName(const char* firstName) {
    delete[] this->firstName;
    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);
}

void NOTE::setPhoneNumber(const char* phoneNumber) {
    delete[] this->phoneNumber;
    this->phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy(this->phoneNumber, phoneNumber);
}

void NOTE::setBirthDate(int day, int month, int year) {
    if (day < 1 || day > 31 || month < 1 || month > 12 || year < 1900 || year > 2100) {
        throw std::invalid_argument("Invalid birth date.");
    }
    this->birthDate[0] = day;
    this->birthDate[1] = month;
    this->birthDate[2] = year;
}

const char* NOTE::getLastName() const {
    return lastName;
}

const char* NOTE::getFirstName() const {
    return firstName;
}

const char* NOTE::getPhoneNumber() const {
    return phoneNumber;
}

const int* NOTE::getBirthDate() const {
    return birthDate;
}

std::ostream& operator<<(std::ostream& os, const NOTE& note) {
    os << "Last Name: " << note.getLastName() << "\n";
    os << "First Name: " << note.getFirstName() << "\n";
    os << "Phone Number: " << note.getPhoneNumber() << "\n";
    os << "Birth Date: " << note.getBirthDate()[0] << "/" << note.getBirthDate()[1] << "/" << note.getBirthDate()[2] << "\n";
    return os;
}

std::istream& operator>>(std::istream& is, NOTE& note) {
    char buffer[256];
    int day, month, year;

    std::cout << "Enter Last Name: ";
    is.getline(buffer, 256);
    note.setLastName(buffer);

    std::cout << "Enter First Name: ";
    is.getline(buffer, 256);
    note.setFirstName(buffer);

    std::cout << "Enter Phone Number: ";
    is.getline(buffer, 256);
    note.setPhoneNumber(buffer);

    std::cout << "Enter Birth Date (day month year): ";
    is >> day >> month >> year;
    note.setBirthDate(day, month, year);

    return is;
}

NOTE& NOTE::operator=(const NOTE& other) {
    if (this == &other) return *this;

    delete[] lastName;
    delete[] firstName;
    delete[] phoneNumber;
    delete[] birthDate;

    lastName = new char[strlen(other.lastName) + 1];
    strcpy(lastName, other.lastName);
    firstName = new char[strlen(other.firstName) + 1];
    strcpy(firstName, other.firstName);
    phoneNumber = new char[strlen(other.phoneNumber) + 1];
    strcpy(phoneNumber, other.phoneNumber);
    birthDate = new int[3];
    birthDate[0] = other.birthDate[0];
    birthDate[1] = other.birthDate[1];
    birthDate[2] = other.birthDate[2];

    return *this;
}

bool NOTE::compareBirthDates(const NOTE& note1, const NOTE& note2) {
    for (int i = 2; i >= 0; --i) {
        if (note1.getBirthDate()[i] != note2.getBirthDate()[i]) {
            return note1.getBirthDate()[i] < note2.getBirthDate()[i];
        }
    }
    return false;
}
