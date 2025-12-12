#include <iostream>
#include <string>
#include <vector>

using namespace std;

#include "User.h"

User::User(std::string _name, std::string _userId, std::vector<std::string> _borrowedBooks, int _maxBookAllowed=3){
    name = _name;
    userId = _userId;
    borrowedBooks = _borrowedBooks;
    maxBooksAllowed = _maxBookAllowed;
    
    if (borrowedBooks.size() > maxBooksAllowed){
        std::string error = "Ошибка: превышен лимит максимального количества взятых книг.";
        throw error;
    }
}
bool User::canBorrowMore(){
    int n = borrowedBooks.size();
    if (n >= maxBooksAllowed) return false;
    return true;
}
void User::addBook(const std::string& isbn){
    //if (borrowedBooks.size() < maxBooksAllowed)
    borrowedBooks.push_back(isbn);
    //else
    //    cout << "Достигнут лимит хранения!" << endl;
}
void User::removeBook(const std::string& isbn){
    int n = borrowedBooks.size();
    for (int i = 0; i < n; i++){
        if (borrowedBooks[i] == isbn){
            borrowedBooks.erase(borrowedBooks.begin()+i);
        }
    }
}
void User::displayProfile(){
    cout << "USER" << endl;
    cout << "Name: " << name << endl;
    cout << "UserId: " << userId << endl;
    cout << "BorrowedBooks: ";
    for (int i = 0; i < borrowedBooks.size(); ++i){
        if (i)
            cout << "|" << borrowedBooks[i];
        else
            cout << borrowedBooks[i];
    }
    cout << endl;
    cout << "MaxBooks: " << maxBooksAllowed << endl;

}
std::string User::getName(){
    return name;
}
std::string User::getUserId(){
    return userId;
}
std::vector<std::string> User::getBorrowedBook(){
    return borrowedBooks;
}
int User::getMaxBooksAllowed(){
    return maxBooksAllowed;
}