#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Class to represent a book
class Book {
public:
    string title;
    string author;
    int id;
    bool available;

    Book(string t, string a, int i) : title(t), author(a), id(i), available(true) {}
};

// Class to represent a user
class User {
public:
    string name;
    int userId;

    User(string n, int id) : name(n), userId(id) {}
};

// Class to manage the library
class Library {
private:
    vector<Book> books;
    vector<User> users;

public:
    void addBook(string title, string author, int id) {
        Book book(title, author, id);
        books.push_back(book);
    }

    void addUser(string name, int userId) {
        User user(name, userId);
        users.push_back(user);
    }

    void displayBooks() {
        cout << "Library Books:" << endl;
        for (const Book& book : books) {
            cout << "ID: " << book.id << "\tTitle: " << book.title << "\tAuthor: " << book.author;
            if (book.available) {
                cout << "\tStatus: Available" << endl;
            } else {
                cout << "\tStatus: Checked Out" << endl;
            }
        }
    }

    void displayUsers() {
        cout << "Library Users:" << endl;
        for (const User& user : users) {
            cout << "ID: " << user.userId << "\tName: " << user.name << endl;
        }
    }

    void borrowBook(int userId, int bookId) {
        for (Book& book : books) {
            if (book.id == bookId && book.available) {
                book.available = false;
                cout << "Book successfully borrowed by user ID " << userId << "." << endl;
                return;
            }
        }
        cout << "Book not available or invalid ID." << endl;
    }

    void returnBook(int bookId) {
        for (Book& book : books) {
            if (book.id == bookId && !book.available) {
                book.available = true;
                cout << "Book successfully returned." << endl;
                return;
            }
        }
        cout << "Invalid book ID or book already available." << endl;
    }
};

int main() {
    Library library;

    // Adding some books and users for testing
    library.addBook("The Catcher in the Rye", "J.D. Salinger", 1);
    library.addBook("To Kill a Mockingbird", "Harper Lee", 2);
    library.addBook("1984", "George Orwell", 3);

    library.addUser("Alice", 101);
    library.addUser("Bob", 102);

    // Displaying the initial state of the library
    library.displayBooks();
    library.displayUsers();

    // Simulating book borrowing and returning
    library.borrowBook(101, 1);
    library.borrowBook(102, 2);
    library.returnBook(1);

    // Displaying the updated state of the library
    library.displayBooks();
    library.displayUsers();

    return 0;
}

			