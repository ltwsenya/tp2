#ifndef NOTE_H
#define NOTE_H

#include <iostream>
#include <cstring>
#include <stdexcept>

class NOTE {
private:
    char* lastName;
    char* firstName;
    char* phoneNumber;
    int* birthDate; // массив из трех чисел: день, месяц, год

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
    void setBirthDate(int day, int month, int year);

    const char* getLastName() const;
    const char* getFirstName() const;
    const char* getPhoneNumber() const;
    const int* getBirthDate() const;

    // Перегрузка операторов
    friend std::ostream& operator<<(std::ostream& os, const NOTE& note);
    friend std::istream& operator>>(std::istream& is, NOTE& note);

    // Перегрузка оператора присваивания
    NOTE& operator=(const NOTE& other);

    // Метод для сравнения дат рождения
    static bool compareBirthDates(const NOTE& note1, const NOTE& note2);
};

#endif // NOTE_H
