#pragma once

#include <iostream>
#include <list>
#include <vector>
#include "book.hpp"

class User {
private:
  std::string name;
  int id;
  int number_of_borrowed_books;
  std::list<Book> books; // has a relationship

public:
  User();
  User(int id);
  User(std::string name, int id, int number_of_borrowed_books);

  void setName(std::string name);
  void setId(int id);
  void incrementNumberOfBorrowedBooks();

  std::string getName() const;
  int getId() const;
  int getNumberOfBorrowedBooks() const;

  bool returnBook(const Book& book);
  bool addBook(const Book& book);

  void printBooks();

  bool operator==(const User& user);

};