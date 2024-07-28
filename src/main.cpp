#include <iostream>

#include "library.hpp"

void menu()
{
  std::cout << "==================================\n";
  std::cout << "1) Add Book\n";
  std::cout << "2) Search for Book\n";
  std::cout << "3) who borrowed a book\n";
  std::cout << "4) Print all Books by name\n";
  std::cout << "5) Print all Books by id\n";
  std::cout << "6) Add User\n";
  std::cout << "7) User want to borrow a book\n";
  std::cout << "8) User want to return a book\n";
  std::cout << "9) Print All Users\n";
  std::cout << "10) Exit\n";
  std::cout << "==================================\n";
}

enum cases
{
  add_book = 1,
  searsh_for_book,
  who_borrowed_a_book,
  print_books_by_name,
  print_books_by_id,
  add_user,
  user_want_to_borrow_a_book,
  user_want_to_return_a_book,
  print_all_user,
  quit
};

void run() {
  menu();

  // the only instance of library system
  auto &ls = Library_System::getInstance();

  bool flag = true;
  while (flag)
  {
    std::cout << "Enter your choice: ";
    int answer;
    std::cin >> answer;
    switch (answer)
    {
      case add_book: {
        int id;
        int numbrOfCopies;
        std::string name;

        std::cout << "Enter Book Info [name, id, copies number]\n";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> id >> numbrOfCopies;
        ls.addBook(Book(name, id, numbrOfCopies, 0));
        std::cout << "Done -> Book '" << name <<"' added.\n";
        break;
      }
      case searsh_for_book: {
        std::string name;
        std::cout << "Enter Book Name: ";
        std::cin >> name;
        ls.searchForBook(name);
        break;
      }
      case who_borrowed_a_book: {
        ls.whoBorroedABook();
        break;
      }

      case print_books_by_name: {
        ls.printAllBooksByName();
        break;
      }
      case print_books_by_id: {
        ls.printAllBooksById();
        break;
      }
      case add_user: {
        std::string name;
        int id;
        std::cout << "Enter user info[name, id]\n";
        std::cin.ignore();
        std::getline(std::cin, name);
        std::cin >> id;
        ls.addUser(User(name, id, 0));
        break;
      }
      case user_want_to_borrow_a_book: {
        std::cout << "Enter bookid, userid\n";
        int bookid;
        int userid;
        std::cin >> bookid >> userid;
        bool done = ls.userWantToBorrowABook(User(userid), Book(bookid));
        done ? std::cout << "Done\n" : std::cout << "Somthing wrong happend!\n";
        break;
      }

      case user_want_to_return_a_book: {
        std::cout << "Enter bookid, userid\n";
        int bookid;
        int userid;
        std::cin >> bookid >> userid;
        bool done = ls.userWantToReturnABook(User(userid), Book(bookid));
        done ? std::cout << "Done\n" : std::cout << "Somthing wrong happend!\n";
        break;
      }

      case print_all_user: {
        ls.printAllUsers();
        break;
      }
      case quit: {
        flag = false;
        std::cout << "Quit.\n";
        break;
      }

      default:
        break;
    }
  }
  
}

int main() {
  
  run();
  


  return 0;
}