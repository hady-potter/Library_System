#pragma once

#include <iostream>
#include <vector>
#include <algorithm>



#include "book.hpp"
#include "user.hpp"


class Library_System{
private:
  std::vector<User> users;
  std::vector<Book> books;
  Library_System();

  bool is_user_exist(const User& user);
  bool is_book_exist(const Book& book);

public:
  static Library_System& getInstance();
  void addBook(const Book& book);
  void addUser(const User& user);
  void searchForBook(std::string name);
  void printAllBooksByName();
  void printAllBooksById();
  bool userWantToBorrowABook(const User &user, const Book &book);
  bool userWantToReturnABook(const User &user, const Book &book);
  void printAllUsers();
  void whoBorroedABook();
  // ~Library_System();

  Library_System(const Library_System&) = delete;
  void operator=(const Library_System&) = delete;
  

};