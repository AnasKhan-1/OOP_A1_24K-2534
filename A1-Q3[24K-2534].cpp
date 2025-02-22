#include <iostream>
#include <cstring>
#include <string>


using namespace std;



class Vehicle
{
public:
    string model;
    double rentalPrice;
    string eligibleLicense;
   
    Vehicle(const string* m, double price, const string* license)
    {
        model = *m;
        rentalPrice = price;
        eligibleLicense = *license;
    }
   
    void displayDetails()
    {
        cout << "Model: " << model << endl << "Rental Price per day: $" << rentalPrice << endl << "Eligible License: " << eligibleLicense << endl;
    }
};




class User
{
public:
    int userID;
    string name;
    int age;
    string licenseType;
    string contact;
   
    User(int id, const string* n, int a, const string* license, const string* c)
    {
        userID = id;
        name = *n;
        age = a;
        licenseType = *license;
        contact = *c;
    }
   
    void updateDetails(const string* newName, int newAge, const string* newLicense, const string* newContact)
    {
        name = *newName;
        age = newAge;
        licenseType = *newLicense;
        contact = *newContact;
    }
   
    void rentVehicle(Vehicle* v)
    {
        if (licenseType == v->eligibleLicense)
        {
            cout << "Vehicle has been rented successfully" << endl;
            v->displayDetails();
        }
        else
        {
            cout << "You are not eligible to rent this vehicle" << endl;
        }
    }
};



int main()
{
    Vehicle* vehicles[3];
    vehicles[0] = new Vehicle(new string("Toyota Corolla"), 50.0, new string("Full"));
    vehicles[1] = new Vehicle(new string("Honda Civic"), 55.0, new string("Intermediate"));
    vehicles[2] = new Vehicle(new string("Suzuki Alto"), 30.0, new string("Learner"));
   
    User u1(1211, new string("Ali"), 25, new string("Full"), new string("123-456-7890"));
    User u2(2534, new string("Anas"), 18, new string("Learner"), new string("0123-4567890"));
   
    cout << "User 1" << endl;
   
    u1.rentVehicle(vehicles[0]);
    u1.rentVehicle(vehicles[2]);
   
   
   
    cout << endl << "User 2" << endl;
   
    u2.rentVehicle(vehicles[0]);
    u2.rentVehicle(vehicles[2]);
       
       
       
   
    for (int i = 0; i < 3; i++)
    {
        delete vehicles[i];
    }
   
    return 0;
}
