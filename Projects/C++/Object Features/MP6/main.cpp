#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

const int MAX_RECORDS = 50;
const int NAME_SIZE = 20;

struct Flower {
    string name;
    int quantity;
    double cost;

    Flower() : name(""), quantity(0), cost(0.0) {}

    string to_string() const {
        return name + " " + std::to_string(quantity) + " " + std::to_string(cost);
    }
};

void initializeFile() {
    ofstream file("flowers.dat");
    Flower emptyFlower;
    for (int i = 0; i < MAX_RECORDS; ++i) {
        file << emptyFlower.to_string() << endl;
    }
    file.close();
}

vector<Flower> loadFlowers() {
    vector<Flower> flowers(MAX_RECORDS);
    ifstream file("flowers.dat");
    for (int i = 0; i < MAX_RECORDS; ++i) {
        file >> flowers[i].name >> flowers[i].quantity >> flowers[i].cost;
    }
    file.close();
    return flowers;
}

void saveFlowers(const vector<Flower>& flowers) {
    ofstream file("flowers.dat");
    for (const auto& flower : flowers) {
        file << flower.to_string() << endl;
    }
    file.close();
}

void inputFlowerData(vector<Flower>& flowers) {
    int recordNum;
    Flower flower;

    cout << "Enter Flower Identification Number (0-49): ";
    cin >> recordNum;
    cin.ignore();

    if (recordNum < 0 || recordNum >= MAX_RECORDS) {
        cerr << "Invalid record number." << endl;
        return;
    }

    cout << "Enter Flower Name: ";
    getline(cin, flower.name);
    cout << "Enter Quantity: ";
    cin >> flower.quantity;
    cout << "Enter Cost: ";
    cin >> flower.cost;

    flowers[recordNum] = flower;
    saveFlowers(flowers);
}

void listAllFlowers(const vector<Flower>& flowers) {
    for (int i = 0; i < MAX_RECORDS; ++i) {
        if (!flowers[i].name.empty()) {
            cout << "Record Num: " << i 
                 << " | Name: " << flowers[i].name 
                 << " | Quantity: " << flowers[i].quantity 
                 << " | Cost: $" << flowers[i].cost << endl;
        }
    }
}

void deleteFlowerRecord(vector<Flower>& flowers) {
    int recordNum;
    cout << "Enter Flower Identification Number to delete (0-49): ";
    cin >> recordNum;

    if (recordNum < 0 || recordNum >= MAX_RECORDS) {
        cerr << "Invalid record number." << endl;
        return;
    }

    flowers[recordNum] = Flower();
    saveFlowers(flowers);
}

void updateFlowerRecord(vector<Flower>& flowers) {
    int recordNum;
    Flower flower;

    cout << "Enter Flower Identification Number to update (0-49): ";
    cin >> recordNum;
    cin.ignore();

    if (recordNum < 0 || recordNum >= MAX_RECORDS) {
        cerr << "Invalid record number." << endl;
        return;
    }

    cout << "Enter New Flower Name: ";
    getline(cin, flower.name);
    cout << "Enter New Quantity: ";
    cin >> flower.quantity;
    cout << "Enter New Cost: ";
    cin >> flower.cost;

    flowers[recordNum] = flower;
    saveFlowers(flowers);
}

int main() {
    initializeFile();
    vector<Flower> flowers = loadFlowers();

    int choice;
    do {
        cout << "\nFlower Store Inventory Menu:\n";
        cout << "1. Input Flower Data\n";
        cout << "2. List All Flowers\n";
        cout << "3. Delete Flower Record\n";
        cout << "4. Update Flower Record\n";
        cout << "5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch (choice) {
            case 1:
                inputFlowerData(flowers);
                break;
            case 2:
                listAllFlowers(flowers);
                break;
            case 3:
                deleteFlowerRecord(flowers);
                break;
            case 4:
                updateFlowerRecord(flowers);
                break;
            case 5:
                cout << "Exiting the program." << endl;
                break;
            default:
                cerr << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 5);

    return 0;
}
