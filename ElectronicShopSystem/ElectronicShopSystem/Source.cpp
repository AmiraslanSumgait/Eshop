#include <iostream>
#include <windows.h>
#include"MenuDisplay.h"
using namespace std;

int main()
{
    ElectronicShop::guestList();
    ElectronicShop::adminsList();
    ElectronicShop::productList();
    ElectronicShop::start();
}