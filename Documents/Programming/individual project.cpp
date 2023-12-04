#include <iostream>
#include <string>

using namespace std;

class CreditScoreCalculator {
public:
    int calculateCreditScore(int age, double income, string employmentStatus, bool regularIncome, double debt);
};

class LoanApplicant {
private:
    string name;
    int age;
    string employmentStatus;
    double monthlyIncome;
    bool regularIncome;
    double debt;

public:
    LoanApplicant(string _name, int _age, string _employmentStatus, double _monthlyIncome, bool _regularIncome, double _debt);

    string getName() const;
    int getAge() const;
    string getEmploymentStatus() const;
    double getMonthlyIncome() const;
    bool hasRegularIncome() const;
    double getDebt() const;

    void applyForLoan();
    void checkCreditScoreAndDecide(int creditScore);
    int presentLoanOptions(double adjustedIncome);
};

class Loan {
private:
    double amount;
    double interestRate;

public:
    Loan(double _amount, double _interestRate);

    double getAmount() const;
    double getInterestRate() const;
};

// Implement the CreditScoreCalculator methods

int CreditScoreCalculator::calculateCreditScore(int age, double income, string employmentStatus, bool regularIncome, double debt) {
    // Adjust income by subtracting debt, ensuring it does not go below 0
    double adjustedIncome = max(income - debt, 0.0);

    double ageScore = (age / 100.0) * 200.0;
    double incomeScore = (adjustedIncome / 100.0) * 500.0;

    double employmentStatusMultiplier = 1.0;

    if (employmentStatus == "student") {
        employmentStatusMultiplier = 0.4;
    } else if (employmentStatus == "unemployed") {
        employmentStatusMultiplier = 0.25;
    }

    double employmentStatusScore = employmentStatusMultiplier * 150.0;

    double regularIncomeScore = regularIncome ? 100.0 : 50.0;

    // Calculate the total credit score using the specified weights
    double totalScore = (0.2 * ageScore) + (0.5 * incomeScore) + (0.15 * employmentStatusScore) + (0.1 * regularIncomeScore);

    // Ensure credit score is not negative
    int creditScore = max(static_cast<int>(totalScore), 0);

    // Ensure credit score does not exceed 1000
    creditScore = min(creditScore, 1000);

    return creditScore;
}

// Implement the LoanApplicant methods

LoanApplicant::LoanApplicant(string _name, int _age, string _employmentStatus, double _monthlyIncome, bool _regularIncome, double _debt) {
    name = _name;
    age = _age;
    employmentStatus = _employmentStatus;
    monthlyIncome = _monthlyIncome;
    regularIncome = _regularIncome;
    debt = _debt;
}

string LoanApplicant::getName() const {
    return name;
}

int LoanApplicant::getAge() const {
    return age;
}

string LoanApplicant::getEmploymentStatus() const {
    return employmentStatus;
}

double LoanApplicant::getMonthlyIncome() const {
    return monthlyIncome;
}

bool LoanApplicant::hasRegularIncome() const {
    return regularIncome;
}

double LoanApplicant::getDebt() const {
    return debt;
}

void LoanApplicant::applyForLoan() {
    // Ask questions and gather information
    // For simplicity, I'm using hard-coded values. You can modify this part based on your needs.
    // ...

    // Calculate credit score
    CreditScoreCalculator calculator;
    int creditScore = calculator.calculateCreditScore(getAge(), getMonthlyIncome(), getEmploymentStatus(), hasRegularIncome(), getDebt());

    // Display the credit score to the user
    cout << "Your credit score: " << creditScore << endl;

    // Check credit score and decide on the loan
    checkCreditScoreAndDecide(creditScore);
}

void LoanApplicant::checkCreditScoreAndDecide(int creditScore) {
    // Implement logic to decide whether to approve or decline the loan
    if (creditScore < 450) {
        cout << "Sorry, " << getName() << ". You do not qualify for a loan due to a low credit score.\n";
    } else {
        cout << "Congratulations, " << getName() << "! You qualify for a loan.\n";
        // Present loan options based on adjusted income
        double adjustedIncome = max(getMonthlyIncome() - getDebt(), 0.0);
        presentLoanOptions(adjustedIncome);
    }
}

int LoanApplicant::presentLoanOptions(double adjustedIncome) {
    // Present loan options without indicating the percentage of adjusted income
    cout << "You qualify for the following loan amounts:\n";
    cout << "1. Option 1\n";
    cout << "2. Option 2\n";
    cout << "3. Option 3\n";

    // Prompt user to select an option
    int selectedOption;
    cout << "Select a loan option (1-3): ";
    cin >> selectedOption;

    // Validate the selected option
    while (selectedOption < 1 || selectedOption > 3) {
        cout << "Invalid option. Please select a loan option (1-3): ";
        cin >> selectedOption;
    }

    // You can use 'selectedOption' for further processing or displaying information
    return selectedOption;
}

// Implement the Loan methods

Loan::Loan(double _amount, double _interestRate) {
    amount = _amount;
    interestRate = _interestRate;
}

double Loan::getAmount() const {
    return amount;
}

double Loan::getInterestRate() const {
    return interestRate;
}

int main() {
    // Example usage
    string name;
    int age;
    string employmentStatus;
    double monthlyIncome;
    bool regularIncome;
    double debt;

    cout << "Enter your name: ";
    getline(cin, name);

    cout << "Enter your age: ";
    cin >> age;

    cout << "Enter your employment status (employed, unemployed, student): ";
    cin.ignore(); // Ignore the newline character left in the buffer
    getline(cin, employmentStatus);

    cout << "Enter your monthly income: ";
    cin >> monthlyIncome;

    cout << "Is your income regular? (1 for yes, 0 for no): ";
    cin >> regularIncome;

    cout << "Enter your debt amount: ";
    cin >> debt;

    LoanApplicant applicant(name, age, employmentStatus, monthlyIncome, regularIncome, debt);
    applicant.applyForLoan();

    return 0;
}
