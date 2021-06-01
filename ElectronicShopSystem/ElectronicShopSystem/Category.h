#pragma once
#include "Exceptions.h"
class Category {
protected:
	int _cId;
	string _cName;
public:
	Category():_cId(),_cName() {

	}
	Category(const int&id,const string&name)
	{
		SetId(id);
		SetName(name);
	}
	int getId() {
		return _cId;
	}
	string getName() {
		return _cName;
	}
	void SetId(const int& id) {
		
		if (id <= 0) {
			Exceptions::writeExceptionsToFile("The id must be greater than 0.", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The id must be greater than 0.", __LINE__, __FILE__);
		}
		_cId = id;
	}
	void SetName(const string& name) {
		if (name.empty()) {
			Exceptions::writeExceptionsToFile("The name is empty", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("The name is empty", __LINE__, __FILE__);
		}
		_cName = name;
	}
	virtual ~Category() = 0 {

	}
};