#include <iostream>
#include <string>

using namespace std;


class Book {
    private:
        string title;
        string author;
        int year;
        string isbn;
        bool isAvailable;
        string borrowedBy;

    public:
        Book(string _title, string _author, int _year, string _isbn, bool _isAvailable, string _borrowedBy){
            title = _title;
            author = _author;
            year = _year;
            isbn = _isbn;
            isAvailable = _isAvailable;
            borrowedBy = _borrowedBy;

            /*if (1450 <= _year && _year <= 2025)
                    year = _year;
            else{
                throw "Wrong year";
            }*/

        }
        void borrowBook(const string& userName){
            isAvailable = false;
            borrowedBy = userName;
        }
        void returnBook() {
            isAvailable = true;
            borrowedBy = "";
        }
        void displayInfo() {
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

        string getTitle(){
            return title;
        }

        string getAuthor(){
            return author;
        }

        int getYear(){
            return year;
        }

        string getIsbn(){
            return isbn;
        }

        bool getIsAvailable(){
            return isAvailable;
        }

        string getBorrowedBy(){
            return borrowedBy;
        }
};


int main(){

    Book b = Book("123", "123", 1450, "123", true, "qwerty");
    b.returnBook();
    b.displayInfo();

    cout << endl;
    
    b.borrowBook("asdf");
    b.displayInfo();

}