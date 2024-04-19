#include <iostream>
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
};

struct date
{
    int day;
    string month;
    int year;    
};

struct time
{
    int hours;
    int minutes;
    int seconds;
};

class Flight: private Passenger
{
    int pass_len;
    Passenger *pass;
    date dept_date;
    time dept_time;
    date arr_date;
    time arr_time;
    string from;
    string to;

    public:
        Flight(){}
        Flight(int a, int b, int c, string d, int e, int f, int g, int h, int i, string j,
         int k, int l, int m, int n, string o, string p)
         {
            pass_len = a;
            pass = new Passenger[pass_len];
            dept_date.day = c;
            dept_date.month = d;
            dept_date.year = e;
            dept_time.hours = f;
            dept_time.minutes = g;
            dept_time.seconds = h;
            arr_date.day = i;
            arr_date.month = j;
            arr_date.year = k;
            arr_time.hours = l;
            arr_time.minutes = m;
            arr_time.seconds = n;
            from = o;
            to = p;
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

};


int main()
{
    cout<<"----------------------*******  WELCOME *******----------------------";
    cout<<"----------------------AIRPORT MANAGEMENT SYSTEM----------------------";
    
}