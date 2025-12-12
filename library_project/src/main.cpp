#include <iostream>
using namespace std;
#include <string>
//#include "Book.h"
//#include "User.h"
#include "Library.h"
#include <vector>

//Функция createBook для ввода данных с клавиатуры для создания экземпляра Book
//Создание этой функции не требовалось по ТЗ, но она была создана для удобного ввода

Book createBook(Library& lib){

    std::string title;
    std::string author;
    int year;
    std::string isbn;
    //std::string isAvailable_str;
    bool isAvailable = true;
    std::string borrowedBy = ""; //по умолчанию книга будет доступна и не взята

    cout << "NEW BOOK" << endl;
    cout << "Title: ";
    cin >> title;
    cout << "Author: ";
    cin >> author;
    cout << "Year: ";
    cin >> year;
    cout << "ISBN: ";
    cin >> isbn;
    
    Book* bb = lib.findBookByISBN(isbn);
    if (bb){
        
        std::string error = "Ошибка: книга уже существует."; // проверка на существование тут (в main), так как нужен доступ к классу библиотеки
        throw error;                                         // проврека на существование тут, так как нужен доступ к isbn
    }
    
    
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

        try{
            Book b = createBook(lib);
            lib.addBook(b);
        }
        catch(std::string e){
            cout << e << endl;
        }

    }
    else if (choice == 4){
        User u = createUser();
        lib.addUser(u);
    }
    else if (choice == 5){
        std::string userName;
        std::string ISBN;
        cout << "Введите имя пользователя: ";
        cin >> userName;
        cout << "Введите ISBN книги: ";
        cin >> ISBN;

        
        try{
            lib.borrowBook(userName, ISBN);
        }
        catch(std::string e){
            cout << e << endl;

        }
    }
    else if (choice == 6){
        std::string userName;
        std::string ISBN;
        cout << "Введите имя пользователя: ";
        cin >> userName;
        cout << "Введите ISBN книги: ";
        cin >> ISBN;

        try{
            lib.returnBook(userName, ISBN);
        }
        catch(std::string error){
            cout << error << endl;
        }

        
    }
    else if (choice == 7){
        std::string isbn;
        cout << "Введите Isbn: ";
        cin >> isbn;

        Book* b = lib.findBookByISBN(isbn);
        if (b == nullptr){
            cout << "Книга не найдена" << endl;
        }
        else{
            cout << "Найдена книга: " << endl;
            b->displayInfo();
        }
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