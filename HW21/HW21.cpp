#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;
class Computer {
    char title[64];
    double frequency;
    int RAM;
    bool DVD;
    double price;
public:
    Computer(const char* name, double new_frequency, int new_RAM, bool has_DVD, double new_price) {
        int i = 0;
        while (name[i] != '\0') {
            title[i] = name[i];
            i++;
        }
        title[i] = '\0';
        frequency = new_frequency;
        RAM = new_RAM;
        DVD = has_DVD;
        price = new_price;
    }
    const char* getTitle() const {
        return title; 
    }
    double getFrequency() const { 
        return frequency; 
    }
    int getRAM() const { 
        return RAM; 
    }
    bool getDVD() const { 
        return DVD; 
    }
    double getPrice() const { 
        return price; 
    }
    void setPrice(double new_price) { price = new_price; }
    void showInfo() const {
        cout << title << ", "
            << frequency << " GHz, "
            << RAM << " GB RAM, "
            << (DVD ? "DVD ROM" : "no DVD ROM") << ", $"
            << price << endl;
    }
};

int main() {
    vector<Computer> computers = {
        Computer("Asus TUF Gaming A17", 3.2, 16, true, 1200),
        Computer("Asus ROG Strix G15", 2.9, 32, false, 1500),
        Computer("Asus VivoBook 15", 1.8, 8, true, 700),
        Computer("Asus ZenBook Pro", 2.4, 16, false, 1300),
        Computer("Asus ExpertBook B1", 2.1, 4, true, 500)
    };

    for (auto a : computers) {
        a.showInfo();
        cout << endl;
    }
    cout << "=======================\n";
    auto find = find_if(computers.begin(), computers.end(), [](Computer obj)
        {
            return strcmp("Asus VivoBook 15", obj.getTitle()) == 0;
        });
    if (find == computers.end()) {
        cout << "Not found!\n";
    }
    else {
        cout << "Found: \n";
        find->showInfo();
        cout << endl;
    }
    cout << "=======================\n";

    auto min = min_element(computers.begin(), computers.end(), [](Computer a, Computer b) {
        return a.getFrequency() < b.getFrequency();
        });
    if (min != computers.end()) {
        computers.erase(min);
    }
    for (auto a : computers) {
        a.showInfo();
        cout << endl;
    }
    cout << "=======================\n";
    int count = count_if(computers.begin(), computers.end(), [](Computer obj)
        {
            return obj.getDVD();
        });
    cout << "Amount: " << count << endl;
    cout << "=======================\n";

    for_each(computers.begin(), computers.end(), [](Computer& obj)
        {
            if (obj.getRAM() > 16) {
                obj.setPrice(obj.getPrice() + 300);
            }
        });
    for (auto a : computers) {
        a.showInfo();
        cout << endl;
    }
    cout << "=======================\n";

    sort(computers.begin(), computers.end(), [](Computer a, Computer b) {
        return a.getPrice() > b.getPrice();
        });
    for (auto a : computers) {
        a.showInfo();
        cout << endl;
    }
    cout << "=======================\n";

    sort(computers.begin(), computers.end(), [](Computer a, Computer b) {
        return a.getPrice() < b.getPrice();
        });
    for (auto a : computers) {
        a.showInfo();
        cout << endl;
    }
}
