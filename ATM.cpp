#include<iostream>
#include<string>
using namespace std;

class Account{
      private:
       // Data Members
         int accNo;
         string password;
         int bal;
      public:
         void createAccount(int a,string p, int b){
            accNo=a;
            password=p;
            bal=b;
         }

         bool login(int a, string p){
            if(accNo==a && password==p)
               return true;
            else
               return false;   
         }

         // funcion to deposit amount    
         void deposit(int amount){
           if(amount>0){
            bal+=amount;
           }else
             cout<<"Enter valid amount..."<<endl;
           cout<<"Total balance : "<<bal<<endl;
         }

         // function to withdraw amount    
         void withdraw(int amount){
            if(amount<=bal){
                 bal-=amount;
                 cout<<"Balance is : "<<bal<<endl;
            }else
             cout<<"Insufficient funds..."<<endl;
         }
     

     // function to show balance    
         void show(){
            cout<<"Your Current balance is : "<<bal<<endl;
         }
};

class ATM {
    Account accounts[5];
    public:
       ATM(){
        accounts[0].createAccount(1,"Hassi123",5000);
        accounts[1].createAccount(2,"Lassi123",5000);
        accounts[2].createAccount(3,"Kassi123",5000);
        accounts[3].createAccount(4,"Nassi123",5000);
        accounts[4].createAccount(5,"Fassi123",5000);
       }
       void start(){
        bool found=false;
        int acc;
        string pass;

        cout<<"Enter account no ; ";
        cin>>acc;
        cout<<"Enter password : ";
        cin.ignore();
        getline(cin,pass);
        
        for(int i=0;i<5;i++){
            if(accounts[i].login(acc,pass)){
                found=true;
                int choice;
                do{
                    cout<<"======ATM MENU======"<<endl;
                    cout<<"1.deposit"<<endl;
                    cout<<"2.Withdraw"<<endl;
                    cout<<"3.Check balance"<<endl;
                    cout<<"4.Exit"<<endl;
                    cout<<"Enter choice :";
                    cin>>choice;
                    int  amount;

                    switch (choice)
                    {
                    case 1:
                        cout<<"Enter amount : ";
                        cin>>amount;
                        accounts[i].deposit(amount);
                        break;
                    case 2:
                        cout<<"Enter amount : ";
                        cin>>amount;
                        accounts[i].withdraw(amount);
                        break;    
                    case 3:
                        accounts[i].show();
                        break;
                    case 4:
                        cout<<"Thank you for using ATM..."<<endl;
                        break;    
                    default:
                        cout<<"Invalid choice..."<<endl;
                        break;
                    }
                }while (choice!=4);
            }
        
        }
        if(!found){
            cout<<"Invalid password or Account number ..."<<endl;
        }
       }
};
int main(){
    // Member of ATM class
    cout<<"---------WELCOME TO THE ATM--------------"<<endl;
    ATM atm;
    atm.start();

    return 0;
}