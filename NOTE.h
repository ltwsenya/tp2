#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <cstring>

class NOTE {
private:
    char* lastName;
    char* firstName;
    char* phoneNumber;
    int birthday[3]; // day, month, year

public:
    // Конструкторы
    NOTE();
    NOTE(const char* lastName, const char* firstName, const char* phoneNumber, int day, int month, int year);
    NOTE(const NOTE& other);

    // Деструктор
    ~NOTE();

    // Методы доступа
    void setLastName(const char* lastName);
    void setFirstName(const char* firstName);
    void setPhoneNumber(const char* phoneNumber);
    void setBirthday(int day, int month, int year);

    const char* getLastName() const;
    const char* getFirstName() const;
    const char* getPhoneNumber() const;
    void getBirthday(int& day, int& month, int& year) const;

    // Перегрузка операторовA
    friend std::ostream& operator<<(std::ostream& os, const NOTE& note);
    friend std::istream& operator>>(std::istream& is, NOTE& note);

    // Перегрузка оператора присваивания
    NOTE& operator=(const NOTE& other);
};

#endif // NOTE_H


