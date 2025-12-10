#include <iostream>
using namespace std;
#include <string>
//#include "Book.h"
//#include "User.h"
#include "Library.h"
#include <vector>

//Функция createBook для ввода данных с клавиатуры для создания экземпляра Book
//Создание этой функции не требовалось по ТЗ, но она была создана для удобного ввода

Book createBook(){

    std::string title;
    std::string author;
    int year;
    std::string isbn;
    std::string isAvailable_str;
    bool isAvailable;
    std::string borrowedBy;

    cout << "NEW BOOK" << endl;
    cout << "Title: ";
    cin >> title;
    cout << "Author: " << endl;
    cout << "Year: ";
    cin >> year;
    cout << "ISBN: ";
    cin >> isbn;
    cout << "Available: ";
    if (isAvailable_str == "yes" || isAvailable_str == "YES") isAvailable = true;
    else if (isAvailable_str == "no" || isAvailable_str == "NO") isAvailable = false;
    cout << "BorrowedBy: ";
    cin >> borrowedBy;


    Book b = Book(title, author, year, isbn, isAvailable, borrowedBy);
    return b;

}


User createUser(){

    std::string name;
    std::string userId;
    int borrowedBooks_cnt;
    std::string new_book;
    std::vector<std::string> borrowedBooks;
    int maxBooksAllowed;

    cout << "NEW USER" << endl;
    cout << "Name: ";
    cin >> name;
    cout << "UserID: ";
    cin >> userId;
    cout << "Number of Borrowed Books: ";
    cin >> borrowedBooks_cnt;

    for (int i = 0; i < borrowedBooks_cnt; i++){
        cin >> new_book;
        borrowedBooks.push_back(new_book);
    }
    
    cout << "MaxBooks: ";
    cin >> maxBooksAllowed;

    User u = User(name, userId, borrowedBooks, maxBooksAllowed);
    return u;

}



int main(){
    
    
    Library lib = Library();
    

    int choice;
    do{
    cout << "=== БИБЛИОТЕКА ===\n"
    "1. Просмотреть все книги\n"
    "2. Просмотреть всех пользователей\n"
    "3. Добавить новую книгу\n"
    "4. Зарегистрировать пользователя\n"
    "5. Выдать книгу пользователю\n"
    "6. Принять книгу от пользователя\n"
    "7. Поиск книги по ISBN\n"
    "8. Просмотреть профиль пользователя\n"
    "9. Сохранить данные в файл\n"
    "10. Выход\n"
    "Ваш выбор: ";

    cin >> choice;
    if (choice == 1){
        lib.displayAllBooks();
    }
    else if (choice == 2){
        lib.displayAllUsers();
    }
    else if (choice == 3){
        Book b = createBook();
        lib.addBook(b);


    }
    else if (choice == 4){
        User u = createUser();
        lib.addUser(u);
    }
    else if (choice == 5){
        /*std::string name = u.getName();
        std::string isbn = b1.getIsbn();

        lib.borrowBook(name, isbn);*/
    }
    else if (choice == 6){
        /*std::string isbn = b1.getIsbn();
        lib.returnBook(isbn);*/
    }
    else if (choice == 7){
        /*std::string isbn = b1.getIsbn();
        lib.findBookByISBN(isbn);*/
    }
    else if (choice == 8){
        std::string name;
        cin >> name;
        cout << "Введите фамилию пользователя для просмотра профиля: ";

        User* ptr = lib.findUserByName(name);
        if (ptr == nullptr){
            cout << "Пользователь с такой фамилией не найден. Повторите попытку" << endl;
        }
        else{
            User u = *ptr;
            u.displayProfile();
        }
        
    }
    else if (choice == 9){
        lib.saveToFile();
    }
        
    else if (!(1 <= choice && choice <= 10)){
        cout << endl;
        cout << "Нет такого выбора. Повторите попытку" << endl;
        cout << endl;
    }

    
    }while(choice != 10);
    return 0;
}