#include<iostream>

using namespace std;

int main()
{
    // current balance  2). deposit money  3). withdraw money 4). exit
    system("cls");
    string userName ="Aman";
    int password = 1234;
    cout<<"********** Welcome to ATM **********"<<endl;
    cout<<"Enter username:";
    cin>>userName;
    cout<<"Enter password:";
    cin>>password;
    if(password==1234)
    {
        cout<<"Welcome "<<userName<<"!"<<endl;
        cout<<"**********ATM Menu**********"<<endl;
        cout<<"1. check balance"<<endl;
        cout<<"2. deposite money"<<endl;
        cout<<"3. withdraw money"<<endl;
        cout<<"4. exit"<<endl;
        cout<<"Enter your choice:";
        int choice;
        cin>>choice;
        double blance = 5000;
        double amount;
        switch (choice)
        {
            case 1:
                cout<<"Your current balance is $" <<balance<<endl;
                break;
            case 2:
                cout<<"Enter Amount to deposit: $";
                cin>>amount;
                balance += amount;
                cout<<"$"<<amount<<" deposited successfully!"<<endl;
                cout<<"Your current balance is $"<<balance<<endl;
                break;
            case 3:
                cout<<"Enter amount to withdraw: $";
                cin>>amount;
                if(amount <= balance && amount > 0)
                {
                    balance -= amount;
                    cout<<"$" <<amount<<" withdrawn successfully!"<<endl;
                    count<<"Your current balance is $"<<balance<<endl;
                
                case 4:
                    cout<<"Thanks you for using ATM!"<<endl;
                    break;

                }
                else if (amount > balance)
                {
                    cout<<"Insufficient funds!"<<endl
                }
                else
                {
                    cout<<"Invalid withdrawal amount!"<<endl;
                    
                }
                break;
                default :
                cout<<"Invalid choice. please try again!"<<endl;
                
                
        }    


    }
}