#include<iostream>
using namespace std;
void func();

class Bank
{
	private:
		int id[10];
		string pass[10];
		string name[10];
		int age[10];
		string ph[10];
		int curr_balance[10];
		int amt;
		int index;
		
	public:
		Bank()
		{
			index=0;
			for(int i=0;i<10;i++)
				curr_balance[i]=0;
		}
		
		void new_user()
		{
			cout<<"\nEnter your name:"<<endl;
			cin>>name[index];
			cout<<"Enter your age:"<<endl;
			cin>>age[index];
			cout<<"Enter your phone number:"<<endl;
			cin>>ph[index];
			cout<<"Enter password:"<<endl;
			cin>>pass[index];
			cout<<"\nYour Id is      :"<<index<<endl;
			cout<<"Your password is:"<<pass[index]<<endl;
			cout<<"\n---Registration Sucessfull---\n"<<endl;
			
			id[index]=index;
			index++;
		}
		
		int login()
		{
			int ab,flag=0;
			string password;
		
			cout<<"Enter id:"<<endl;
			cin>>ab;
			cout<<"Enter password:"<<endl;
			cin>>password;
			for(int i=0;i<index;i++)
			{
				if(ab==id[i] && password==pass[i])
				{
					cout<<"\n---Login Successfull---\n"<<endl;
					flag=1;
					return ab;
				}
			}
			if(flag!=1)
				cout<<"---Invalid user! Register now!!---"<<endl;
			return -1;
		}
		
		void withdraw(int para)
		{
			cout<<"Enter amount to withdraw:"<<endl;
			cin>>amt;
			if(amt<=curr_balance[para])
			{
				curr_balance[para]=curr_balance[para]-amt;
				cout<<"Current balance:"<<curr_balance[para]<<endl;
			}
			else
				cout<<"Insufficient balance"<<endl;
		}
		
		void deposit(int para)
		{
			cout<<"Enter amount to deposit:"<<endl;
			cin>>amt;
			curr_balance[para]=curr_balance[para]+amt;
		}
		
		void balance(int para)
		{
			cout<<"Balance:"<<curr_balance[para]<<endl;
		}
				
		void display()
		{
			cout<<"\nID\tName\t\tAge\tPhone\t\t\tBalance\n";
			cout<<"--------------------------------------------------------------------\n";	
			for(int i=0;i<index;i++)
			{
				cout<<id[i]<<"\t"<<name[i]<<"\t\t"<<age[i]<<"\t"<<ph[i]<<"\t\t"<<curr_balance[i]<<"\n";
			}
		}
};

void perform(Bank &b,int user_id)
{
	int cont=1,choose;	
	
	while(cont)
	{
		cout<<"Enter your choice:"<<endl;
		cout<<"     1-Withdraw\n";
		cout<<"     2-Deposit\n";
		cout<<"     3-Check balance\n";
		cout<<"     4-Details\n";
		cout<<"Enter your choice:"<<endl;
		cin>>choose;
		switch(choose)
		{
			case 1:
				b.withdraw(user_id);
				break;
			case 2:
				b.deposit(user_id);
				break;
			case 3:
				b.balance(user_id);
				break;
			case 4:
				b.display();
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
		cout<<"\nDo you want to continue(1/0)"<<endl;
		cin>>cont;
	}
}

int main()
{
	Bank b;
	cout<<"---Bank Management System---\n\n";
	int can=1;
	
	while(can)
	{
		int ch;
		cout<<"Enter your choice:"<<endl;
		cout<<"     1-Login\n";
		cout<<"     2-New user\n";
		cin>>ch;
		
		int user_id=-1;
		switch(ch)
		{
			case 1:
				user_id=b.login();
				if(user_id!=-1)
					perform(b,user_id);
				break;
			case 2:
				b.new_user();
				user_id=b.login();
				if(user_id!=-1)
					perform(b,user_id);
				break;
			default:
				cout<<"Invalid choice"<<endl;
		}
		cout<<"\nDo you want to continue(1/0)"<<endl;
		cin>>can;
	}	
}