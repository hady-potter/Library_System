// #include "user.hpp"
#include "user.hpp"

User::User(): books() {
  name = "";
  id = 0;
  number_of_borrowed_books = 0;
}

User::User(int id): books() {
  name = "";
  this -> id = id;
  number_of_borrowed_books = 0;
}

User::User(std::string name, int id, int number_of_borrowed_books):books() {
  this -> name = name;
  this -> id = id;
  this -> number_of_borrowed_books = number_of_borrowed_books;
}

bool User::operator==(const User& user) {
  return id == user.getId();
}


bool User::returnBook(const Book& b) {
  for(auto book: books) {
    if(book.getId() == b.getId()){
      books.remove(book);
      number_of_borrowed_books--;
      return true;
    }
  }
  return false;
}

bool User::addBook(const Book& book) {
  books.push_front(book);
  number_of_borrowed_books++;
  return true;
}


void User::printBooks() {
  for(auto book: books) {
    std::cout << book.getName() << std::endl;
  }
}


// Setters
void User::setName(std::string name) { this -> name = name; }
void User::setId(int id) { this -> id = id; }
void User::incrementNumberOfBorrowedBooks() {  number_of_borrowed_books++; }

// Getters
std::string User::getName() const { return name; }
int User::getId() const { return id; }
int User::getNumberOfBorrowedBooks() const {return number_of_borrowed_books; }


