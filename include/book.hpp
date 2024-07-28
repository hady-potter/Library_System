#pragma once

#include <iostream>

class Book
{
private:
  std::string name;
  int id;
  int total_number_of_copies;
  int number_of_borrowed_copies;

public:
  Book();
  Book(int id);
  Book(std::string name, int id, int total_number_of_copies, int number_of_borrowed_copies);

  std::string getName() const;
  int getId() const;
  int getNumberOfCopies() const;
  int getNumberOfBorrowedCopies() const;
  bool canBorrowACopy() const;

  bool operator==(const Book& book);

  void setName(std::string name);
  void setId(int id);
  void setNumberOfCopies(int number);
  void incrementNumberOfBorrowedCopies();

  void info();
};
