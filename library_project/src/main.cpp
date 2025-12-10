#include <iostream>
using namespace std;
#include <string>
#include "Book.h"

int main(){
    Book b = Book("123", "123", 1450, "123", true, "qwerty");
    b.returnBook();
    b.borrowBook("adsfgerg");
    b.displayInfo();
    
    return 0;
}