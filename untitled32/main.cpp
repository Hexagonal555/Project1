#include <iostream>
#include <cstring>
using namespace std;

class Book {
private:
    char* title;
    int* isbn;
    int pages;
public:
    // constructor
    Book(const char* t = "", const int* i = nullptr, int p = 0) {
        title = new char[strlen(t) + 1];
        strcpy(title, t);

        isbn = new int[5];
        for (int j = 0; j < 5; j++) {
            isbn[j] = i[j];
        }

        pages = p;
    }

    // copy constructor
    Book(const Book& other) {
        title = new char[strlen(other.title) + 1];
        strcpy(title, other.title);

        isbn = new int[5];
        for (int j = 0; j < 5; j++) {
            isbn[j] = other.isbn[j];
        }

        pages = other.pages;
    }

    // destructor
    ~Book() {
        delete[] title;
        delete[] isbn;
    }

    // getters
    char* getTitle() const {
        return title;
    }

    int* getISBN() const {
        return isbn;
    }

    int getPages() const {
        return pages;
    }

    // setters
    void setTitle(const char* t) {
        delete[] title;
        title = new char[strlen(t) + 1];
        strcpy(title, t);
    }

    void setISBN(const int* i) {
        for (int j = 0; j < 5; j++) {
            isbn[j] = i[j];
        }
    }

    void setPages(int p) {
        pages = p;
    }

    // operator overloading
    bool operator==(const Book& other) const {
        for (int j = 0; j < 5; j++) {
            if (isbn[j] != other.isbn[j]) {
                return false;
            }
        }

        return true;
    }

    friend ostream& operator<<(ostream& os, const Book& book) {
        os << "Title:" << book.title << " ISBN:[";
        for (int j = 0; j < 4; j++) {
            os << book.isbn[j] << " ";
        }
        os << book.isbn[4] << "]";

        return os;
    }
};

/*
#include <iostream>
#include <cstring>

class Book {
private:
    char* title;
    char* isbn;
    int numPages;

public:
    Book(const char* _title, const char* _isbn, int _numPages) {
        title = new char[strlen(_title) + 1];
        strcpy(title, _title);

        isbn = new char[strlen(_isbn) + 1];
        strcpy(isbn, _isbn);

        numPages = _numPages;
    }

    ~Book() {
        delete[] title;
        delete[] isbn;
    }

    char* getIsbn() const {
        return isbn;
    }

    bool operator==(const Book& other) const {
        return strcmp(isbn, other.isbn) == 0;
    }

    friend std::ostream& operator<<(std::ostream& os, const Book& book) {
        os << "Title: " << book.title << " ISBN:[" << book.isbn << "]" << std::endl;
        return os;
    }
};
*/

/*
class BorrowABook {
private:
    char* libraryName;
    Book* books;
    int numBooks;

public:
    BorrowABook(const char* _libraryName) {
        libraryName = new char[strlen(_libraryName) + 1];
        strcpy(libraryName, _libraryName);

        books = new Book[1];
        numBooks = 0;
    }

    ~BorrowABook() {
        delete[] libraryName;
        delete[] books;
    }

    void addBook(const Book& book) {
        bool alreadyExists = false;
        for (int i = 0; i < numBooks; i++) {
            if (books[i] == book) {
                alreadyExists = true;
                break;
            }
        }

        if (alreadyExists) {
            std::cout << "The book with the same ISBN already exists in the library." << std::endl;
            return;
        }

        numBooks++;
        Book* newBooks = new Book[numBooks];
        for (int i = 0; i < numBooks - 1; i++) {
            newBooks[i] = books[i];
        }
        newBooks[numBooks - 1] = book;

        delete[] books;
        books = newBooks;
    }

    void removeBook(const char* isbn) {
        int indexToRemove = -1;
        for (int i = 0; i < numBooks; i++) {
            if (strcmp(books[i].getIsbn(), isbn) == 0) {
                indexToRemove = i;
                break;
            }
        }

        if (indexToRemove == -1) {
            std::cout << "The book with the given ISBN does not exist in the library." << std::endl;
            return;
        }

        numBooks--;
        Book* newBooks = new Book[numBooks];
        for (int i = 0; i < indexToRemove; i++) {
            newBooks[i] = books[i];
        }
        for (int i = indexToRemove; i < numBooks; i++) {
            newBooks[i] = books[i + 1];
        }

        delete[] books;
        books = newBooks;
    }

    void printBooks() const {
        std::cout << "Library name: " << libraryName << std::endl;
        std::cout << "Books with more than 150 pages:" << std::endl;
        for (int i = 0; i < numBooks; i++) {
            if (books[i].numPages > 150)


            continue
        };

// Implementation of the += operator for adding a new book to the library
        BorrowABook& BorrowABook::operator+=(const Book& book) {
// Check if the library is full, if it is allocate more memory
            if (numBooks == capacity) {
                Book* temp = new Book[capacity + 1];
                for (int i = 0; i < capacity; i++) {
                    temp[i] = books[i];
                }
                delete[] books;
                books = temp;
                capacity++;
            }
            books[numBooks++] = book;
            return *this;
        }

// Implementation of the -= operator for removing a book from the library
        BorrowABook& BorrowABook::operator-=(const Book& book) {
            for (int i = 0; i < numBooks; i++) {
                if (books[i] == book) {
                    for (int j = i; j < numBooks - 1; j++) {
                        books[j] = books[j + 1];
                    }
                    numBooks--;
                    break;
                }
            }
            return *this;
        }

// Function to print the number of pages of books with more than max pages
        void BorrowABook::printNumberOfPages(int max) {
            int total = 0;
            for (int i = 0; i < numBooks; i++) {
                if (books[i].getNumPages() > max) {
                    total += books[i].getNumPages();
                }
            }
            cout << "The total number of pages for books with more than " << max << " pages is: " << total << endl;
        }
*/


int main (){



    return 0;
}