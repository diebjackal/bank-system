#include<iostream>
#define MAX_LEN 20
#define Resident_registration_number RRN
using namespace std;

class Account {
private:
	const int accID;
	int balance;
	const int RRN;
	char* cusName;
public:
	Account(int accID, int balance, int RRN, char* cusName)
		: accID(accID), RRN(RRN)
	{
		this->balance = balance;
		this->cusName = new char[MAX_LEN];
		strcpy_s(this->cusName, MAX_LEN, cusName);
	}

	Account(Account* account)
		: accID(accID), RRN(RRN)
	{
		this->balance = balance;
		this->cusName = new char[MAX_LEN];
		strcpy_s(this->cusName, MAX_LEN, cusName);
	}

	~Account()
	{
		delete[] cusName;
	}

	void Deposit(int balance) {
		this->balance += balance;
	}

	bool Check_AccID(int accID) const {
		return this->accID == accID;
	}

	bool Withdraw(int balance) {
		if (this->balance < balance) {
			return false;
		}

		this->balance -= balance;
		return true;
	}

	void printfAllAcc() {
		cout << "계좌ID: " << accID << endl;
		cout << "이  름: " << cusName << endl;
		cout << "잔  액: " << balance << endl;
		cout << endl;
	}

	bool Check_RRN(int RRN) {
		return this->RRN == RRN;
	}
};

class AcountManager {
private:
	Account* Acc_Member[100];
	int Member_Number = 0;

public:
	void makeAcc() {
		int accID;
		int balance;
		int RRN;
		char cusnName[MAX_LEN];

		if (Member_Number == 100) {
			cout << "가입 인원이 초과되었습니다.\n" << endl;
			return;
		}

		cout << "[계좌개설]" << endl;
		cout << "계좌ID: ";
		cin >> accID;

		cout << "이  름: ";
		cin >> cusnName;

		cout << "주민등록번호: ";
		cin >> RRN;

		cout << "입금액: ";
		cin >> balance;
		if (balance < 10) {
			cout << "계좌개설시 10원 이상을 입금해야 합니다.\n" << endl;
			return;
		}

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_RRN(RRN)) {
				cout << "이미 가입 되었습니다." << endl;
				return;
			}
			if (Acc_Member[i]->Check_AccID(accID)) {
				cout << "이미 있는 계좌ID 입니다." << endl;
				return;
			}
		}

		Acc_Member[Member_Number] = new Account(accID, balance, RRN, cusnName);
		Member_Number++;
		cout << endl;
	}

	void Deposit() {
		int Deposit_Amount;
		int Check_AccID;

		cout << "[입    금]" << endl;
		cout << "계좌ID: ";
		cin >> Check_AccID;
		cout << "입금액: ";
		cin >> Deposit_Amount;

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_AccID(Check_AccID)) {
				Acc_Member[i]->Deposit(Deposit_Amount);
			}
			else {
				cout << "유효하지 않은 ID 입니다." << endl;
			}
		}
		cout << endl;
	}

	void Withdraw() {
		int Withdrawal_Amount;
		int Check_AccID;

		cout << "[출    금]" << endl;
		cout << "계좌ID: ";
		cin >> Check_AccID;
		cout << "출금액: ";
		cin >> Withdrawal_Amount;

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_AccID(Check_AccID)) {
				if (!Acc_Member[i]->Withdraw(Withdrawal_Amount)) {
					cout << "출금액이 현재 잔액보다 많습니다." << endl;
				}
				return;
			}
		}

		cout << "유효하지 않은 ID 입니다." << endl;
		cout << endl;
	}

	void printfAllAcc() {

		for (int i = 0; i < Member_Number; i++) {
			Acc_Member[i]->printfAllAcc();
		}
	}
};

int main(void) {
	int select = 0;
	AcountManager account_manager;

	while (1) {
		cout << "-----Menu-----" << endl
			<< "1. 계좌개설" << endl
			<< "2. 입    금" << endl
			<< "3. 출    금" << endl
			<< "4. 계좌정보 전체 출력" << endl
			<< "5. 프로그램 종료" << endl;
		cout << "선택: ";
		cin >> select;
		cout << endl;

		switch (select)
		{
		case 1:
			account_manager.makeAcc();
			break;
		case 2:
			account_manager.Deposit();
			break;
		case 3:
			account_manager.Withdraw();
			break;
		case 4:
			account_manager.printfAllAcc();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}