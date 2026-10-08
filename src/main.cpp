
#include <iostream>
#include <string>
using namespace std;
// Assignment-Linked list assignment

struct BankAccount { // bank class simple
    int    id;        // this is for an account ID
    string name;      // String for account holders name
    double balance;   // the current balance of account
};

struct Node { // linked list node for bank account
    BankAccount data; // We will store the account here
    Node* next;       // This is the use of pointers to next node

    Node(const BankAccount& acc) {
        data = acc;      // This copies account info
        next = nullptr;  // The new node doesn't point to anything yet
    }
};


class BankList { // this is the linked list class for bank accounts
private:
    Node* head;  // This points the pointer to the head of the list

public:
    BankList() : head(nullptr) {}

    ~BankList() { // all the nodes must be deleted so that their is no memory leaks destructor
        Node* cur = head;  // the traversal
        while (cur != nullptr) {
            Node* toDelete = cur; //  moves cur forward to next node
            cur = cur->next;   //loops through the list
            delete toDelete;  //deletes node stored
        }
    }

    bool IsEmpty() const {  //declares function to see if the list is empty
        return head == nullptr; //returns true if no head
    }


    void AddAccount(const BankAccount& acc) { //  The new accounts will be added to the end
        Node* n = new Node(acc);
        if (head == nullptr) {          // Here The list here is empty
            head = n;
            return;
        }
        Node* cur = head;               // Here the list is not empty
        while (cur->next != nullptr) {
            cur = cur->next;
        }
        cur->next = n;                  // This is were we add the new node to the end
    }


    BankAccount* FindById(int id) { // this is to finding the  account by ID
        Node* cur = head;
        while (cur != nullptr) {
            if (cur->data.id == id) {
                return &cur->data;      // This returns theddress to modify balance
            }
            cur = cur->next;
        }
        return nullptr;
    }


    bool RemoveById(int id) { // this function wer reomve the accounts with matching ID and returns true
        if (head == nullptr) return false;

        if (head->data.id == id) {  // this function checks if the head is the one to remove
            Node* oldHead = head;   // temporary pointer
            head = head->next;
            delete oldHead;
            return true;
        }


        Node* prev = head;  // if not find the previous node
        Node* cur  = head->next;
        while (cur != nullptr) { // loops through nodes
            if (cur->data.id == id) {
                prev->next = cur->next;
                delete cur;
                return true;
            }
            prev = cur;
            cur  = cur->next; //moves to the next node
        }
        return false;
    }


    bool Deposit(int id, double amount) { // The boolean deposit function to deposit on account if and return true in success
        if (amount < 0) return false;  // no negative deposit
        BankAccount* acc = FindById(id);   //search for account
        if (acc == nullptr) return false;   //if not found
        acc->balance += amount;
        return true;
    }

    // here we withdraw from account id; returns true on success
    bool Withdraw(int id, double amount) { // The boolean withdraw function
        if (amount < 0) return false;  // no negative withdrawal
        BankAccount* acc = FindById(id);
        if (acc == nullptr) return false; //if not found
        if (acc->balance < amount) return false;
        acc->balance -= amount;
        return true;
    }

    // This prints all the accounts
    void Print() const {
        if (head == nullptr) {
            cout << "empty\n"; //checks if empty
            return;
        }
        Node* cur = head;
        while (cur != nullptr) {
            cout << "id: " << cur->data.id
                 << ", name: " << cur->data.name
                 << ", balance: $" << cur->data.balance << '\n';
            cur = cur->next;
        }
    }
};




void ShowMenu() { //menu titles printed
    cout << "\nSimple Bank Menu\n"
         << "1) Add account\n"
         << "2) Deposit\n"
         << "3) Withdraw\n"
         << "4) Remove account\n"
         << "5) Find account\n"
         << "6) Print all\n"
         << "0) Exit\n"
         << "Choose: ";
}

int main() {
    BankList bank; // bank list
    int choice = -1; // store the selection initialized to -1

    while (true) { // infinite loop for menu
        ShowMenu();
        if (!(cin >> choice)) break;
        if (choice == 0) break;

        if (choice == 1) {
            BankAccount acc;
            cout << "enter id: ";
            cin >> acc.id;
            cin.ignore(); // clear newline before getline
            cout << "enter name: ";
            getline(cin, acc.name);
            cout << "Please enter the starting balance: ";
            cin >> acc.balance;
            bank.AddAccount(acc);
            cout << "added.\n";
        }
        else if (choice == 2) {
            int id;
            double amt;
            cout << "id: ";
            cin >> id;
            cout << "amount: ";
            cin >> amt;
            bool ok = bank.Deposit(id, amt);  // This call deposits and save result
            if (ok) {
                cout << "deposited.\n";
            } else {
                cout << "The deposit failed.\n";
            }
        }
        else if (choice == 3) {
            int id;
            double amt;
             cout << "id: ";
             cin >> id;
             cout << "amount: ";
             cin >> amt;
             bool ok = bank.Withdraw(id, amt);  // This calls Withdraw and save result
             if (ok) {
                cout << "withdrawn.\n";
            } else {
                cout << "The withdraw failed.\n";
            }
        }
        else if (choice == 4) {
            int id;
            cout << "The id to remove: ";
             cin >> id;
             bool ok = bank.RemoveById(id);  // This calls RemoveById and saves result
             if (ok) {
                cout << "removed\n";
            } else {
                cout << "not found\n";
            }
        }
        else if (choice == 5) {
            int id; cout << "ID to find: "; cin >> id;
            BankAccount* acc = bank.FindById(id);
            if (acc == nullptr) cout << "not found.\n";
            else {
                cout << "id: " << acc->id
                     << ", name: " << acc->name
                     << ", balance: $" << acc->balance << '\n';
            }
        }
        else if (choice == 6) {
            bank.Print();
        }
        else {
            cout << "Thats an invalid choice.\n";
        }
    }

    cout << "Goodbye.\n";
    return 0;
}


//g++ Linkedlist.cpp -o Linkedlist
// ./Linkedlist
