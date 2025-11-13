#pragma once
#include <string>

class Book{

    public:
        Book(const std::string& isbn, const std::string& title, const std::string& author, const std::string& year);
        std::string getISBN() const;
        std::string getTitle() const;
        std::string getAuthor() const;
        std::string getYear() const;
        void display() const;
        
    private:
        std::string m_isbn;
        std::string m_title;
        std::string m_author;
        std::string m_year;
};
