#pragma once
#include <vector>
#include <string>
#include "Book.h"

class Inventory{

public:
    Inventory();
    void listAllBooks() const;
    void addBook(const std::string& isbn, const std::string& title, const std::string& author, const std::string& year);
    bool updateBook(const std::string& isbn, const std::string& newTitle, const std::string& newAuthor, const std::string& newYear);
    bool deleteBook(const std::string& isbn);

    void saveToFile(const std::string& fileName) const;
    void loadFromFile(const std::string& fileName);
private:
    std::vector<Book> m_books;

};