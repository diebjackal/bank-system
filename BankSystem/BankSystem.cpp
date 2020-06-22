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
		cout << "����ID: " << accID << endl;
		cout << "��  ��: " << cusName << endl;
		cout << "��  ��: " << balance << endl;
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
			cout << "���� �ο��� �ʰ��Ǿ����ϴ�.\n" << endl;
			return;
		}

		cout << "[���°���]" << endl;
		cout << "����ID: ";
		cin >> accID;

		cout << "��  ��: ";
		cin >> cusnName;

		cout << "�ֹε�Ϲ�ȣ: ";
		cin >> RRN;

		cout << "�Աݾ�: ";
		cin >> balance;
		if (balance < 10) {
			cout << "���°����� 10�� �̻��� �Ա��ؾ� �մϴ�.\n" << endl;
			return;
		}

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_RRN(RRN)) {
				cout << "�̹� ���� �Ǿ����ϴ�." << endl;
				return;
			}
			if (Acc_Member[i]->Check_AccID(accID)) {
				cout << "�̹� �ִ� ����ID �Դϴ�." << endl;
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

		cout << "[��    ��]" << endl;
		cout << "����ID: ";
		cin >> Check_AccID;
		cout << "�Աݾ�: ";
		cin >> Deposit_Amount;

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_AccID(Check_AccID)) {
				Acc_Member[i]->Deposit(Deposit_Amount);
			}
			else {
				cout << "��ȿ���� ���� ID �Դϴ�." << endl;
			}
		}
		cout << endl;
	}

	void Withdraw() {
		int Withdrawal_Amount;
		int Check_AccID;

		cout << "[��    ��]" << endl;
		cout << "����ID: ";
		cin >> Check_AccID;
		cout << "��ݾ�: ";
		cin >> Withdrawal_Amount;

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_AccID(Check_AccID)) {
				if (!Acc_Member[i]->Withdraw(Withdrawal_Amount)) {
					cout << "��ݾ��� ���� �ܾ׺��� �����ϴ�." << endl;
				}
				return;
			}
		}

		cout << "��ȿ���� ���� ID �Դϴ�." << endl;
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
			<< "1. ���°���" << endl
			<< "2. ��    ��" << endl
			<< "3. ��    ��" << endl
			<< "4. �������� ��ü ���" << endl
			<< "5. ���α׷� ����" << endl;
		cout << "����: ";
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