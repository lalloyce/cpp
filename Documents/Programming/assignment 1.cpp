#include <iostream>
/*
Student Name: Lawrence JUma
Student ID: KCA/10/03594
Course Unit: BIT 02103 - Object Oriented Technologies
*/



class Videotape {
public:
    std::string title;
    std::string ISBN;
    int quantityOrdered;

    Videotape(const std::string& _title, const std::string& _ISBN, int _quantity)
        : title(_title), ISBN(_ISBN), quantityOrdered(_quantity) {}
};

class PurchaseOrder {
public:
    std::string date;
    std::string supplierName;
    std::string supplierAddress;
    Videotape* tapes;
    int tapeCount;
    int tapeCapacity;
    std::string completionDate;

    PurchaseOrder() : tapes(nullptr), tapeCount(0), tapeCapacity(0) {}

    void addVideotape(const Videotape& tape) {
        if (tapeCount >= tapeCapacity) {
            // If the array is full, expand it by allocating more memory.
            int newCapacity = (tapeCapacity == 0) ? 1 : tapeCapacity * 2;
            Videotape* newTapes = new Videotape[newCapacity];
            for (int i = 0; i < tapeCount; i++) {
                newTapes[i] = tapes[i];
            }
            delete[] tapes;
            tapes = newTapes;
            tapeCapacity = newCapacity;
        }
        tapes[tapeCount++] = tape;
    }

    void receiveTapes(const Videotape* receivedTapes, int receivedCount) {
        for (int i = 0; i < receivedCount; i++) {
            // Update inventory and mark the tapes as received.
            // Remove them from the purchase order list if needed.
        }
    }

    void sendPayment() {
        // Send payment to the supplier.
        completionDate = getCurrentDate();
    }

    void displayOrderDetails() {
        // Display purchase order details.
    }

    std::string getCurrentDate() {
        // Implement date retrieval logic here.
        return "2023-10-24";
    }
};

class Inventory {
public:
    Videotape* videotapes;
    int tapeCount;
    int tapeCapacity;

    Inventory() : videotapes(nullptr), tapeCount(0), tapeCapacity(0) {}

    void addVideotape(const Videotape& tape) {
        if (tapeCount >= tapeCapacity) {
            // If the array is full, expand it by allocating more memory.
            int newCapacity = (tapeCapacity == 0) ? 1 : tapeCapacity * 2;
            Videotape* newTapes = new Videotape[newCapacity];
            for (int i = 0; i < tapeCount; i++) {
                newTapes[i] = videotapes[i];
            }
            delete[] videotapes;
            videotapes = newTapes;
            tapeCapacity = newCapacity;
        }
        videotapes[tapeCount++] = tape;
    }

    void removeVideotape(const Videotape& tape) {
        // Remove the videotape from the inventory.
    }

    void displayInventory() {
        // Display the list of videotapes in the inventory.
    }
};


