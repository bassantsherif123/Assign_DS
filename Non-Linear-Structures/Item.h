#ifndef NON_LINEAR_STRUCTURES_ITEM_H
#define NON_LINEAR_STRUCTURES_ITEM_H

#include <bits/stdc++.h>
using namespace std;


class Item
{
    string itemName;
    string category;
    int price;
public:
    Item(string name, string c, int p) : itemName(name), category(c), price(p) {}
    bool operator<(const Item& other) const;
    bool operator>=(const Item &other) const;
    bool operator<=(const Item &other) const;
    bool operator>(const Item& other) const;
    bool operator==(const Item &other) const;
    void print(ofstream &outputFile);
    void print() const;
};



#endif //NON_LINEAR_STRUCTURES_ITEM_H
