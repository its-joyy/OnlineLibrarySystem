#include <iostream>
#include <string>
#include <limits>
#include "Library.h"
using namespace std;

int main() {
    Library lib;
    int choice;

    while (true) {
        cout << "\n=== Library Menu ===\n";
        cout << "1. Add Book\n";
        cout << "2. Remove Book\n";
        cout << "3. Display Books\n";
        cout << "4. Add User\n";
        cout << "5. Display Users\n";
        cout << "6. Issue Book\n";
        cout << "7. Return Book\n";
        cout << "8. Search Book by Title\n";
        cout << "9. Search Book by Author\n";
        cout << "10. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

      
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        if (choice == 1) {
            int id;
            string title, author;
            cout << "Book ID: "; cin >> id; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Title: "; getline(cin, title);
            cout << "Author: "; getline(cin, author);
            lib.addBook(id, title, author);
        }
        else if (choice == 2) {
            int id;
            cout << "Book ID to remove: "; cin >> id; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            lib.removeBook(id);
        }
        else if (choice == 3) {
            lib.displayBooks();
        }
        else if (choice == 4) {
            int id;
            string name;
            cout << "User ID: "; cin >> id; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Name: "; getline(cin, name);
            lib.addUser(id, name);
        }
        else if (choice == 5) {
            lib.displayUsers();
        }
        else if (choice == 6) {
            int bookId, userId;
            cout << "Book ID to issue: "; cin >> bookId;
            cout << "User ID: "; cin >> userId; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            lib.issueBook(bookId, userId);
        }
        else if (choice == 7) {
            int bookId;
            cout << "Book ID to return: "; cin >> bookId; cin.ignore(numeric_limits<streamsize>::max(), '\n');
            lib.returnBook(bookId);
        }
        else if (choice == 8) {
            string title;
            cout << "Enter Title to search: "; getline(cin, title);
            lib.searchBookByTitle(title);
        }
        else if (choice == 9) {
            string author;
            cout << "Enter Author to search: "; getline(cin, author);
            lib.searchBookByAuthor(author);
        }
        else if (choice == 10) {
            cout << "Exiting program...\n";
            break;
        }
        else {
            cout << "Invalid choice! Please try again.\n";
        }
    }

    return 0;
}

