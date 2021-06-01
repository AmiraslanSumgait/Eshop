#pragma once
#include"Admin.h"
#include"Guest.h"
#include"Product.h"
#include<list>
template<typename T>
class DbSet {
	int count = 0;
	list<T>items;
public:
	list <T> GetItems()const {
		return items;
	}
	void Print() {
		for (auto& i : items)
		{
			i->Print();
		}
	}
	bool ItemsListEmpty() {
		if (items.empty()) {
			return true;
		}
		return false;
	}
	bool isExistsItem(const size_t id) {
		if (id < 0) {
			throw Exceptions::InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		}
		for (auto& item : items)
		{
			if (id == item->getId()) return true;
		}
		return false;
	}
	T* getItem(const int& id) {
		if (id < 0) throw Exceptions::InvalidArgumentException("Id cannot be negative.", __LINE__, __FILE__);
		for (auto& i : items)
		{
			if (i->getId == id) return i;
		}
		throw Exceptions::DatabaseException("Product not found !", __LINE__, __FILE__);
	}
	void add(T item) {
		items.push_back(item);
	}
	void DeleteItem(T item) {
		items.remove(item);
	}
	bool isExistItemWithName(string name) {
		for (auto& i : items)
		{
			if (i->getName() == name) return true;
		}
		return false;
	}
	bool isExistItemWithPassword(string password) {
		for (auto& i : items)
		{
			if (i->getPassword() == password) return true;
		}
		return false;
	}
	void deleteItem( int& id) {
		if (id < 0) {
			Exceptions::writeExceptionsToFile("Id must be greater than 0", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("Id must be greater than 0", __LINE__, __FILE__);
		}
		else if (isExistsItem(id)) {
			auto iter = items.begin();
			advance(iter, id - 1);
			items.erase(iter);
		}
		else {
			Exceptions::writeExceptionsToFile("Incorrect id", __LINE__, __FILE__);
			throw Exceptions::InvalidArgumentException("Incorrect id", __LINE__, __FILE__);
		}
		

	}
};
struct Database {
	DbSet<Product*> products;
	DbSet<Admin*> admins;
	DbSet<Guest*> guests;
	DbSet<Product*>cart;
	Database() = default;
	DbSet<Admin*> getAdmins()const {
		return admins;
	}

	DbSet<Guest*> getGuests()const {
		return guests;
	}
	DbSet<Product*> getCart()const {
		return cart;
	}
	DbSet<Product*> getProducts()const {
		return products;
	}
	~Database() {
		for (auto& i : admins.GetItems())
		{
			delete[] & i;
		}
		for (auto& i : guests.GetItems())
		{
			delete[] & i;
		}
		for (auto& i : products.GetItems())
		{
			delete[] & i;
		}
		for (auto& i : cart.GetItems())
		{
			delete[] & i;
		}
	
	}
};

