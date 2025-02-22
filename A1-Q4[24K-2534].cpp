#include <iostream>
#include <string>
using namespace std;

const int MaxStops = 20;
const int MaxStudents = 100;

class Student 
{
private:
    string studentID;
    string name;
    double balance;
    bool isActive;

public:
    Student(string id, string n)
	{
		studentID = id;
		name = n;
		balance = 0.0;
		isActive = false;
	}
	   
    string getStudentID() const { return studentID; }
    string getName() const { return name; }
    double getBalance() const { return balance; }
    bool getIsActive() const { return isActive; }

    void setBalance(double amount) { balance = amount; }
    void setIsActive(bool active) { isActive = active; }

    void registerForTransport()
	{
        if (!isActive)
		{
            isActive = true;
            cout << name << " (ID: " << studentID << ") has registered for the transportation service." << endl;
        }
		else
		{
            cout << name << " is already registered." << endl;
        }
    }

    void payFees(double amount)
	{
        if (amount > 0)
		{
            balance += amount;
            cout << name << " has paid Rs." << amount << ". Current balance: Rs." << balance << endl;
            if (!isActive)
			{
                isActive = true;
                cout << name << "'s transportation card is now active." << endl;
            }
        }
		else
		{
            cout << "Invalid payment amount." << endl;
        }
    }

    void tapCard() const
	{
        if (isActive)
		{
            cout << name << " (ID: " << studentID << ") has tapped their card. Attendance recorded." << endl;
        } 
		else
		{
            cout << name << "'s card is inactive. Please pay fees to activate." << endl;
        }
    }
};

class Route {
private:
    string routeID;
    string stops[MaxStops];
    int stopCount;

public:
    Route(string id)
	{
		routeID = id;
		stopCount = 0;
	}
   
    void addStop(const string& stop)
	{
        if (stopCount < MaxStops)
		{
            stops[stopCount++] = stop;
            cout << "Stop '" << stop << "' added to Route " << routeID << "." << endl;
        }
		else
		{
            cout << "Cannot add more stops. Maximum limit reached." << endl;
        }
    }

    void removeStop(const string& stop)
	{
        for (int i = 0; i < stopCount; ++i) 
		{
            if (stops[i] == stop)
			{
                for (int j = i; j < stopCount - 1; ++j)
				{
                    stops[j] = stops[j + 1];
                }
                stopCount--;
                cout << "Stop '" << stop << "' removed from Route " << routeID << "." << endl;
                return;
            }
        }
        cout << "Stop '" << stop << "' not found in Route " << routeID << "." << endl;
    }

    void displayStops() const 
	{
        cout << "Stops for Route " << routeID << ":" << endl;
        for (int i = 0; i < stopCount; ++i) 
		{
            cout << "- " << stops[i] << endl;
        }
    }
};




class Bus {
private:
    string busType;
    Route* route;
    Student* students[MaxStudents];
    int studentCount;

public:
    Bus(string b)
	{
		busType = b;
		route = NULL;
		studentCount = 0;
	}
   
    void assignRoute(Route* r)
	{
        route = r;
        cout << "Route assigned to " << busType << "." << endl;
    }

    void recordAttendance(Student* s)
{
        if (studentCount < MaxStudents)
{
            students[studentCount++] = s;
            s->tapCard();
        }
else
{
            cout << "Bus " << busType << " is full. Cannot record attendance for " << s->getName() << "." << endl;
        }
    }
};

int main()
{
    Student s1("24k-2534", "Anas");
    Student s2("24k-2517", "Hasan");

    s1.registerForTransport();
    s2.registerForTransport();
   
    cout << endl;
   
    s1.payFees(36000);
    s2.payFees(39000);
   
    cout << endl;
   
    Route r1("4B");
    r1.addStop("Maskan");
    r1.addStop("Disco Bakery");
    r1.addStop("Rimjhim Halls");
   
    cout << endl;
   
    r1.displayStops();

    Bus b1("Jadoon Transport");
    b1.assignRoute(&r1);
    cout << endl;

    b1.recordAttendance(&s1);
    b1.recordAttendance(&s2);

    return 0;
}
