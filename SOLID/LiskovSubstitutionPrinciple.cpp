#include <iostream>
#include<bits/stdc++.h>
using namespace std;

struct Vehicle
{
    virtual int numbeOfWheels() const = 0;
    virtual bool hasEngine() = 0;
};

struct EngineType : public Vehicle
{

    bool hasEngine()
    {
        return true;
    }
};

struct Car : public EngineType
{
   int numbeOfWheels() const override
    {
        return 4;
    }
};


struct Bike : public EngineType
{
    int numbeOfWheels() const override
    {
        return 2;
    }
};

struct Bicycle : public Vehicle
{
    int numbeOfWheels() const override
    {
        return 2;
    }
    bool hasEngine() override
    {
        return false;
    }
};




int main()
{

    Car car;
    Bike bike;
    Bicycle bicycle;
    cout << "Car has engine: " << car.hasEngine() << endl;
    cout << "Bike has engine: " << bike.hasEngine() << endl;
    cout << "Bicycle has engine: " << bicycle.hasEngine() << endl;
    cout << "Car has wheels: " << car.numbeOfWheels() << endl;
    cout << "Bike has wheels: " << bike.numbeOfWheels() << endl;
    cout << "Bicycle has wheels: " << bicycle.numbeOfWheels()<<endl;

}
