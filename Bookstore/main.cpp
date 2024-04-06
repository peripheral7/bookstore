#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class Book {
private:
	string title;
	string author;
	string isbn;
	int price, quantity, published_year;
public:
	Book(string _title, string _author, string _isbn, int _price, int _quantity, int _published_year)
		: title(_title), author(_author), isbn(_isbn), price(_price), quantity(_quantity), published_year(_published_year) {}

	string getISBN() {
		return isbn;
	}


	void showInfo() {
		cout << title << author << isbn << price << quantity << endl;
	}
};

class Bookstore {
	vector<Book> books;
public:
	Bookstore() {}

	void addBook(const Book & book) {
		books.push_back(book);
	}

	void removeBook(const string& isbn) {
		for (auto it = books.begin(); it != books.end(); ++it) {
			if (it->getISBN() == isbn) {
				books.erase(it);
				break;
			}
		}
	}

	void printBooks() {
		for (auto& book : books) {
			book.showInfo();
		}
	}
};

int main() {
	Book book1("John Wick", "Brothers", "4444444", 10000, 100, 2023);
	Bookstore First_bookstore;
	First_bookstore.addBook(book1);
	First_bookstore.printBooks();
}