#include <iostream>
#define NAME_LEN 20
#define RRN ResidentRegistrationNum
using namespace std;
class Account
{
private:
	int accID;
	int balance;
	int RRN;
	char* cusName;
public:
	Account(int accID, int balance, int RRN, char* cusName) {
		this->accID = accID;
		this->balance = balance;
		this->cusName = new char[NAME_LEN];
		strcpy_s(this->cusName, NAME_LEN, cusName);
		this->RRN = RRN;
	}
	int getaccID() {
		return this->accID;
	}
	int getbalance() {
		return this->balance;
	}

	int getRRN() {
		return this->RRN;
	}

	~Account() {
		delete[] cusName;
	}

	void deposit(int money) {
		balance += money;
	}
	void withdrawal(int money) {
		balance -= money;
	}
};

Account* Acc_Member[100];
int Member_number = 0;

int accID = 0;
int cusName = 0;
int balance = 0;
int depositMoney = 0;
int withdrawalMoney = 0;

int notAccID() {
	for (int i = 0; i < Member_number; i++) {
		if (accID != accID) {
			cout << "유효하지 않는 ID입니다." << endl;
			return 5;
		}
	}
}

void makeAcc() {
	int accID;
	int balance;
	int RRN;
	char cusName[NAME_LEN];

	cout << "[계좌개설]" << endl;
	cout << "계좌ID: ";
	cin >> accID;

	cout << "이름: ";
	cin >> cusName;

	cout << "주민등록 번호: ";
	cin >> RRN;

	cout << "입금액: ";
	cin >> balance;
	if (balance < 10) {
		cout << "계좌개설시 10원 이상을 입금해야 합니다" << endl << endl;
		return;
	}
	else {
		Member_number++;
	}
	Acc_Member[Member_number] = new Account(accID, balance, RRN, cusName);
	return;
}

void deposit() {
	int depositMoney;
	cout << "[입  금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;

	cout << "입금액: ";
	cin >> depositMoney;
	if (Member_number == 0) {
		cout << "보유하고 계신 계좌가 없습니다." << endl << endl;
		return;
	}
	if (notAccID() == 5) {
		return;
	}
	else {
		deposit();
	}
	return;
}

void withdrawal() {
	int balance = 0;
	cout << "[출  금]" << endl;

	cout << "계좌ID: ";
	cin >> accID;
	if (notAccID() == 5) {
		return;
	}

	cout << "출금액:";
	cin >> withdrawalMoney;

	if (balance < withdrawalMoney) {
		cout << "출금액이 현재 잔액 보다 많습니다." << endl;
		return;
	}
	else {
		balance -= depositMoney;
	}
	return;
}

void printfAllAcc() {
	cout << "" << endl;
	for (int i = 0; i < Member_number; i++) {
		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << cusName << endl;
		cout << "잔  액: " << balance << endl << endl;
	}
	return;
}

int mainpage() {
	while (true) {
		int select = 0;
		cout << "-----Menu-----" << endl
			<< "1. 계좌개설" << endl
			<< "2. 입    금" << endl
			<< "3. 출    금" << endl
			<< "4. 계좌정보 전체 출력" << endl
			<< "5. 프로그램 종료" << endl;

		cout << "선 택: ";
		cin >> select;
		switch (select) {
		case 1:
			makeAcc();
			break;
		case 2:
			deposit();
			break;
		case 3:
			withdrawal();
			break;
		case 4:
			printfAllAcc();
			break;
		case 5:
			return 0;
			break;
		default:
			break;
		}
	}
}

int main() {
	mainpage();
}
