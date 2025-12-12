#include "Library.h"


Library::Library(){

}
Library::Library(std::vector<Book> _books, std::vector<User> _users, std::string _dataFile){
    books = _books;
    users = _users;
    dataFile = _dataFile;

    /*std::ifstream in;
    in.open(dataFile);

    std::string type;
    std::string title;
    std::string author;
    int year;
    std::string isbn;
    std::string isAvailable;
    std::string borrowedBy;

    std::string name;
    std::string userId;
    std::string borrowedBooks;
    std::vector<
    int maxBooksAllowed;

    cin >> type;
    while(type == "BOOK"){
        cin >> title >> author >> year >> isbn >> isAvailable >> borrowedBy >> type;
        if (isAvailable == "yes" || isAvailable == "YES")
            Book b = Book(title, author, year, isbn, true, borrowedBy);
        else if (isAvailable == "no" || isAvailable == "NO"){
            Book b = Book(title, author, year, isbn, false, borrowedBy);
        }
    }

    cin >> type;
    
    while((type == "---USERS---" || type == "USER")){
        cin >> type >> name >> userId >> borrowedBooks >> maxBooksAllowed;
        
        }
    }*/


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

    if (b->getIsAvailable() == false){
        std::string error = "Ошибка: книга уже занята.";
        throw error;
    }
    
    if (b->getBorrowedBy() == u->getName()){
        std::string error = "Вы уже взяли эту книгу.";
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

    if (b->getIsAvailable() == true){
        std::string error = "Эта книга уже возвращена.";
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
    std::ofstream out;
    out.open(dataFile);

    for (int i = 0; i < books.size(); i++){
        out << "BOOK" << endl;
        out << "Title: " << books[i].getTitle() << endl;
        out << "Author: " << books[i].getAuthor() << endl;
        out << "Year: " << books[i].getYear() << endl;
        out << "ISBN: " << books[i].getIsbn() << endl;
        out << "Available: ";
        if (books[i].getIsAvailable()) out << "yes" << endl;
        else out << "no" << endl;
        out << "BorrowedBy: " << books[i].getBorrowedBy() << endl;
    }
    
    out << "---USERS---" << endl;

    for (int i = 0; i < users.size(); i++){
        out << "USER" << endl;
        out << "Name: " << users[i].getName() << endl;
        out << "UserId: " << users[i].getUserId() << endl;
        out << "BorrowedBooks: ";
        std::vector<std::string> bbooks = users[i].getBorrowedBook();
        for (int i = 0; i < bbooks.size(); ++i){
            if (i)
                out << "|" <<bbooks[i];
            else
                out << bbooks[i];
        }
        out << endl;
        out << "MaxBooks: " << users[i].getMaxBooksAllowed() << endl;
    }
}
void Library::loadFromFile(){

}