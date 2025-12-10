#include <iostream>
using namespace std;
#include <string>
//#include "Book.h"
//#include "User.h"
#include "Library.h"
#include <vector>

int main(){
    vector<std::string> books;
    
    books.push_back("isbn1");
    books.push_back("isbn2");
    books.push_back("isbn3");
    Book b1 = Book("123", "123", 1450, "123", true, "qwerty");
    User u = User("name", "123", books, 10);
    
    Library lib = Library();
    lib.addBook(b1);
    lib.addUser(u);

    Book b2 = Book("456", "456", 2025, "456", false, "asdsdf");
    lib.addBook(b2);

    lib.displayAllBooks();
    cout << endl;
    lib.displayAllUsers();


    return 0;
}