#ifndef BOOK_H
#define BOOK_H

#include <string>
using namespace std;

class Book {
private:
    int id;
    string title;
    string author;
    bool isIssued;

public:
    Book(int bookId, string bookTitle, string bookAuthor) {
        id = bookId;
        title = bookTitle;
        author = bookAuthor;
        isIssued = false;
    }

    int getId() { return id; }
    string getTitle() { return title; }
    string getAuthor() { return author; }
    bool getIsIssued() { return isIssued; }

    void issueBook() { isIssued = true; }
    void returnBook() { isIssued = false; }
};

#endif
