#include <iostream>
using namespace std;
#include <string>
#include "Book.h"
#include "User.h"
#include <vector>

int main(){
    vector<std::string> books;
    books.push_back("isbn1");
    books.push_back("isbn2");
    books.push_back("isbn3");
    Book b = Book("123", "123", 1450, "123", true, "qwerty");
    User u = User("name", "123", books, 10);
    
    u.displayProfile();
    cout << endl;

    cout << u.canBorrowMore() << endl;
    u.addBook("isbn4");
    u.removeBook("isbn1");
    u.displayProfile();

    return 0;
}