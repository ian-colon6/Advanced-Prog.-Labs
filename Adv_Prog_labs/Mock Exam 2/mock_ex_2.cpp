#include <string>
#include <vector>
#include <iostream>

using namespace std;

enum AccountType
{
    SAVINGS,
    CHECKING,
    ENTERPRISE
};

class Account
{
private:
    int accNo;
    double balance;
    AccountType accType;

public:
    Account(int accNo, double balance, AccountType type){
        this->accNo = accNo;
        this->balance = balance;
        this->accType = type;
    }

    const AccountType getType() const
    {
        return accType;
    }

    int getAccNo()
    {
        return this->accNo;
    }

    double getBalance()
    {
        return this->balance;
    }

    void setBalance(double balance)
    {
        this->balance = balance;
    }

    string toString()
    {
        string result = "";
        result += "AccNo: ";
        result += to_string(this->accNo);
        result += ", Balance: ";
        result += to_string(this->balance);
        result += ", AccType: ";
        if(this->getType()==ENTERPRISE)
            result += "ENTERPRISE";
        if(this->getType()==SAVINGS)
            result += "SAVINGS";
        if(this->getType()== CHECKING)
            result += "CHECKING";

        return result;
    }

    // 1. TODO
    bool overdraft(int amount); // TODO First
    void withdraw(int amount);
    void deposit(int amount);
};

class Bank{
private:
    string name;
    vector<Account> accounts;
public:
    Bank(string name, vector<Account> v){
        this->name = name;
        this->accounts = v;
    }

    const string getName() const {
        return name;
    }

    void setName(string name) {
        this->name = name;
    }

    //10. TODO: return the amount of accounts based on the account type passed as parameter that are on the bank
    int getNoOfAccounts(AccountType type);
};

class CheckingAccount : public Account
{
private:
    int transactionsNo;
    bool activeCard = true;

public:
    CheckingAccount(int accNo, double balance) : Account(accNo, balance, CHECKING)
    {
        this->transactionsNo = 0;
    }

    // 2. TODO: create a constructor that accepts a parameter
    CheckingAccount(int accNo, double balance, int transactions);

    int getTransactionsNo() const
    {
        return transactionsNo;
    }

    void setTransactionsNo(int transactionsNo)
    {
        this->transactionsNo = transactionsNo;
    }

    bool isActiveCard() {
        return activeCard;
    }

    void setActiveCard(bool card) {
        activeCard = card;
    }

    string toString()
    {
        string result = Account::toString();
        result += ", Transactions: ";
        result += to_string(this->transactionsNo);

        return result;
    }
};

class SavingsAccount : public Account
{
private:
    double interestRate;
    double defaultInterest = 0.04;

public:
    // 2. TODO: interest rate to be 4%
    SavingsAccount(int accNo, double balance);

    SavingsAccount(int accNo, double balance, double interest) : Account(accNo, balance, SAVINGS)
    {
        this->interestRate = interest;
    }

    double getInterestRate()
    {
        return this->interestRate;
    }

    string toString()
    {
        string result = Account::toString();
        result += ", Interest Rate: ";
        result += to_string(this->interestRate);

        return result;
    }

    // Formula: New Balance = currentBalance * interestRate * timesInAYear
    // 4. TODO: Calculate the simple interest gained in a year and add it to the balance
    double getNewBalanceWithInterestGained();
};

class EnterpriseAccount : public Account
{
private:
    int amountOfAuthorizedPeople;
    vector<string> authorizedPeople;

public:
    EnterpriseAccount(int accNo, double balance) : Account(accNo, balance, ENTERPRISE){
        this->amountOfAuthorizedPeople = 0;
    }

    EnterpriseAccount(int accNo, double balance, vector<string> v) : Account(accNo, balance, ENTERPRISE){
        this->amountOfAuthorizedPeople = v.size();
        this->authorizedPeople = v;
    }

    vector<string> getAuthorizedPeople(){
        return this->authorizedPeople;
    }


    int getAmountOfAuthorizedPeople() {
        return this->amountOfAuthorizedPeople;
    }

    void setAmountOfAuthorizedPeople(int people) {
        this->amountOfAuthorizedPeople = people;
    }

    string toString(){
        string result = Account::toString();
        result += ", Authorized people for this bank account: ";
        for (int i = 0; i < authorizedPeople.size(); i++)
        {
            string authorizedString = authorizedPeople[i] + " ";
            result += authorizedString;
        }

        return result;
    }

    // 5. TODO: add people & remove the specified person from the vector
    void addPeople(string nameAdded);
    void removePeople(string nameRemove);

    /* 6. TODO: verify if the account complies with the bank's policy:
    * return 1 if the account is valid, 0 if is acceptable and -1 if not valid
    * if the account has less than 3 authorized people then the account is not valid
    * if the account has more than 3 but less than 5 the account is acceptable
    * if the account has 5 or more authorized people then the account is valid.
    * You cannot use the .size() function of the vector or the # number of autorized
    * people as the bank believes there has been an error when it comes to this number
    * and needs the verification.
    * HINT: Use a loop and verify if a string is empty or not
    */
    int verifyAccount();
};


//----------------------EXERCISES-----------------------
//EXERCISE #1
//You must implement the overdraft method first and then use it on withdrawal
bool Account::overdraft(int amount){

    if(amount > this->getBalance()){
        return true;
    }

    return false;
}
void Account::deposit(int amount) {
    this->setBalance(this->getBalance() + amount);
}
void Account::withdraw(int amount) {
    if(this->overdraft(amount) == false){
        this->setBalance(this->getBalance() - amount);
    }
}

//EXERCISE #2
CheckingAccount::CheckingAccount(int accNo, double balance, int transactions) : Account(accNo, balance, CHECKING) {

    this->transactionsNo = transactions;
}
SavingsAccount::SavingsAccount(int accNo, double balance) : Account(accNo, balance, SAVINGS) {

    this->interestRate = defaultInterest;
}


//EXERCISE #3
//TODO: return the account number of the checking account that does not have an active card
//if all the accounts have active cards, return 0;
//USE AN ENHANCED FOR LOOP
int checkActiveCards(vector<CheckingAccount> v) {

    for(CheckingAccount acc : v){
        if(acc.isActiveCard() == false){
            return acc.getAccNo();
        }
    }

    return 0;
}

//EXERCISE #4
// Formula: New Balance = currentBalance * interestRate * timesInAYear
// TODO: Calculate the simple interest gained in a year and add it to the balance
double SavingsAccount::getNewBalanceWithInterestGained() {

    double New_balance = this->getBalance() + (this->getBalance() * this->getInterestRate());

    return New_balance;
}

//EXERCISE #5
//TODO: Add and remove the specified person from the vector of authorized people
void EnterpriseAccount::addPeople(string nameAdded) {

    authorizedPeople.push_back(nameAdded);

}
void EnterpriseAccount::removePeople(string nameRemove) {
    for(int i = 0; i < authorizedPeople.size(); i++){
        if(authorizedPeople[i] == nameRemove){
            authorizedPeople.erase(authorizedPeople.begin() + i);
        }
    }
}

//EXERCISE #6
//TODO: Verify if the account complies with the bank's policy.
/* return 1 if the account is valid, 0 if is acceptable and -1 if not valid
 *
 * if the account has less than 3 authorized people then the account is not valid
 * if the account has more than 3 but less than 5 the account is acceptable
 * if the account has 5 or more authorized people then the account is valid.
 * You cannot use the .size() function of the vector or the # number of authorized
 * people as the bank believes there has been an error when it comes to this number
 * and needs verification.
 * HINT: Use any loop and verify if a string is empty or not
*/
int EnterpriseAccount::verifyAccount() {

    int people = 0;
    for(string accName : authorizedPeople){
        if(accName.empty() == false){
            people++;
        }
        
    }

    if(people < 3){
        return -1;
    }
    else if(people >= 3 && people <= 5){
        return 0;
    }
    else{
        return 1;
    }
}

//EXERCISE #7
// TODO:find & return the account number with the highest interest rate
// USE A FOR LOOP
int highestInterestRate(vector<SavingsAccount> v) {

    double highest = -1;
    int accNum = 0;
    for(int i = 0; i < v.size(); i++){

        if(v[i].getInterestRate() > highest){
            highest = v[i].getInterestRate();
            accNum = v[i].getAccNo();
        }
        
    }
    
    return accNum;
}


//EXERCISE #8
// TODO: find & return the account number with the lowest amount of transactions
// USE A WHILE LOOP
int lowestTransactions(vector<CheckingAccount> v) {

    int CheckAcc = 0;
    int lowest = v[0].getTransactionsNo();
    int lowest_acc = v[0].getAccNo();
    while(CheckAcc < v.size()){
        
        if(v[CheckAcc].getTransactionsNo() < lowest){

            lowest = v[CheckAcc].getTransactionsNo();
            lowest_acc = v[CheckAcc].getAccNo();
        }
        CheckAcc++;
    }
    return lowest_acc;
}

//EXERCISE #9
// TODO: find & return the account with the acc number passed on as parameter.
/* If not found return a new account with that accNo, a balance of 0 and an interest rate of 0%
 * HINT: Remember there are different constructors, choose the ones provided
*/
const CheckingAccount getCheckingAccount(vector<CheckingAccount> v, int accNo) {
    
    
    CheckingAccount cuenta = CheckingAccount(accNo, 0.0);
    
    for(CheckingAccount acc : v){
        if(acc.getAccNo() == accNo){
            cuenta = acc;
        }
    }

    return cuenta;

}
const SavingsAccount getSavingAccount(vector<SavingsAccount> v, int accNo) {

    SavingsAccount cuenta = SavingsAccount(accNo, 0.0, 0.0);
    
    for(SavingsAccount acc : v){
        if(acc.getAccNo() == accNo){
            cuenta = acc;
        }
    }

    return cuenta;
}


//EXERCISE #10
//TODO: return the amount of accounts that are on the bank based on the account type passed as parameter
int Bank::getNoOfAccounts(AccountType type) {

    int num_of_acc = 0;
    for(Account acc : accounts){
        if(type == acc.getType()){
            num_of_acc++;
        }
    }
    return num_of_acc;
}


//----------------------TEST CASES-----------------------

EnterpriseAccount ea1(120, 897544);
EnterpriseAccount ea2(123, 632593);
EnterpriseAccount ea3(124, 5896314);

SavingsAccount sa1(121, 545, 0.08);
SavingsAccount sa2(125, 1456, 0.10);
SavingsAccount sa3(126, 789, 0.98);
SavingsAccount sa4(127, 159, 0.06);
SavingsAccount sa5(128, 545, 0.73);

CheckingAccount ca1(122, 6785);
CheckingAccount ca2(129, 693);
CheckingAccount ca3(130, 4587);
CheckingAccount ca4(131, 9632);
CheckingAccount ca5(132, 7896);

void testWithdraw_Deposit() {

    cout << "---------BEFORE DEPOSIT & WITHDRAW----------" << endl;
    cout << ea1.toString() << endl;
    cout << sa1.toString() << endl;
    cout << ca1.toString() << endl;

    ca1.withdraw(234);
    sa1.withdraw(600);
    ea1.withdraw(98760);
    ca1.deposit(5435);
    sa1.deposit(642035);
    ea1.deposit(112444345);

    cout << "---------AFTER DEPOSIT & WITHDRAW----------" << endl;
    cout << ea1.toString() << endl;
    cout << sa1.toString() << endl;
    cout << ca1.toString() << endl;
}

void testActiveCards(){
    vector<CheckingAccount> v;
    v.push_back(ca1);
    v.push_back(ca2);
    v.push_back(ca3);
    cout << "---------VERIFYING ACTIVE CARDS----------" << endl;
    cout << checkActiveCards(v) << endl;
}

void testConstructorOfCheckingAcc(){
    CheckingAccount ca(122,6785, 56);

    cout << "------TESTING CHECKING_ACC CONSTRUCTOR WITH PARAMETERS------" << endl;
    cout << ca.getTransactionsNo() << endl;
}

void testConstructorOfSavingsAcc(){
    SavingsAccount sa(121, 545);

    cout << "------TESTING DEFAULT SAVINGS_ACC CONSTRUCTOR------" << endl;
    cout << sa.getInterestRate() << endl;
}

void testNewBalance(){
    cout << "---TESTING INTEREST GAINED ON A SAVINGS ACCOUNT AFTER A YEAR---" << endl;
    cout << sa1.getNewBalanceWithInterestGained() << endl;
}

void testAdd_RemovePeople() {
    cout << "---------BEFORE ADDING AND REMOVING----------" << endl;
    cout << ea1.toString() << endl;

    ea1.addPeople("Naomi");
    ea1.addPeople("Bob");
    ea1.addPeople("Sam");
    ea1.addPeople("Ted");
    ea1.addPeople("Addison");
    ea1.removePeople("Bob");
    ea1.removePeople("Ted");
    ea1.removePeople("Naomi");

    cout << "---------AFTER ADDING AND REMOVING----------" << endl;
    cout << ea1.toString() << endl;
}

void testVerifyAccount() {
    vector<string> v;
    v.push_back(""); v.push_back("Jamie");
    v.push_back("Flora"); v.push_back("Miles");
    EnterpriseAccount ea(123, 632593, v);

    cout << "---------VERIFYING ENTERPRISE ACCOUNTS----------" << endl;
    cout << ea.verifyAccount() << endl;
}

void testHighestInterestRate() {
    vector<SavingsAccount> savingsVector;
    savingsVector.push_back(sa1);
    savingsVector.push_back(sa2);
    savingsVector.push_back(sa3);
    savingsVector.push_back(sa4);
    savingsVector.push_back(sa5);
    cout << "---------VERIFYING HIGHEST INTEREST RATE----------" << endl;
    cout << "Account number with the highest interest rate: " << highestInterestRate(savingsVector) << endl;
}

void testLowestTransaction() {
    vector<CheckingAccount> checkingVector;
    ca2.setTransactionsNo(25);
    ca3.setTransactionsNo(3);
    ca4.setTransactionsNo(5);
    ca5.setTransactionsNo(45);
    checkingVector.push_back(ca1);
    checkingVector.push_back(ca2);
    checkingVector.push_back(ca3);
    checkingVector.push_back(ca4);
    checkingVector.push_back(ca5);
    cout << "---------VERIFYING LOWEST TRANSACTION NUMBER----------" << endl;
    cout << "Account number for lowest transaction number: " << lowestTransactions(checkingVector) << endl;
}

void testGetCheckingAccount() {
    vector<CheckingAccount> checkingVector;
    checkingVector.push_back(ca1);
    checkingVector.push_back(ca2);
    checkingVector.push_back(ca3);
    checkingVector.push_back(ca4);
    checkingVector.push_back(ca5);
    cout << "---------VERIFYING GET CHECKING ACCOUNT FROM ACCOUNT NUMBER----------" << endl;
    CheckingAccount testing1 = getCheckingAccount(checkingVector, 125);
    cout << testing1.toString() << endl;
    CheckingAccount testing2 = getCheckingAccount(checkingVector, 130);
    cout << testing2.toString() << endl;
}

void testGetSavingsAccount() {
    vector<SavingsAccount> savingsVector;
    savingsVector.push_back(sa1);
    savingsVector.push_back(sa2);
    savingsVector.push_back(sa3);
    savingsVector.push_back(sa4);
    savingsVector.push_back(sa5);
    cout << "---------VERIFYING GET SAVINGS ACCOUNT FROM ACCOUNT NUMBER----------" << endl;
    SavingsAccount testing1 = getSavingAccount(savingsVector, 125);
    cout << testing1.toString() << endl;
    SavingsAccount testing2 = getSavingAccount(savingsVector, 130);
    cout << testing2.toString() << endl;
}

void testGetNoOfAccounts() {
    vector<Account> accounts;
    accounts.push_back(ea1);
    accounts.push_back(sa1);
    accounts.push_back(ca1);
    accounts.push_back(sa2);
    accounts.push_back(ca3);
    accounts.push_back(ea2);
    accounts.push_back(ea3);
    cout << "---------VERIFYING GET NUMBER OF ACCOUNTS WITH A TYPE----------" << endl;
    Bank testingBank("Testing Banks", accounts);
    cout << testingBank.getNoOfAccounts(CHECKING) << endl;
    cout << testingBank.getNoOfAccounts(SAVINGS) << endl;
    cout << testingBank.getNoOfAccounts(ENTERPRISE) << endl;
}


int main() {
    testWithdraw_Deposit();
    testConstructorOfCheckingAcc();
    testConstructorOfSavingsAcc();
    testActiveCards();
    testNewBalance();
    testAdd_RemovePeople();
    testVerifyAccount();
    testHighestInterestRate();
    testLowestTransaction();
    testGetCheckingAccount();
    testGetSavingsAccount();
    testGetNoOfAccounts();
}