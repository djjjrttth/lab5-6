#ifndef LIBRARY_H
#define LIBRARY_H

using namespace std;
#include <vector>
#include "Book.h"
#include "User.h"

class Library{
    private:
        std::vector<Book> books;
        std::vector<User> users;
        std::string dataFile;
    public:
        Library();
        Library(std::vector<Book> books, std::vector<User> users, std::string dataFile);
        void addBook(const Book& book);
        void addUser(const User& user);
        void borrowBook(const std::string& userName, const std::string& isbn);
        void returnBook(const std::string& userName, const std::string& isbn);
        Book* findBookByISBN(const std::string& isbn);
        User* findUserByName(const std::string& name);
        void displayAllBooks();
        void displayAllUsers();
        void saveToFile();
        void loadFromFile();
};

#endif // LIBRARY_H