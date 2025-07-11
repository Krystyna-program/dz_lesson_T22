#include <vector>
#include <algorithm>
#include "Computer.h"

int main()
{
    vector<Computer> comp;

    comp.push_back(Computer("Lenovo", 3.5, 16, true, 18000));
    comp.push_back(Computer("Asus", 2.8, 8, false, 14500));
    comp.push_back(Computer("HP", 3.0, 32, true, 23000));

    cout << "=== List of Computers ===\n";
    for (int i = 0; i < comp.size(); ++i) {
        comp[i].showInfo();
    }
    cout << "===================================\n";

    // 1
    char user[100];
    cout << "Input title: ";
    cin.getline(user, 100);

    auto result = find_if(comp.begin(), comp.end(), [user](const Computer& obj) {
        return strcmp(user, obj.getTitle()) == 0;
        });

    if (result == comp.end()) {
        cout << "Not found!\n";
    }
    else {
        cout << "\n=== Found Computer ===\n";
        result->showInfo();
        comp.erase(result);

        cout << "\n=== Updated List ===\n";
        for (int i = 0; i < comp.size(); ++i) {
            comp[i].showInfo();
        }
    }
    cout << "===================================\n";
}
