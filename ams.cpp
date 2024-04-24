#include <iostream>
#include <cstdlib>
#include <vector>
#include <cstring>
using namespace std;

class Passenger
{
    protected:
        string id;
        string password;
        string p_name;
        int age;
        string flight_name;
        string from;
        string to;
        string classes;
        int rating;

    public:
        Passenger(){}

        Passenger(string a,string b,string c, int d, string e, string f, string g, string h)
        {
            id = a;
            password = b;
            p_name = c;
            age = d;
            flight_name = e;
            from = f;
            to = g;
            classes = h;
        }

        Passenger(Passenger &obj)
        {
            id = obj.id;
            password = obj.password;
            p_name = obj.p_name;
            age = obj.age;
            flight_name = obj.flight_name;
            from = obj.from;
            to = obj.to;
            classes = obj.classes;
        }

        void display_all_passenger_of_flight(vector <Passenger> obj,string p_name,string to,string from)
        {
            if(obj.size()==0)
                cout<<"No passengers found\n";
            else
            {    
                for(int i = 0;i<obj.size();i++)
                {
                    if((p_name == obj[i].flight_name) && (to == obj[i].to) && (from == obj[i].from))
                    {    
                        cout<<"--------------Passenger : "<<i+1<<"--------------"<<endl;
                        cout<<"Name : "<<obj[i].p_name<<endl;
                        cout<<"Age : "<<obj[i].age<<endl;
                        cout<<"Flight p_name : "<<obj[i].flight_name<<endl;
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
        }

        void display_all_passenger(vector <Passenger> obj)
        {
            if(obj.size()==0)
                cout<<"No passenger found\n";
            else
            {    
                for(int i = 0;i<obj.size();i++)
                {
                    cout<<"--------------Passenger : "<<i+1<<"--------------"<<endl;
                    cout<<"Name : "<<obj[i].p_name<<endl;
                    cout<<"Age : "<<obj[i].age<<endl;
                    cout<<"Flight p_name : "<<obj[i].flight_name<<endl;
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

        void display()
        {
            cout<<"Name : "<<p_name<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<"PNR no. : "<<flight_name<<endl;
            cout<<"The passenger has chosen a flight from "<<from<<" to "<<to<<endl;
            cout<<"Class : "<<classes<<endl;
            cout<<"The ratings given by the passenger : ";
            for(int i=0;i<rating;i++)
                cout<<"* ";
            cout<<endl;
        }

        Passenger search_passenger(string id,vector <Passenger> obj,int flag)
        {
            //File Handling : Take data from file
            if(obj.size()==0)
                cout<<"No passengers foun!!\n";
            else
            {    
                for(int i = 0;i<obj.size();i++)
                {
                    if(obj[i].id==id)
                    {
                        
                        cout<<"Details of this passenger :\n";
                        obj[i].display();
                        return obj[i];
                    }
                }
            }
        }
        
        void rate_this_flight()
        {     
            cout<<"How many stars do you want to give to this flight?\n";
            cin>>rating;
            for(int i = 0;i<rating;i++)
                cout<<"* ";
            cout<<"\nThank you...See you soon next time :)";
            cout<<"\n";
        }
};

class bag:public Passenger
{
    int num;
    float *weight;
    public:
    bag(int c,float *d)
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

class ticket 
{
    int seat_no[26][7];/*assuming there are 7 column_cs represented by letters and 
                    26 rows represented by no.s => seat no. is like A16*/
    public:
        ticket()
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

        void seat_matrix_gen()
        {
            cout<<"--------- SEAT MATRIX ---------\n";
            cout<<"    A  B  C\tD  E  F  G";
            for(int i = 0;i<26;i++)
            {   
                cout<<i<<"  ";
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
        void updateSeatMatrix_file()
        {
            //File handling : to updated seat details in file
        }
        void book_ticket()
        {
            
            this->seat_matrix_gen();
            cout<<"How many seats do you want ? ";
            int n;
            cin>>n;
            for(int i = 0;i<n;i++)
            {
                char column_char;
                int row;
                cout<<"Choose the seat no "<<i<<" you want to book : (eg: A 16)";
                cin>>column_char>>row;
                int column;
                switch(column_char)
                {
                    case 'A':
                        column = 0;
                        break;
                    case 'B':
                        column = 1;
                        break;
                    case 'C':
                        column = 2;
                        break;
                    case 'D':
                        column = 3;
                        break;
                    case 'E':
                        column = 4;
                        break;
                    case 'F':
                        column = 5;
                        break;
                    case 'G':
                        column = 6;
                        break;
                }
                if(seat_no[column][row])
                    throw 1;
                else  
                {
                    cout<<"Do you want me to confirm this seat ? (Y/N) ";
                    char opt1;
                    if(opt1 == 'Y')
                    {    
                        seat_no[column][row];  
                        cout<<"Seat successfully booked\n";
                    }
                    else if(opt1 == 'N')
                        throw opt1;
                    else    
                        throw "Invalid input\n";
                } 
            }
            system("cls");
            cout<<"Updated seat matrix :\n";
            this->seat_matrix_gen();
        }

};

struct date
{
    int day;
    string month;
    int year;    
};

struct timing
{
    int hours;
    int minutes;
    int seconds;
};

class services
{
    string food;
    string health;
    public:
        services(string x, string y)
        {
            food = x;
            health = y;
        }
};

class Flight: public Passenger,public ticket
{
    string f_name;
    string no;
    date dept_date;
    timing dept_timing;
    date arr_date;
    timing arr_timing;
    string from;
    string to;

    public:
        Flight(){}
        Flight(string a, int c, string d, int e, int f, int g, int h, int i, string j, int k, int l, int m, int n, string o, string p,string q)
         {
            no = a;
            f_name = q;
            dept_date.day = c;
            dept_date.month = d;
            dept_date.year = e;
            dept_timing.hours = f;
            dept_timing.minutes = g;
            dept_timing.seconds = h;
            arr_date.day = i;
            arr_date.month = j;
            arr_date.year = k;
            arr_timing.hours = l;
            arr_timing.minutes = m;
            arr_timing.seconds = n;
            from = o;
            to = p;
         }

        Flight(Flight &obj)
        {
            f_name = obj.f_name;
            no = obj.no;
            dept_date.day = obj.dept_date.day;
            dept_date.month = obj.dept_date.month;
            dept_date.year = obj.dept_date.year;
            dept_timing.hours = obj.dept_timing.hours;
            dept_timing.minutes = obj.dept_timing.minutes;
            dept_timing.seconds = obj.dept_timing.seconds;
            arr_date.day = obj.arr_date.day;
            arr_date.month = obj.arr_date.month;
            arr_date.year = obj.arr_date.year;
            arr_timing.hours = obj.arr_timing.hours;
            arr_timing.minutes = arr_timing.minutes;
            arr_timing.seconds = arr_timing.seconds;
            from = obj.from;
            to = obj.to;
        }
         
        void addSeatMatrix_file()
        {
            //File handling : to add new seat details in new file
        }

        float calc_avg_rating(const vector <Passenger> obj)
        {
            int sum;
            for(int i = 0;i<182;i++)
                sum = sum + rating;
            float avg = sum/182;
            return avg;
        }
        void addRating_file(const vector <Passenger> obj)
        {
            int rate = calc_avg_rating(obj);
            //File handling : update ratings to flight file
        }

        Flight &search_flight(vector<Flight> &obj,int flag)
        {
            //File Handling : Take data from file
            if(obj.size()==0)
                cout<<"No flights found!!\n";
            else
            {    
                cout<<"Enter the flight no. : ";
                string no;
                cin>>no;
                for(int i = 0;i<obj.size();i++)
                {
                    if(obj[i].no == no)
                    {
                        if(flag==1)
                            update_ArrDep(obj[i]);
                        else if(flag == 2)
                            update_travelDet(obj[i]);
                        else if(flag == 3)
                            display(obj[i]);
                        break;
                    }
                }
                return obj[0];
            }
        }

        void update_travelDet(Flight &obj)
        //flag=2
        {
            cout<<"Flight is travelling from ?? ";
            cin>>from;
            cout<<"Flight is going to ?? ";
            cin>>to;
        }

        void update_ArrDep(Flight &obj)
        //flag = 1
        {
            cout<<"Enter the new arrival date : ";
            cin>>obj.arr_date.day>>obj.arr_date.month>>obj.arr_date.year;
            cout<<"Enter the new arrival time : ";
            cin>>obj.arr_timing.hours>>obj.arr_timing.minutes>>obj.arr_timing.seconds;
            cout<<"Enter the new departure date : ";
            cin>>obj.dept_date.day>>obj.dept_date.month>>obj.dept_date.year;
            cout<<"Enter the new departure time : ";
            cin>>obj.dept_timing.hours>>obj.dept_timing.minutes>>obj.dept_timing.seconds;
            cout<<"Details successfully updated\n";
        }

        void update_details_to_file()
        {
            //File Handling
        }

        void update_arr_dep_details_to_file()
        {
            //File Handling
        }

        void add_details_of_new_flight_to_file()
        {
            //File handling
        }

        void display_all_flight(vector<Flight> obj)
        {
            for(int i = 0;i<obj.size();i++)
            {
                cout<<"------------Flight : "<<i+1<<"------------\n";
                cout<<"Name : "<<obj[i].f_name<<endl;
                cout<<"Number : "<<obj[i].no<<endl;
                cout<<"Capacity : 182"<<endl;
                cout<<"Departure Date : "<<obj[i].dept_date.day<<obj[i].dept_date.month<<obj[i].dept_date.year<<endl;
                cout<<"Departure Time : "<<obj[i].dept_timing.hours<<obj[i].dept_timing.minutes<<obj[i].dept_timing.seconds<<endl;
                cout<<"Arrival Date : "<<obj[i].arr_date.day<<obj[i].arr_date.month<<obj[i].arr_date.year<<endl;
                cout<<"Arrival Time : "<<obj[i].arr_timing.hours<<obj[i].arr_timing.minutes<<obj[i].arr_timing.seconds<<endl;
                cout<<"The flight is from "<<obj[i].from<<" to "<<obj[i].to<<endl;
            }
        }

        void display(Flight obj)
        //flag = 3
        {
            cout<<"Name : "<<obj.f_name<<endl;
            cout<<"Number : "<<obj.no<<endl;
            cout<<"Capacity : 182"<<endl;
            cout<<"Departure Date : "<<obj.dept_date.day<<obj.dept_date.month<<obj.dept_date.year<<endl;
            cout<<"Departure Time : "<<obj.dept_timing.hours<<obj.dept_timing.minutes<<obj.dept_timing.seconds<<endl;
            cout<<"Arrival Date : "<<obj.arr_date.day<<obj.arr_date.month<<obj.arr_date.year<<endl;
            cout<<"Arrival Time : "<<obj.arr_timing.hours<<obj.arr_timing.minutes<<obj.arr_timing.seconds<<endl;
            cout<<"The flight is from "<<obj.from<<" to "<<obj.to<<endl;   
        }

        void view_ticket()
        {
            cout<<f_name<<endl;
            cout<<"\t\t\tFlight : "<<no;
            cout<<"\nName : "<<p_name;
            cout<<"\tAge : "<<age;
            cout<<"\tClass : "<<classes;
            cout<<"\nDeparture Time : "<<obj.dept_timing.hours<<obj.dept_timing.minutes<<obj.dept_timing.seconds<<endl;
            cout<<"\t\tDeparture Date :"<<obj.dept_date.day<<obj.dept_date.month<<obj.dept_date.year<<endl;
        }
};

class Staff
{
    string id;
    string password;
    string p_name;
    string job;
    int salary;

    public:
        Staff(){}

        Staff(string a, string b, string c, string d, int e)
        {
            id = a;
            password = b;
            p_name = c;
            job = d;
            salary = e;
        }
        
        Staff(Staff &obj)
        {
            id = obj.id;
            password = obj.password;
            p_name = obj.p_name;
            job = obj.p_name;
            salary = obj.salary;
        }

        void display()
        {
            cout<<"Name : "<<p_name<<endl;
            cout<<"Job : "<<job<<endl;
            cout<<"Salary : "<<salary<<endl;
        }

        void search_staff(string id,vector <Staff> obj)
        {
            //File Handling : Take data from file
            if(obj.size()==0)
                cout<<"No Staff Found!!\n";
            else
            {    
                for(int i = 0;i<obj.size();i++)
                {
                    if(obj[i].id==id)
                    {
                        obj[i].display();
                    }
                }
            }
        }
};


int main()
{
    int opt1,opt2=-1,opt3,opt4;
    string id;
    Passenger pass;
    Flight fly;
    Staff st;
    vector <Passenger> p_obj;
    vector <Flight> f_obj;
    vector <Staff> s_obj;

    //screen 1
    cout<<"----------------------*******  WELCOME *******----------------------";
    cout<<"----------------------AIRPORT MANAGEMENT SYSTEM----------------------";
    cout<<"WHO ARE YOU ??\n";
    cout<<"1. STAFF\t\t2. PASSENGER\n";
    cin>>opt1;
    system("cls");

    //screen 2
    string login, password;
    
    if(opt1 == 1)
    {
        cout<<"Please enter your login id and password : \nID : ";
        cin>>login;
        cout<<"PASSWORD : ";
        cin>>password;
        st.search_staff(id,s_obj);
        //FILE HANDLING : 1. CHECK WHETHER THE PERSON EXIST 2. TO SHOW HIS/HER DETAILS ON SCREEN AFTER LOADING FROM FILE
        while(opt2!=0)
        {   
            cout<<"Which task do you wish to perform?\n";
            cout<<"1. Add details of a flight\n";
            cout<<"2. Update Travel details of a flight\n";
            cout<<"3. View all passengers\n";
            cout<<"4. To search for a passenger\n";
            cout<<"5. Update Arrival/Departure details of Flight\n";
            cout<<"6. View details of all the flights\n";
            cout<<"0. exit\n";
            cin>>opt2;
            string p_name,no,from,to;
            date a_d,d_d;
            timing a_t,d_t;
            switch (opt2)
            {
            case 1:
                cout<<"Enter the p_name of the flight : ";
                cin>>p_name;
                cout<<"Enter the no of flight : ";
                cin>>no;
                cout<<"Enter the arrival date (dd mm yyyy): ";
                cin>>a_d.day>>a_d.month>>a_d.year;
                cout<<"Enter the arrival time (hh mm ss): ";
                cin>>a_t.hours>>a_t.minutes>>a_t.seconds;
                cout<<"Enter the departure date (dd mm yyyy): ";
                cin>>d_d.day>>d_d.month>>d_d.year;
                cout<<"Enter the departure time (hh mm ss): ";
                cin>>d_t.hours>>d_t.minutes>>d_t.seconds;
                cout<<"Flight is travelling from ?? ";
                cin>>from;
                cout<<"Flight is going to ?? ";
                cin>>to;
                break;

            case 2:
                fly.search_flight(f_obj,2);
                break;

            case 3:
                cout<<"Do you want to 1.view passengers of all flights or 2.passengers of a specific flight ??";
                cin>>opt3;
                if(opt3 == 1)
                {
                    pass.display_all_passenger(p_obj);
                }
                else if(opt3 == 2)
                {
                    cout<<"Enter the p_name of the flight whose passengers you want to view:\n";
                    cout<<"1. SpiceJet : from Delhi to Dhaka\n";
                    cout<<"2. SpiceJet : from Delhi to Sydney\n";
                    cout<<"3. IndiGo : from Delhi to Kathmandu\n";
                    cout<<"4. IndiGo : from Delhi to Doha\n";
                    cout<<"5. Vistara : from Delhi to Lucknow\n";
                    cout<<"6. Vistara : from Delhi to Bombay\n";
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
                            cout<<"Invalid Input!!\n";
                    }
                }
            case 4:
                cout<<"Enter the id of passenger whom you want to find : ";
                cin>>id;
                pass.search_passenger(id,p_obj);
            
            case 5:
                fly.search_flight(f_obj,1);
            
            case 6:
                fly.display_all_flight(f_obj);
            
            default:
                cout<<"Invalid Input!!\n";
                break;
            }
            Flight obj(no,d_d.day,d_d.month,d_d.year,d_t.hours,d_t.minutes,d_t.seconds,a_d.day,a_d.month,a_d.year,a_t.hours,a_t.minutes,a_t.seconds,from,to,p_name);
            f_obj.push_back(obj);
        }
    }

    else if(opt1 == 2)
    {
        cout<<"Please enter your login id and password : \nID : ";
        cin>>login;
        cout<<"PASSWORD : ";
        cin>>password;
        pass.search_passenger(id,p_obj);
        //FILE HANDLING : 1. CHECK WHETHER THE PERSON EXIST 2. TO SHOW HIS/HER DETAILS ON SCREEN AFTER LOADING FROM FILE
    while (opt2 != 0)
        {
            cout<<"Which task do you wish to perform ??\n";

        }
        
    }
}
