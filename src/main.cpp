#include <iostream>
#include <string>
#include <limits>
#include "Inventory.h"

int displayMenu(), libraryOpNumber;
void libraryOperation(int number, Inventory& library, std::string dbFile);
std::string getISBN();

int main(){
    const std::string dbFile = "../data/database.txt";
    Inventory library;

    library.loadFromFile(dbFile);
    while(true){
        libraryOpNumber = displayMenu();
        libraryOperation(libraryOpNumber, library, dbFile);
        if(libraryOpNumber == 5)
            break;
    }
}

int displayMenu(){
    int chosenNumber;
    std::cout << "=== LIBRARY MANAGING SYSTEM ===\n[1] List All the Books\n[2] Add a New Book\n[3] Update a Book\n[4] Delete a Book\n[5] Save and Quit\n";
    std::cout << "\nPick a number: ";
    std::cin >> chosenNumber;

    return chosenNumber;
}

std::string getISBN(){
    std::string isbn;
    do{
        std::cout << "Enter the ISBN number of the book with 13 digits: \n";
        std::cin >> isbn;
        if(isbn.size() != 13)
            std::cout << "You entered a number with unvalid digits.\n";
    }while(isbn.size() != 13);

    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    return isbn;
}

void libraryOperation(int number, Inventory& library, std::string dbFile){
    std::string isbn, title, author, year, newTitle, newAuthor, newYear;
    switch(number){
        case 1: 
                library.listAllBooks();
                break;

        case 2: 
                
                isbn = getISBN();

                std::cout << "Enter the title of the book: ";
                std::getline(std::cin, title);
                std::cout << "Enter the author of the book: ";
                std::getline(std::cin, author);
                std::cout << "Enter the publicaton year of the book: ";
                std::cin >> year;

                library.addBook(isbn, title, author, year);
                break;
            
        case 3: 
                isbn = getISBN();

                std::cout << "Enter the new title of the book: ";
                std::getline(std::cin, newTitle);
                std::cout << "Enter the new author of the book: ";
                std::getline(std::cin, newAuthor);
                std::cout << "Enter the new publicaton year of the book: ";
                std::cin >> newYear;
                
                library.updateBook(isbn, newTitle, newAuthor, newYear);
                break;

        case 4: 
                isbn = getISBN();
                library.deleteBook(isbn);
                break;

        case 5:
                library.saveToFile(dbFile);
                break;
    }
}
