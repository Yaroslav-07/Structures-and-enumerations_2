#include <iostream>
#include <fstream>
struct bank_account {
    int number;
    std::string name;
    double* balance;
};
void сreate_account_an_file(bank_account& acc) {
    std::ifstream file("file.txt");
    if (!file.is_open()) {
        std::cout << "Ошибка при открытии файла!" << std::endl;
    }
    else {
        file >> acc.number >> acc.name >> *(acc.balance);
        file.close();
    }



}

void change_balance(bank_account& acc) {
    double change;
    char how_change;
    std::cout << "\nHow cange your balance? (for example: + 10 or - 10)\n";

    std::cin >> how_change >> change;
    if (how_change == '+') {
        *(acc.balance) = *(acc.balance) + change;
    }
    else {
        *(acc.balance) = *(acc.balance) - change;
    }
}
int main() {
    bank_account acc1;
    acc1.balance = new double;
    
    {char choice;
    std::cout << "How do you enter the data? (f - file or h - hands)";
    std::cin >> choice;
    if (choice == 'f') {
        сreate_account_an_file(acc1);
    }
    else {

        std::cout << "Wellcome!\nEnter your bank number: ";
        std::cin >> acc1.number;
        std::cout << "Enter your name: ";
        std::cin >> acc1.name;
        std::cout << "Enter your balance: ";
        std::cin >> *(acc1.balance);
    }
    }
    while (*(acc1.balance) > 0 && *(acc1.balance) < 1000000) {
        change_balance(acc1);
        std::cout << "Your bank account: " << acc1.number << ", " << acc1.name << ", " << *(acc1.balance);
        
    }
    if (*(acc1.balance) < 0) {
        std::cout << "\nYour balance =" << *(acc1.balance) << "\nWait for the collectors) ";
    }
    else
        std::cout << "\nYour balance =" << *(acc1.balance) << "\nWait for the tax office) ";
    delete acc1.balance;
}