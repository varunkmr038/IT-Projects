#include<iostream>
#include<string.h>
#include<fstream>
#include<iomanip>
#include <time.h>
#include <conio.h>
#include <windows.h>

using namespace std;


void MainMenu();
void UserMenu();
void AdminMenu();
void Welcome();

fstream buses,ticket;
class Admin;

class Bus{
protected :

int busID, max_seats,fare,booked;
char DeptSt[200],Time[50];
string seat[8][4];

public: 

friend class Admin;
friend class Ticket;
   Bus()
    {
        busID = 0;
        booked = 0;
        fare = 0;
        strcpy(Time, "9:10AM");
        strcpy(DeptSt, "");
    }

void showBus();
  void showTicket(int i);
    

  int getBusId()
    {
        return busID;
    }

    char* getDeptSt()
    {
        return DeptSt;
    }

    void book(int s)
    {
        booked+=s;
    }

    char* getArrTime()
    {
        return Time;
    }

    int getBooked()
    {
        return booked;
    }

    int getMax()
    {
        return max_seats;
    }

    int getFare()
    {
        return fare;
    }

   
    void setMaxSeats(int m){
      max_seats=m;
    }
    
}b;


void Bus::showBus()
{

    cout<<"\t\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t\tBus No:-> " << busID;
    cout<<"\n\t\t\t\t\tDestination:-> " << DeptSt;
    cout<<"\n\t\t\t\t\tTime:-> " << Time;
    cout<<"\n\t\t\t\t\tSeats Remaining:-> " << max_seats - booked;
    cout<<"\n\t\t\t\t\tFare:-> " << fare;
    cout<<"\n\t\t\t\t\t-------------------------------------------------\n";

    cout <<"\n\n";
}
void Bus::showTicket(int i)
{     
    cout<<"\n\t\t\t\t\t\t\t\t\t\tBus No:-> " << busID;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tDestination:-> " << DeptSt;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tTime:-> " << Time;
    if(i==1)
    cout<<"\n\t\t\t\t\t\t\t\t\t\tFare:-> " << fare;
    cout<<"\n\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";

    cout <<"\n\n";
}



void vline(char ch)
{ for (int i=80;i>0;i--)
  cout<<ch;
}





class Admin
{
    
  public:
    void AdminLogin();
    void AddBus();
    void ViewBus();
    void friend cancelTicket();
    void friend modifyTickets();
    void deleteBus();
    void viewBookings();
    void Bus_bookings();

  } ad;

class Ticket
{
private:
    char name[50];
     int ticket_no;
     int seats;
     int fare;
    Bus b;
public:
    void generateTicket(char cname[], Bus bu,int s)
    {
        strcpy(name,cname);
        b=bu;
        seats=s;
    }

    void displayTicket()
    {
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout <<"\t\t\t\t\t\t\t\t\t\tName: " << name;
        cout <<"\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tTicket No: " << ticket_no;
        cout <<"\t\t\t\tSeats: " << seats;
        cout <<"\t\t\t\tFare: " << fare;
        b.showTicket(2);

    }

    char* getName()
    {
        return name;
    }

     int getTicketNo()
    {
        return ticket_no;
    }
void setTicketNo()
    {   srand(time(NULL));
        ticket_no=rand()%1000;
    }
    
    void change_name(char* na){
  strcpy(name,na );
    }
     
     void change_seats(int s){
       seats=s; 
     }
    int get_seats(){
        return seats;
    }

    void set_fare(){
        fare=b.fare*seats;
    }
    int getBusId(){
        return b.busID;
    }

    void show_bus(){
       b.showBus(); 
    }
}t;

void Admin::viewBookings()
{

    system("cls");

    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ################::YOUR BOOKINGS::###############\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    ticket.open("tickets.dat", ios::in | ios::app | ios::binary);
    if(ticket.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {
        ticket.read((char*)&t, sizeof(t));
        while(!ticket.eof())
        {
            t.displayTicket();
            ticket.read((char*)&t, sizeof(t));
        }

    }

    ticket.close();
}


void Admin::Bus_bookings(){

system("cls");
   
    int bid;
    int chk = 0;
   int i=0;
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Bus No:-> ";
    cin>>bid;
 system("cls");
    ticket.open("tickets.dat", ios::in | ios::out | ios::app | ios::binary);

    if(ticket.fail())
    {
        cout << "\n\\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {
        ticket.seekg(0,ios::beg);
        while(ticket.read((char*)&t, sizeof(t)))
        {
            if(t.getBusId() == bid)
            {    if(i==0){
                t.show_bus();
                i++;
            }
                 t.displayTicket();

            }
            else
            {   
                chk = 1;
            }
        }
        if(chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Not Found...!!";
        }
        
            system("pause");
        

    }

    buses.close();
    ticket.close();



}

void modifyTickets()
{
    system("cls");

    int chk = 0,ticket_no;
    char cname[50],seats;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter TicketNo:-> ";
    cin>>ticket_no;
    
    ticket.open("tickets.dat", ios::in | ios::out  | ios::binary);
    if(ticket.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {
        while(ticket.read((char*)&t, sizeof(t)))
        {
            if(t.getTicketNo()==ticket_no)
            {
                t.displayTicket();
                ticket.seekg(0,ios::cur);
                cout << "\n\n\t\t\t\t\t\t\t\t\t\tEnter New Details \n";
                cout << "\n\t\t\t\t\t\t\t\t\t\tEnter Customer Name :-> ";   
                cin.ignore();
                cin.getline(cname,50);
                t.change_name(cname);
               cout << "\n\t\t\t\t\tEnter Seats :-> ";
                cin>>seats;
                t.change_seats(seats);
                t.set_fare();
                int pos=-1*sizeof(t);
                
                ticket.seekp(pos,ios::cur);
                ticket.write((char*)&t, sizeof(t));
                cout << "\n\t\t\t\t\t\t\t\t\t\tName and seats Updated Successfully...!!";
                chk = 1; 
                break;
            }
        }
        if(chk = 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tRecord Not Found...!!";
            system("pause");
        }

    }

system("pause");
    ticket.close();

}

void Admin::deleteBus()
{
    system("cls");
   Bus B;
    int bid;
    int chk = 0;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Bus No:-> ";
    cin>>bid;

    buses.open("Buses.dat", ios::in | ios::out | ios::app | ios::binary);
    ticket.open("temp.dat", ios::out | ios::app | ios::binary);

    if(buses.fail())
    {
        cout << "\n\\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {
        buses.seekg(0,ios::beg);
        while(buses.read((char*)&b, sizeof(b)))
        {
            if(b.getBusId() != bid)
            {
                ticket.write((char*)&b, sizeof(b));

            }
            else
            {  B=b;   
                chk = 1;
            }
        }
        if(chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tBus Not Found...!!";
        }
        else
        {
            cout << "\n\t\t\t\t\t\tBus Deleted...!!\n\n";
            B.showBus();

            system("pause");
        }

    }

    buses.close();
    ticket.close();
    remove("Buses.dat");
    rename("temp.dat","Buses.dat");
}




void Admin::AddBus()
{  t:
    system("cls");
 int m;
    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ###################::ADD BUS::##################\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";
  
  try{
    
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Bus Number:-> ";
    cin >>b.busID;
     
     cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Max Seats:-> ";
    cin>>m; 
     if(b.busID <= 0 or m <= 0 or m>50) throw 1;
    b.setMaxSeats(m);
    r:
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Time:-> ";
    cin.ignore();
    cin.getline(b.Time,50);
    cout<<"\n\t\t\t\t\t\t\t\t\t\tDestination:-> ";
    cin.getline(b.DeptSt,200);
    if(strcmp(b.Time,"")==0 or strcmp(b.DeptSt,"")==0) throw 'a'; 
    cout<<"\n\t\t\t\t\t\t\t\t\t\tFare:-> ";
    cin >> b.fare;
     b.booked=0;
    if(b.fare <= 0) throw 2;
    buses.open("Buses.dat",ios::out|ios::app|ios::binary);
    buses.write((char*)&b, sizeof(b));
    buses.close();

    cout<<"\n\t\t\t\t\t\t\t\t\t\tBus Added Successfully...!!!:-> \n";
}

catch(int i){
if(i==1){
   cout<<"\n\n\t\t\t Bus Number or Max Seats is invalid ! Enter again!! "; 
   Sleep(1000);
   
   goto t;
}

if(i==2){
   cout<<"\n\n\t\t\t Fare is invalid ! Enter again!!  ";
   Sleep(1000);
   goto t;  
 }

}

catch(char c){
cout<<"\n\n\t\t\tTime or Destination is invalid!! Enter again !! ";
Sleep(1000);
goto t;
}

}



void Admin::ViewBus()
{
    system("cls");

    buses.open("Buses.dat",ios::in|ios::app|ios::binary);
    if(!buses)
        cout<<"\n\t\t\t\tFile Not Found...!!!";
    else
    {
        cout<<"\n\n";
        cout<<"\t                                                     ::BUS DETAILS::                                             \n\n";
        cout<<"\t===================================================================================================================\n";
        cout<<"\t"<<"   Bus No." << setw(22) << "Destination" << setw(16) << "Arrival" << setw(20) << "Seats" << setw(16) << "Fare" << "\n";
        cout<<"\t===================================================================================================================\n";


        while( buses.read((char*)&b, sizeof(b)))
        {
            cout << "\n\t    " << b.busID << setw(20) << b.DeptSt << setw(20) << b.Time << setw(20) << b.max_seats - b.booked 
            << setw(18) << b.fare << "\n"; 

           

        }
        buses.close();
    }
}


void Admin::AdminLogin()
{  
try{    
    string AdmnUname;
    char AdmnPass[5];
    AdmnPass[4]='\0';

    system("cls");

    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t #################::ADMIN LOGIN::################\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter AdminID:-> ";
    cin>>AdmnUname;
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Password:-> ";
    for(int i=0;i<4;i++){
     AdmnPass[i]=getch();
     cout<<"*";
    }

    if(AdmnUname == "admin" && strcmpi(AdmnPass,"pass")==0)
    {     
      cout<<"\n\n\n\n\n\t\t\t\t\t\t\t      ACCESS GRANTED";
         Sleep(3000);
        AdminMenu();
    }
    else
         throw 1;
       
}


catch(int i){
     cout<<"\n\t\t\t\t\t\t\t\t\t\tUsername or Password is wrong...!!! ";
        system("pause");
        AdminLogin();
}
      AdminMenu();
}


class Customer
{
private:

public:
    void bookTicket();
    void viewBookings();
    void friend cancelTicket();
    void friend modifyTickets();
} c;


void Customer::bookTicket()
{
    system("cls");

    char from[200],name[50];
    int chk=0,bus_no=0,seats;

    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t ###############::TICKET BOOKING::###############\n";
    cout<<"\t\t\t\t\t ================================================\n\n\n";

    cout<<"\n\t\t\t\t\tEnter Destination:-> ";
    cin.ignore();
    cin.getline(from,200);

    buses.open("Buses.dat", ios::in | ios::out  | ios::binary);
    if(buses.fail())
    {
        cout << "\n\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {

               system("cls");
                cout<<"\n\n\n\n";
                cout<<"\t\t\t\t\t ================================================\n";
                cout<<"\t\t\t\t\t ###############::AVAILABLE BUSES::##############\n";
                cout<<"\t\t\t\t\t ================================================\n\n\n";

        while(buses.read((char*)&b, sizeof(b)))
        {
            if(strcmpi(b.getDeptSt(),from) == 0)
            {
                
                b.showBus();

                chk = 1;

                   

            }
        }
        t:          
        try{
                
                 if(chk==1){ cout << "\n\t\t\t\t\tEnter Bus No :-> ";
                 cin>>bus_no;
                
                }

                if(bus_no < 0) throw 1; 
                
                buses.clear();
                buses.seekg(0,ios::beg);
               
               while(buses.read((char*)&b, sizeof(b)))
            {
              if(bus_no==b.getBusId()){
            
                 
                cout << "\n\t\t\t\t\tEnter Customer Name :-> ";
                cin.ignore();
                
                cin.getline(name,50);

                if(strcmpi(name,"")==0) throw 'a';      
                cout << "\n\t\t\t\t\tEnter Seats :-> ";
                cin>>seats;
                if(seats > 50) throw 1;
                
                b.book(seats);
                t.setTicketNo();
                t.generateTicket(name,b,seats);
                t.set_fare();
                ticket.open("tickets.dat", ios::out | ios::app | ios::binary);
                ticket.write((char*)&t, sizeof(t));
                ticket.close();
                
                int pos=-1*sizeof(b);
                buses.seekp(pos,ios::cur);
                buses.write((char*)&b, sizeof(b));
                                                                  
                cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\tTicket Booked Successfully...!!";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tYour Alloted TicketNo is [" << t.getTicketNo() << "]";
                cout << "\n\n\n\t\t\t\t\t\t\t\t\t\tPlease Remember Your TicketNo Carefully...!!";

  
                
            
        }
               
     }           


       
    }

    catch(int i){
    cout<<"\n\n\t\t\t Invalid ! Enter again ";
       goto t;
    }

    catch (char c){
      cout<<"\n\n\t\t\t Empty Name! Enter again ";
       goto t;
    }

     if(chk == 0)
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Buses Found...!!";
        cout<<"\n\n";
        system("pause");
}
    buses.close();

}

void Customer::viewBookings()
{
    system("cls");

    int ticket_no;
    int chk = 0;

    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter Ticket No:-> ";
     cin>>ticket_no;    


    system("cls");

    cout<<"\n\n\n\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ################::YOUR BOOKINGS::###############\n";
    cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";

    ticket.open("tickets.dat", ios::in | ios::app | ios::binary);
    if(ticket.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
       
    {    
       
        ticket.seekg(0,ios::beg);
        while(ticket.read((char*)&t, sizeof(t)))
        {
            if(t.getTicketNo()==ticket_no)
            {
                t.displayTicket();
                chk = 1;
            }
        }
        if(chk = 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tNo Bookings...!!";
            system("pause");
        }

    }

    ticket.close();
}

void cancelTicket()
{
    system("cls");
   Ticket T;
    int chk = 0;
int ticket_no;
    cout<<"\n\n\n\n\n\n\n";
    cout<<"\n\t\t\t\t\t\t\t\t\t\tTicket No:-> ";
   cin>>ticket_no;

    ticket.open("tickets.dat", ios::in | ios::out | ios::app | ios::binary);
    buses.open("temp.dat", ios::out | ios::app | ios::binary);

    if(ticket.fail())
    {
        cout << "\n\t\t\t\t\t\t\t\t\t\tCan't Open File...!!";
        system("pause");
    }

    else
    {
        ticket.seekg(0,ios::beg);
        while(ticket.read((char*)&t, sizeof(t)))
        {
            if(t.getTicketNo()!=ticket_no)
            {
                buses.write((char*)&t, sizeof(t));

            }
            else
            {    T=t;
                chk = 1;
            }
        }
        if(chk == 0)
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Not Found...!!";
        }
        else
        {
            cout << "\n\t\t\t\t\t\t\t\t\t\tTicket Cancelled...!!\n\n\n";
             T.displayTicket();

        }

    }

    ticket.close();
    buses.close();
    remove("tickets.dat");
    rename("temp.dat","tickets.dat");
}

int main()
{
    system("cls");
    system("COLOR F0");

    Welcome();

    return 0;
}

void Welcome()
{
    system("cls");

    cout<<"\n\n\n\n\n\n\n\n\n\n";
    cout<<"\t\t\t\t\t ================================================\n";
    cout<<"\t\t\t\t\t ||                  WELCOME TO                ||\n";
    cout<<"\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t ||            BUS RESERVATION SYSTEM          ||\n";
    cout<<"\t\t\t\t\t ||                                            ||\n";
    cout<<"\t\t\t\t\t ||                    PROJECT                 ||\n";
    cout<<"\t\t\t\t\t ================================================\n\n\n";

    cout<<"\t\t\t\t\t-------------------------------------------------\n";
    cout<<"\t\t\t\t\t\t\t Created By:-             \t\n";
    cout<<"\t\t\t\t\t\t\t                           \t\n";
    cout<<"\t\t\t\t\t\t\t  VARUN KUMAR             \t\n";
    cout<<"\t\t\t\t\t\t\t  YASHIT KUMAR        \t\n";
    cout<<"\t\t\t\t\t-------------------------------------------------\n\n";

    system("pause");
    MainMenu();
}

void MainMenu()
{
    int choice;

    while(1)
    {
        system("cls");

        cout<<"\n\n\n\n";
        cout<<"\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t #################::MAIN MENU::##################\n";
        cout<<"\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. PASSENGER \t\t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. BUS AUTHORITY \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3. EXIT \t\t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";

        cout<<"\n\t\t\t\t\tEnter your choice:-> ";

        cin>>choice;

        switch(choice)

        {

        case 1:
            UserMenu();
            break;

        case 2:
            ad.AdminLogin();
            break;

        case 3:
            system("cls");
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t          Have a nice day...!!!      \t\t\t\n\n";
            exit(0);

        default:
            cout<<"\n\n\t\t\t\t\t\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            break;

        }

    }

}

void UserMenu()
{
    int usr_choice;

    while(1)
    {
        system("cls");

        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t #################::USER PORTAL::################\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t ================================================\n\n\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t1. Book Ticket       \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t2. View Bookings     \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t3. Cancel Ticket     \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t4. Modify Ticket     \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t|\t5. BACK              \t\t\t|\n";
        cout<<"\t\t\t\t\t\t\t\t\t\t-------------------------------------------------\n";

        cout<<"\n\t\t\t\t\t\t\t\t\t\tEnter your choice:-> ";

        cin>>usr_choice;

        switch(usr_choice)

        {

        case 1:
            c.bookTicket();
            break;

        case 2:
            c.viewBookings();
            system("pause");
            break;

        case 3:
            cancelTicket();
            system("pause");
            break;

        case 4:
        modifyTickets();
            system("cls");
            MainMenu();
            break;

        case 5:
         system("cls");
            MainMenu();
            break;

        default:
            cout<<"\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            UserMenu();
            break;

        }

    }
}
void AdminMenu()
{
    int admn_choice;

    while(1)
    {
        system("cls");

        cout<<"\n\n\n";
        cout<<"\t\t\t\t\t ================================================\n";
        cout<<"\t\t\t\t\t ################::ADMIN PORTAL::################\n";
        cout<<"\t\t\t\t\t ================================================\n\n\n";

        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t1. Add Bus            \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t2. View Buses         \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t3. View Bookings      \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t4. Show Bus Booking      \t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t5. Modify Booking     \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t6. Delete Bus         \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n";
        cout<<"\t\t\t\t\t|\t7. BACK               \t\t\t|\n";
        cout<<"\t\t\t\t\t-------------------------------------------------\n\n";

        cout<<"\n\t\t\t\t\tEnter your choice:-> ";

        cin>>admn_choice;

        switch(admn_choice)

        {

        case 1:
            ad.AddBus();
            system("pause");
            break;

        case 2:
            ad.ViewBus();
            cout<<"\n\n";
            system("pause");
            break;

        case 3:
            ad.viewBookings();
            system("pause");
            break;

        case 4:
            ad.Bus_bookings();
            system("pause");
            break;

        case 5:
            modifyTickets();
            break;

        case 6:
            ad.deleteBus();
            break;

        case 7:
            system("cls");
            MainMenu();
            break;

        default:
            cout<<"\n\t\t\t\t\t  Choose valid option!!! \t\t\t\n";
            system("pause");
            break;

        }

    }
}

