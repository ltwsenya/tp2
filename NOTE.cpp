#include "NOTE.h"

NOTE::NOTE() : lastName(nullptr), firstName(nullptr), phoneNumber(nullptr) {
    std::cout << "NOTE default constructor called" << std::endl;
}

NOTE::NOTE(const char* lastName, const char* firstName, const char* phoneNumber, int day, int month, int year)
        : lastName(new char[strlen(lastName) + 1]), firstName(new char[strlen(firstName) + 1]), phoneNumber(new char[strlen(phoneNumber) + 1]) {
    strcpy(this->lastName, lastName);
    strcpy(this->firstName, firstName);
    strcpy(this->phoneNumber, phoneNumber);
    this->birthday[0] = day;
    this->birthday[1] = month;
    this->birthday[2] = year;
    std::cout << "NOTE parameterized constructor called" << std::endl;
}

NOTE::NOTE(const NOTE& other)
        : lastName(new char[strlen(other.lastName) + 1]), firstName(new char[strlen(other.firstName) + 1]), phoneNumber(new char[strlen(other.phoneNumber) + 1]) {
    strcpy(this->lastName, other.lastName);
    strcpy(this->firstName, other.firstName);
    strcpy(this->phoneNumber, other.phoneNumber);
    this->birthday[0] = other.birthday[0];
    this->birthday[1] = other.birthday[1];
    this->birthday[2] = other.birthday[2];
    std::cout << "NOTE copy constructor called" << std::endl;
}

NOTE::~NOTE() {
    delete[] lastName;
    delete[] firstName;
    delete[] phoneNumber;
    std::cout << "NOTE destructor called" << std::endl;
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

void NOTE::setBirthday(int day, int month, int year) {
    this->birthday[0] = day;
    this->birthday[1] = month;
    this->birthday[2] = year;
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

void NOTE::getBirthday(int& day, int& month, int& year) const {
    day = birthday[0];
    month = birthday[1];
    year = birthday[2];
}

std::ostream& operator<<(std::ostream& os, const NOTE& note) {
    os << "Last Name: " << note.getLastName() << std::endl;
    os << "First Name: " << note.getFirstName() << std::endl;
    os << "Phone Number: " << note.getPhoneNumber() << std::endl;
    int day, month, year;
    note.getBirthday(day, month, year);
    os << "Birthday: " << day << "/" << month << "/" << year << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, NOTE& note) {
    char buffer[256];
    is.getline(buffer, 256);
    note.setLastName(buffer);
    is.getline(buffer, 256);
    note.setFirstName(buffer);
    is.getline(buffer, 256);
    note.setPhoneNumber(buffer);
    int day, month, year;
    is >> day >> month >> year;
    note.setBirthday(day, month, year);
    return is;
}

NOTE& NOTE::operator=(const NOTE& other) {
    if (this == &other) return *this;

    delete[] lastName;
    delete[] firstName;
    delete[] phoneNumber;

    lastName = new char[strlen(other.lastName) + 1];
    firstName = new char[strlen(other.firstName) + 1];
    phoneNumber = new char[strlen(other.phoneNumber) + 1];

    strcpy(lastName, other.lastName);
    strcpy(firstName, other.firstName);
    strcpy(phoneNumber, other.phoneNumber);

    birthday[0] = other.birthday[0];
    birthday[1] = other.birthday[1];
    birthday[2] = other.birthday[2];

    std::cout << "NOTE assignment operator called" << std::endl;
    return *this;
}

