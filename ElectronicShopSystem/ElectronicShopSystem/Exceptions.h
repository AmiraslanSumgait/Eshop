#pragma once
#include<iostream>
#include<fstream>
using namespace std;
namespace Exceptions {
	class Exception {
	protected:
		string text;
		int line;
		string file;
		string createdTime;
		Exception(const string& text, const int line, const string& file)
		{
			setText(text);
			setLine(line);
			setFile(file);
			setTime();
		}
		string getText()const {
			return text;
		}
		int getLine()const {
			return line;
		}
		string getFile()const {
			return file;
		}
		string getTime()const {
			return createdTime;
		}

		void setText(const string& text) {
			if (text.empty()) throw "Text is empty";
			this->text = text;
		}
		void setLine(const int line) {
			if (line < 0) throw "Line must be positive";
			this->line = line;
		}
		void setFile(const string& file) {
			if (file.empty()) throw "Source is empty";
			this->file = file;
		}
		void setTime() {
			time_t currently = time(0);
			char dt[30]{};
			ctime_s(dt, sizeof dt, &currently);
			string time = dt;

			this->createdTime = dt;
		}

	public:
		void PrintMsg()const {
			cout << endl;
			cout << "Text:" << getText() << endl;
			cout << "Line:" << getLine() << endl;
			cout << "Source:" <<getFile() << endl;
			cout << "Time: " << getTime() << endl;
		}
	};
	class InvalidArgumentException :public Exceptions::Exception {
	public:
		InvalidArgumentException(const string& text, const int line, const string& source)
			:Exception(text, line, source)
		{

		}
	};
	class DatabaseException :public Exceptions::Exception {
	public:
		DatabaseException(const string& text, const int line, const string& source)
			:Exception(text, line, source)
		{

		}
	};
	void writeExceptionsToFile(const string& exceptionText, const int& line, const string& file) {
		ofstream fout("FileExceptions.txt", ios_base::app);
		if (!fout) throw InvalidArgumentException("File not found", __LINE__, __FILE__);
		if (fout.is_open()) {
			fout << "Text: " << exceptionText << endl;
			fout << "Line: " << line + 1 << endl;
			fout << "Source: " << file << endl;
			fout << "Date and Time: " << __TIMESTAMP__ << endl;
			cout << endl;
		}
		else {
			throw InvalidArgumentException("File not open!", __LINE__, __FILE__);
		}
		fout.close();
	}
	
	
}





