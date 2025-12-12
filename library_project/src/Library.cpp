#include "Library.h"

Library::Library(){

}
Library::Library(std::vector<Book> _books, std::vector<User> _users, std::string _dataFile){
    books = _books;
    users = _users;
    dataFile = _dataFile;
}
void Library::addBook(const Book& book){
    books.push_back(book);
}

void Library::addUser(const User& user){
    users.push_back(user);
}
void Library::borrowBook(const std::string& userName, const std::string& isbn){
    Book* b = Library::findBookByISBN(isbn);
    User* u = Library::findUserByName(userName);
    
    if (u == nullptr || b == nullptr){
        std::string error = "Неверное имя пользователя или ISBN книги. Повторите попытку.";
        throw error;
    }

    if (!(u->canBorrowMore())){
        std::string error = "Невозможно взять книгу. Достигнуто макимальное количество доступных книг.";
        throw error;
        
    }

    u->addBook(isbn);
    b->borrowBook(userName);
    cout << "Книга успешно взята." << endl;


}
//в эту функцию добавлено, что передается поле userName для того, чтобы у пользователя удалить эту книгу
void Library::returnBook(const std::string& userName, const std::string& isbn){
    Book* b = Library::findBookByISBN(isbn);
    User* u = Library::findUserByName(userName);
    
    if (u == nullptr || b == nullptr){
        std::string error = "Неверное имя пользователя или ISBN книги. Повторите попытку.";
        throw error;
    }

    b->returnBook();
    u->removeBook(isbn);
    cout << "Книга успешно возвращена." << endl;

}
Book* Library::findBookByISBN(const std::string& isbn){
    Book* p = nullptr;
    for (int i = 0; i < books.size(); ++i){
        if (books[i].getIsbn() == isbn){
            p = &books[i];
        }
    }

    return p;
}

User* Library::findUserByName(const std::string& name){
    User* p = nullptr;
    for (int i = 0; i < users.size(); ++i){
        if (users[i].getName() == name)
            p = &users[i];
    }
    return p;
}
void Library::displayAllBooks(){
    if (books.size() == 0) cout << "Нет книг в библиотеке. Повторите попытку позже" << endl;
    else{
        for (int i = 0; i < books.size(); ++i){
            books[i].displayInfo();
        }
    }
}
void Library::displayAllUsers(){
    if (users.size() == 0) cout << "Нет зарегистрированных пользователей в библиотеке. Повторите попытку позже" << endl;
    else{
        for (int i = 0; i < users.size(); ++i){
            users[i].displayProfile();
        }
    }
}
void Library::saveToFile(){

}
void Library::loadFromFile(){

}