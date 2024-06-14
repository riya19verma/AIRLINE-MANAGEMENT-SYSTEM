#include <iostream>
#include <cstring>
#include <cstdlib>
#include <vector>
#include <fstream>
using namespace std;

class Passenger
{
    string id;
    string password;
    string p_name;
    int age;
    string flight_no;
    string flight_name;
    string from;
    string to;
    string classes;
    int rating;
    string ticket_no;

    public: 

    static int p_count;

        void setter()
        {
            cout<<"Enter the details of Passenger :\n ";
            cout<<" Login Id : ";
            cin>>id;
            cout<<" Password : ";
            cin>>password;
            cout<<" Name : ";
            cin>>p_name;
            cout<<" Age : ";
            cin>>age;
            flight_no;
            flight_name = " ";
            from = " ";
            to = " ";
            classes = " ";
            rating = 0;
            ticket_no = " ";
        }

        Passenger* search_pass(vector <Passenger> &obj)
        {
            //Take data from the file
            string i,p;
            int flag = 0;
            cout<<"Enter the following :\n";
            cout<<"Id : ";
            cin>>i;
            cout<<"Password : ";
            cin>>p;
            for(int j = 0;j<p_count;j++)
            {
                if(obj[j].id == i && obj[j].password == p)
                { 
                    obj[j].display(); 
                    return &obj[j];
                }
                else
                {
                    flag = 1;
                }
                if(flag == 1)
                {
                    throw "Passenger not found !!\n";
                } 
            }
        }

        void choose_flight(Passenger* ptr, string n, string f, string t,string no)
        {  
            ptr->flight_name = n;
            ptr->from = f;
            ptr->to = t;
            ptr->flight_no = no;
        }

        void display_all_passenger_of_flight(vector <Passenger> obj,string p_name,string to,string from)
        {
            for(int i = 0;i<p_count;i++)
            {
                if((p_name == obj[i].flight_name) && (to == obj[i].to) && (from == obj[i].from))
                {    
                    cout<<"--------------Passenger : "<<i+1<<"--------------"<<endl;
                    cout<<"Name : "<<obj[i].p_name<<endl;
                    cout<<"Age : "<<obj[i].age<<endl;
                    cout<<"Flight name : "<<obj[i].flight_name<<endl;
                    cout<<"The passenger has chosen a flight from "<<obj[i].from;
                    cout<<" to "<<obj[i].to<<endl;
                    cout<<"Class : "<<obj[i].classes<<endl;
                    cout<<"The ratings given by the passenger : ";
                    for(int i=0;i<obj[i].rating;i++)
                        cout<<"* ";
                    cout<<endl;
                }
            }
        }

        void display_all_passenger(vector <Passenger> obj)
        {
            for(int i = 0;i<p_count;i++)
            { 
                cout<<"--------------Passenger : "<<i+1<<"--------------"<<endl;
                cout<<"Name : "<<obj[i].p_name<<endl;
                cout<<"Age : "<<obj[i].age<<endl;
                cout<<"Flight name : "<<obj[i].flight_name<<endl;
                cout<<"The passenger has chosen a flight from "<<obj[i].from;
                cout<<" to "<<obj[i].to<<endl;
                cout<<"Class : "<<obj[i].classes<<endl;
                cout<<"The ratings given by the passenger : ";
                for(int i=0;i<obj[i].rating;i++)
                    cout<<"* ";
                cout<<endl;
            }
        }

    void display()
        {
            cout<<"Name : "<<p_name<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<"Flight name : "<<flight_name<<endl;
            cout<<"The passenger has chosen a flight from "<<from<<" to "<<to<<endl;
            cout<<"Class : "<<classes<<endl;
            cout<<"The ratings given by the passenger : ";
            for(int i=0;i<rating;i++)
                cout<<"* ";
            cout<<endl;
        }

}; 
int Passenger :: p_count = 0;

struct date
{
    int day;
    int month;
    int year;    
};

struct timing
{
    int hours;
    int minutes;
    int seconds;
};

class baggage:public Passenger
{
    int num;
    float *weight;
    public:
    baggage(int c,float *d)
    {
        num=c;
        if(num<=0)
        {
            throw "LUGGAGE WEIGHT CAN'T BE NEGATIVE OR ZERO!!!";
        }
        weight=new float[num];
        for(int i=0;i<num;i++)
        {
         *(weight+i)=*(d+i);
          if(*(weight+i)<=0)
        {
            throw 'A';
        }
        }
    }
    void price()
    {
        float p=0, x;
        int found = 0;
        int po[num] {0};
        for(int i=0;i<num;i++)
        {
            if(*(weight+i)>15)
            {
                po[i]=i+1;
                x = *(weight+i) - 15;
                x = x * 500;
                p = p + x;
            }
        }
        for(int i=0;i<num;i++)
        {
            if(po[i] > 0)
            {
                found = 1;
                cout<<"LUGGAGE NUMBER "<<(po[i]);
                cout<<endl;
            }
        }
        if(found == 1)
        {
            int o,io;
            cout<<"ARE OVER WEIGHT ";
            cout<<endl;
            cout<<"KINDLY PAY AN EXTRA CHARGE OF RUPEES: "<<p;
            cout<<endl;
            cout<<"CHOOSE THE FOLLOWING OPTIONS: ";
            cout<<endl;
            cout<<"1. REMOVE LUGGAGE";
            cout<<"\n";
            cout<<"2. DON'T REMOVE LUGGAGE";
            cout<<"\n";
            cin>>o;
            switch(o)
            {
                case 1:
                cout<<"WHICH LUGGAGE DO YOU WANT TO REMOVE: ";
                cin>>io;
                for(int i=io-1;i<num;i++)
                {
                    weight[i] = weight[i+1];
                    po[i] = po[i + 1];
                }
                num--;
                p = 0;
                for(int i=0;i<num;i++)
                {
                    if(*(weight+i)>15)
                    {
                        po[i]=i+1;
                        x = *(weight+i) - 15;
                        x = x * 500;
                        p = p + x;
                    }
                }
                cout<<"KINDLY PAY AN EXTRA CHARGE OF RUPEES: "<<p;
                cout<<endl;
                break;
                case 2:
                    cout<<"CHARGE WILL REMAIN SAME: "<<p;
                    break;
                default:
                    cout << "WRONG CHOICE";
                    cout<<"\n";
            }
        }

    }
};

class Flight 
{
    protected:
    string f_name;
    date dept_date;
    timing dept_timing;
    date arr_date;
    timing arr_timing;
    string from;
    string to;

    public:

    int seat_no[26][7];/*assuming there are 7 column_cs represented by letters and 
                    26 rows represented by no.s => seat no. is like A16*/
    string flight_no;
    
    static int f_count;

    void setter()
    {
        cout<<"Enter the details flight :\n";
        cout<<"Flight name : ";
        cin>>f_name;
        cout<<"Flight no : ";
        cin>>flight_no;
        cout<<"Departure from : ";
        cin>>from;
        cout<<"Date of Departure (DD / MM / YY) : ";
        cin>>dept_date.day;
        if(dept_date.day > 31 || dept_date.day < 0)
            throw "Invalid day entered \n";
        cout<<" / ";
        cin>>dept_date.month;
        if(dept_date.month > 12 || dept_date.day < 0)
            throw "Invalid month entered \n";
        cout<<" / ";
        cin>>dept_date.year;
        if(dept_date.year > 30 || dept_date.day < 24)
            throw "Invalid year entered \n";
        cout<<"Time of Departure (hh : mm : ss)<24hrClock>: ";
        cin>>dept_timing.hours;
        if(dept_timing.hours > 24 || dept_timing.hours < 0)
            throw "Invalid time entered \n";
        cout<<" : ";
        cin>>dept_timing.minutes;
        if(dept_timing.minutes > 60 || dept_timing.minutes < 0)
            throw "Invalid time entered \n";
        cout<<" : ";
        cin>>dept_timing.seconds;
        if(dept_timing.seconds > 60 || dept_timing.seconds < 0)
            throw "Invalid time entered \n";
        
        cout<<"Destination : ";
        cin>>to;
        cout<<"Date of Arrival (DD / MM / YY) : ";
        cin>>arr_date.day;
        if(arr_date.day > 31 || arr_date.day < 0)
            throw "Invalid day entered \n";
        cout<<" / ";
        cin>>arr_date.month;
        if(arr_date.month > 12 || arr_date.day < 0)
            throw "Invalid month entered \n";
        cout<<" / ";
        cin>>arr_date.year;
        if(arr_date.year > 30 || arr_date.day < 24)
            throw "Invalid year entered \n";
        cout<<"Time of Departure (hh : mm : ss)<24hrClock>: ";
        cin>>arr_timing.hours;
        if(arr_timing.hours > 24 || arr_timing.hours < 0)
            throw "Invalid time entered \n";
        cout<<" : ";
        cin>>arr_timing.minutes;
        if(arr_timing.minutes > 60 || arr_timing.minutes < 0)
            throw "Invalid time entered \n";
        cout<<" : ";
        cin>>arr_timing.seconds;
        if(arr_timing.seconds > 60 || arr_timing.seconds < 0)
            throw "Invalid time entered \n";
        cout<<"Details successully added !!\n\n";
    }

    void display_all_flight(vector<Flight> obj)
    {
        for(int i = 0;i<obj.size();i++)
        {
            cout<<"------------Flight : "<<i+1<<"------------\n";
            cout<<"Name : "<<obj[i].f_name<<endl;
            cout<<"Number : "<<obj[i].flight_no<<endl;
            cout<<"Capacity : 182"<<endl;
            cout<<"Departure Date : "<<obj[i].dept_date.day<<obj[i].dept_date.month<<obj[i].dept_date.year<<endl;
            cout<<"Departure Time : "<<obj[i].dept_timing.hours<<obj[i].dept_timing.minutes<<obj[i].dept_timing.seconds<<endl;
            cout<<"Arrival Date : "<<obj[i].arr_date.day<<obj[i].arr_date.month<<obj[i].arr_date.year<<endl;
            cout<<"Arrival Time : "<<obj[i].arr_timing.hours<<obj[i].arr_timing.minutes<<obj[i].arr_timing.seconds<<endl;
            cout<<"The flight is from "<<obj[i].from<<" to "<<obj[i].to<<endl;
        }
        cout<<"\n";
    }

    void display_all_flight_options()
    {
        cout<<"1. SpiceJet : from Delhi to Dhaka\n";
        cout<<"2. SpiceJet : from Delhi to Sydney\n";
        cout<<"3. IndiGo : from Delhi to Kathmandu\n";
        cout<<"4. IndiGo : from Delhi to Doha\n";
        cout<<"5. Vistara : from Delhi to Lucknow\n";
        cout<<"6. Vistara : from Delhi to Bombay\n";
    }
    
    Flight* search_fly(vector <Flight> &obj,string no)
        {
            //Take data from the file
            int flag = 0;
            for(int j = 0;j<f_count;j++)
            {
                if(obj[j].flight_no == no)
                {  
                    return &obj[j];
                }
                else
                {
                    flag = 1;
                } 
            }
            if(flag == 1)
            {
                throw "Flight not found !!\n";
            }
        }
};
int Flight :: f_count = 0;

class ticket : public Flight,public Passenger
{
    string ticket_no = " ";
    string r;
    public:
        string seat;

        ticket(){}
        void built_ticket(int seat_no[26][7])
        {
            for(int i = 0;i<26;i++)
                for(int j = 0;j<7;j++)
                    seat_no[i][j] = 0;
        }

        ticket(ticket &obj)
        {
            for(int i = 0;i<26;i++)
                for(int j = 0;j<7;j++)
                    seat_no[i][j] = obj.seat_no[i][j];
        }
        
        void seat_matrix_gen(int seat_no[26][7])
        {
            cout<<"--------- SEAT MATRIX ---------\n";
            cout<<"    A  B  C\tD  E  F  G\n";
            for(int i = 0;i<26;i++)
            {   
                cout<<i+1<<"  ";
                for(int j = 0;j<7;j++)
                {    
                    cout<<seat_no[i][j];
                    if(j==2)
                        cout<<"\t";
                    else
                        cout<<"  ";
                }
                cout<<"\n";
            }
        }

        void book_ticket(Flight* obj)
        {  
            built_ticket(obj->seat_no);          
            seat_matrix_gen(obj->seat_no);
            cout<<"How many seats do you want ? ";
            int n;
            cin>>n;
            for(int i = 0;i<n;i++)
            {
                seat = " ";
                char row_char;
                int column;
                cout<<"Choose the seat no "<<i+1<<" you want to book : (eg: A 16)";
                cin>>row_char>>column;
                int row;
                switch(row_char)
                {
                    case 'A':
                        row = 0;
                        break;
                    case 'B':
                        row = 1;
                        break;
                    case 'C':
                        row = 2;
                        break;
                    case 'D':
                        row = 3;
                        break;
                    case 'E':
                        row = 4;
                        break;
                    case 'F':
                        row = 5;
                        break;
                    case 'G':
                        row = 6;
                        break;
                }
                if(obj->seat_no[column][row])
                {
                    cout<<"Enter another seat....this is already booked\n";
                    i--;
                }
                else  
                {
                    cout<<"Do you want me to confirm this seat ? (Y/N) ";
                    char opt1;
                    cin>>opt1;
                    if(opt1 == 'Y')
                    {    
                        obj->seat_no[column][row] = 1;  
                        r = to_string(column);
                        seat += row_char;
                        seat += r;
                        cout<<"Seat "<<seat<<" is successfully booked\n";
                        assign_ticketNo(seat,obj->flight_no);
                    }
                    else if(opt1 == 'N')
                    {
                        cout<<"Ok then enter another seat\n";
                        i--;
                    }
                    else    
                        throw "Invalid input\n";
                } 
            }
            cout<<"Updated seat matrix :\n";
            seat_matrix_gen(obj->seat_no);
        }

        void assign_ticketNo(string s, string fn)
        {
            ticket_no += s;
            ticket_no += fn;
        }

};

class Staff
{
    string s_name;
    string job;

    public:
    string id;
    string password;
    static int s_count;

    void setter()
    {
        cout<<"Enter the details of Passenger :\n ";
        cout<<" Login Id : ";
        cin>>id;
        cout<<" Password : ";
        cin>>password;
        cout<<" Name : ";
        cin>>s_name;
        cout<<" Job : ";
        cin>>job;
        s_count++;
    }

    void search_staff(vector <Staff> obj)
    {
        //Take data from the file
        string i,p;
        int flag=0;
        cout<<"Enter the following :\n";
        cout<<"Id : ";
        cin>>i;
        cout<<"Password : ";
        cin>>p;
        for(int j = 0;j<s_count;j++)
        {
            if(obj[j].id == i && obj[j].password == p)
            { 
                obj[j].display(obj[j]); 
            }
            else
            {
                flag = 1;
            } 
        }
        if(flag == 1)
        {
            throw "Staff not found !!\n";
        }
    }

    void display(Staff &st)
    {
        cout<<"Name : "<<st.s_name<<endl;
        cout<<"Job : "<<st.job<<endl;
    }
};

int Staff :: s_count = 0;

int main()
{
    try
    {    

        int opt1,opt2=-1,opt3,opt4;
        char yesno;

        //class objects
        Staff st;
        Passenger pass;
        Flight fly;
        ticket tick;

        //class vector objects
        vector <Staff> s_obj;
        vector <Passenger> p_obj;
        vector <Flight> f_obj;

        //screen 1
        cout<<"----------------------*******  WELCOME *******----------------------"<<endl;
        cout<<"----------------------AIRPORT MANAGEMENT SYSTEM----------------------"<<endl;
        cout<<"WHO ARE YOU ??\n";
        cout<<"1. STAFF\t\t2. PASSENGER\n";
        cin>>opt1;

        //screen 3
        if(opt1 == 1)
        {
            //User Authentication
            cout<<"Are you a new user ?(Y/N) ";
            cin>>yesno;
            if(yesno == 'Y')
            {
                st.setter();
                s_obj.push_back(st);
                cout<<"Now Login : \n";
            }
            else if(yesno = 'N')
            {
                cout<<"Login : \n";
            }
            else
            {
                throw "Invalid input !!\n";
            }
            st.search_staff(s_obj);

            cout<<"What task do you wish to perform??\n";
            cout<<"1. Add details of a flight\n";
            cout<<"2. View all passengers\n";
            cout<<"3. To search for a passenger\n";
            cout<<"4. Update Arrival/Departure details of Flight\n";
            cout<<"5. View details of all the flights\n";
            cout<<"6. Add deatils of staff\n";
            cout<<"0. exit\n";
            cin>>opt2;
            while(opt2 != 0)
            {    
                
                switch(opt2)
                {
                    case 1:
                        fly.setter();
                        f_obj.push_back(fly);
                        break;
                    case 2:
                        cout<<"Do you want to 1.view passengers all flights or 2.passengers of specific flight ? ";
                        cin>>opt3;
                        if(opt3 == 1)
                        {
                            pass.display_all_passenger(p_obj);
                        }
                        else if(opt3 == 2)
                        {   
                            fly.display_all_flight_options();
                            cin>>opt4;
                            switch(opt4)
                            {
                                case 1:
                                    pass.display_all_passenger_of_flight(p_obj,"SpiceJet","Delhi","Dhaka");
                                    break;
                                case 2:
                                    pass.display_all_passenger_of_flight(p_obj,"SpiceJet","Delhi","Sydney");
                                    break;
                                case 3:
                                    pass.display_all_passenger_of_flight(p_obj,"IndiGo","Delhi","Kathmandu");
                                    break;
                                case 4:
                                    pass.display_all_passenger_of_flight(p_obj,"IndiGo","Delhi","Doha");
                                    break;
                                case 5:
                                    pass.display_all_passenger_of_flight(p_obj,"Vistara","Delhi","Lucknow");
                                    break;
                                case 6:
                                    pass.display_all_passenger_of_flight(p_obj,"Vistara","Delhi","Bombay");
                                    break;
                                default:
                                    throw "Invalid Input!!\n";

                            }
                        }
                        else
                        {
                            throw "Invalid input\n";
                        }
                        break;
                    case 3:
                        pass.search_pass(p_obj);
                        break;
                    case 4:
                        break;
                    case 5 :
                        fly.display_all_flight(f_obj);
                        break;
                    case 6:
                        st.setter();
                        s_obj.push_back(st);
                        break;
                }
                cout<<"What task do you wish to perform??\n";
                cout<<"1. Add details of a flight\n";
                cout<<"2. View all passengers\n";
                cout<<"3. To search for a passenger\n";
                cout<<"4. Update Arrival/Departure details of Flight\n";
                cout<<"5. View details of all the flights\n";
                cout<<"0. exit\n";
                cin>>opt2;
            }
        }
        else if(opt1 == 2)
        {
            //User Authentication
            // cout<<"Are you a new user ?(Y/N) ";
            // cin>>yesno;
            // if(yesno == 'Y')
            // {
            //     pass.setter();
            //     p_obj.push_back(pass);
            //     cout<<"Now Login : \n";
            // }
            // else if(yesno = 'N')
            // {
            //     cout<<"Login : \n";
            // }
            // else
            // {
            //     throw "Invalid input !!\n";
            // }
            Passenger *passPtr = pass.search_pass(p_obj);
            string f_no;
            Flight* flyObj;
            while(opt2 != 0)
            {    
                cout<<"Which task do you wish to perform ??\n";
                cout<<"1. Book ticket\n";
                cout<<"2. View your ticket\n";
                cout<<"3. Avail the services\n";
                cout<<"4. Add Baggage and check price\n";
                cout<<"5. Rate the flight\n";
                cout<<"0. exit\n";
                cin>>opt2;
                switch(opt2)
                {
                    case 1:
                        fly.display_all_flight_options();
                        cin>>opt4;
                        switch(opt4)
                        {
                            case 1:
                                pass.choose_flight(passPtr,"SpiceJet","Delhi","Dhaka","SJ1");
                                f_no = "SJ1";
                                break;
                            case 2:
                                pass.choose_flight(passPtr,"SpiceJet","Delhi","Sydney","SJ2");
                                f_no = "SJ2";
                                break;
                            case 3:
                                pass.choose_flight(passPtr,"IndiGo","Delhi","Kathmandu","IG1");
                                f_no = "IG1";
                                break;
                            case 4:
                                pass.choose_flight(passPtr,"IndiGo","Delhi","Doha","IG2");
                                f_no = "IG2";
                                break;
                            case 5:
                                pass.choose_flight(passPtr,"Vistara","Delhi","Lucknow","VS1");
                                f_no = "VS1";
                                break;
                            case 6:
                                pass.choose_flight(passPtr,"Vistara","Delhi","Bombay","VS2");
                                f_no = "VS2";
                                break;
                            default:
                                throw "Invalid Input!!\n";
                        }   
                        flyObj = fly.search_fly(f_obj,f_no); 
                        tick.book_ticket(flyObj);
                        break;
                    case 2:

                        break;
                    case 3:

                        break;
                    case 4:

                        break;
                    case 5:

                        break;
                }
            }
        }
        else
        {
            throw "Invalid input!!\n";
        }
    }
    catch(const char *s)
    {
        cout<<s;
    }
}
