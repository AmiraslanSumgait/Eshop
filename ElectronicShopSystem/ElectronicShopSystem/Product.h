#pragma once
#include<string>
#include"Exceptions.h"
using namespace std;

	class Product {
	private:
		static int ID;
		int _thisId;
		int _categoryId;
		string _name;
		string _description;
		double _price;
		double _tax;
		double _discount;
		int _quantity;
	public:
		
		Product():_categoryId(),_name(),_price(),_tax(),_discount(),_quantity()
		{
			
		}
		Product(const int&categoryId,const string& name,const string&description,const double&price,const double&tax,const double&discount,const int&quantity)
		{
			_thisId = ++ID;
			SetCategoryId(categoryId);
			SetName(name);
			SetDescription(description);
			SetPrice(price);
			SetTax(tax);
			SetDiscount(discount);
			SetQuantiy(quantity);
		}
		int getId()const { return _thisId; }
		const string& getName() const { return _name; }
		const string& getDescription() const { return _description; }
		double getPrice() const { return _price; }
		double getDiscount() const { return _discount; }
		int getCategoryId()const { return  _categoryId; }
		double getTax() const { return _tax; }
		int getQuantity() const { return _quantity; }
		void SetId(const int& id) {
			
			if (id <= 0) {
				Exceptions::writeExceptionsToFile("The id must be greater than 0.", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The id must be greater than 0.", __LINE__, __FILE__);
			}
			_thisId = id;
		}
		void SetCategoryId(const int& categoryId) {
			
			if (categoryId <= 0) {
				Exceptions::writeExceptionsToFile("The categoryId must be greater than 0.", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The categoryId must be greater than 0.", __LINE__, __FILE__);
			}
			_categoryId = categoryId;
		}
		void SetName(const string& name) {
			
			if (name.empty()) {
				Exceptions::writeExceptionsToFile("The name is empty", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The name is empty", __LINE__, __FILE__);
			}
			_name = name;
		}
		void SetDescription(const string& description) {
			if (description.empty()) {
				Exceptions::writeExceptionsToFile("The description is empty", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The description is empty", __LINE__, __FILE__);
			}
			_description = description;
		}
		void SetPrice(const double &price) {
			if (price < 0) {
				Exceptions::writeExceptionsToFile("The price cannot be negative.", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The price cannot be negative.", __LINE__, __FILE__);
			}
			_price = price;
		}
		void SetTax(const double& tax) {
			if (tax < 0 && tax > 100) {
				Exceptions::writeExceptionsToFile("The tax should be between 0 and 100.", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The tax should be between 0 and 100.", __LINE__, __FILE__);
			}
			_tax = tax;
		}
		void SetDiscount(const double& discount) {
			
			if (discount < 0 && discount > 100) {
				Exceptions::writeExceptionsToFile("The discount should be between 0 and 100.", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The discount should be between 0 and 100.", __LINE__, __FILE__);
			}
			_discount = discount;
		}
		void SetQuantiy(const int& quantity) {
			if (quantity < 0) {
				Exceptions::writeExceptionsToFile("The price cannot be negative.", __LINE__, __FILE__);
				throw Exceptions::InvalidArgumentException("The price cannot be negative.", __LINE__, __FILE__);
			}
			_quantity = quantity;
		}
		virtual void Print() {
			cout << "--------Id:" << _thisId <<"--------"<< endl;
			cout << "Category Id: " << _categoryId << endl;
			cout << "Name: " << _name << endl;
			cout << "Description: " << _description << endl;
			cout << "Price:  " << _price <<" Azn"<< endl;
			cout << "Tax:  " << _tax << endl;
			cout << "Discount:  " << _discount << endl;
			cout << "Quantity:  " << _quantity << endl;
		}
		virtual void previewPrint() {
			cout << "--------Id:" << _thisId << "--------" << endl;
			cout << "Category Id: " << _categoryId << endl;
			cout << "Name: " << _name << endl;
			cout << "Price: " << _price << endl;
			cout << "Description: " << _description << endl;
			cout << "Quantity: " << _quantity << endl;
			cout << "Tax: " << _tax << endl;
		}
		virtual ~Product() = 0 {

		}
		
	};
	int Product::ID = 0;
