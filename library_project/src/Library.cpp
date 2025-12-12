#include "Library.h"


Library::Library(){

}
Library::Library(std::vector<Book> _books, std::vector<User> _users, std::string _dataFile){
    books = _books;
    users = _users;
    dataFile = _dataFile;

    loadFromFile();
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

    out.close();
}
void Library::loadFromFile(){

    std::ifstream in;
    in.open(dataFile);

    std::string type = "BOOK";
    std::string title;
    std::string author;
    std::string str_year;
    std::string isbn;
    std::string isAvailable;
    std::string borrowedBy;
    int year;
    bool isAvail;
    std::string name;
    std::string userId;
    std::string borrowedBooks;
    
    std::string maxBooksAllowed;
    int maxBooks;
    
    while (type == "BOOK"){
        
        getline(in, type);
        if (type == "---USERS---") break;
        else{
        getline(in, title);
        getline(in, author);
        getline(in, str_year);
        getline(in, isbn);
        getline(in, isAvailable);
        getline(in, borrowedBy);

    
        
        title = title.substr(7, title.size()-7);
       
        author = author.substr(8, author.size()-8);
        
        int year = std::stoi(str_year.substr(6, str_year.size()-6));
        isbn = isbn.substr(6, isbn.size()-6);
        isAvailable = isAvailable.substr(8, isAvailable.size()-8);
        if (isAvailable == "yes" || isAvailable == "YES")
            isAvail = true;
        else if (isAvailable == "no" || isAvailable == "NO"){
            isAvail = false;
        }
        
        borrowedBy = borrowedBy.substr(12, borrowedBy.size()-12);
        

        Book b = Book(title, author, year, isbn, isAvail, borrowedBy);
        addBook(b);
    }
    }
    
    
   while((type == "---USERS---" || type == "USER")){
        
        getline(in, type);
        if (type != "USER") break;
        getline(in, name);
        getline(in, userId);
        getline(in, borrowedBooks);
        getline(in, maxBooksAllowed);
        
        name = name.substr(6, name.size()-6);
        userId = userId.substr(8, userId.size()-8);
        borrowedBooks = borrowedBooks.substr(15, borrowedBooks.size()-15);
        maxBooks = std::stoi(maxBooksAllowed.substr(10, maxBooksAllowed.size()-10));

        //cout << name << " " << userId << " " << borrowedBooks << " " << maxBooksAllowed << endl;

        std::vector<std::string> bb;
        if (borrowedBooks != " "){
        
        
        int prev = 0;

        borrowedBooks += '|';

        char delim = '|';

        for (int i = 0; i < borrowedBooks.size(); i++){
            if (borrowedBooks[i] == delim){
                std::string book = borrowedBooks.substr(prev, i-prev);
                std::string s = "";
                for (int i = 0; i < book.size(); i++){
                    s += book[i];
                }
                bb.push_back(s);
                
                prev = i;
            }
        }
        
        }
        
        User u = User(name, userId, bb, maxBooks);
        addUser(u);
        
        }
        
        
        
        //User u = User(name, userId, bb, maxBooksAllowed);
        //addUser(u);
    
    
}