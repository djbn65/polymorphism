/**
main
====

Solve the main input and output here.
Within the main loop of your program, you must use the same polymorphic pointer to an Operating_system to manage multiple objects of type Cluster and Personal_surveillance_device.
Do not reference the objects directly.
Note: only a small fraction of your cpp implementations are tested in main.
**/

#include "managing_hierarchies.h"

int main()
{
  bool keepGoing = true, numberSet = false;
  int verNum;
  long IMEI;
  string deviceToManage, number, encrypt;
  Operating_system *operptr;

  while (keepGoing)
  {
    cout << endl << "What devices do you need to manage (choose one or enter 0 to exit): phone, cluster";
    cin >> deviceToManage;

    if (deviceToManage == "0")
    {
      cout << endl << "Exiting now" << endl;
      return 0;
    }
    else if (deviceToManage == "phone")
    {
      cout << endl << "What is your IMEI?";
      cin >> IMEI;
      Personal_surveillance_device phone(IMEI);
      operptr = &phone;
      cout << endl;
      dynamic_cast<Personal_surveillance_device*>(operptr)->get_func_purpose();
      cout << endl << "What is the version number of your operating system?";
      cin >> verNum;
      operptr->set_version_number(verNum);
      cout << endl << "Your OS version number is: ";
      operptr->get_version_number();
      cout << endl << "What is your phone number?";
      cin.ignore();
      do {
        getline(cin, number);
        try
        {
          dynamic_cast<Personal_surveillance_device*>(operptr)->set_phone_number(number);
          numberSet = true;
        }
        catch (MyException &e)
        {
          cout << endl << "That was not a valid phone number, please try again." << endl;
        }
      } while(!numberSet);

      cout << "Your phone number is ";
      dynamic_cast<Personal_surveillance_device*>(operptr)->get_phone_number();
      cout << endl << "Would you like to encrypt your phone (type yes or no)?" << endl;
      cin >> encrypt;
      dynamic_cast<Personal_surveillance_device*>(operptr)->set_pretend_encryption();
    }
    else if (deviceToManage == "cluster")
    {
      Cluster aCluster;
      operptr = &aCluster;
      cout << endl;
      dynamic_cast<Cluster*>(operptr)->get_func_purpose();
      cout << endl << "What is the version number of your operating system?";
      cin >> verNum;
      operptr->set_version_number(verNum);
      cout << endl << "Your OS version number is: ";
      operptr->get_version_number();
      cout << endl;
    }
  }

  return 0;
}
