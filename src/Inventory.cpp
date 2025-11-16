#include <iostream>
#include <fstream>
#include <sstream>
#include "Inventory.h"

Inventory::Inventory(){};

void Inventory::listAllBooks() const{
    if(m_books.size() != 0){
        std::cout << "There is " << m_books.size() << " books total in this library.\n\n";
        for(int i = 0; i < m_books.size(); i++){
            m_books[i].display();
        }
    }

    else
        std::cout << "\n The library is empty. \n\n";
};

void Inventory::addBook(const std::string& isbn, const std::string& title, const std::string& author, const std::string& year){
    Book newBook(isbn, title, author, year);
    bool isEqual = false;
    for (int i = 0; i < m_books.size(); i++){
        if(newBook.getISBN() == m_books[i].getISBN())
            isEqual = true;
    }

    if(!isEqual){
        m_books.push_back(newBook);
        std::cout << "The book with isbn number " << isbn << " successfully added.\n\n";
    }

    else{
        std::cout << "The book with isbn number " << isbn << " has already been added.\n\n";
    }
};

bool Inventory::updateBook(const std::string& isbn, const std::string& newTitle, const std::string& newAuthor, const std::string& newYear){
    bool isUpdated = false;
    if(m_books.size() != 0){
        for (int i = 0; i < m_books.size(); i++){
            if(m_books[i].getISBN() == isbn){
                m_books[i] = Book(isbn, newTitle, newAuthor, newYear);
                isUpdated = true;
                break;
            }
        }

        if(isUpdated){
            std::cout << "The book with isbn number " << isbn << " has been updated successfully.\n\n"; 
            return true;
        }

        
        else
            std::cout << "The book with isbn number " << isbn << " doesn't exist in this library.\n\n"; return false; 
        
    }
};

bool Inventory::deleteBook(const std::string& isbn){
    bool isDeleted = false;
    if(m_books.size() != 0){
        for (int i = 0; i < m_books.size(); i++){
            if(m_books[i].getISBN() == isbn){
                m_books.erase(m_books.begin() + i);
                isDeleted = true;
                break;
            }
        }

        if(isDeleted){
            std::cout << "The book with isbn number " << isbn << " has been deleted successfully.\n\n"; 
            return true; 
        }
            

        else{
            std::cout << "There is an error with deleting the book.\n\n";
            return false;
        }
    }
};

void Inventory::saveToFile(const std::string& fileName) const{
    std::ofstream outFile(fileName);
    if(!outFile.is_open()){
        std::cout << "There is an error with opening the data file.\n\n";
        return;
    }

    else{
        for(int i = 0; i < m_books.size(); i++){
            outFile << m_books[i].getISBN() << "," << m_books[i].getTitle() << "," << m_books[i].getAuthor() << "," << m_books[i].getYear() << "\n"; 
        }
        outFile.close();
    }
};

void Inventory::loadFromFile(const std::string& fileName){
    m_books.clear();
    std::ifstream inFile(fileName);
    if(!inFile.is_open()){
        std::cout << "There is an error with opening the data file.\n\n";
        return;
    }

    else{
        std::string line;
        while(std::getline(inFile, line)){
            std::stringstream ss(line);
            std::string isbn, title, author, year;
            std::getline(ss, isbn, ',');
            std::getline(ss, title, ',');
            std::getline(ss, author, ',');
            std::getline(ss, year);

            Book bookInLine = Book(isbn, title, author, year);
            m_books.push_back(bookInLine);
        }

        inFile.close();
    }
};