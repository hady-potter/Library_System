#include "library.hpp"


Library_System::Library_System():users(),books(){}

// sengilton design pattern
Library_System &Library_System::getInstance(){
  static Library_System INSTANCE;
  return INSTANCE;

}

void Library_System::addBook(const Book &book)
{
  books.push_back(book);
}

void Library_System::addUser(const User& user) {
  users.push_back(user);
}

void Library_System::searchForBook(std::string name) {
  std::vector<Book> matchedBooks;
  bool flag;
  for(auto book: books) {
    flag = true;
    for(int i = 0; i < name.size(); i++) {
      if(book.getName()[i] != name[i]){
        flag = false;
        break;
      }
    }
    if(flag) matchedBooks.push_back(book);
  }

  std::cout << "Id\tName\n";
  for(auto book: matchedBooks) {
    std::cout << book.getId() << "\t" << book.getName() << std::endl;
  }
}


void Library_System::printAllBooksByName() {
  std::sort(books.begin(), books.end(), [](const Book &a, const Book &b){ return a.getName() < b.getName(); });
  std::cout << "Id\tName\n";
  for(auto book: books) {
    std::cout << book.getId() << "\t" << book.getName() << std::endl;
  }
}

void Library_System::printAllBooksById() {
  std::sort(books.begin(), books.end(), [](const Book &a, const Book&b){return a.getId() < b.getId(); });
  std::cout << "Id\tName\n";
  for (auto book : books) {
    std::cout << book.getId() << "\t" << book.getName() << std::endl;
  }
}


bool Library_System::is_user_exist(const User& user) {
  return std::find(users.begin(), users.end(), user) != users.end();
}

bool Library_System::is_book_exist(const Book& book) {
  return std::find(books.begin(), books.end(), book) != books.end();
}


bool Library_System::userWantToBorrowABook(const User& user, const Book& book) {
    auto user_it = std::find(users.begin(), users.end(), user);
    auto book_it = std::find(books.begin(), books.end(), book);

    if(user_it != users.end() and book_it != books.end() and book_it -> canBorrowACopy()) {
      // user_it -> incrementNumberOfBorrowedBooks();
      user_it -> addBook(book);
      book_it -> incrementNumberOfBorrowedCopies();

      return true;
    }
    return false;

}

bool Library_System::userWantToReturnABook(const User &user, const Book &book) {
  auto user_it = std::find(users.begin(), users.end(), user);

  if(user_it != users.end()) {
    return user_it -> returnBook(book);
  }
  return false;
}

void Library_System::printAllUsers() {
  std::cout << "Id\tName\n";
  for(auto user: users) {
    std::cout << user.getId() << "\t" << user.getName() << std::endl;
  }
}

void Library_System::whoBorroedABook() {
  std::cout << "Id\tName\n";
  for(auto user: users) {
    if(user.getNumberOfBorrowedBooks() > 0) {
      std::cout << user.getId() << "\t" << user.getName() << std::endl;
    }
  }
}
