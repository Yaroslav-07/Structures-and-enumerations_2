#include <iostream>
#include <fstream>
struct bank_account {
    int number;
    std::string name;
    double balance;
};
void fnew_balance(bank_account& acc, double new_balance) {

    acc.balance = new_balance;

}

int main() {
    setlocale(LC_ALL, "Russian");
    bank_account acc1;
    double new_balance;
    std::cout << "Введите номер счёта: ";
    std::cin >> acc1.number;
    std::cout << "Введите имя владельца: ";
    std::cin >> acc1.name;
    std::cout << "Введите баланс: ";
    std::cin >> acc1.balance;
    while (true) {
        std::cout << "Введите новый баланс: ";
        std::cin >> new_balance;
        fnew_balance(acc1, new_balance);
        std::cout << "Ваш счёт : " << acc1.number << ", " << acc1.name << ", " << acc1.balance << std::endl;

    }

}