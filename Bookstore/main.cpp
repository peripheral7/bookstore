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
	Book(string title, string _author, string _isbn, int _price, int _quantity, int _published_year)
		: title(title), author(_author), isbn(_isbn), price(_price), quantity(_quantity), published_year(_published_year) {}

	string getISBN() {
		return isbn;
	}

	string price_comma(int price) {
		string string_price = to_string(price);
		for (int i = string_price.size() - 3; i > 0; i -= 3) {
			string_price.insert(i, ",");
		}
		return string_price;
	}

	void showInfo() {
		cout << setw(10) << left << "Book: " << title << endl;
		cout << setw(10) << left << "Author: " <<  author << endl;
		cout << setw(10) << left << "ISBN: " << isbn << endl;
		cout << setw(10) << left << "Price: " << price_comma(price) << endl;
		cout << setw(10) << left << "Quantity: " << quantity << endl;
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
	Book book1("Sheltering Sky", "Paul Bowles", "006083482X", 15000, 100, 2005);
	Bookstore KHU_bookstore;
	KHU_bookstore.addBook(book1);
	KHU_bookstore.printBooks();
}