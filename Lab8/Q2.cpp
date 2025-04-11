#include <iostream>
#include <string>

using namespace std;

class Librarian; 

class Book 
{
private:
    string title;
    float price;

public:
    Book(string t, float p) : title(t), price(p) {}
    friend class Librarian;
};

class Librarian 
{
public:
    void displayDetails(const Book& b) 
    {
        cout << "Book Title: " << b.title << endl;
        cout << "Book Price: $" << b.price << endl;
    }

    void applyDiscount(Book& b, float discountPercent) 
    {
        if (discountPercent > 0 && discountPercent <= 100) 
        {
            b.price -= (b.price * discountPercent / 100);
        }
    }
};

int main() 
{
    Book myBook("1984", 39.99f);
    Librarian manager;

    cout << "Before Discount:" << endl;
    manager.displayDetails(myBook);

    manager.applyDiscount(myBook, 25); 

    cout << "\nAfter 25% Discount:" << endl;
    manager.displayDetails(myBook);

    return 0;
}
