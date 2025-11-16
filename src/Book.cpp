#include <iostream>
#include "Book.h"

Book::Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& year){
    m_isbn = isbn;
    m_title = title;
    m_author = author;
    m_year = year;
}

std::string Book::getISBN() const{
    return m_isbn;
}

std::string Book::getTitle() const{
    return m_title;
}

std::string Book::getAuthor() const{
    return m_author;
}

std::string Book::getYear() const{
    return m_year;
}

void Book::display() const{
    std::cout << "\nISBN number of the book: " << m_isbn << "\n";
    std::cout << "Title of the book: " << m_title << "\n";
    std::cout << "Author of the book: " << m_author << "\n";
    std::cout << "Publication year of the book: " << m_year << "\n\n";
}