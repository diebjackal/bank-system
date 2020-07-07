#include<iostream>
#define MAX_LEN 20
#define MAX_MEMBER 100
#define Resident_registration_num RRN
using namespace std;

class Account {
protected:
	const int accID;
	int balance;
	const long long int RRN;
	char* cusName;

public:
	Account(int accID, int balance, int RRN, char* cusName)	//������
		: accID(accID), RRN(RRN)
	{
		this->balance = balance;
		this->cusName = new char[MAX_LEN];
		strcpy_s(this->cusName, MAX_LEN, cusName);

		//�̰� �� ��������� ��������
	}

	Account(Account& copy_user)	//���� ������
		: accID(copy_user.accID), RRN(copy_user.RRN)
	{
		cout << "���� ������ ȣ��" << endl;
		this->balance = copy_user.balance;
		this->cusName = new char[MAX_LEN];
		strcpy_s(this->cusName, MAX_LEN, copy_user.cusName);
	}

	~Account()	//�Ҹ���
	{
		delete[] cusName;
	}

	void Deposit(int balance) {
		this->balance += Interest(balance);
		this->balance += balance;
	}

	virtual int Interest(int money) {
		int interest = (this->balance + money) * 0.01;	//����
		cout << "���ھ� : " << interest << endl << endl;
		return interest;
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

	virtual void Print_Account_Information() {
		cout << "���� ����" << endl;
		cout << "����ID: " << accID << endl;
		cout << "��  ��: " << cusName << endl;
		cout << "��  ��: " << balance << endl << endl;
	}

	bool Check_SSN(int RRN) const {
		return this->RRN == RRN;
	}

	int get_balance()
	{
		return balance;
	}

	const long long int get_RRN()
	{
		return RRN;
	}

	char* get_cusName()
	{
		return cusName;
	}
};

class Deposit_Account : public Account {
public:
	Deposit_Account(int accID, Account* Member) : Account(accID, 0, Member->get_RRN(), Member->get_cusName())
	{

	}

	virtual int Interest(int money) {
		int interest = (this->balance + money) * 0.02;	//����
		cout << "���ھ� : " << interest << endl << endl;
		return interest;
	}

	virtual void Print_Account_Information() {
		cout << "���� ����" << endl;
		cout << "����ID: " << accID << endl;
		cout << "��  ��: " << cusName << endl;
		cout << "��  ��: " << balance << endl << endl;
	}
};

class AccountManager {
private:
	Account* Acc_Member[MAX_MEMBER];
	int Member_Number;

public:
	AccountManager() {
		for (int i = 0; i < MAX_MEMBER; i++) {
			Acc_Member[i] = NULL;
		}

		Member_Number = 0;
	}

	~AccountManager()
	{
		for (int i = 0; i < Member_Number; i++) {
			delete Acc_Member[i];
		}
	}

	void Account_Open() {
		int account_select;
		cout << "������ ���¸� ������ �ּ���." << endl;
		cout << "1. ���� ���� " << endl;
		cout << "2. ���� ����" << endl;
		cin >> account_select;

		if (account_select == 1) {
			Ordinary_Account_Open();
		}
		else if (account_select == 2) {
			Deposit_Account_Open();
		}
		else {
			cout << "���� ���¿� ���ݰ��� �� �ϳ��� �������ּ���." << endl << endl;
		}
	}

	void Ordinary_Account_Open() {
		int accID;
		int balance;
		int RRN;
		char cusnName[MAX_LEN];

		if (Member_Number == MAX_MEMBER) {
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
			cout << "���°��� �ÿ��� 10���̻��� �Աݾ��� �־�� �մϴ�.\n" << endl << endl;
			return;
		}

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_SSN(RRN)) {
				cout << "�̹� ���� �Ǿ����ϴ�." << endl << endl;
				return;
			}
			if (Acc_Member[i]->Check_AccID(accID)) {
				cout << "�̹� �ִ� ����ID �Դϴ�." << endl << endl;
				return;
			}
		}

		Acc_Member[Member_Number] = new Account(accID, balance, RRN, cusnName);

		Member_Number++;
		cout << endl;
	}

	void Deposit_Account_Open() {
		int accID;
		int deposit_accID;
		int save_memberNumber = -1;

		cout << "���� ������ ���¹�ȣ�� �Է��� �ּ���." << endl;
		cout << "���� ���� ID : ";
		cin >> accID;

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_AccID(accID)) {
				save_memberNumber = i;
				break;
			}
		}
		if (save_memberNumber == -1)
		{
			cout << endl;
			cout << "���� ���� ���� �� ���� ���¸� ������ �� �ֽ��ϴ�." << endl;
			cout << "���� ���¸� ���� ����� �õ��Ͽ� �ֽʽÿ�." << endl << endl;
			return;
		}

		cout << "���� ���¿��� ����� ���¹�ȣ�� �Է��� �ּ���." << endl;
		cout << "���� ���� ID : ";
		cin >> deposit_accID;

		for (int i = 0; i < Member_Number; i++) {
			if (Acc_Member[i]->Check_AccID(deposit_accID)) {
				cout << "�̹� �ִ� ����ID �Դϴ�." << endl << endl;
				return;
			}
		}

		Acc_Member[Member_Number] = new Deposit_Account(deposit_accID, Acc_Member[save_memberNumber]);

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
				cout << "a" << endl;
				Acc_Member[i]->Deposit(Deposit_Amount);
				return;
			}
		}

		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
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
					cout << "��� �ݾ��� ���� �ܾ׺��� �����ϴ�." << endl << endl;
				}
				return;
			}
		}
		cout << "��ȿ���� ���� ID �Դϴ�." << endl << endl;
		cout << endl;
	}

	void Print_Account_Information() {

		for (int i = 0; i < Member_Number; i++) {
			Acc_Member[i]->Print_Account_Information();
		}
	}
};

int main(void) {
	int select;
	AccountManager account_manager;

	while (true) {
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
			account_manager.Account_Open();
			break;
		case 2:
			account_manager.Deposit();
			break;
		case 3:
			account_manager.Withdraw();
			break;
		case 4:
			account_manager.Print_Account_Information();
			break;
		case 5:
			return 0;
		default:
			break;
		}
	}
}
