#include <iostream>

#include <string>
#include "Book.h"

using namespace std;

void Book::Hello(){
    cout << "Hello" << endl;
}

Book::Book(std::string _title, std::string _author, int _year, std::string _isbn, bool _isAvailable, std::string _borrowedBy){
    title = _title;
    author = _author;
    
    year = _year;
    
    
    isAvailable = _isAvailable;
    borrowedBy = _borrowedBy;

    if (_year < 1450 || _year > 2025){
        std::string error = "Неверный год издания. Повторите попытку.";
        throw error;
    }
    else if (1450 <= _year && _year <= 2025){
        _year = year;
    }
    
    if (_isbn == ""){
        std::string error = "Ошибка: пустой ISBN. Повторите попытку.";
        throw error;
    }
    else if (_isbn != ""){
        isbn = _isbn;
    }
    
    

}
void Book::borrowBook(const std::string& userName){
    isAvailable = false;
    borrowedBy = userName;
}
void Book::returnBook() {
    isAvailable = true;
    borrowedBy = "";
}
void Book::displayInfo() {
    cout << "BOOK" << endl;
    cout << "Title: " << title << endl;
    cout << "Author: " << author << endl;
    cout << "Year: " << year << endl;
    cout << "ISBN: " << isbn << endl;
    cout << "Available: ";
    if (isAvailable) cout << "yes" << endl;
    else cout << "no" << endl;
    cout << "BorrowedBy: " << borrowedBy << endl;

}

std::string Book::getTitle(){
    return title;
}

std::string Book::getAuthor(){
    return author;
}

int Book::getYear(){
    return year;
}

std::string Book::getIsbn(){
    return isbn;
}

bool Book::getIsAvailable(){
    return isAvailable;
}

std::string Book::getBorrowedBy(){
    return borrowedBy;
}



