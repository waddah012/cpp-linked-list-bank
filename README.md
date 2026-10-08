# Linked list bank

I used a singly linked list to store bank accounts in this project. Each node holds an account and a pointer to the next node.

The menu lets you add an account, find it by ID, make a deposit or withdrawal, remove it, and print the accounts. Enter 0 when you want to exit.

The accounts only stay in memory while the program is running. It does not save them to a file, and it does not stop you from using the same ID twice.

To build and run it, you need a C++17 compiler and Make. Open a terminal in this folder and run:

```sh
make
make run
```

You can also run `make check` to check the sample output. That needs Python 3. Use `make clean` if you want to remove the compiled program.
