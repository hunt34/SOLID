//A. High-level modules should not depend on low-level modules. Both should depend on abstractions.
//B. Abstractions should not depend on details. Details should depend on abstractions.  


#include <iostream>
#include<memory>
using namespace std;


class InputDevice
{
    public:
    virtual string devicetype()=0;
};

class Keyboard : public InputDevice
{
    string devicetype()override
    {
        return "Keyboard";
    }
};

class Mouse : public InputDevice
{
    string devicetype()override
    {
        return "Mouse";
    }
};

class Computer
{
  shared_ptr<InputDevice> inputdevice;
  public:
  Computer( shared_ptr<InputDevice> device):inputdevice(device) {}

  void connect()
  {
      cout << "Connecting to " << inputdevice->devicetype() << endl;
  }
 
};



int main()
{
    shared_ptr<InputDevice> keyboard = make_shared<Keyboard>();
    shared_ptr<InputDevice> mouse = make_shared<Mouse>();

    Computer comp1(keyboard);
    comp1.connect();

    Computer comp2(mouse);
    comp2.connect();



}