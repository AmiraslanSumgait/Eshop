#pragma once
#include"Product.h"
class HeadPhone:public Product {
	string _computerPlatform;
	string _surroundSound;
	double _spikerDriverSize;
	string _soundQuality;
public:
	HeadPhone( const int& categoryid, const string& name, const string& description, const double& price, const double& tax, const double& discount, const int& quantity,const string&computerplatform,const string&surroundsound,const double&spikerDriverSize,const string&soundQuality ) :Product( categoryid, name, description, price, tax, discount, quantity)
	{
		SetComputerPlatform(computerplatform);
		SetSurroundSound(surroundsound);
		SetSpikerDriverSize(spikerDriverSize);
		SetSoundQuality(soundQuality);
	}
	string& getComputerPlatform() {
		return _computerPlatform;
	}
	string& getSurroundSound() {
		return _surroundSound;
	}
	double& getSpikerDriverSize() {
		return _spikerDriverSize;
	}
	string& getSoundQuality() {
		return _soundQuality;
	}
	void SetComputerPlatform(const string&computerplatform) {
		if (computerplatform.empty()) {
			Exceptions::writeExceptionsToFile("The computerplatform is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The computerplatform is empty", __LINE__, __FILE__);
		}
		_computerPlatform = computerplatform;
	}
	void SetSurroundSound(const string& surroundsound) {
		if (surroundsound.empty()) {
			Exceptions::writeExceptionsToFile("The surroundsound is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The surroundsound is empty", __LINE__, __FILE__);
		}
		_surroundSound = surroundsound;
	}
	void SetSpikerDriverSize(const double& spikerdriversize) {
		if (spikerdriversize < 0) {
			Exceptions::writeExceptionsToFile("The battery cannot be negative.", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The battery cannot be negative.", __LINE__, __FILE__);
		}
		_spikerDriverSize = spikerdriversize;
	}
	void SetSoundQuality(const string& soundquality) {
		if (soundquality.empty()) {
			Exceptions::writeExceptionsToFile("The soundquality is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The soundquality is empty", __LINE__, __FILE__);
		}
		_soundQuality = soundquality;
	}
	void Print()override {
		Product::Print();
		cout << "Computer Platform: " << _computerPlatform << endl;
		cout << "Surround Sound: " << _surroundSound << endl;
		cout << "Spiker Driver Size: " << _spikerDriverSize <<" mm"<< endl;
		cout << "Sound Quality: " << _soundQuality << endl;
	}


};