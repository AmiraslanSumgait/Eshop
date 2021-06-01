#pragma once

	class Person {
	private:
		static int ID;
		int thisId;
	public:
		Person()
		{
			thisId = ++ID;
		}
		int getId() {
			return thisId;
		}
		virtual void Print() {
			cout << "Id: " <<thisId<< endl;
		}
		virtual ~Person() = 0 {

		}


	};

int Person::ID =50;