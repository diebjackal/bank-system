#include <iostream>
#define NAME_LEN 20
using namespace std;
typedef struct
{
	int accID;
	int balance;
	char cusName[NAME_LEN];
} Account;

int select;
int depositmoney;
Account list[100];
int Max = 0;
int b = 0;

void makeAcc(){
	int a;
	int accID;
	char cusName[NAME_LEN];
	cout<<""<<endl;
	cout << "[���°���]" <<endl;
	cout << "����ID: ";
	cin >> accID;
	list[b].accID = accID;
	b++;
	for(int i = 0; i < Max; i++){
		if(list[i].accID == accID){
			cout <<"�̹��ִ� ����ID �Դϴ�."<< endl;
			return;
		}
	}
	cout << "��  ��: ";
	cin >> list[Max].cusName;
	cout << "�Աݾ�: ";
	cin >> a;
	if(a < 10){
		cout << "���°����� 10�� �̻��� �Ա��ؾ� �մϴ�" << endl;
		return; 
	}
	else{	
		list[Max].balance += a; 
	}
	Max++;
	return;
}

void deposit(){
	int a;
	int accID;
	cout<<""<<endl;
	cout << "[��  ��]"<< endl; 
	cout << "����ID: ";
	cin >> accID;
	for(int i = 0; i < Max; i++){
		if(list[i].accID != accID){
			cout << "��ȿ���� �ʴ� ID�Դϴ�." << endl;
			return;
		}
	}	
	cout << "�Աݾ�: ";
	cin >> a;
	if(Max == 0){
		cout << "��ȿ���� �ʴ� ID�Դϴ�."<< endl;
		return;
	}
	list[Max].balance += a;
}

void withdrawal(){
	int accID;
	int a;
	cout<<""<<endl;
	cout << "����ID: ";
	cin >> accID;
	for(int i = 0; i < Max; i++){
		if(list[i].accID != accID){
			cout << "��ȿ���� �ʴ� ID�Դϴ�.";
			return;
		}
	}
		cout << "��ݾ�: ";
		cin >> a;
}

void printfAllAcc(){
	cout<<""<<endl;
	for(int i=0; i < Max; i++){
	cout << "����ID: " << list[i].accID << endl;
	cout << "��  ��: " << list[i].cusName << endl;
	cout << "��  ��: " << list[i].balance  << endl;
	}
}

int mainpage(){
while(true){
	cout << "" << endl;
	cout << "-----Menu-----" <<endl
		 << "1. ���°���"<<endl
		 << "2. ��    ��"<<endl
		 << "3. ��    ��"<<endl
		 << "4. �������� ��ü ���"<<endl
		 << "5. ���α׷� ����"<<endl;
	cout << "�� ��: ";
	cin >> select;
	switch(select){
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
int main(){
	mainpage();
}
