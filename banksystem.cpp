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
	cout << "[계좌개설]" <<endl;
	cout << "계좌ID: ";
	cin >> accID;
	list[b].accID = accID;
	b++;
	for(int i = 0; i < Max; i++){
		if(list[i].accID == accID){
			cout <<"이미있는 계좌ID 입니다."<< endl;
			return;
		}
	}
	cout << "이  름: ";
	cin >> list[Max].cusName;
	cout << "입금액: ";
	cin >> a;
	if(a < 10){
		cout << "계좌개설시 10원 이상을 입금해야 합니다" << endl;
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
	cout << "[입  금]"<< endl; 
	cout << "계좌ID: ";
	cin >> accID;
	for(int i = 0; i < Max; i++){
		if(list[i].accID != accID){
			cout << "유효하지 않는 ID입니다." << endl;
			return;
		}
	}	
	cout << "입금액: ";
	cin >> a;
	if(Max == 0){
		cout << "유효하지 않는 ID입니다."<< endl;
		return;
	}
	list[Max].balance += a;
}

void withdrawal(){
	int accID;
	int a;
	cout<<""<<endl;
	cout << "계좌ID: ";
	cin >> accID;
	for(int i = 0; i < Max; i++){
		if(list[i].accID != accID){
			cout << "유효하지 않는 ID입니다.";
			return;
		}
	}
		cout << "출금액: ";
		cin >> a;
}

void printfAllAcc(){
	cout<<""<<endl;
	for(int i=0; i < Max; i++){
	cout << "계좌ID: " << list[i].accID << endl;
	cout << "이  름: " << list[i].cusName << endl;
	cout << "잔  액: " << list[i].balance  << endl;
	}
}

int mainpage(){
while(true){
	cout << "" << endl;
	cout << "-----Menu-----" <<endl
		 << "1. 계좌개설"<<endl
		 << "2. 입    금"<<endl
		 << "3. 출    금"<<endl
		 << "4. 계좌정보 전체 출력"<<endl
		 << "5. 프로그램 종료"<<endl;
	cout << "선 택: ";
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
