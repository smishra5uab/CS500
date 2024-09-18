/*
 * File: main.cpp
 * This program shall be used to build a card catalog system for a library. The data structure shall
 * hold details of books upto a 1000 books. The end user can add a book to the library catalog, view
 * all books and their authors, and to search a book by subject. 
 */
#include <iostream>
#include <string>
#include <vector>

// Define constants
const int MAX_BOOKS_COUNT = 1000;
const int MAX_AUTHORS = 5;
const int MAX_SUBJECTS = 5;

// book defines the structure that shall hold the details per book
struct book {
    std::string title;
    std::string authors[MAX_AUTHORS];
    std::string congressCatalogNumber;
    std::string subjects[MAX_SUBJECTS];
    std::string publisher;
    int yearOfPublication;
    bool isCirculating;
};

// libraryT defines the structure that shall hold all books and their count
struct libraryT {
    book books[MAX_BOOKS_COUNT];
    int bookCount;
};

// Function prototype
void PopulateBooks(libraryT& libdata);
void SearchBySubject(const libraryT& libdata, const std::string& subject);
void AddBook(libraryT& libdata);
void ListBooks(libraryT& libdata);

/* 
 * Main program
 * NOTE: libdata is referenced all throughout the code keeping in mind that there could be 1000
 * books in it. This would become a large data structure and hence it is better to just reference
 * so as to save memory.
 */
int main() {
    libraryT libdata;
    libdata.bookCount = 0;

    PopulateBooks(libdata);

    // Update bookCount to 5 as 5 books have been populated.
    libdata.bookCount = 5;

    // Loop through the menu
    while (true) {
        std::cout << "Menu:" << std::endl;
        std::cout << "1. Add a new book" << std::endl;
        std::cout << "2. Search by subject" << std::endl;
        std::cout << "3. Display all book titles and authors" << std::endl;
        std::cout << "4. Exit" << std::endl;
        std::cout << "Enter your choice: ";
        
        int choice;
        std::cin >> choice;
        std::cin.ignore();

        // Switch case to process from the menu based on user input
        switch (choice) {
            case 1:
                AddBook(libdata);
                break;
            case 2: {
                std::cout << "Enter subject to search: ";
                std::string subject;
                getline(std::cin, subject);
                SearchBySubject(libdata, subject);
                break;
            }
            case 3:
                ListBooks(libdata);
                break;
            case 4:
                return 0;
            default:
                std::cout << "Invalid choice. Please try again." << std::endl;
        }
    }
    return 0;
}

/*
 * Function: AddBook
 * Usage: AddBook(libdata)
 * ------------------------
 * AddBook shall check if there are already 1000 books. If not, this function shall instantiate a
 * new book and insert it to the libdata after getting all relevant details from the user.
 */
void AddBook(libraryT& libdata) {
    if (libdata.bookCount >= 1000) {
        std::cout << "Cant add any more books. 1000 books have already been stored in the library.";
        return;
    }

    book& newBook = libdata.books[libdata.bookCount];

    std::cout << "Enter the title: ";
    getline(std::cin, newBook.title);

    std::cout << "Enter the number of authors of the book (max 5): ";
    int authorCount;
    std::cin >> authorCount;
    std::cin.ignore();
    // for loop to input authors
    for (int i = 0; i < authorCount && i < MAX_AUTHORS; ++i) {
        std::cout << "Enter author " << (i+1) << ": ";
        getline(std::cin, newBook.authors[i]);
    } 

    std::cout << "Enter the Congress Catalog Number: ";
    getline(std::cin, newBook.congressCatalogNumber);

    std::cout << "Enter the number of subjects (max 5): ";
    int subjectCount;
    std::cin >> subjectCount;
    std::cin.ignore();
    // for loop to input subjects
    for (int i = 0; i < subjectCount && i < MAX_SUBJECTS; ++i) {
        std::cout << "Enter subject " << (i+1) << ": ";
        getline(std::cin, newBook.subjects[i]);
    }

    std::cout << "Enter the publisher name: ";
    getline(std::cin, newBook.publisher);

    std::cout << "Enter the year of publication: ";
    std::cin >> newBook.yearOfPublication;
    std::cin.ignore();

    std::cout << "Is the book circulating? (1 for Yes, 0 for No): ";
    int circulates;
    std::cin >> circulates;
    newBook.isCirculating = (circulates == 1);

    libdata.bookCount++;
    std::cout << "Book added successfully!" << std::endl;
}

/*
 * Function: ListBooks
 * Usage: ListBooks(libdata)
 * --------------------------
 * ListBooks shall list all the books in the library and their respective authors
 */
void ListBooks(libraryT& libdata) {
    std::cout << "\nBooks List" << std::endl;
    std::cout << "===============================" << std::endl;
    for (int i = 0; i < libdata.bookCount; ++i) {
        std::cout << "Title: " << libdata.books[i].title << std::endl;
        for (const std::string& author : libdata.books[i].authors) {
            if (!author.empty()) {
                std::cout << author << std::endl;
            }
        }
        std::cout << "-------------------------------" << std::endl;

    }
}

/*
 * Function:SearchBySubject
 * Usage: SearchBySubject(libdata, subject)
 * -----------------------------------------
 * SearchBySubject is used to search the titles in the library that match the subject passed to the
 * function.
 */
void SearchBySubject(const libraryT& libdata, const std::string& subject) {
    for (int i = 0; i < libdata.bookCount; ++i) {
        for (int j = 0; j < MAX_SUBJECTS; ++j) {
            if (libdata.books[i].subjects[j] == subject) {
                std::cout << "Title: " << libdata.books[i].title << std::endl;
                std::cout << "Author: " << libdata.books[i].authors[0] << std::endl;
                std::cout << "Catalog Number: " << libdata.books[i].congressCatalogNumber << std::endl;
                std::cout << "-----------------------" << std::endl;
                break;
            }
        }
    }
}

/*
 * Function: PopulateBooks
 * Usage: PopulateBooks(libdata)
 * ------------------------------
 * PopulateBooks shall create 5 dummy entries of books into the library.
 */
void PopulateBooks(libraryT& libdata) {
    libdata.books[0].title = "The Kite Runner";
    libdata.books[0].authors[0] = "Khaled Hosseini";
    libdata.books[0].authors[1] = "Khaled Hosseiniee";
    libdata.books[0].congressCatalogNumber = "1234567890";
    libdata.books[0].subjects[0] = "Classic";
    libdata.books[0].subjects[1] = "Novel";
    libdata.books[0].publisher = "Penguin Books";
    libdata.books[0].yearOfPublication = 2003;
    libdata.books[0].isCirculating = true;

    libdata.books[1].title = "To Kill a Mockingbird";
    libdata.books[1].authors[0] = "Harper Lee";
    libdata.books[1].congressCatalogNumber = "2345678901";
    libdata.books[1].subjects[0] = "Classic";
    libdata.books[1].subjects[1] = "Novel";
    libdata.books[1].publisher = "J.B. Lippincott & Co.";
    libdata.books[1].yearOfPublication = 1960;
    libdata.books[1].isCirculating = true;

    libdata.books[2].title = "It Ends With Us";
    libdata.books[2].authors[0] = "Colleen Hoover";
    libdata.books[2].congressCatalogNumber = "3456789012";
    libdata.books[2].subjects[0] = "Romance";
    libdata.books[2].publisher = "Atria Books";
    libdata.books[2].yearOfPublication = 2016;
    libdata.books[2].isCirculating = true;

    libdata.books[3].title = "A Thousand Splendid Suns";
    libdata.books[3].authors[0] = "Khaled Hosseini";
    libdata.books[3].congressCatalogNumber = "4567890123";
    libdata.books[3].subjects[0] = "Fiction";
    libdata.books[3].subjects[1] = "Classic";
    libdata.books[3].publisher = "Riverhead Books";
    libdata.books[3].yearOfPublication = 1851;
    libdata.books[3].isCirculating = false;

    libdata.books[4].title = "Pride and Prejudice";
    libdata.books[4].authors[0] = "Jane Austen";
    libdata.books[4].congressCatalogNumber = "5678901234";
    libdata.books[4].subjects[0] = "Classic";
    libdata.books[4].subjects[1] = "Romance";
    libdata.books[4].publisher = "T. Egerton";
    libdata.books[4].yearOfPublication = 1813;
    libdata.books[4].isCirculating = true;
}