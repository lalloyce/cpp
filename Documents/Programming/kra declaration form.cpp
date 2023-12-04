/*
Students:
1. */

#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Date {
    int day;
    int month;
    int year;

    // Constructor to initialize the date
    Date(int d, int m, int y) : day(d), month(m), year(y) {}

    // Function to display the full date
    void displayDate() {
        std::cout << day << "/" << month << "/" << year << std::endl;
    }
};

struct Item {
    string item_description, item_type, item_remarks;
    double item_value;
    int item_quantity;
};

int main()
{
    // Declare variables to store input
    string pin, surname, other_names, gender, nationality, passport_number, flight_number, origin, resident_status, address_hotel, city, animal_products, valuables_residents, valuables_nonresidents, alcohols, perfumes, cigarettes, money, commercial_goods, food_products, others, passenger_signature, officer_signature, receipt_number;

    int day, month, year, postal_address, postal_code;

    double import_duty, excise_duty, vat, other_tax, total_tax;

    //Form headings
    cout << "FORM F88" << endl;
    cout << "Regulations 45(1)(2)" << endl;
    cout << "EAST AFRICAN COMMUNITY" << endl;
    cout << "REPUBLIC OF KENYA" << endl;
    cout << "KENYA REVENUE AUTHORITY" << endl;
    cout << "KENYA REVENUE AUTHORITY" << endl;
    cout << "PASSENGER DECLARATION FORM" << endl;

    cout << "This form must be completed by passengers prior to arrival from foreign (including those from East" << std::endl;
    cout << "African Community Partner States) and presented to the Kenya Revenue Authority Customs officers at" << std::endl;
    cout << "the point of entry into Kenya." << std::endl;
    cout << "For further guidance regarding the statutory requirements, please refer to the explanatory notes on" << std::endl;
    cout << "the back of this form." << endl;

    // Prompt for and read the surname
    cout << "Surname: ";
    getline(cin, surname); 

    // Prompt for and read the other names
    cout << "Other names: ";
    getline(cin, other_names); 

    // Prompt for and read the gender
    cout << "Are you male or female?";
    getline(cin, gender);   

    // Prompt the user to enter their date of birth
    cout << "Enter your date of birth (DD MM YYYY): ";
    cin >> day >> month >> year;
    Date dob(day, month, year); // Create a Date object and initialize it with the entered date components
    
    // Prompt the user to enter their Nationality
    cout << "Nationality: ";
    getline(cin, nationality);

    // Prompt the user to enter their Passport Number
    cout << "Passport Number. ";
    cin >> passport_number;

    // Prompt the user to enter Flight Number
    cout << "Flight No / Vehicle No/ Vessel No.";
    getline(cin, flight_number);

    // Prompt the user to enter their origin
    cout << "From where";
   getline(cin, origin);

    // Prompt the user to enter their date of entry
    cout << "Date of entry (DD MM YYYY): ";
    cin >> day >> month >> year;
    Date entry_date(day, month, year); // Create a Date object and initialize it with the entered date components

    // Prompt the user to enter their Resident Status
    cout << "Are you a Resident or Non-Resident?";
    cin >> resident_status;

    // Prompt the user to enter their local address
    cout << "Address in Kenya";
    cout << "(a) Hotel";
    getline(cin, address_hotel);

    cout << "(b) Post Office Box";
    cin >> postal_address;

    cout << "Code";
    cin >> postal_code;

    cout << "City";
    cin >> city;

    cout << "I am bringing into Kenya the following (Please respond with Yes or No, where applicable, in the appropriate boxes)";

    cout << "1. Animal and plants, animal and plant products, microbes, biological products, human tissues, blood" << std::endl;
    cout << "and animal products";
    cin >> animal_products;

    cout << "2. a) Residents: Articles valued at/over USD 500 from overseas:";
    cin >> valuables_residents;

    cout << "b) Non-Residents: Articles valued at/over USD 500 which will remain in the territory";
    cin >> valuables_nonresidents;

    cout << "3. Spirits, including liquors exceeding in all one litre, or wine excecding, fwo Itres";
    cin >> alcohols;

    cout << "4. Perfumes and toiletries exceeding in all one litre, of which the perfume is more than a quarter.";
    cin >> perfumes;

    cout << "5. Cigarettes, cigars, cheroots, cigarillos, tobacco and snuff exceeding in all 250 grams in weight";
    cin >> cigarettes;

    cout << "6. Carrying currency or monetary instruments over $5,000 US (or forelan equivalent)";
    cin >> money;

    cout << "7. Goods of commercial value, samples, advertisement products";
    cin >> commercial_goods;

    cout << "8. Any food products";
    cin >> food_products;

    cout << "9. Other articles that should be declared to Gustoms";
    cin >> others;

    cout << "Full details of articles/goods in the passenger's possession should be provided in the space indicated below;";
    vector<Item> items;  // Store items in a vector

    int itemCount;
    cout << "How many items are you declaring? ";
    cin >> itemCount;

    // Input loop to gather declared items information
    for (int i = 0; i <= itemCount; i++) {
        Item item;
        
        cout << "Item " << (i + 1) << " Description of Goods/type of Currency: ";
        cin >> item.item_description;

        cout << "Item " << (i + 1) << " Type/Model: ";
        cin >> item.item_type;

        cout << "Item " << (i + 1) << " Quantity: ";
        cin >> item.item_quantity;

        cout << "Item " << (i + 1) << " Value in US$: ";
        cin >> item.item_value;

        cout << "Item " << (i + 1) << " Remarks, if any: ";
        cin >> item.item_remarks;

        items.push_back(item);  // Add the item to the vector
    }

    cout << "Declaration";
    cout << "I declare the information oven in this form is true and accurate to the best of my knowledge.";

    cout << "Passenger's signature";
    cin >> passenger_signature;

    cout << "Date DD MM YYYY";
    cin >> day >> month >> year;
    Date signature_date(day, month, year); // Create a Date object and initialize it with the entered date components


    cout << "FOR OFFICIAL USE ONLY";

    cout << "COMPUTED TAXES (Kshs)";
    
    cout << "Import Duty";
    cin >> import_duty;

    cout << "Excise Duty";
    cin >> excise_duty;

    cout << "VAT";
    cin >> vat;

    cout << "Any other tax";
    cin >> other_tax;

    //sum up all taxes due and display it
    total_tax = import_duty + excise_duty + vat + other_tax; 
    cout << "Total: " << total_tax << " Kshs" << endl;

    cout << "Receipt Number, where applicable.";
    cin >> receipt_number;
  
    cout << "Officer's signature";
    cin >> officer_signature;

    cout << "Date DD MM YYYY";
    cin >> day >> month >> year;
    Date officer_signature_date(day, month, year); // Create a Date object and initialize it with the entered date components
    
    cout << "WARNING: It is an offence under the East African Community Customs management Act 2004";
    cout << "to give false information to a Customs Officer, and is punishable under Section 203 of";
    cout << "the sald Act";
    cout << "Including forfeiture of the subject goods.";


    return 0;
}
