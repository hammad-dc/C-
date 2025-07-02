//This is a programme showcasing supermarket billing system 
//with file handling and oops

#include<iostream>
#include<fstream>
#include<sstream>
#include<windows.h>
using namespace std;

class Bill{
    private:
        string item;
        int rate , quantity;
    public:
        Bill():item(""),rate(0),quantity(0) {}
        void setItem(string item) {
            this-> item = item;
        }
        void setRate(int rate) {
            this-> rate = rate;
        }
        void setQuantity(int quantity) {
            this-> quantity = quantity;
        }

        string getItem() {
            return item;
        }
        int getRate() {
            return rate;
        }
        int getQuantity() {
            return quantity;
        }
};

void addItem(Bill b) {
    bool close = false;
    while(!close) {
        int choice;
        cout<<"\t 1.Add"<<endl;
        cout<<"\t 2.Close"<<endl;
        cout<<"\t 3.Enter choice: ";
        cin>>choice;

        if(choice == 1) {
            system("cls");
            string item;
            int rate, quantity;
            cout<<"\t Enter the name of item: ";
            cin>>item;
            b.setItem(item);
            cout<<"\t Enter the rate of item: ";
            cin>>rate;
            b.setRate(rate);
            cout<<"\t Enter the quantity of item: ";
            cin>>quantity;
            b.setQuantity(quantity);

            ofstream out("Bill.txt", ios::app);
            if(!out) {
                cout<<"\t Error!! Cannot open file"<<endl;
            }
            else{
                out<<"\t "<<b.getItem()<<" : "<<b.getRate()<<" : "<<b.getQuantity()<<endl<<endl;
            }
            out.close();
            cout<<"\t Item Added successfully"<<endl;
            Sleep(3000);
        }
        else if(choice == 2) {
            system("cls");
            close = true;
            cout<<"\t Back to main menu"<<endl;
            Sleep(3000);
        }

    }
}

void printBill () {
    system("cls");
    int count = 0;
    bool close = false;
    while(!close) {
        system("cls");
        int choice;
        cout<<"\t 1.Add Bill"<<endl;
        cout<<"\t 2.Close session"<<endl;
        cout<<"\t 3.Enter choice: ";
        cin>>choice;

        if(choice == 1) {
            string item;
            int quantity;
            cout<<"\t Enter Item:  ";
            cin>>item;
            cout<<"\t Enter Quantity: ";
            cin>>quantity;

            ifstream in("Bill.txt");
            ofstream out("Bill_Temp.txt");

            string line;
            bool found = false;
            while(getline(in,line)) {
                stringstream ss;
                ss<<line;
                string itemName;
                int itemRate, itemQuant;
                char delimiter1,delimiter2;
                ss>>itemName>>delimiter1>>itemRate>>delimiter2>>itemQuant;

                if(item == itemName) {
                    found = true;    
                    if(quantity <= itemQuant) {
                        int amount = itemRate * quantity;
                        cout<<"\t Item | Rate | Quantity | Amount"<<endl;
                        cout<<"\t "<<itemName<<"\t "<<itemRate<<"\t "<<quantity<<"\t "<<amount<<endl;
                        int newQuant = itemQuant - quantity;
                        itemQuant =  newQuant;
                        count += amount;

                        out<<"\t "<<itemName<<" : "<<itemRate<<" : "<<itemQuant<<endl;
                    }   
                    else {
                        cout<<"\t Sorry,"<<item<<" is out of stock!"<<endl;
                    }            
                }
                else {
                    out<<line<<endl;
                }
            }
            if(!found) {
                cout<<"\t Item Not Available!"<<endl;
            }
            out.close();
            in.close();
            remove("Bill.txt");
            rename("Bill_Temp.txt","Bill.txt");
        }
        else if(choice == 2) {
            close = true;
            cout<<"\t Counting Total Bill"<<endl;
        }
        Sleep(3000); 
    }
    system("cls");
    cout<<endl<<endl;
    cout<<"\t Total Bill --------------- : "<<count<<endl<<endl;
    cout<<"\t Thanks For Shopping!"<<endl;
    Sleep(5000);
}

int main() {
    Bill b;
    bool exit = false;
    while(!exit) {
        system("cls");
        int val;

        cout<<"\t Welcome to The Billing system"<<endl;
        cout<<"\t *****************************"<<endl;
        cout<<"\t\t 1.Add Item"<<endl;
        cout<<"\t\t 2.Print Bill"<<endl;
        cout<<"\t\t 3.Exit"<<endl;
        cout<<"\t\t Enter Choice: ";
        cin>>val;

        switch (val) {
            case 1: {
                system("cls");
                addItem(b);
                Sleep(3000);
                break;
            }
            case 2: {
                printBill();
                break;
            }
            case 3: {
                system("cls");
                exit = true;
                cout<<"\t Have a Good Day!"<<endl;
                Sleep(3000);
                break;
            }

        }
        
    }
    
}