#include "book.hpp"


Book::Book() {
  name = "";
  id = 0;
  total_number_of_copies = 0;
  number_of_borrowed_copies = 0;
}

Book::Book(int id)
{
  name = "";
  this -> id = id;
  total_number_of_copies = 0;
  number_of_borrowed_copies = 0;
}

Book::Book(std::string name, int id, int total_number_of_copies, int number_of_borrowed_copies)
{
  this -> name = name;
  this -> id = id;
  this -> total_number_of_copies = total_number_of_copies;
  this -> number_of_borrowed_copies = number_of_borrowed_copies;
}


void Book::info() {
  std::cout << name << std::endl;
  std::cout << id << std::endl;
  std::cout << total_number_of_copies << std::endl;
  std::cout << number_of_borrowed_copies << std::endl;
}

bool Book::operator==(const Book &book) {
  return id == book.id;
}

bool Book::canBorrowACopy() const {
  return total_number_of_copies - number_of_borrowed_copies;
}

// Getters
std::string Book::getName() const { return name; }
int Book::getId() const { return id; }
int Book::getNumberOfCopies() const { return total_number_of_copies; }
int Book::getNumberOfBorrowedCopies() const { return number_of_borrowed_copies; }

// Setters
void Book::setName(std::string name) { this -> name = name; }
void Book::setId(int id){ this -> id = id; }
void Book::setNumberOfCopies(int number) { this -> total_number_of_copies = number; }
void Book::incrementNumberOfBorrowedCopies() {  number_of_borrowed_copies++; }


