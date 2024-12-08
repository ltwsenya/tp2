#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <cstring>

class NOTE {
private:
    char* lastName;
    char* firstName;
    char* phoneNumber;
    int* birthday;

public:
    // Конструкторы
    NOTE();
    NOTE(const char* lastName, const char* firstName, const char* phoneNumber, int* birthday);
    NOTE(const NOTE& other);

    // Деструктор
    ~NOTE();

    // Методы доступа
    void setLastName(const char* lastName);
    void setFirstName(const char* firstName);
    void setPhoneNumber(const char* phoneNumber);
    void setBirthday(int* birthday);

    const char* getLastName() const;
    const char* getFirstName() const;
    const char* getPhoneNumber() const;
    const int* getBirthday() const;

    // Перегрузка операторов
    NOTE& operator=(const NOTE& other);
    friend std::ostream& operator<<(std::ostream& os, const NOTE& note);
    friend std::istream& operator>>(std::istream& is, NOTE& note);

    // Сравнение по дате рождения
    bool operator<(const NOTE& other) const;
};

#endif // NOTE_H
