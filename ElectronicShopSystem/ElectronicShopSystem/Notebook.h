#pragma once
#include "Product.h"
class NoteBook : public Product {
	string _cpuModel;
	double _ram_size;
	string _screen_size;
	string _screen_resoulition;
	string _ssdModel;
	double _ssd_size;
public:
	NoteBook( const int& categoryid, const string& name, const string& description, const double& price, const double& tax, const double& discount, const int& quantity, const string& cpuModel, const double& ramSize, const string& screenSize, const string& screenResoulition, const string& ssdModel, const double& ssdSize) :Product( categoryid, name, description, price, tax, discount, quantity)
	{
		SetCpuModel(cpuModel);
		SetRamSize(ramSize);
		SetScreenSize(screenSize);
		SetScreenResoulition(screenResoulition);
		SetSsdModel(ssdModel);
		SetSsdSize(ssdSize);

		
	}
	string& getCpuModel() {
		return _cpuModel;
	}
	double& getRamSize() {
		return _ram_size;
	}
	string& getScreenSize() {
		return _screen_size;
	}
	string& getScreenResouliton() {
		return _screen_resoulition;
	}
	string& getSsdModel() {
		return _ssdModel;
	}
	double& getSsdSize() {
		return _ssd_size;
	}
	void SetCpuModel(const string& cpumodel) {
		if (cpumodel.empty()) {
			Exceptions::writeExceptionsToFile("The cpuModel is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The cpuModel is empty", __LINE__, __FILE__);
		}
		_cpuModel = cpumodel;
	}
	void SetRamSize(const double& ramsize) {
		if (ramsize < 0) {
			Exceptions::writeExceptionsToFile("Ram size cannot be negative", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("Ram size cannot be negative", __LINE__, __FILE__);
		}
		_ram_size = ramsize;
	}
	void SetScreenSize(const string& screensize) {
		if (screensize.empty()) {
			Exceptions::writeExceptionsToFile("The screensize is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The screensize is empty", __LINE__, __FILE__);
		}
		_screen_size = screensize;
	}
	void SetScreenResoulition(const string& screenresouliton) {
		if (screenresouliton.empty()) {
			Exceptions::writeExceptionsToFile("The screenresouliton is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The screenresouliton is empty", __LINE__, __FILE__);
		}
		_screen_resoulition = screenresouliton;
	}
	void SetSsdModel(const string& ssdmodel) {
		if (ssdmodel.empty()) {
			Exceptions::writeExceptionsToFile("The ssdmodel is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The ssdmodel is empty", __LINE__, __FILE__);
		}
		_ssdModel = ssdmodel;
	}
	void SetSsdSize(const double& ssdsize) {
		if (ssdsize < 0) {
			Exceptions::writeExceptionsToFile("Ssd size cannot be negative", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("SSd size cannot be negative", __LINE__, __FILE__);
		}
		_ssd_size = ssdsize;
	}
	void Print() {
	
		Product::Print();
		cout << "Cpu Model: " << _cpuModel << endl;
		cout << "Ram Size: " << _ram_size << endl;
		cout << "Screen Size: " << _screen_size << endl;
		cout << "Screen Resoulition: " << _screen_resoulition << endl;
		cout << "SSD Model: " << _ssdModel << endl;
		cout << "SSD Size: " << _ssd_size << endl;
		cout << endl << endl;
	}
};
