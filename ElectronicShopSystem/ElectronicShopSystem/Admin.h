#pragma once
#include<string>
#include"Exceptions.h"
#include"Person.h"
using namespace std;

class Admin :public Person {
		string _username;
		string _password;
	public:
		Admin() = default;
		Admin(const string& username, const string& password) :Person()
		{
			SetUserName(username);
			SetPassword(password);
		}
		string getName() {
			return _username;
		}
		string getPassword() {
			return _password;
		}
		void SetUserName(const string& username) {
			if (username.empty()) {
				Exceptions::writeExceptionsToFile("The username is empty", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The username is empty", __LINE__, __FILE__);
			}
			_username = username;
		}
		void SetPassword(const string& password) {
			if (password.empty()) {
				Exceptions::writeExceptionsToFile("The password is empty", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The password is empty", __LINE__, __FILE__);
			}
			_password = password;
		}
		void Print() {
			Person::Print();
			cout << "Username: " << _username << endl;
			cout << "Password: " << _password << endl;
		}
};
