#include "Item.h"
#include <bits/stdc++.h>
using namespace std;

bool Item::operator<(const Item &other) const {
    return itemName < other.itemName;
}

bool Item::operator>=(const Item &other) const {
    return itemName >= other.itemName;
}

bool Item::operator<=(const Item &other) const {
    return price <= other.price;
}

bool Item::operator>(const Item &other) const {
    return price > other.price;
}

bool Item::operator==(const Item &other) const {
    return itemName == other.itemName && category == other.category && price == other.price;
}

void Item::print(ofstream &outputFile) {
    outputFile << "Name: " << itemName << '\n'
               << "Category: " << category << '\n'
               << "price: $" << price << "\n\n";
}

void Item::print() const {
    cout << "Name: " << itemName << '\n'
         << "Category: " << category << '\n'
         << "price: $" << price << "\n\n";
}
