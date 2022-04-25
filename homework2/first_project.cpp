#include <iostream>
#include <memory>

using namespace std;

class BankCell {

private:
    int id;

public:
    BankCell(int id1) {
        id = id1;
        cout << "Bank Cell " << id << " was created\n";
    }
    ~BankCell() {
        cout << "Bank Cell " << id << " was deleted";
    }
    int get_id() const {
        return id;
    }
};

class Human {

private:
    string name;
    shared_ptr<BankCell> cell;

public:
    Human(string name1) {
        name = move(name1);
        cout << "Human " << name << " was created\n";
    }
    void createBankCell(int id) {
        cell = make_shared<BankCell>(id);
    }

    void addBankCell(shared_ptr<BankCell> cell1) {
        cell = move(cell1);
    }

    shared_ptr<BankCell> getBankCell() {
        return cell;
    }

    ~Human() {
        cout << "Human " << name << " was deleted\n";
    }
};

