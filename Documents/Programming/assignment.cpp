#include <iostream>
#include <vector>

class Videotape {
public:
    std::string title;
    std::string ISBN;
    int quantityOrdered;

    Videotape(std::string _title, std::string _ISBN, int _quantity) {
        title = _title;
        ISBN = _ISBN;
        quantityOrdered = _quantity;
    }
};

class PurchaseOrder {
public:
    std::string date;
    std::string supplierName;
    std::string supplierAddress;
    std::vector<Videotape> tapes;
    std::string completionDate;

    void addVideotape(Videotape tape) {
        tapes.push_back(tape);
    }

    void receiveTapes(std::vector<Videotape> receivedTapes) {
        for (Videotape& tape : receivedTapes) {
            // Update inventory and mark the tape as received.
            // Remove it from the purchase order list if needed.
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
    std::vector<Videotape> videotapes;

    void addVideotape(Videotape tape) {
        videotapes.push_back(tape);
    }

    void removeVideotape(Videotape tape) {
        // Remove the videotape from the inventory.
    }

    void displayInventory() {
        // Display the list of videotapes in the inventory.
    }
};

int main() {
    // Example usage of the classes.
    PurchaseOrder order;
    Videotape tape1("Title1", "ISBN1", 10);
    order.addVideotape(tape1);
    // ... Add more tapes, receive them, and send payment.

    Inventory inventory;
    inventory.addVideotape(tape1);
    // ... Add more tapes to the inventory and manage it.

    return 0;
}
