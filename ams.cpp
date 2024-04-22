#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

class Passenger
{
    protected:
        string id;
        string password;
        string name;
        int age;
        string pnr_no;
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
            name = c;
            age = d;
            pnr_no = e;
            from = f;
            to = g;
            classes = h;
        }

        Passenger(Passenger &obj)
        {
            id = obj.id;
            password = obj.password;
            name = obj.name;
            age = obj.age;
            pnr_no = obj.pnr_no;
            from = obj.from;
            to = obj.to;
            classes = obj.classes;
        }

        void display_all_passenger(int n, Passenger obj[])
        {
            for(int i = 0;i<n;i++)
            {
                cout<<"--------------Passenger : "<<i+1<<"--------------"<<endl;
                cout<<"Name : "<<name<<endl;
                cout<<"Age : "<<age<<endl;
                cout<<"PNR no. : "<<pnr_no<<endl;
                cout<<"The passenger has chosen a flight from "<<from<<" to "<<to<<endl;
                cout<<"Class : "<<classes<<endl;
                cout<<"The ratings given by the passenger : ";
                for(int i=0;i<rating;i++)
                    cout<<"* ";
                cout<<endl;
            }
        }

        void display()
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Age : "<<age<<endl;
            cout<<"PNR no. : "<<pnr_no<<endl;
            cout<<"The passenger has chosen a flight from "<<from<<" to "<<to<<endl;
            cout<<"Class : "<<classes<<endl;
            cout<<"The ratings given by the passenger : ";
            for(int i=0;i<rating;i++)
                cout<<"* ";
            cout<<endl;
        }

        Passenger search_passenger(string id,int n,Passenger obj[])
        {
            //File Handling : Take data from file
            for(int i = 0;i<n;i++)
            {
                if(obj[i].id==id)
                {
                    cout<<"Details of this passenger :\n";
                    obj[i].display();
                    return obj[i];
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
                    char opt;
                    if(opt == 'Y')
                    {    
                        seat_no[column][row];  
                        cout<<"Seat successfully booked\n";
                    }
                    else if(opt == 'N')
                        throw opt;
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
    string name;
    string no;
    date dept_date;
    timing dept_timing;
    date arr_date;
    timing arr_timing;
    string from;
    string to;

    public:
        Flight(){}
        Flight(string a,int b, int c, string d, int e, int f, int g, int h, int i, string j, int k, int l, int m, int n, string o, string p,string q)
         {
            no = a;
            name = q;
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
            name = obj.name;
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

        float calc_avg_rating(const Passenger obj[])
        {
            int sum;
            for(int i = 0;i<182;i++)
                sum = sum + rating;
            float avg = sum/182;
            return avg;
        }
        void addRating_file(const Passenger obj[])
        {
            int rate = calc_avg_rating(obj);
            //File handling : update ratings to flight file
        }

        Flight search_flight(string no,int n, Flight obj[])
        {
            //File Handling : Take data from file
            for(int i = 0;i<n;i++)
            {
                if(obj[i].no == no)
                    return obj[i];
            }
            return obj[0];
        }

        void update_ArrDep(int n, Flight obj[])
        {
            cout<<"Which flight's arrival/departure details you want to edit (enter its no)? ";
            string no;
            cin>>no;
            Flight obj1;
            Flight flight = obj1.search_flight(no,n,obj);
            cout<<"Enter the new arrival date : ";
            cin>>flight.arr_date.day>>flight.arr_date.month>>flight.arr_date.year;
            cout<<"Enter the new arrival time : ";
            cin>>flight.arr_timing.hours>>flight.arr_timing.minutes>>flight.arr_timing.seconds;
            cout<<"Enter the new departure date : ";
            cin>>flight.dept_date.day>>flight.dept_date.month>>flight.dept_date.year;
            cout<<"Enter the new departure time : ";
            cin>>flight.dept_timing.hours>>flight.dept_timing.minutes>>flight.dept_timing.seconds;
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

        void display_all_flight(int n, Flight obj[])
        {
            for(int i = 0;i<n;i++)
            {
                cout<<"------------Flight : "<<i+1<<"------------\n";
                cout<<"Name : "<<obj[i].name<<endl;
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
        {
            cout<<"Name : "<<obj.name<<endl;
            cout<<"Number : "<<obj.no<<endl;
            cout<<"Capacity : 182"<<endl;
            cout<<"Departure Date : "<<obj.dept_date.day<<obj.dept_date.month<<obj.dept_date.year<<endl;
            cout<<"Departure Time : "<<obj.dept_timing.hours<<obj.dept_timing.minutes<<obj.dept_timing.seconds<<endl;
            cout<<"Arrival Date : "<<obj.arr_date.day<<obj.arr_date.month<<obj.arr_date.year<<endl;
            cout<<"Arrival Time : "<<obj.arr_timing.hours<<obj.arr_timing.minutes<<obj.arr_timing.seconds<<endl;
            cout<<"The flight is from "<<obj.from<<" to "<<obj.to<<endl;   
        }
};

class Staff
{
    string id;
    string password;
    string name;
    string job;
    int salary;

    public:
        Staff(){}

        Staff(string a, string b, string c, string d, int e)
        {
            id = a;
            password = b;
            name = c;
            job = d;
            salary = e;
        }
        
        Staff(Staff &obj)
        {
            id = obj.id;
            password = obj.password;
            name = obj.name;
            job = obj.name;
            salary = obj.salary;
        }

        void display()
        {
            cout<<"Name : "<<name<<endl;
            cout<<"Job : "<<job<<endl;
            cout<<"Salary : "<<salary<<endl;
        }

        Staff search_staff(string id,int n,Staff obj[])
        {
            //File Handling : Take data from file
            for(int i = 0;i<n;i++)
            {
                if(obj[i].id==id)
                {
                    obj[i].display();
                    return obj[i];
                }
            }
        }
};


int main()
{
    //screen 1
    cout<<"----------------------*******  WELCOME *******----------------------";
    cout<<"----------------------AIRPORT MANAGEMENT SYSTEM----------------------";
    cout<<"WHO ARE YOU ??\n";
    cout<<"1. STAFF\t\t2. PASSENGER\n";
    int opt;
    cin>>opt;
    system("cls");

    //screen 2
    if(opt == 1)
    {
        cout<<"Please enter your login id and password : \nID : ";
        string login, password;
        cin>>login;
        cout<<"PASSWORD : ";
        cin>>password;
        //FILE HANDLING : 1. CHECK WHETHER THE PERSON EXIST 2. TO SHOW HIS/HER DETAILS ON SCREEN AFTER LOADING FROM FILE
        cout<<"Which task do you wish to perform?\n";
        cout<<"1. Add details of a flight\n";
        cout<<"2. Update basic details of a flight\n";
        cout<<"3. View all passengers\n";//To view the name and seat no. of all the passengers of a flight
        cout<<"4. To search for a passenger\n";
        cout<<"5. Update Arrival/Departure details of Flight\n";
        cout<<"6. View details of all the flights\n";
    }

    else if(opt == 2)
    {

    }
}
