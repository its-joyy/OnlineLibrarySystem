#ifndef LIBRARY_H
#define LIBRARY_H

#include <iostream>
#include <vector>
#include <string>
#include "Book.h"
#include "User.h"
using namespace std;

class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(int id, string title, string author) {
        for (Book &b : books)
            if (b.getId() == id) { 
                cout << "Book ID already exists!\n"; 
                return; 
            }
        books.push_back(Book(id, title, author));
        cout << "Book added successfully!\n";
    }

    void removeBook(int id) {
        for (int i = 0; i < books.size(); i++) {
            if (books[i].getId() == id) {
                books.erase(books.begin() + i);
                cout << "Book removed successfully!\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void displayBooks() {
        if (books.empty()) { 
            cout << "No books available.\n"; 
            return; 
        }
        cout << "\nBooks in Library:\n";
        for (Book &b : books)
            cout << "ID: " << b.getId() 
                 << ", Title: " << b.getTitle()
                 << ", Author: " << b.getAuthor()
                 << ", Status: " << (b.getIsIssued() ? "Issued" : "Available") 
                 << endl;
    }

    void addUser(int id, string name) {
        for (User &u : users)
            if (u.getId() == id) { 
                cout << "User ID already exists!\n"; 
                return; 
            }
        users.push_back(User(id, name));
        cout << "User added successfully!\n";
    }

    void displayUsers() {
        if (users.empty()) { 
            cout << "No users registered.\n"; 
            return; 
        }
        cout << "\nUsers in Library:\n";
        for (User &u : users)
            cout << "ID: " << u.getId() << ", Name: " << u.getName() << endl;
    }

    void issueBook(int bookId, int userId) {
        for (Book &b : books) {
            if (b.getId() == bookId) {
                if (b.getIsIssued()) { 
                    cout << "Book is already issued.\n"; 
                    return; 
                }
                b.issueBook();
                cout << "Book issued successfully to User ID: " << userId << endl;
                return;
            }
        }
        cout << "Book not found.\n";
    }

    void returnBook(int bookId) {
        for (Book &b : books) {
            if (b.getId() == bookId) {
                if (!b.getIsIssued()) { 
                    cout << "Book was not issued.\n"; 
                    return; 
                }
                b.returnBook();
                cout << "Book returned successfully.\n";
                return;
            }
        }
        cout << "Book not found.\n";
    }

    // Flexible search: partial match works
    void searchBookByTitle(string title) {
        bool found = false;
        for (Book &b : books) {
            if (b.getTitle().find(title) != string::npos) {
                cout << "ID: " << b.getId() 
                     << ", Author: " << b.getAuthor()
                     << ", Status: " << (b.getIsIssued() ? "Issued" : "Available") 
                     << endl;
                found = true;
            }
        }
        if (!found) cout << "No book found with this title.\n";
    }

    void searchBookByAuthor(string author) {
        bool found = false;
        for (Book &b : books) {
            if (b.getAuthor().find(author) != string::npos) {
                cout << "ID: " << b.getId() 
                     << ", Title: " << b.getTitle()
                     << ", Status: " << (b.getIsIssued() ? "Issued" : "Available") 
                     << endl;
                found = true;
            }
        }
        if (!found) cout << "No book found by this author.\n";
    }
};

#endif
