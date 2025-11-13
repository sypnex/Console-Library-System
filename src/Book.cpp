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
    std::cout << "Kitabın ISBN numarası: " << m_isbn;
    std::cout << "Kitabın başlığı: " << m_title;
    std::cout << "Kitabın yazarı: " << m_author;
    std::cout << "Kitabın basım yılı: " << m_year;
}