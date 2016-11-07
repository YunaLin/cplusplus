#ifndef PERSONALACCOUNT_H
#define PERSONALACCOUNT_H

class PersonalAccount {
    private:
        int balance;
    public:
        PersonalAccount();
        void add(int value);
        void subtract(int value);
        void getBalance();
};

#endif
