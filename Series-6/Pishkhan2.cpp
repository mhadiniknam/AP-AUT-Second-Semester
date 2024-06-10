#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <sstream>
#include <iomanip>

using namespace std;

struct Order {
    int second;
    int msecond;
    vector<string> items;
};

class Restaurant {
private:
    int n, m, k;
    map<string, int> menu;
    vector<int> tableCapacities;
    vector<vector<int>> tables;
    int totalMoney = 0;
    int paymentCounter = 1;

public:
    Restaurant() {
        cin >> n >> m >> k;
        tables.resize(200, vector<int>(5, 0));

        for (int i = 0; i < m; ++i) {
            string food;
            int price;
            cin >> food >> price;
            menu[food] = price;
        }

        tableCapacities.resize(k);
        for (int i = 0; i < k; ++i) {
            cin >> tableCapacities[i];
        }
    }

    void start() {
        cin.ignore(); // To ignore the newline character after the last input
        for (int i = 0; i < n; ++i) {
            string input;
            getline(cin, input);
            processInput(input);
        }
    }

private:
    void processInput(const string& input) {
        Order order;
        stringstream ss(input);
        string word;
        while (ss >> word) {
            order.items.push_back(word);
        }

        parseTimestamp(order);

        char command = input[0];
        switch (command) {
            case 'o':
                handleOrder(order);
                break;
            case 'p':
                handlePayment(order);
                break;
            case 't':
                handleTableStatus(order);
                break;
            case 'g':
                handleGeneralStatus(order);
                break;
            default:
                cerr << "Error: Invalid command!" << endl;
                exit(1);
        }
    }

    void parseTimestamp(Order& order) {
        try {
            string timestamp = order.items.back();
            order.second = stoi(timestamp.substr(0, 2)) * 60 + stoi(timestamp.substr(3, 2));
            order.msecond = stoi(timestamp.substr(6, 3));
        } catch (const exception& e) {
            cerr << "Error parsing timestamp: " << e.what() << endl;
        }
    }

    void handleOrder(Order& order) {
        int numPeople = stoi(order.items[order.items.size() - 2]);
        int tableIndex = findTable(numPeople);

        if (tableIndex == -1) {
            cout << "not enough seat." << endl;
            return;
        }

        int totalCost = calculateOrderCost(order);
        if (totalCost == -1) {
            cerr << "Error calculating order cost." << endl;
            return;
        }

        totalMoney += totalCost;
        tables[tableIndex][1] += totalCost;
        tables[tableIndex][2] = paymentCounter++;
        tables[tableIndex][3] = order.second;
        tables[tableIndex][4] = order.msecond;

        cout << "please sit at table number " << tableIndex + 1 << "." << endl;
    }

    int findTable(int numPeople) {
        int bestTable = -1;
        int minCapacity = INT_MAX;

        for (size_t i = 0; i < tableCapacities.size(); ++i) {
            if (tableCapacities[i] >= numPeople && tableCapacities[i] < minCapacity && tables[i][2] == 0) {
                bestTable = i;
                minCapacity = tableCapacities[i];
            }
        }

        return bestTable;
    }

    int calculateOrderCost(Order& order) {
        int totalCost = 0;
        for (size_t i = 0; i < order.items.size() - 2; ++i) {
            try {
                size_t pos = order.items[i].find("X");
                int quantity = stoi(order.items[i].substr(pos + 1));
                string food = order.items[i].substr(0, pos);
                totalCost += menu[food] * quantity;
            } catch (const exception& e) {
                cerr << "Error calculating order cost: " << e.what() << endl;
                return -1;
            }
        }
        return totalCost;
    }

    void handlePayment(Order& order) {
        int paymentId = stoi(order.items[0]);
        int tableIndex = findTableByPaymentId(paymentId);

        if (tableIndex == -1) {
            cout << "pays after eating." << endl;
            return;
        }

        int amount = tables[tableIndex][1];
        cout << "you should pay " << amount << " Toman." << endl;

        tables[tableIndex][1] = 0;
        tables[tableIndex][2] = 0;
    }

    int findTableByPaymentId(int paymentId) {
        for (size_t i = 0; i < tables.size(); ++i) {
            if (tables[i][2] == paymentId) {
                return i;
            }
        }
        return -1;
    }

    void handleTableStatus(Order& order) {
        // Implement table status logic
    }

    void handleGeneralStatus(Order& order) {
        // Implement general status logic
    }
};

int main() {
    Restaurant restaurant;
    restaurant.start();
    return 0;
}
