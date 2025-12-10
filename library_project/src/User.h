#ifndef USER_H
#define USER_H

#include <string>
#include <vector>
class User{
    private:
        std::string name;
        std::string userId;
        std::vector<std::string> borrowedBooks;
        int maxBooksAllowed;
    public:
        User(std::string _name, std::string _userId, std::vector<std::string> _borrowedBooks, int _maxBookAllowed);
        bool canBorrowMore();
        void addBook(const std::string& isbn);
        void removeBook(const std::string& isbn);
        void displayProfile();

        std::string getName();
        std::string getUserId();
        std::vector<std::string> getBorrowedBook();
        int getMaxBooksAllowed();

};

#endif 