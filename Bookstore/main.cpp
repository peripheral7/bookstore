#include <iostream>

class Sales_item {
    int isbn;
    int count;
    int price;

public:
    Sales_item(int isbn, int count, int price) : isbn(isbn), count(count), price(price) {}

    friend std::ostream& operator<<(std::ostream& os, const Sales_item& sales_item) {
        os << sales_item.isbn << " " << sales_item.count << " " << sales_item.price;
        return os;
    }

    friend std::istream& operator>>(std::istream& input, Sales_item& sales_item) {
        input >> sales_item.isbn >> sales_item.count >> sales_item.price;
        return input;
    }

};

int main() {
    Sales_item item(123456, 5, 20);
    std::cout << item << std::endl;

    int cnt = 0;
    while (std::cin >> item) {
        ++cnt;
    }
    std::cout << "Count: " << cnt << std::endl;
}