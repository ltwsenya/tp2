#include "NOTE.h"

NOTE::NOTE() {
    lastName = nullptr;
    firstName = nullptr;
    phoneNumber = nullptr;
    birthday = nullptr;
    std::cout << "Default constructor called for NOTE" << std::endl;
}

NOTE::NOTE(const char* lastName, const char* firstName, const char* phoneNumber, int* birthday) {
    this->lastName = new char[strlen(lastName) + 1];
    strcpy(this->lastName, lastName);

    this->firstName = new char[strlen(firstName) + 1];
    strcpy(this->firstName, firstName);

    this->phoneNumber = new char[strlen(phoneNumber) + 1];
    strcpy(this->phoneNumber, phoneNumber);

    this->birthday = new int[3];
    std::copy(birthday, birthday + 3, this->birthday);

    std::cout << "Parameterized constructor called for NOTE" << std::endl;
}

NOTE::NOTE(const NOTE& other) {
    lastName = new char[strlen(other.lastName) + 1];
    strcpy(lastName, other.lastName);

    firstName = new char[strlen(other.firstName) + 1];
    strcpy(firstName, other.firstName);

    phoneNumber = new char[strlen(other.phoneNumber) + 1];
    strcpy(phoneNumber, other.phoneNumber);

    birthday = new int[3];
    std::copy(other.birthday, other.birthday + 3, birthday);

    std::cout << "Copy constructor called for NOTE" << std::endl;
}

NOTE::~NOTE() {
    delete[] lastName;
    delete[] firstName;
    delete[] phoneNumber;
    delete[] birthday;
    std::cout << "Destructor called for NOTE" << std::endl;
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

void NOTE::setBirthday(int* birthday) {
    delete[] this->birthday;
    this->birthday = new int[3];
    std::copy(birthday, birthday + 3, this->birthday);
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

const int* NOTE::getBirthday() const {
    return birthday;
}

NOTE& NOTE::operator=(const NOTE& other) {
    if (this == &other) return *this;

    delete[] lastName;
    delete[] firstName;
    delete[] phoneNumber;
    delete[] birthday;

    lastName = new char[strlen(other.lastName) + 1];
    strcpy(lastName, other.lastName);

    firstName = new char[strlen(other.firstName) + 1];
    strcpy(firstName, other.firstName);

    phoneNumber = new char[strlen(other.phoneNumber) + 1];
    strcpy(phoneNumber, other.phoneNumber);

    birthday = new int[3];
    std::copy(other.birthday, other.birthday + 3, birthday);

    std::cout << "Assignment operator called for NOTE" << std::endl;
    return *this;
}

std::ostream& operator<<(std::ostream& os, const NOTE& note) {
    os << "Last Name: " << note.lastName << std::endl;
    os << "First Name: " << note.firstName << std::endl;
    os << "Phone Number: " << note.phoneNumber << std::endl;
    os << "Birthday: " << note.birthday[0] << "/" << note.birthday[1] << "/" << note.birthday[2] << std::endl;
    return os;
}

std::istream& operator>>(std::istream& is, NOTE& note) {
    char buffer[256];

    std::cout << "Enter Last Name: ";
    is.getline(buffer, 256);
    note.setLastName(buffer);

    std::cout << "Enter First Name: ";
    is.getline(buffer, 256);
    note.setFirstName(buffer);

    std::cout << "Enter Phone Number: ";
    is.getline(buffer, 256);
    note.setPhoneNumber(buffer);

    int birthday[3];
    std::cout << "Enter Birthday (day month year): ";
    is >> birthday[0] >> birthday[1] >> birthday[2];
    note.setBirthday(birthday);

    return is;
}

bool NOTE::operator<(const NOTE& other) const {
    for (int i = 2; i >= 0; --i) {
        if (birthday[i] != other.birthday[i]) {
            return birthday[i] < other.birthday[i];
        }
    }
    return false;
}
