#pragma once
#include"Category.h"
class PhoneCategory :public Category {
public:
	PhoneCategory() = default;

	PhoneCategory(const int& id, const string& name)
	{
		SetId(id);
		SetName(name);
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
};