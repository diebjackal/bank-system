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
			cout << "��ȿ���� �ʴ� ID�Դϴ�." << endl;
			return 5;
		}
	}
}

void makeAcc() {
	int accID;
	int balance;
	int RRN;
	char cusName[NAME_LEN];

	cout << "[���°���]" << endl;
	cout << "����ID: ";
	cin >> accID;

	cout << "�̸�: ";
	cin >> cusName;

	cout << "�ֹε�� ��ȣ: ";
	cin >> RRN;

	cout << "�Աݾ�: ";
	cin >> balance;
	if (balance < 10) {
		cout << "���°����� 10�� �̻��� �Ա��ؾ� �մϴ�" << endl << endl;
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
	cout << "[��  ��]" << endl;

	cout << "����ID: ";
	cin >> accID;

	cout << "�Աݾ�: ";
	cin >> depositMoney;
	if (Member_number == 0) {
		cout << "�����ϰ� ��� ���°� �����ϴ�." << endl << endl;
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
	cout << "[��  ��]" << endl;

	cout << "����ID: ";
	cin >> accID;
	if (notAccID() == 5) {
		return;
	}

	cout << "��ݾ�:";
	cin >> withdrawalMoney;

	if (balance < withdrawalMoney) {
		cout << "��ݾ��� ���� �ܾ� ���� �����ϴ�." << endl;
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
		cout << "����ID: " << accID << endl;
		cout << "��  ��: " << cusName << endl;
		cout << "��  ��: " << balance << endl << endl;
	}
	return;
}

int mainpage() {
	while (true) {
		int select = 0;
		cout << "-----Menu-----" << endl
			<< "1. ���°���" << endl
			<< "2. ��    ��" << endl
			<< "3. ��    ��" << endl
			<< "4. �������� ��ü ���" << endl
			<< "5. ���α׷� ����" << endl;

		cout << "�� ��: ";
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
