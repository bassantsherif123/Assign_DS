#include <bits/stdc++.h>
#include "BST.cpp"
#include "Heap.cpp"
#include "AVLTree.cpp"
using namespace std;

void Non_Linear();
vector<Item> items;
void readItems(istream& Input);

//_____________________________________
int main()
{
    Non_Linear();
    return 0;
}

//_____________________________________
// read from input file
void readItems(istream& Input)
{
    items.clear();
    if (!Input)
    {
        cerr << "Failed to open the input file.\n";
        return;
    }
    else
    {
        // read from file and save to items vector
        int n;
        string name, c;
        int p;
        Input >> n;
        while (n--)
        {
            Input.ignore();
            getline(Input, name);
            getline(Input, c);
            Input >> p;

            // same as "items.push_back(Item(x, y, z))"
            items.emplace_back(name, c, p);
        }
    }
}

//_____________________________________
void menu()
{
    // Shows the menu the user can choose from
    cout << "Please select a non-linear structure or 0 to exit:\n"
            "1- Binary Search Trees (BST)\n"
            "2- Heaps\n"
            "3- AVL Trees\n";
}

void miniMenu()
{
    // Shows the miniMenu of operations the user can choose from
    cout << "Choose the operation you want to apply or 0 to exit:\n"
            "1. Add item data.\n"
            "2. Remove item data.\n"
            "3. Display the item data normally.\n"
            "4. Display all the items sorted by their name ascending.\n"
            "5. Display all the items sorted by their name descending.\n"
            "6. Display all the items sorted by their prices ascending.\n"
            "7. Display all the items sorted by their prices descending.\n";
}

void Non_Linear()
{
    // read from input.txt
    ifstream Input("../input.txt");
    readItems(Input);

    int ChooseStruct , ChooseOp;
    
    // Call Menu function to show the menu
    menu();

    // let user choose from the previous menu
    while (cin >> ChooseStruct, ChooseStruct != 0)
    {
        // if the user's choice is not in the menu the program will give an error message and loop again until user enter a valid choice
        while (ChooseStruct < 0 || ChooseStruct > 3)
        {
            cout << "Your choice doesn't exist in the menu.\n";
            menu();
            cin >> ChooseStruct;
        }

        // Goes to the case according to user's choice
        if (ChooseStruct == 1)
        {
            cout << "_BST_\n";
            string x, y;
            int z;
            // one tree sort data according to name and the other according to name
            BST tName, tPrice;
            for (auto &item: items) {
                tName.add(item, false);
                tPrice.add(item, true);
            }

            // Call miniMenu function to show the menu for operations' options to be done
            miniMenu();

            // user choose an option other than 0
            // if the choice is 0 terminate the program
            while (cin >> ChooseOp, ChooseOp != 0) {
                switch (ChooseOp) {
                    case 1:
                        cout << "Enter the item details in the corresponding order\n(Name, Category, Price):\n";
                        cin >> x >> y >> z;
                        tName.add(Item(x, y, z), false);
                        tPrice.add(Item(x, y, z), true);
                        break;
                    case 2:
                        cout << "Enter the item details in the corresponding order\n(Name, Category, Price):\n";
                        cin >> x >> y >> z;
                        tName.remove(Item(x, y, z), false);
                        tPrice.remove(Item(x, y, z), true);
                        break;
                    case 3:
                        tName.displayNormally();
                        break;
                    case 4:
                        tName.displaySortedByNameAscending();
                        break;
                    case 5:
                        tName.displaySortedByNameDescending();
                        break;
                    case 6:
                        tPrice.displaySortedByPriceAscending();
                        break;
                    case 7:
                        tPrice.displaySortedByPriceDescending();
                        break;
                    default:
                        // error message if the user choose an option not in [0, ..., 7]
                        cout << "Your choice doesn't exist in the menu.\n";
                        break;
                }
                // Show the miniMenu again
                miniMenu();
            }
        }
        else if (ChooseStruct == 2)
        {
            cout << "_Heap_\n";
            heap x;
            for (auto &item : items)
            {
                x.add(item);
            }
            string n, c;
            int p;
            miniMenu();
            while (cin >> ChooseOp, ChooseOp != 0)
            {
                switch (ChooseOp)
                {
                    case 1:
                        cout << "Enter the name of the item:";
                        cin >> n;
                        cout << "Enter the category of the item:";
                        cin >> c;
                        cout << "Enter the price of the item:";
                        cin >> p;
                        x.add(Item(n, c, p));
                        break;
                    case 2:
                        cout << "Enter the name of the item you want to remove:";
                        cin >> n;
                        cout << "Enter the category of the item:";
                        cin >> c;
                        cout << "Enter the price of the item:";
                        cin >> p;
                        x.remove(Item(n, c, p));
                        break;
                    case 3:
                        x.displayItems();
                        break;
                    case 4:
                        x.sortItem(3);
                        break;
                    case 5:
                        x.sortItem(4);
                        break;
                    case 6:
                        x.sortItem(1);
                        break;
                    case 7:
                        x.sortItem(2);
                        break;
                    default:
                        cout << "Your choice doesn't exist in the menu.\n";
                        break;
                }
                miniMenu();
            }
        }
        else if (ChooseStruct == 3)
        {
            cout << "_AVL Tree_\n";
            AVLTree<Item> avlTree;
            for (auto &item : items)
            {
                avlTree.insert(item);
            }
            string name, category;
            int price;
            ChooseOp = -1;
            while (ChooseOp != 0)
            {
                miniMenu();
                cin >> ChooseOp;
                switch (ChooseOp)
                {
                    case 0:
                        break;
                    case 1:
                        cout << "Enter the name of the item:";
                        cin >> name;
                        cout << "Enter the category of the item:";
                        cin >> category;
                        cout << "Enter the price of the item:";
                        cin >> price;
                        avlTree.insert(Item(name, category, price));
                        break;
                    case 2:
                        cout << "Enter the name of the item:";
                        cin >> name;
                        cout << "Enter the category of the item:";
                        cin >> category;
                        cout << "Enter the price of the item:";
                        cin >> price;
                        avlTree.remove(Item(name, category, price));
                        break;
                    case 3:
                        avlTree.display();
                        break;
                    case 4:
                        avlTree.displayByNameAscending();
                        break;
                    case 5:
                        avlTree.displayByNameDescending();
                        break;
                    case 6:
                        avlTree.displayByPriceAscending();
                        break;
                    case 7:
                        avlTree.displayByPriceDescending();
                        break;
                    default:
                        cout << "Your choice doesn't exist in the menu.\n";
                        break;
                }
            }
        }
        else
        {
            break;
        }

        // Show menu again
        menu();
    }
}
