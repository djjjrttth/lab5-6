#ifndef BOOK_H
#define BOOK_H
#include <iostream>
using namespace std;
#include <string>
class Book {
    public:
    void Hello();
    private:
        std::string title;
        std::string author;
        int year;
        std::string isbn;
        bool isAvailable;
        std::string borrowedBy;

    public:
        Book(std::string _title, std::string _author, int _year, std::string _isbn, bool _isAvailable, std::string _borrowedBy);
        void borrowBook(const std::string& userName);
        void returnBook();
        void displayInfo();
        std::string getTitle();
        std::string getAuthor();
        int getYear();
        std::string getIsbn();
        bool getIsAvailable();
        std::string getBorrowedBy();

        //~Book();
};


#endif //BOOK_H