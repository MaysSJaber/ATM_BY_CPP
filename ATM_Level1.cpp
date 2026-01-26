# include<iostream>
#include<string>
using namespace std;
int MaxDepositAmount = 10000;
int MaxWithdrawAmount = 5000;
enum enSuccessfulOparetains { DepositSuccessful = 1, DepositFalid=2, WithdrawSuccessful = 3, WithdrawFalidDedline=4, WithdrawHasntEnoughBalance=5};
enum enOparetars{ DepositOparetion=1, WithdrawOparetion =2, ShowBalanceOparetion =3,ExictOparetion =4};
double ReadPossiteveNumber(string Massege) {
	double Number;
	do {
		cout << Massege;
		cin >> Number;
	} while (Number < 0);
	return Number;
}
void WelcomeMassege(string Id) {
	cout << "Welcome " << Id << " to your ATM account" << endl;
}
string ReadInputId(string Massege) {
	string InputId;
	cout << Massege;
	cin.ignore();
getline(cin,InputId);
return InputId;
}
string ReadInputPassword(string Massege, string Password, int Attempts = 3) {
	string InputPassword;
	while (Attempts>0) {
		cout << Massege;
		getline(cin,InputPassword);
		if (InputPassword == Password)return InputPassword;
		else cout << "Wrong Password! You have " << Attempts << " attempts left " << endl;
		Attempts--;
	}
	return InputPassword;
}
bool CheckPassword(string Password, string InputPassword) {
	return Password == InputPassword;
}
void ShowBalance(double Balance) {
	cout << "Your Current Balance is: " << Balance << endl;
}
enSuccessfulOparetains Deposit(double& Balance) {
	double Add = ReadPossiteveNumber("Please enter the amount to deposit: ");
	if (Add > MaxDepositAmount)return enSuccessfulOparetains::DepositFalid;
 Balance += Add;
 return enSuccessfulOparetains::DepositSuccessful;
}
void ShowDepositResult(double& Balance) {
    enSuccessfulOparetains result = Deposit(Balance);
    if (result == enSuccessfulOparetains::DepositFalid) {
        cout << "The dedline to deposit is 10000 , if you need try again enter 1 !" << endl;
        return;
    }
    else {
        cout << "Deposit Successfuly!" << endl;
        ShowBalance(Balance);
        return;
    }
}
enSuccessfulOparetains Withdraw(double& Balance) {
	double  Withdraw = ReadPossiteveNumber("Please enter the amount to withdraw: ");
	if (Withdraw > MaxWithdrawAmount)return enSuccessfulOparetains::WithdrawFalidDedline;
	else if (Withdraw > Balance)return enSuccessfulOparetains::WithdrawHasntEnoughBalance;
	Balance -= Withdraw;
	return enSuccessfulOparetains::WithdrawSuccessful;
}
void ShowWithdrawResult(double& Balance) {
	enSuccessfulOparetains result = Withdraw(Balance);
	if (result == enSuccessfulOparetains::WithdrawFalidDedline) {
		cout << "The dedline to withdraw is 5000 , if you need try again enter 1 !" << endl;
		return;
	}
	else if (result == enSuccessfulOparetains::WithdrawHasntEnoughBalance) {
		cout << "You haven't enough balance to withdraw this amount , if you need try again enter 1 !" << endl;
		return;
	}
	else {
		cout << " Withdraw Successfuly!" << endl;
		ShowBalance(Balance);
		return;
	}
}

void Menue() {
	cout << "Please select an operation: " << endl;
	cout << "1. Deposit" << endl;
	cout << "2. Withdraw" << endl;
	cout << "3. ShowBalance" << endl;
	cout << "4. Exict" << endl;
}
void OparetarsSelection(double &Balance) {
	int oparetars=0;
	while(oparetars != 4) {
		Menue();
		cin >> oparetars;
		switch ((enOparetars)oparetars) {
		case enOparetars::DepositOparetion:ShowDepositResult(Balance); break;
		case enOparetars::WithdrawOparetion:
			ShowWithdrawResult(Balance); break;
		case enOparetars::ShowBalanceOparetion:ShowBalance(Balance); break;
		case enOparetars::ExictOparetion:cout << "Thank you for using our ATM service!" << endl; break;
		default:cout << "Invalid operation selected!" << endl; break;
		}
	}
}
void Login(string Password, string InputPassword, string Id, double &Balance) {
	if (CheckPassword(Password, InputPassword)) {
		system("color 2F");
		cout << "\n-----Login Succfuly-----\n";
		WelcomeMassege(Id);
		OparetarsSelection(Balance);
	}
	else {
		cout << "\n-----Login Failed!-----\n" << "Your lose all attempts pleas call support on 059943134832";
		system("color 4F");
	}
}
int main() {
	string Password = "1234";
	string Id = "0147569";
	double Balance = 5000.00;
	string InputId = ReadInputId("Please enter your Id: ");
	string InputPassword = ReadInputPassword("Please enter your Password: ", Password,3);
	Login(Password, InputPassword, Id,Balance);
	return 0;
}