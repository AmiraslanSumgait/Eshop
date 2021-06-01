#pragma once
#include"Product.h"
class Phone :public Product {
private:
	double _ram_size;
	string _sim_type;
	string _screen_size;
	string _cpu_model;
	double  _battery;
	double _memory_size;
public:
	Phone( const int& categoryid, const string& name, const string& description, const double& price, const double& tax, const double& discount, const int& quantity, const double& ramSize, const string& simType, const string& screenSize, const string& cpuModel, const double &battery, const double& memorySize) :Product( categoryid, name, description, price, tax, discount, quantity)
	{
		SetRamSize(ramSize);
		SetSimType(simType);
		SetScreenSize(screenSize);
		SetCpuModel(cpuModel);
		SetBattery(battery);
		SetMemorySize(memorySize);

	}
	double& getRamSize() {
		return _ram_size;
	}
	string& getSimType() {
		return _sim_type;
	}
	string& getScreenSize() {
		return _screen_size;
	}
	string& getCpuModel() {
		return _cpu_model;
	}
	double& getBattery() {
		return _battery;
	}
	double& getMemorySize() {
		return _memory_size;
	}
	void SetRamSize(const double& ramSize) {
		if (ramSize < 0) {
			Exceptions::writeExceptionsToFile("The ramsize cannot be negative.", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The ramsize cannot be negative.", __LINE__, __FILE__);
		}
		_ram_size = ramSize;

	}
	void SetSimType(const string& simType) {
		if (simType.empty()) {
			Exceptions::writeExceptionsToFile("The simtype is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The simtype is empty", __LINE__, __FILE__);
		}
		_sim_type = simType;
	}
	void SetScreenSize(const string& screenSize) {
		if (screenSize.empty()) {
			Exceptions::writeExceptionsToFile("The screenSize is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The screenSize is empty", __LINE__, __FILE__);
		}
		_screen_size = screenSize;
	}
	void SetCpuModel(const string& cpuModel) {
		if (cpuModel.empty()) {
			Exceptions::writeExceptionsToFile("The cpuModel is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The cpuModel is empty", __LINE__, __FILE__);
		}
		_cpu_model = cpuModel;
	}
	void SetBattery(const double& battery) {
		if (battery < 0) {
			Exceptions::writeExceptionsToFile("The battery cannot be negative.", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The battery cannot be negative.", __LINE__, __FILE__);
		}
		_battery = battery;
	}
	void SetMemorySize(const double& memorySize) {
		if (memorySize < 0) {
			Exceptions::writeExceptionsToFile("The memorySize cannot be negative.", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The memorySize cannot be negative.", __LINE__, __FILE__);
		}
		_memory_size = memorySize;
	}
	void Print()override {
		Product::Print();
		cout << "Ram size: " << _ram_size << endl;
		cout << "Sim Type: " << _sim_type << endl;
		cout << "Screen size: " << _screen_size << endl;
		cout << "Cpu Model: " << _cpu_model << endl;
		cout << "Battery: " << _battery <<"Mah"<< endl;
		cout << "Memory Storage: " << _memory_size << endl;

	}


};