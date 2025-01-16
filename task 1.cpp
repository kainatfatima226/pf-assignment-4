#include <iostream>
#include <fstream>
#include <string>
using namespace std;
struct Book {
    int bookID;
    string title;
    string author;
    int quantity;
    Book* next; 
};
void addBook(Book*& head);
void searchBook(Book* head);
void displayBooks(Book* head);
void saveToFile(Book* head);
void loadFromFile(Book*& head);
void deleteList(Book* head);
int main() {
    Book* library = nullptr;  
    loadFromFile(library); 
 int choice;
 while (true) {
        cout << "\nLibrary Management System\n";
        cout << "1. Add a new book\n";
        cout << "2. Search for a book\n";
        cout << "3. Display all books\n";
        cout << "4. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
switch (choice) {
            case 1:
                addBook(library);
                break;
            case 2:
                searchBook(library);
                break;
            case 3:
                displayBooks(library);
                break;
            case 4:
                saveToFile(library);
                deleteList(library);  
                cout << "Exiting the system...\n";
                return 0;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    }

    return 0;
}
void addBook(Book*& head) {
    int id, quantity;
    string title, author;
    cout << "Enter Book ID: ";
    cin >> id;
    cin.ignore();  
    cout << "Enter Book Title: ";
    getline(cin, title);
    cout << "Enter Author Name: ";
    getline(cin, author);
    cout << "Enter Quantity: ";
    cin >> quantity;
    Book* newBook = new Book;
    newBook->bookID = id;
    newBook->title = title;
    newBook->author = author;
    newBook->quantity = quantity;
    newBook->next = head;  
    head = newBook;  
  cout << "Book added successfully!\n";
}
void searchBook(Book* head) {
    int choice;
    cout << "Search by:\n";
    cout << "1. Book ID\n";
    cout << "2. Book Title\n";
    cout << "Enter your choice: ";
    cin >> choice;
 if (choice == 1) {
        int id;
        cout << "Enter Book ID: ";
        cin >> id;
    bool found = false;
        Book* current = head;
        while (current != nullptr) {
            if (current->bookID == id) {
                cout << "Book found!\n";
                cout << "ID: " << current->bookID << "\n";
                cout << "Title: " << current->title << "\n";
                cout << "Author: " << current->author << "\n";
                cout << "Quantity: " << current->quantity << "\n";
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Book with ID " << id << " not found.\n";
        }
    } else if (choice == 2) {
        string title;
        cin.ignore(); 
        cout << "Enter Book Title: ";
        getline(cin, title);

        bool found = false;
        Book* current = head;
        while (current != nullptr) {
            if (current->title == title) {
                cout << "Book found!\n";
                cout << "ID: " << current->bookID << "\n";
                cout << "Title: " << current->title << "\n";
                cout << "Author: " << current->author << "\n";
                cout << "Quantity: " << current->quantity << "\n";
                found = true;
                break;
            }
            current = current->next;
        }
        if (!found) {
            cout << "Book with title '" << title << "' not found.\n";
        }
    } else {
        cout << "Invalid choice.\n";
    }
}
void displayBooks(Book* head) {
    if (head == nullptr) {
        cout << "No books in the library.\n";
        return;
    }
 cout << "\nList of Books in Library:\n";
    Book* current = head;
    while (current != nullptr) {
        cout << "ID: " << current->bookID << ", Title: " << current->title
             << ", Author: " << current->author << ", Quantity: " << current->quantity << endl;
        current = current->next;
    }
}
void saveToFile(Book* head) {
    ofstream outFile("library.txt", ios::out);
    if (outFile) {
        Book* current = head;
        while (current != nullptr) {
            outFile << current->bookID << "\n" << current->title << "\n" << current->author << "\n" << current->quantity << "\n";
            current = current->next;
        }
        cout << "Library data saved successfully.\n";
    } else {
        cout << "Error saving data.\n";
    }
}
void loadFromFile(Book*& head) {
    ifstream inFile("library.txt", ios::in);
    if (inFile) {
        int id, quantity;
        string title, author;
       while (inFile >> id) {
            inFile.ignore(); 
            getline(inFile, title);
            getline(inFile, author);
            inFile >> quantity;
            inFile.ignore();  
            Book* newBook = new Book;
            newBook->bookID = id;
            newBook->title = title;
            newBook->author = author;
            newBook->quantity = quantity;
            newBook->next = head;
            head = newBook;
        }
        cout << "Library data loaded successfully.\n";
    } else {
        cout << "No existing library data found. Starting fresh.\n";
    }
}
void deleteList(Book* head) {
    Book* current = head;
    Book* nextBook;
    while (current != nullptr) {
        nextBook = current->next;
        delete current;
        current = nextBook;
    }
}