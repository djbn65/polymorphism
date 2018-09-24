/**
.cpp
====

This is the .cpp you should define and implement the functions and classes that are declared in the .h file.
Add any non-required functions here.
**/

#include "managing_hierarchies.h"


void get_identity(string my_id[])
{
  my_id[0] = "djbn65";
  my_id[1] = "12534397";
  cout << "University Username: " << my_id[0] << endl;
  cout << "Univeristy SID: " << my_id[1] << endl;
  return;
}


// This is provided as an example of scoping and defining a class function
const char* MyException::what() const throw()
{
  return "Custom Error has occurred";
}

string Machine::get_function()
{
    cout << my_function;

    return my_function;
}

X86::X86()
{
  my_function = "Backward compatible";
  num_cores = new bool[2];
}

X86::X86(string init_function, int init_cores)
{
  my_function = init_function;
  try
  {
    if (init_cores % 2 == 1)
    {
      throw MyException();
    }
    num_cores = new bool[init_cores];
  }
  catch (MyException &e)
  {
    cout << e.what() << ". num_core's size default to 2." << endl;
    num_cores = new bool[2];
  }
}

X86::~X86()
{
  delete[] num_cores;
}

void X86::set_core_pos(int position, bool value)
{
  num_cores[position] = value;

  return;
}

bool X86::get_core_pos(int index)
{
  return num_cores[index];
}

ARM::ARM()
{
  my_function = "Reduced Instruction Set";
  num_bits = 64;
}

ARM::ARM(string init_function, short init_bits)
{
  my_function = init_function;
  try
  {
    if (init_bits != 32 && init_bits != 64)
    {
      throw MyException();
    }
    num_bits = init_bits;
  }
  catch (MyException &e)
  {
    cout << e.what() << ". Object constructed, and num_bits default to 64." << endl;
  }
}

short ARM::get_num_bits()
{
  cout << num_bits;
  return num_bits;
}

void ARM::set_num_bits(short set_bits)
{
  try
  {
    if (set_bits != 32 && set_bits != 64)
    {
      throw MyException();
    }
    num_bits = set_bits;
  }
  catch (MyException &e)
  {
    cout << e.what() << ". num_bits not set. Value passed was not 32 or 64" << endl;
  }

  return;
}

string Operating_system::get_purpose()
{
  cout << purpose;
  return purpose;
}

Linux::Linux()
{
  purpose = "Anything you want";
}

Linux::Linux(string init_purpose)
{
  purpose = init_purpose;
}

string Cluster::get_func_purpose()
{
  cout << "Your cluster architecture is " << my_function << ", its purpose is " << purpose << ", and lots of it!";
  return "Your cluster architecture is " + my_function + ", its purpose is " + purpose + ", and lots of it!";
}

void Cluster::set_version_number(int set_ver_num)
{
  version_number = set_ver_num;

  return;
}

int Cluster::get_version_number()
{
  cout << version_number;

  return version_number;
}

Personal_surveillance_device::Personal_surveillance_device()
{
  my_IMEI = new long(0000);
}

Personal_surveillance_device::Personal_surveillance_device(long input_my_IEMI)
{
  my_IMEI = new long(input_my_IEMI);
}

Personal_surveillance_device::~Personal_surveillance_device()
{
  delete my_IMEI;
}

Personal_surveillance_device::Personal_surveillance_device(const Personal_surveillance_device &source)
{
  purpose = source.purpose;
  version_number = source.version_number;
  my_function = source.my_function;

  if (source.my_IMEI) //If pointer not NULLPTR
    my_IMEI = new long(*(source.my_IMEI));
  else
    my_IMEI = 0;
}

Personal_surveillance_device& Personal_surveillance_device::operator=(const Personal_surveillance_device &rhs)
{
  if (this == &rhs) //in case of self assignment
    return *this;

  delete my_IMEI; //delete reference to old value to avoid pointing to wrong value

  purpose = rhs.purpose;
  version_number = rhs.version_number;
  my_function = rhs.my_function;

  if (rhs.my_IMEI) //If pointer is not nullptr
    my_IMEI = new long(*(rhs.my_IMEI));
  else
    my_IMEI = 0;

  return *this;
}

void Personal_surveillance_device::set_phone_number(string init_phone)
{
  string format_string = "+1(573)-465-1111";
    for (int i = 0; i < 16; i++)
    {
      if (i == 0 || i == 2 || i == 6 || i == 7 || i == 11)
      {
        if (init_phone[i] != format_string[i])
        {
          throw MyException();
        }
      }
      else
      {
        if (init_phone[i] < 48 || init_phone[i] > 57)
        {
          throw MyException();
        }
      }
    }
    my_phone_number = init_phone;

  return;
}

string Personal_surveillance_device::get_phone_number()
{
  cout << my_phone_number;
  return my_phone_number;
}

void Personal_surveillance_device::set_version_number(int set_ver_num)
{
  version_number = set_ver_num;

  return;
}

int Personal_surveillance_device::get_version_number()
{
  cout << version_number;
  return version_number;
}

string Personal_surveillance_device::get_func_purpose()
{
  cout << "Your phone architecture is " << my_function << ", its purpose is " << purpose << ", and I follows you around!";
  return "Your phone architecture is " + my_function + ", its purpose is " + purpose + ", and I follows you around!";
}
