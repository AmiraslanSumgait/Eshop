#pragma once
#include <iostream>
#include <windows.h>
#include <conio.h>
#include<string>
#include"Database.h"
#include"Notebook.h"
#include"Exceptions.h"
#include"Phone.h"
#include"NoteBookCategory.h"
#include"PhoneCategory.h"
#include"Headphone.h"
#include"HeadPhoneCategory.h"
#include <stdlib.h>
using namespace std;
void mySetColor(int fg, int bg) {
    HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(h, fg | (bg << 4));
}
int Set[] = { 7,7,7,7,7 }; // DEFAULT COLORS
void gotoxy(int x, int y)
{
    COORD c;
    c.X = x;
    c.Y = y;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}
Database db;
void AddproductPhone() {
    system("cls");
    mySetColor(6, 0);
    cout << "New Phone  name-> ";
    cin.ignore();
    string name; getline(cin, name);
    cout << "New Phone  description-> ";
    string description; getline(cin, description);
    cout << "New Phone price-> ";
    double price; cin >> price;
    cout << "New Phone tax-> ";
    double tax; cin >> tax;
    cout << "New Phone discount-> ";
    double discount; cin >> discount;
    cout << "New Phone quantity-> ";
    int quantity; cin >> quantity;
    cout << "New Phone ram size-> ";
    int ramsize; cin >> ramsize;
    cout << "New Phone battery-> ";
    int battery; cin >> battery;
    cout << "New Phone memory size-> ";
    int memorysize; cin >> memorysize;
    cout << "New Phone sim type-> ";
    cin.ignore();
    string simtype; getline(cin, simtype);
    cout << "New Phone  screen size-> ";
    string screensize; getline(cin, screensize);
    cout << "New Phone  cpu model-> ";
    string cpumodel; getline(cin, cpumodel);
    mySetColor(7, 0);
    mySetColor(5, 0);
    cout << "--------New phone created succesfully--------" << endl;
    mySetColor(7, 0);
    Sleep(1500);
    Phone* phone = new Phone(1, name, description, price, tax, discount, quantity, ramsize, simtype, screensize, cpumodel, battery, memorysize);
    db.products.add(phone);
}
void AddProductNotebook() {
    system("cls");
    mySetColor(6, 0);
    cout << "New Notebook  name-> ";
    cin.ignore();
    string name; getline(cin, name);
    cout << "New Notebook  description-> ";
    string description; getline(cin, description);
    cout << "New Notebook price-> ";
    double price; cin >> price;
    cout << "New Notebook tax-> ";
    double tax; cin >> tax;
    cout << "New Notebook discount-> ";
    double discount; cin >> discount;
    cout << "New Notebook quantity-> ";
    int quantity; cin >> quantity;
    cin.ignore();
    cout << "New Notebook cpu model-> ";
    string cpumodel; getline(cin, cpumodel);;
    cout << "New Notebook ram size-> ";
    int ramsize; cin >> ramsize;
    cout << "New Notebook screen size-> ";
    cin.ignore();
    string screensize; getline(cin, screensize);
    cout << "New Notebook screen resoulition-> ";
    string screenresouliton; getline(cin, screenresouliton);
    cout << "New Notebook ssd model-> ";
    string ssdmodel; getline(cin, ssdmodel);
    cout << "New Notebook ssd size-> ";
    int ssdsize; cin >> ssdsize;
    mySetColor(7, 0);
    mySetColor(5, 0);
    cout << "--------New notebook created succesfully--------" << endl;
    mySetColor(7, 0);
    Sleep(1500);
    NoteBook* notebook = new NoteBook(2, name, description, price, tax, discount, quantity, cpumodel, ramsize, screensize, screenresouliton, ssdmodel, ssdsize);
    db.products.add(notebook);
}
void AddProductHeadphone() {
    system("cls");
    mySetColor(6, 0);
    cout << "New Headphone  name-> ";
    cin.ignore();
    string name; getline(cin, name);
    cout << "New Headphone  description-> ";
    string description; getline(cin, description);
    cout << "New Headphone price-> ";
    double price; cin >> price;
    cout << "New Headphone tax-> ";
    double tax; cin >> tax;
    cout << "New Headphone discount-> ";
    double discount; cin >> discount;
    cout << "New Headphone quantity-> ";
    int quantity; cin >> quantity;
    cout << "New Headphone spiker driver size-> ";
    int spikerdriversize; cin >> spikerdriversize;
    cout << "New Headphone  computer platform-> ";
    cin.ignore();
    string computerplatform; getline(cin, computerplatform);
    cout << "New Headphone  surround sound -> ";
    string surroundsound; getline(cin, surroundsound);
    cout << "New Headphone  sound quality -> ";
    string soundquality; getline(cin, soundquality);
    mySetColor(7, 0);
    mySetColor(5, 0);
    cout << "--------New headphone created succesfully--------" << endl;
    mySetColor(7, 0);
    Sleep(1500);
    HeadPhone* headphone = new HeadPhone(3, name, description, price, tax, discount, quantity, computerplatform, surroundsound, spikerdriversize, soundquality);
    db.products.add(headphone);
}
void adminDisplay() {
    gotoxy(50, 8);
    cout << "Which operation do you want procced: " << endl;
    gotoxy(50, 9);
    mySetColor(Set[0], 0);
    cout << "[1]Show All products " << endl;
    gotoxy(50, 10);
    mySetColor(Set[1], 0);
    cout << "[2]Add Product" << endl;
    gotoxy(50, 11);
    mySetColor(Set[2], 0);
    cout << "[3]Delete Product" << endl;
    gotoxy(50, 12);
    mySetColor(Set[3], 0);
    cout << "[4]Update Product" << endl;
    gotoxy(50, 13);
    mySetColor(Set[4], 0);
    cout << "[5]Exit panel" << endl;
    mySetColor(7, 0);
}
namespace ElectronicShop {
   
    void productList() {
        NoteBook* notebook1 = new NoteBook(2, "Hp 16 da 2192 nia", "Economical", 1500, 50, 10, 8, "Intel(R) Core i7-10510 Cpu", 8, "8 inch", "1920x1080", "Kingston", 240);
        db.products.add(notebook1);
        NoteBook* notebook2 = new NoteBook(2, " HP EliteBook 1050 G1 notebook PC", "Powerfull", 9000, 100, 15, 4, "8th Generation hexa-core Intel Core i7 processor", 16, "15.6 inch", "3840x2160", "Sandisk", 480);
        db.products.add(notebook2);
        NoteBook* notebook3 = new NoteBook(2, "Macbook Pro", "Quality and reabilitiy", 3500, 50, 10, 5, "Core i7 2.9 Touch/Mid-2017 Specs", 16, "13 inch", "3840X2160", "OWC 1.0TB Aura PCIe ", 540);
        db.products.add(notebook3);
        Phone* phone1 = new Phone(1, "Redmi Note 8 pro", "Ideal for games", 480, 5, 5, 20, 4, "Nano sim", "6.3 inch", "Qualcomm Snapdragon 665", 4000, 128);
        db.products.add(phone1);
        Phone* phone2 = new Phone(1, "Iphone 8", "Best performance for games", 1100, 6, 10, 5, 2, "Nano-sim", "4,7 inch", "Apple A11 Bionic", 1821, 64);
        db.products.add(phone2);
        HeadPhone* headphone1 = new HeadPhone(3, "Corsair Hs 70 pro", "Comfortable HeadPhone", 200, 4, 8, 2, "Pc windows,PS4/PS5", "Virtual Surround Sound", 50, "Poor");
        db.products.add(headphone1);
    }
    void adminsList() {
        Admin* admin1 = new Admin("admin", "admin");
        db.admins.add(admin1);
    }
    void guestList() {
        Guest* guest1 = new Guest("nebi", __TIMESTAMP__);
        db.guests.add(guest1);
    }
    int start() {
        PhoneCategory* phoneCategory = new PhoneCategory(1, "Phones Category");
        NoteBookCategory* notebookCategory = new NoteBookCategory(2, "NoteBooks Category");
        HeadPhoneCategory* headphoneCategory = new HeadPhoneCategory(3, "HeadPhones Category");
       
        try {
            int counter = 1;
            char key;
            for (int i = 0;;)
            {
                gotoxy(50, 9);
                mySetColor(Set[0], 0);
                cout << "[1]GUEST SIGN UP";
                gotoxy(50, 10);
                mySetColor(Set[1], 0);
                cout << "[2]ADMIN LOGIN ";
                gotoxy(50, 11);
                mySetColor(Set[2], 0);
                cout << "[3]GUEST SIGN IN";
                mySetColor(7, 0);
                cout << endl;
                key = _getch();
                if (key == 72 && (counter >= 2 && counter <= 3))
                {
                    counter--;
                }
                if (key == 80 && (counter >= 1 && counter <= 2))
                {
                    counter++;
                }
                if (key == '\r')//carriage return
                {
                    if (counter == 1)
                    {
                        cout << "Enter your fullName: ";
                        string fullName;
                        cin >> fullName;
                        Guest* guest = new Guest(fullName, __TIMESTAMP__);
                        db.guests.add(guest);
                        mySetColor(3, 0);
                        cout << "----Succesfully Registered----" << endl;
                        mySetColor(7, 0);
                        Sleep(2000);
                        system("cls");
                        start();
                    }
                    if (counter == 2)
                    {
                        while (true) {
                            cout << "Enter admin username:";
                            string adminUsername; cin >> adminUsername;
                            cout << "Enter admin password: ";
                            string adminPassword; cin >> adminPassword;
                            if (db.admins.isExistItemWithName(adminUsername) && db.admins.isExistItemWithPassword(adminPassword)) {
                                system("cls");
                                
                                while (true) {
                                    adminDisplay();
                                    key = _getch();
                                    if (key == 72 && (counter >= 2 && counter <= 5))
                                    {
                                        counter--;
                                    }
                                    if (key == 80 && (counter >= 1 && counter <= 4))
                                    {
                                        counter++;
                                    }
                                    if (key == '\r')//carriage return
                                    {
                                        if (counter == 1)
                                        {
                                            system("cls");
                                            mySetColor(3, 0);
                                            cout << "------------"<<notebookCategory->getName()<<" ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(5, 0);
                                            for (auto& notebook : db.products.GetItems())
                                            {
                                                if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                    notebook->Print();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            mySetColor(3, 0);
                                            cout << "------------" << phoneCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(4, 0);
                                            for (auto& phone : db.products.GetItems())
                                            {
                                                if (phoneCategory->getId() == phone->getCategoryId()) {
                                                    phone->Print();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            mySetColor(3, 0);
                                            cout << "------------" << headphoneCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(6, 0);
                                            for (auto& headphone : db.products.GetItems())
                                            {
                                                if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                    headphone->Print();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            int counter6 = 1;
                                            for (i = 0;;) {
                                                gotoxy(50, 9);
                                                mySetColor(Set[0], 0);
                                                cout << "[1]Back" << endl;
                                                gotoxy(50, 10);
                                                mySetColor(Set[1], 0);
                                                cout << "[2]Exit" << endl;
                                                mySetColor(7, 0);
                                                key = _getch();
                                                if (key == 80 && (counter6 >= 0 && counter6 <= 1)) {
                                                    counter6++;
                                                }
                                                if (key == 72 && (counter6 == 2)) {
                                                    counter6--;
                                                }
                                                if (key == '\r')//carriage return
                                                {
                                                    if (counter6 == 1)
                                                    {
                                                        system("cls");
                                                        break;
                                                        adminDisplay();
                                                    }
                                                    if (counter6 == 2)
                                                    {
                                                        system("cls");
                                                        mySetColor(4, 0);
                                                        cout << "You exit from panel" << endl;
                                                        mySetColor(7, 0);
                                                        exit(0);
                                                    }
                                                }
                                                Set[0] = 7;
                                                Set[1] = 7;
                                                if (counter6 == 1) {
                                                    Set[0] = 2;
                                                }
                                                if (counter6 == 2) {
                                                    Set[1] = 2;
                                                }
                                            }
                                        }
                                        if (counter == 2)
                                        {
                                            int counter1 = 3;
                                            system("cls");
                                            gotoxy(45, 7);
                                            mySetColor(5, 0);
                                            cout << "Which category do you want to add the product to?" << endl;
                                            mySetColor(7, 0);
                                            for (i = 0;;) {
                                                gotoxy(50, 9);
                                                mySetColor(Set[0], 0);
                                                cout << "[1]Notebook Category" << endl;
                                                gotoxy(50, 10);
                                                mySetColor(Set[1], 0);
                                                cout << "[2]Phone category" << endl;
                                                gotoxy(50, 11);
                                                mySetColor(Set[2], 0);
                                                cout << "[3]HeadPhone category" << endl;
                                                gotoxy(50, 12);
                                                mySetColor(Set[3], 0);
                                                cout << "[4]Back" << endl;
                                                gotoxy(50, 13);
                                                mySetColor(Set[4], 0);
                                                cout << "[5]Exit" << endl;
                                                mySetColor(7, 0);
                                                key = _getch();
                                                if (key == 72 && (counter1 >= 2 && counter1 <= 5))
                                                {
                                                    counter1--;
                                                }
                                                if (key == 80 && (counter1 >= 1 && counter1 <= 4))
                                                {
                                                    counter1++;
                                                }
                                                if (key == '\r')//carriage return
                                                {
                                                    if (counter1 == 1)
                                                    {
                                                        AddProductNotebook();
                                                        system("cls");
                                                        continue;
                                                    }
                                                    if (counter1 == 2)
                                                    {
                                                        AddproductPhone();
                                                        system("cls");
                                                        continue;
                                                    }
                                                    if (counter1 == 3) {
                                                        AddProductHeadphone();
                                                        system("cls");
                                                        continue;
                                                    }
                                                    if (counter1 == 4) {
                                                        system("cls");
                                                        break;
                                                    }
                                                    if (counter1 == 5) {
                                                        system("cls");
                                                        cout << "You exit from panel" << endl;
                                                        exit(0);
                                                    }
                                                }
                                                Set[0] = 7;
                                                Set[1] = 7;
                                                Set[2] = 7;
                                                Set[3] = 7;
                                                Set[4] = 7;
                                                if (counter1 == 1) Set[0] = 2;
                                                if (counter1 == 2) Set[1] = 2;
                                                if (counter1 == 3) Set[2] = 2;
                                                if (counter1 == 4) Set[3] = 2;
                                                if (counter1 == 5) Set[4] = 2;
                                            }
                                        }
                                        if (counter == 3)
                                        {
                                            system("cls");
                                            mySetColor(3, 0);
                                            cout << "------------" << notebookCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(5, 0);
                                            for (auto& notebook : db.products.GetItems())
                                            {
                                                if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                    notebook->Print();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            mySetColor(3, 0);
                                            cout << "------------" << phoneCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(4, 0);
                                            for (auto& phone : db.products.GetItems())
                                            {
                                                if (phoneCategory->getId() == phone->getCategoryId()) {
                                                    phone->Print();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            mySetColor(3, 0);
                                            cout << "------------" << headphoneCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(6, 0);
                                            for (auto& headphone : db.products.GetItems())
                                            {
                                                if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                    headphone->Print();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            mySetColor(9, 0);
                                            cout << "\n\n\n--------Which product you want delete(with id)->-------- ";
                                            mySetColor(7, 0);
                                            int deletionid; cin >> deletionid;
                                            db.products.deleteItem(deletionid);
                                            system("cls");
                                            cout << "-----------PRODUCT DELETED SUCESSFULLY-----------" << endl;
                                            Sleep(1500);
                                            system("cls");
                                        }
                                        if (counter == 4)
                                        {
                                            db.products.Print();
                                            mySetColor(4, 0);
                                            while (true) {
                                                cout << "Which product you want update(with id)" << endl;
                                                cout << "Enter id: "; int id; cin >> id;
                                                if (db.products.isExistsItem(id)) {
                                                    for (auto& product : db.products.GetItems())
                                                    {
                                                        if (product->getId() == id) {
                                                            if (product->getCategoryId() == notebookCategory->getId()) {
                                                                system("cls");
                                                                mySetColor(6, 0);
                                                                cout << " Notebook  name-> ";
                                                                cin.ignore();
                                                                string name; getline(cin, name);
                                                                cout << " Notebook  description-> ";
                                                                string description; getline(cin, description);
                                                                cout << " Notebook price-> ";
                                                                double price; cin >> price;
                                                                cout << " Notebook tax-> ";
                                                                double tax; cin >> tax;
                                                                cout << " Notebook discount-> ";
                                                                double discount; cin >> discount;
                                                                cout << " Notebook quantity-> ";
                                                                int quantity; cin >> quantity;
                                                                cin.ignore();
                                                                cout << " Notebook cpu model-> ";
                                                                string cpumodel; getline(cin, cpumodel);;
                                                                cout << " Notebook ram size-> ";
                                                                int ramsize; cin >> ramsize;
                                                                cout << " Notebook screen size-> ";
                                                                cin.ignore();
                                                                string screensize; getline(cin, screensize);
                                                                cout << " Notebook screen resoulition-> ";
                                                                string screenresouliton; getline(cin, screenresouliton);
                                                                cout << " Notebook ssd model-> ";
                                                                string ssdmodel; getline(cin, ssdmodel);
                                                                cout << " Notebook ssd size-> ";
                                                                int ssdsize; cin >> ssdsize;
                                                                product->SetName(name);
                                                                product->SetDescription(description);
                                                                product->SetTax(tax);
                                                                product->SetDiscount(discount);
                                                                product->SetQuantiy(quantity);
                                                                product->SetPrice(price);
                                                                mySetColor(3, 0);
                                                                cout << product->getName() << "succesfully updated" << endl;
                                                                mySetColor(7, 0);
                                                                Sleep(2000);
                                                                system("cls");
                                                                break;
                                                            }
                                                            if (product->getCategoryId() == phoneCategory->getId()) {
                                                                system("cls");
                                                                mySetColor(6, 0);
                                                                cout << " Phone  name-> ";
                                                                cin.ignore();
                                                                string name; getline(cin, name);
                                                                cout << " Phone  description-> ";
                                                                string description; getline(cin, description);
                                                                cout << " Phone price-> ";
                                                                double price; cin >> price;
                                                                cout << " Phone tax-> ";
                                                                double tax; cin >> tax;
                                                                cout << " Phone discount-> ";
                                                                double discount; cin >> discount;
                                                                cout << " Phone quantity-> ";
                                                                int quantity; cin >> quantity;
                                                                cout << " Phone ram size-> ";
                                                                int ramsize; cin >> ramsize;
                                                                cout << " Phone battery-> ";
                                                                int battery; cin >> battery;
                                                                cout << " Phone memory size-> ";
                                                                int memorysize; cin >> memorysize;
                                                                cout << " Phone sim type-> ";
                                                                cin.ignore();
                                                                string simtype; getline(cin, simtype);
                                                                cout << " Phone  screen size-> ";
                                                                string screensize; getline(cin, screensize);
                                                                cout << " Phone  cpu model-> ";
                                                                string cpumodel; getline(cin, cpumodel);
                                                                product->SetName(name);
                                                                product->SetDescription(description);
                                                                product->SetTax(tax);
                                                                product->SetDiscount(discount);
                                                                product->SetQuantiy(quantity);
                                                                product->SetPrice(price);
                                                                mySetColor(3, 0);
                                                                cout << product->getName() << " succesfully updated" << endl;
                                                                mySetColor(7, 0);
                                                                Sleep(2000);
                                                                system("cls");
                                                                break;
                                                            }
                                                            if (product->getCategoryId() == headphoneCategory->getId()) {
                                                                system("cls");
                                                                mySetColor(6, 0);
                                                                cout << " Headphone  name-> ";
                                                                cin.ignore();
                                                                string name; getline(cin, name);
                                                                cout << " Headphone  description-> ";
                                                                string description; getline(cin, description);
                                                                cout << " Headphone price-> ";
                                                                double price; cin >> price;
                                                                cout << " Headphone tax-> ";
                                                                double tax; cin >> tax;
                                                                cout << " Headphone discount-> ";
                                                                double discount; cin >> discount;
                                                                cout << " Headphone quantity-> ";
                                                                int quantity; cin >> quantity;
                                                                cout << " Headphone spiker driver size-> ";
                                                                int spikerdriversize; cin >> spikerdriversize;
                                                                cout << " Headphone  computer platform-> ";
                                                                cin.ignore();
                                                                string computerplatform; getline(cin, computerplatform);
                                                                cout << " Headphone  surround sound -> ";
                                                                string surroundsound; getline(cin, surroundsound);
                                                                cout << " Headphone  sound quality -> ";
                                                                string soundquality; getline(cin, soundquality);
                                                                mySetColor(7, 0);
                                                                product->SetName(name);
                                                                product->SetDescription(description);
                                                                product->SetTax(tax);
                                                                product->SetDiscount(discount);
                                                                product->SetQuantiy(quantity);
                                                                product->SetPrice(price);
                                                                mySetColor(3, 0);
                                                                cout << product->getName() << " succesfully updated" << endl;
                                                                mySetColor(7, 0);
                                                                Sleep(2000);
                                                                system("cls");
                                                                break;
                                                            }
                                                        }
                                                    }
                                                    break;
                                                }
                                                else {
                                                mySetColor(3, 0);
                                                cout << "We dont have product this id!!!" << endl;
                                                mySetColor(7, 0);

                                                }
                                            }    
                                        }
                                        if (counter == 5)
                                        {
                                            system("cls");
                                            start();
                                        }
                                    }
                                    Set[0] = 7;
                                    Set[1] = 7;
                                    Set[2] = 7;
                                    Set[3] = 7;
                                    Set[4] = 7;
                                    if (counter == 1)Set[0] = 2;
                                    if (counter == 2)Set[1] = 2;
                                    if (counter == 3)Set[2] = 2;
                                    if (counter == 4)Set[3] = 2;
                                    if (counter == 5)Set[4] = 2;
                                }
                            }
                            else {
                                mySetColor(4, 0);
                                cout << "Username or password incorrect!!!" << endl;
                                mySetColor(7, 0);
                                continue;
                            }
                            break;
                        }
                    }
                    if (counter == 3)
                    {
                        while (true) {
                            cout << "Enter your full name: ";
                            string fullname; cin >> fullname;
                            if (db.guests.isExistItemWithName(fullname)) {
                                system("cls");
                                int counter2 = 1;
                                for (i = 0;;) {
                                    gotoxy(50, 9);
                                    mySetColor(Set[0], 0);
                                    cout << "[1]Notebook Category" << endl;
                                    gotoxy(50, 10);
                                    mySetColor(Set[1], 0);
                                    cout << "[2]Phone category" << endl;
                                    gotoxy(50, 11);
                                    mySetColor(Set[2], 0);
                                    cout << "[3]HeadPhone category" << endl;
                                    gotoxy(50, 12);
                                    mySetColor(Set[3], 0);
                                    cout << "[4]Cart" << endl;
                                    gotoxy(50, 13);
                                    mySetColor(Set[4], 0);
                                    cout << "[5]Back" << endl;
                                    mySetColor(7, 0);
                                    key = _getch();
                                    if (key == 72 && (counter2 >= 2 && counter2 <= 5))
                                    {
                                        counter2--;
                                    }
                                    if (key == 80 && (counter2 >= 1 && counter2 <= 4))
                                    {
                                        counter2++;
                                    }
                                    if (key == '\r')//carriage return
                                    {
                                        if (counter2 == 1) {
                                            system("cls");
                                            mySetColor(3, 0);
                                            cout << "------------" << notebookCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(5, 0);
                                            for (auto& notebook : db.products.GetItems())
                                            {
                                                if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                    notebook->previewPrint();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            int counter3 = 1;
                                            for (int i = 0;;)
                                            {
                                                gotoxy(50, 9);
                                                mySetColor(Set[0], 0);
                                                cout << "[1]Add to cart";
                                                gotoxy(50, 10);
                                                mySetColor(Set[1], 0);
                                                cout << "[2] Details";
                                                gotoxy(50, 11);
                                                mySetColor(Set[2], 0);
                                                cout << "[3]Look Cart ";
                                                gotoxy(50, 12);
                                                mySetColor(Set[3], 0);
                                                cout << "[4]Exit";
                                                gotoxy(50, 13);
                                                mySetColor(Set[4], 0);
                                                key = _getch();
                                                if (key == 72 && (counter3 >= 2 && counter3 <= 4)) counter3--;
                                                if (key == 80 && (counter3 >= 1 && counter3 <= 3)) counter3++;
                                                if (key == '\r')//carriage return
                                                {
                                                    if (counter3 == 1)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "------------" << notebookCategory->getName() << " ------------ " << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(5, 0);
                                                        for (auto& notebook : db.products.GetItems())
                                                        {
                                                            if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                                notebook->previewPrint();
                                                            }
                                                        }
                                                        mySetColor(7, 0);
                                                        cout << "Which notebook you want add(with id)-> ";
                                                        int id; cin >> id;
                                                        for (auto& notebook : db.products.GetItems())
                                                        {
                                                            if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                                if (notebook->getId() == id) {
                                                                    while (true) {
                                                                        mySetColor(6, 0);
                                                                        cout << "How much do you want this notebook-> ";
                                                                        mySetColor(7, 0);
                                                                        int number; cin >> number;
                                                                        if ((notebook->getQuantity() - number < 0)) {
                                                                            cout << "We have only-> " << notebook->getQuantity() << " notebooks " << endl;
                                                                            continue;
                                                                        }
                                                                        else {
                                                                            notebook->SetQuantiy(notebook->getQuantity() - number);
                                                                            cout << notebook->getName() << "-> this notebook sucessfully add cart " << endl;
                                                                            db.cart.add(notebook);
                                                                            Sleep(2000);
                                                                            system("cls");
                                                                            break;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                        continue;
                                                    }
                                                    if (counter3 == 2)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "------------" << notebookCategory->getName() << " ------------ " << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(5, 0);
                                                        for (auto& notebook : db.products.GetItems())
                                                        {
                                                            if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                                notebook->Print();
                                                            }
                                                        }
                                                        mySetColor(7, 0);
                                                        int counter4 = 1;
                                                        for (int i = 0;;) {
                                                            gotoxy(50, 9);
                                                            mySetColor(Set[0], 0);
                                                            cout << "[1]Add to cart";
                                                            gotoxy(50, 10);
                                                            mySetColor(Set[1], 0);
                                                            cout << "[2] Back";
                                                            key = _getch();
                                                            if (key == 80 && (counter4 >= 0 && counter4 <= 1))   counter4++;
                                                            if (key == 72 && (counter4 == 2))  counter4--;
                                                            if (key == '\r')//carriage return
                                                            {
                                                                if (counter4 == 1)
                                                                {
                                                                    system("cls");
                                                                    mySetColor(3, 0);
                                                                    cout << "------------" << notebookCategory->getName() << " ------------ " << endl;
                                                                    mySetColor(7, 0);
                                                                    mySetColor(5, 0);
                                                                    for (auto& notebook : db.products.GetItems())
                                                                    {
                                                                        if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                                            notebook->Print();
                                                                        }
                                                                    }
                                                                    mySetColor(6, 0);
                                                                    cout << "Which notebook you want add(with id)-> ";
                                                                    int id; cin >> id;
                                                                    mySetColor(7, 0);
                                                                    for (auto& notebook : db.products.GetItems())
                                                                    {
                                                                        if (notebookCategory->getId() == notebook->getCategoryId()) {
                                                                            if (notebook->getId() == id) {
                                                                                while (true) {
                                                                                    mySetColor(6, 0);
                                                                                    cout << "How much do you want this computer-> ";
                                                                                    mySetColor(7, 0);
                                                                                    int number; cin >> number;
                                                                                    if ((notebook->getQuantity() - number < 0)) {
                                                                                        cout << "We have only-> " << notebook->getQuantity() << " notebooks " << endl;
                                                                                        continue;
                                                                                    }
                                                                                    else {
                                                                                        notebook->SetQuantiy(notebook->getQuantity() - number);
                                                                                        cout << notebook->getName() << "-> this notebook sucessfully add cart " << endl;
                                                                                        db.cart.add(notebook);
                                                                                        Sleep(2000);
                                                                                        system("cls");
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                    break;
                                                                }
                                                                if (counter4 == 2)
                                                                {
                                                                    system("cls");
                                                                    break;
                                                                }
                                                            }
                                                            Set[0] = 7;
                                                            Set[1] = 7;
                                                            if (counter4 == 1) {
                                                                Set[0] = 2;
                                                            }
                                                            if (counter4 == 2) {
                                                                Set[1] = 2;
                                                            }
                                                        }
                                                        break;
                                                    }
                                                    if (counter3 == 3)
                                                    {
                                                        system("cls");
                                                        db.cart.Print();
                                                        Sleep(2000);
                                                        system("pause");
                                                        system("cls");
                                                        continue;
                                                    }
                                                    if (counter3 == 4)
                                                    {
                                                        system("cls");
                                                        break;
                                                    }
                                                }
                                                Set[0] = 7;
                                                Set[1] = 7;
                                                Set[2] = 7;
                                                Set[3] = 7;
                                                if (counter3 == 1)Set[0] = 2;
                                                if (counter3 == 2)Set[1] = 2;
                                                if (counter3 == 3)Set[2] = 2;
                                                if (counter3 == 4)Set[3] = 2;
                                            }
                                            continue;
                                        }
                                        if (counter2 == 2) {
                                            system("cls");
                                            mySetColor(3, 0);
                                            cout << "------------" << phoneCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(5, 0);
                                            for (auto& phone : db.products.GetItems())
                                            {
                                                if (phoneCategory->getId() == phone->getCategoryId()) {
                                                    phone->previewPrint();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            int counter3 = 2;
                                            for (int i = 0;;)
                                            {
                                                gotoxy(50, 9);
                                                mySetColor(Set[0], 0);
                                                cout << "[1]Add to cart";
                                                gotoxy(50, 10);
                                                mySetColor(Set[1], 0);
                                                cout << "[2] Details";
                                                gotoxy(50, 11);
                                                mySetColor(Set[2], 0);
                                                cout << "[3]Look Cart ";
                                                gotoxy(50, 12);
                                                mySetColor(Set[3], 0);
                                                cout << "[4]Exit";
                                                gotoxy(50, 13);
                                                mySetColor(Set[4], 0);
                                                key = _getch();
                                                if (key == 72 && (counter3 >= 2 && counter3 <= 4)) counter3--;
                                                if (key == 80 && (counter3 >= 1 && counter3 <= 3)) counter3++;
                                                if (key == '\r')//carriage return
                                                {
                                                    if (counter3 == 1)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "------------" << phoneCategory->getName() << " ------------ " << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(5, 0);
                                                        for (auto& phone : db.products.GetItems())
                                                        {
                                                            if (phoneCategory->getId() == phone->getCategoryId()) {
                                                                phone->previewPrint();
                                                            }
                                                        }
                                                        mySetColor(7, 0);
                                                        cout << "Which phone you want add(with id)-> ";
                                                        int id; cin >> id;
                                                        for (auto& phone : db.products.GetItems())
                                                        {
                                                            if (phoneCategory->getId() == phone->getCategoryId()) {
                                                                if (phone->getId() == id) {
                                                                    while (true) {
                                                                        mySetColor(6, 0);
                                                                        cout << "How much do you want this phone-> ";
                                                                        mySetColor(7, 0);
                                                                        int number; cin >> number;
                                                                        if ((phone->getQuantity() - number < 0)) {
                                                                            cout << "We have only-> " << phone->getQuantity() << " phones " << endl;
                                                                            continue;
                                                                        }
                                                                        else {
                                                                            phone->SetQuantiy(phone->getQuantity() - number);
                                                                            cout << phone->getName() << "-> this phone sucessfully add cart " << endl;
                                                                            db.cart.add(phone);
                                                                            Sleep(2000);
                                                                            system("cls");
                                                                            break;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (counter3 == 2)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "------------" << phoneCategory->getName() << " ------------ " << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(5, 0);
                                                        for (auto& phone : db.products.GetItems())
                                                        {
                                                            if (phoneCategory->getId() == phone->getCategoryId()) {
                                                                phone->Print();
                                                            }
                                                        }
                                                        mySetColor(7, 0);
                                                        int counter4 = 1;
                                                        for (int i = 0;;) {
                                                            gotoxy(50, 9);
                                                            mySetColor(Set[0], 0);
                                                            cout << "[1]Add to cart";
                                                            gotoxy(50, 10);
                                                            mySetColor(Set[1], 0);
                                                            cout << "[2] Back";
                                                            key = _getch();
                                                            if (key == 80 && (counter4 >= 0 && counter4 <= 1))   counter4++;
                                                            if (key == 72 && (counter4 == 2))  counter4--;
                                                            if (key == '\r')//carriage return
                                                            {
                                                                if (counter4 == 1)
                                                                {
                                                                    system("cls");
                                                                    mySetColor(3, 0);
                                                                    cout << "------------" << phoneCategory->getName() << " ------------ " << endl;
                                                                    mySetColor(7, 0);
                                                                    mySetColor(5, 0);
                                                                    for (auto& phone : db.products.GetItems())
                                                                    {
                                                                        if (phoneCategory->getId() == phone->getCategoryId()) {
                                                                            phone->Print();
                                                                        }
                                                                    }
                                                                    mySetColor(6, 0);
                                                                    cout << "Which phone you want add(with id)-> ";
                                                                    int id; cin >> id;
                                                                    mySetColor(7, 0);
                                                                    for (auto& phone : db.products.GetItems())
                                                                    {
                                                                        if (phoneCategory->getId() == phone->getCategoryId()) {
                                                                            if (phone->getId() == id) {
                                                                                while (true) {
                                                                                    mySetColor(6, 0);
                                                                                    cout << "How much do you want this phone-> ";
                                                                                    mySetColor(7, 0);
                                                                                    int number; cin >> number;
                                                                                    if ((phone->getQuantity() - number < 0)) {
                                                                                        cout << "We have only-> " << phone->getQuantity() << " phones " << endl;
                                                                                        continue;
                                                                                    }
                                                                                    else {
                                                                                        phone->SetQuantiy(phone->getQuantity() - number);
                                                                                        cout << phone->getName() << "-> this phone sucessfully add cart " << endl;
                                                                                        db.cart.add(phone);
                                                                                        Sleep(2000);
                                                                                        system("cls");
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                if (counter4 == 2)
                                                                {
                                                                    system("cls");
                                                                    break;
                                                                }
                                                            }
                                                            Set[0] = 7;
                                                            Set[1] = 7;
                                                            if (counter4 == 1) {
                                                                Set[0] = 2;
                                                            }
                                                            if (counter4 == 2) {
                                                                Set[1] = 2;
                                                            }
                                                        }
                                                    }
                                                    if (counter3 == 3)
                                                    {
                                                        system("cls");
                                                        db.cart.Print();
                                                        Sleep(2000);
                                                        system("pause");
                                                        system("cls");
                                                        continue;
                                                    }
                                                    if (counter3 == 4)
                                                    {
                                                        system("cls");
                                                        break;
                                                    }
                                                }
                                                Set[0] = 7;
                                                Set[1] = 7;
                                                Set[2] = 7;
                                                Set[3] = 7;
                                                if (counter3 == 1)Set[0] = 2;
                                                if (counter3 == 2)Set[1] = 2;
                                                if (counter3 == 3)Set[2] = 2;
                                                if (counter3 == 4)Set[3] = 2;
                                            }
                                            continue;
                                        }
                                        if (counter2 == 3) {
                                            system("cls");
                                            mySetColor(3, 0);
                                            cout << "------------" << headphoneCategory->getName() << " ------------ " << endl;
                                            mySetColor(7, 0);
                                            mySetColor(5, 0);
                                            for (auto& headphone : db.products.GetItems())
                                            {
                                                if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                    headphone->previewPrint();
                                                }
                                            }
                                            mySetColor(7, 0);
                                            int counter3 = 2;
                                            for (int i = 0;;)
                                            {
                                                gotoxy(50, 9);
                                                mySetColor(Set[0], 0);
                                                cout << "[1]Add to cart";
                                                gotoxy(50, 10);
                                                mySetColor(Set[1], 0);
                                                cout << "[2] Details";
                                                gotoxy(50, 11);
                                                mySetColor(Set[2], 0);
                                                cout << "[3]Look Cart ";
                                                gotoxy(50, 12);
                                                mySetColor(Set[3], 0);
                                                cout << "[4]Exit";
                                                gotoxy(50, 13);
                                                mySetColor(Set[4], 0);
                                                key = _getch();
                                                if (key == 72 && (counter3 >= 2 && counter3 <= 4)) counter3--;
                                                if (key == 80 && (counter3 >= 1 && counter3 <= 3)) counter3++;
                                                if (key == '\r')//carriage return
                                                {
                                                    if (counter3 == 1)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "------------" << headphoneCategory->getName() << " ------------ " << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(5, 0);
                                                        for (auto& headphone : db.products.GetItems())
                                                        {
                                                            if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                                headphone->previewPrint();
                                                            }
                                                        }
                                                        mySetColor(7, 0);
                                                        cout << "Which headphone you want add(with id)-> ";
                                                        int id; cin >> id;
                                                        for (auto& headphone : db.products.GetItems())
                                                        {
                                                            if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                                if (headphone->getId() == id) {
                                                                    while (true) {
                                                                        mySetColor(6, 0);
                                                                        cout << "How much do you want this headphone-> ";
                                                                        mySetColor(7, 0);
                                                                        int number; cin >> number;
                                                                        if ((headphone->getQuantity() - number < 0)) {
                                                                            cout << "We have only-> " << headphone->getQuantity() << " headphones " << endl;
                                                                            continue;
                                                                        }
                                                                        else {
                                                                            headphone->SetQuantiy(headphone->getQuantity() - number);
                                                                            cout << headphone->getName() << "-> this headphone sucessfully add cart " << endl;
                                                                            db.cart.add(headphone);
                                                                            Sleep(2000);
                                                                            system("cls");
                                                                            break;
                                                                        }
                                                                    }
                                                                }
                                                            }
                                                        }
                                                    }
                                                    if (counter3 == 2)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "------------" << headphoneCategory->getName() << " ------------ " << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(5, 0);
                                                        for (auto& headphone : db.products.GetItems())
                                                        {
                                                            if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                                headphone->Print();
                                                            }
                                                        }
                                                        mySetColor(7, 0);
                                                        int counter4 = 1;
                                                        for (int i = 0;;) {
                                                            gotoxy(50, 9);
                                                            mySetColor(Set[0], 0);
                                                            cout << "[1]Add to cart";
                                                            gotoxy(50, 10);
                                                            mySetColor(Set[1], 0);
                                                            cout << "[2] Back";
                                                            key = _getch();
                                                            if (key == 80 && (counter4 >= 0 && counter4 <= 1))   counter4++;
                                                            if (key == 72 && (counter4 == 2))  counter4--;
                                                            if (key == '\r')//carriage return
                                                            {
                                                                if (counter4 == 1)
                                                                {
                                                                    system("cls");
                                                                    mySetColor(3, 0);
                                                                    cout << "------------Headphones Category------------ " << endl;
                                                                    mySetColor(7, 0);
                                                                    mySetColor(5, 0);
                                                                    for (auto& headphone : db.products.GetItems())
                                                                    {
                                                                        if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                                            headphone->Print();
                                                                        }
                                                                    }
                                                                    mySetColor(6, 0);
                                                                    cout << "Which headphone you want add(with id)-> ";
                                                                    int id; cin >> id;
                                                                    mySetColor(7, 0);
                                                                    for (auto& headphone : db.products.GetItems())
                                                                    {
                                                                        if (headphoneCategory->getId() == headphone->getCategoryId()) {
                                                                            if (headphone->getId() == id) {
                                                                                while (true) {
                                                                                    mySetColor(6, 0);
                                                                                    cout << "How much do you want this headphone-> ";
                                                                                    mySetColor(7, 0);
                                                                                    int number; cin >> number;
                                                                                    if ((headphone->getQuantity() - number < 0)) {
                                                                                        cout << "We have only-> " << headphone->getQuantity() << " headphones " << endl;
                                                                                        continue;
                                                                                    }
                                                                                    else {
                                                                                        headphone->SetQuantiy(headphone->getQuantity() - number);
                                                                                        cout << headphone->getName() << "-> this headphone sucessfully add cart " << endl;
                                                                                        db.cart.add(headphone);
                                                                                        Sleep(2000);
                                                                                        system("cls");
                                                                                        break;
                                                                                    }
                                                                                }
                                                                            }
                                                                        }
                                                                    }
                                                                }
                                                                if (counter4 == 2)
                                                                {
                                                                    system("cls");
                                                                    break;
                                                                }
                                                            }
                                                            Set[0] = 7;
                                                            Set[1] = 7;
                                                            if (counter4 == 1) {
                                                                Set[0] = 2;
                                                            }
                                                            if (counter4 == 2) {
                                                                Set[1] = 2;
                                                            }
                                                        }
                                                    }
                                                    if (counter3 == 3)
                                                    {
                                                        system("cls");
                                                        db.cart.Print();
                                                        Sleep(2000);
                                                        system("pause");
                                                        system("cls");
                                                        continue;
                                                    }
                                                    if (counter3 == 4)
                                                    {
                                                        system("cls");
                                                        break;
                                                    }
                                                }
                                                Set[0] = 7;
                                                Set[1] = 7;
                                                Set[2] = 7;
                                                Set[3] = 7;
                                                if (counter3 == 1)Set[0] = 2;
                                                if (counter3 == 2)Set[1] = 2;
                                                if (counter3 == 3)Set[2] = 2;
                                                if (counter3 == 4)Set[3] = 2;
                                            }
                                            continue;

                                        }
                                        if (counter2 == 4) {
                                            system("cls");
                                            int counter5 = 1;
                                            for (int i = 0;;)
                                            {
                                                gotoxy(50, 9);
                                                mySetColor(Set[0], 0);
                                                cout << "[1]Buy from card";
                                                gotoxy(50, 10);
                                                mySetColor(Set[1], 0);
                                                cout << "[2]Delete from card";
                                                mySetColor(7, 0);
                                                key = _getch();
                                                if (key == 72 && (counter5 == 2)) counter5--;
                                                if (key == 80 && (counter5 >= 0 && counter5 <= 1)) counter5++;
                                                if (key == '\r')//carriage return
                                                {
                                                    if (counter5 == 1)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "----------------YOUR CART----------------" << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(6, 0);
                                                        db.cart.Print();
                                                        mySetColor(7, 0);
                                                        if (db.cart.ItemsListEmpty()) {
                                                            mySetColor(3, 0);
                                                            cout << "Your cart is empty " << endl;
                                                            mySetColor(7, 0);
                                                            Sleep(1500);
                                                            system("cls");

                                                            break;
                                                        }
                                                        for (auto& product : db.cart.GetItems())
                                                        {
                                                            while (true) {
                                                                mySetColor(4, 0);
                                                                cout << "Which product you want buy?(with id)" << endl;
                                                                mySetColor(7, 0);
                                                                int id; cin >> id;
                                                                if (db.cart.isExistsItem(id)) {
                                                                    if (product->getId() == id) {
                                                                        db.cart.DeleteItem(product);
                                                                        break;
                                                                    }
                                                                }
                                                                else {
                                                                    cout << "We dont have product this id " << endl;
                                                                    continue;
                                                                }
                                                            }

                                                        }
                                                        mySetColor(5, 0);
                                                        cout << "You sucesfully buy this product" << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(3, 0);
                                                        cout << "--------THANKS YOU FOR CHOOSING US--------" << endl;
                                                        mySetColor(7, 0);
                                                        Sleep(2000);
                                                        system("cls");
                                                        break;

                                                        
                                                    }
                                                    if (counter5 == 2)
                                                    {
                                                        system("cls");
                                                        mySetColor(3, 0);
                                                        cout << "----------------YOUR CART----------------" << endl;
                                                        mySetColor(7, 0);
                                                        mySetColor(6, 0);
                                                        db.cart.Print();
                                                        mySetColor(7, 0);
                                                        if (db.cart.ItemsListEmpty()) {
                                                            mySetColor(3, 0);
                                                            cout << "Your cart is empty " << endl;
                                                            mySetColor(7, 0);
                                                            Sleep(1500);
                                                            system("cls");
                                                            break;
                                                        }
                                                        for (auto& product : db.cart.GetItems())
                                                        {
                                                           
                                                            while (true) {
                                                                mySetColor(4, 0);
                                                                cout << "Which product you want delete?(with id)" << endl;
                                                                mySetColor(7, 0);
                                                                int id; cin >> id;
                                                                if (db.cart.isExistsItem(id)) {
                                                                    if (product->getId() == id) {
                                                                        db.cart.DeleteItem(product);
                                                                        break;
                                                                    }
                                                                }
                                                                else {
                                                                    cout << "We dont have product this id " << endl;
                                                                    continue;
                                                                }
                                                            }
                                                           
                                                        }
                                                        mySetColor(5, 0);
                                                        cout << "You sucesfully delete this product" << endl;
                                                        mySetColor(7, 0);
                                                       

                                                        Sleep(2000);
                                                        system("cls");
                                                        break;
                                                        
                                                    }
                                                }
                                                Set[0] = 7;
                                                Set[1] = 7;
                                                if (counter5 == 1)Set[0] = 2;
                                                if (counter5 == 2)Set[1] = 2;
                                            }
                                        }
                                        if (counter2 == 5) {
                                            system("cls");
                                            start();
                                        }
                                    }
                                    Set[0] = 7;
                                    Set[1] = 7;
                                    Set[2] = 7;
                                    Set[3] = 7;
                                    Set[4] = 7;
                                    if (counter2 == 1) Set[0] = 2;
                                    if (counter2 == 2) Set[1] = 2;
                                    if (counter2 == 3) Set[2] = 2;
                                    if (counter2 == 4) Set[3] = 2;
                                    if (counter2 == 5) Set[4] = 2;
                                }
                            }
                            else {
                                cout << "Username is incorrect" << endl;
                                continue;
                            }
                        }
                    }
                }
                Set[0] = 7;
                Set[1] = 7;
                Set[2] = 7;
                Set[3] = 7;
                Set[4] = 7;
                if (counter == 1) Set[0] = 2;
                if (counter == 2) Set[1] = 2;
                if (counter == 3) Set[2] = 2;
            }
        }
        catch (Exceptions::Exception& ex) {
            ex.PrintMsg();
        }
        return 0;
    }
}
