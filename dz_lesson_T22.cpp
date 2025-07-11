#include <vector>
#include <algorithm>
#include "Computer.h"

int main()
{
    vector<Computer> comp;

    comp.push_back(Computer("Lenovo", 3.5, 16, true, 18000));
    comp.push_back(Computer("Asus", 2.8, 8, false, 14500));
    comp.push_back(Computer("HP", 3.0, 32, true, 23000));
    comp.push_back(Computer("Dell", 3.2, 12, true, 20000));
    comp.push_back(Computer("Acer", 2.5, 8, false, 12000));
    comp.push_back(Computer("Apple", 3.8, 16, true, 35000));

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

    // 2
    if (comp.size() > 0) {
        auto min_obj = min_element(comp.begin(), comp.end(), [](const Computer& a, const Computer& b) {
            return a.getFrequency() < b.getFrequency();
            });

        cout << "\n=== Computer with MIN Frequency ===\n";
        min_obj->showInfo();
        comp.erase(min_obj);

        cout << "\n=== Updated List ===\n";
        for (int i = 0; i < comp.size(); ++i) {
            comp[i].showInfo();
        }
    }
    else {
        cout << "\nVector is empty\n";
    }
    cout << "===================================\n";

    // 3
    int countDVD = count_if(comp.begin(), comp.end(), [](const Computer& c) {
        return c.getDVD();
        });
    cout << "\nNumber of computers with DVD-ROM: " << countDVD << endl;
    cout << "===================================\n";

    // 4
    for_each(comp.begin(), comp.end(), [](Computer& d) {
        if (d.getRAMSize() > 16) {
            float oldPrice = d.getPrice();
            float newPrice = oldPrice * 1.10f;
            d.setPrice(newPrice);

            cout << "Was: " << oldPrice << " UAH --> Now: " << newPrice << " UAH\n";
            d.showInfo();
        }
        });
    cout << "=== Updated List ===\n";
    for (int i = 0; i < comp.size(); ++i) {
        comp[i].showInfo();
    }
    cout << "===================================\n";
    
}
