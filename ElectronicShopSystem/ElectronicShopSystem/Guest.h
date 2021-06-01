#pragma once
#include<string>
#include<time.h>
#include"Person.h"
using namespace std;

class Guest :public Person {
		string _fullname;
		string _connected_data;
	public:
		Guest(const string& fullname, string connectedata) :Person()
		{

			SetFullName(fullname);
			SetConnectedData(connectedata);
		}
		void SetFullName(const string& fullname) {
			if (fullname.empty()) {
				Exceptions::writeExceptionsToFile("The fullname is empty", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The fullname is empty", __LINE__, __FILE__);
			}
			_fullname = fullname;
		}
		string& getName() {
			return _fullname;
		}
		void SetConnectedData(const string& connecteddata) {
			if (connecteddata.empty()) return;

			time_t currently = time(0);
			char dt[30]{};
			ctime_s(dt, sizeof dt, &currently);
			string time = dt;
			this->_connected_data = dt;
			
		}
		void Print()override {
			cout << "Fullname: " << _fullname<< endl;
			cout << "Connected datetime: " << _connected_data<<endl;
		}
};
