#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class Product 
{
private:
    string productId;
    string productName;
    double productPrice;
public:
    Product(string id, string name, double price) 
    {
        productId = id;
        productName = name;
        productPrice = price;
    }
     string getProductId()  
    {
    return productId;
    }
    string getProductName()  
    { 
    return productName;
    }
    double getProductPrice() 
    {
    return productPrice;
    }

    void displayProduct() const 
    {
        cout << "Product ID: " << productId << " | Name: " << productName
             << " | Price: $" << fixed << setprecision(2) << productPrice << endl;
    }
};

class Inventory 
{
private:
    Product** products; 
    int maxProducts;
    int currentSize;
public:
    Inventory(int maxSize) 
    {
        maxProducts = maxSize;
        currentSize = 0;
        products = new Product*[maxSize]; 
    }
    ~Inventory() 
    {
        for (int i = 0; i < currentSize; ++i) 
        {
            delete products[i]; 
        }
        delete[] products; 
    }

    void addProduct(Product &product) 
    {
        if (currentSize < maxProducts) 
        {
            products[currentSize] = new Product(product);
            ++currentSize;
            cout << "Added: " << product.getProductName() << " to inventory." << endl;
        } 
        else 
        {
            cout << "Inventory full! No space for new products." << endl;
        }
    }

    void sortProductsByPrice() 
    {
        for (int i = 0; i < currentSize - 1; i++) 
        {
            for (int j = i + 1; j < currentSize; j++) 
            {
                if (products[i]->getProductPrice() > products[j]->getProductPrice()) 
                {
                    Product* temp = products[i];
                    products[i] = products[j];
                    products[j] = temp;
                }
            }
        }
        cout << "Inventory sorted by price." << endl;
    }

    Product* searchProductByName(const string &name) 
    {
        for (int i = 0; i < currentSize; ++i) 
        {
            if (products[i]->getProductName() == name) 
            {
                return products[i];
            }
        }
        return nullptr; 
    }

    void displayInventory() const 
    {
        if (currentSize == 0) 
        {
            cout << "Inventory is empty." << endl;
            return;
        }
        for (int i = 0; i < currentSize; i++) 
        {
            products[i]->displayProduct();
        }
    }
};

int main() 
{
    Inventory inventory(10); 
    while (true) 
    {
        cout << "\nStore Inventory System\n";
        cout << "1. Add Product\n";
        cout << "2. Sort Products by Price\n";
        cout << "3. Search Product by Name\n";
        cout << "4. Display Inventory\n";
        cout << "5. Exit\n";
        int choice;
        cout << "Select an option: ";
        cin >> choice;
        if (choice == 1) 
        {   
            string productId, productName;
            double productPrice;
            cout << "Enter ID: ";
            cin >> productId;
            
            getchar();
            cout << "Enter name: ";
            getline(cin, productName);  
            
            cout << "Enter price: ";
            cin >> productPrice;
            Product newProduct(productId, productName, productPrice);
            
            inventory.addProduct(newProduct);
        }
        else if (choice == 2) 
        {
            inventory.sortProductsByPrice();
        }
        else if (choice == 3) 
        {   
            string searchName;
            cout << "Search product name: ";
            getchar();
            getline(cin, searchName);

            Product* foundProduct = inventory.searchProductByName(searchName);
            if (foundProduct) 
            {
                cout << "Product located: ";
                foundProduct->displayProduct();
            } 
            else 
            {
                cout << "No matching product found." << endl;
            }
        }
        else if (choice == 4) 
        {
            inventory.displayInventory();
        }
        else if (choice == 5) 
        {
            cout << "Shutting down inventory system." << endl;
            break;
        }
        else 
        {
            cout << "Invalid input! Try again." << endl;
        }
    }
    return 0;
}
