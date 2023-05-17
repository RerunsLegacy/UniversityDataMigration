#include <iostream>
#include <string>
#include "roster.h"



//Public
void Roster::parse(string studentData)
{
	/*Parse*/
	int rhs = (int)studentData.find(",");
	string student_id = studentData.substr(0, rhs);

	int lhs = rhs + 1;
	rhs = (int)studentData.find(",", lhs);
	string first_name = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = (int)studentData.find(",", lhs);
	string last_name = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = (int)studentData.find(",", lhs);
	string email_address = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = (int)studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = (int)studentData.find(",", lhs);
	int day_one = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = (int)studentData.find(",", lhs);
	int day_two = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = (int)studentData.find(",", lhs);
	int day_three = stoi(studentData.substr(lhs, rhs - lhs));

	DegreeProgram degree_program = SECURITY;
	if (studentData.at(rhs+4) == 'T') degree_program = SOFTWARE;
	else if (studentData.at(rhs+4) == 'W') degree_program = NETWORK;

	add(student_id, first_name, last_name, email_address, age, day_one, day_two, day_three, degree_program);

};

void Roster::add(string student_id, string first_name, string last_name, string email_address, int age, int day_one, int day_two, int day_three, DegreeProgram degree_program)
{
	int day_array[3] = { day_one, day_two, day_three };

	studentRoster[++lastI] = Student(student_id, first_name, last_name, email_address, age, day_array, degree_program);
};

/*Print All*/
void Roster::printAll()
{
	cout << "Print All: \n";
	for (int i = 0; i < Roster::number_of_students; i = i + 1)
	{
		studentRoster[i].print();
		cout << "\n";
	}
};

/*Print Invalid Emails*/
void Roster::printInvalidEmails()
{
	cout << "Invalid Emails: \n";
	for (int i = 0; i < Roster::number_of_students; i = i + 1) 
	{
		string email_address = (studentRoster[i].getemail_address());
		
		if (email_address.find(' ') == string::npos &&
			(email_address.find("gmailcom") == string::npos &&
				email_address.find('_') == string::npos)) { }
		
		else 
		{
			cout << email_address << ": " << studentRoster[i].getfirst_name() << endl;
		}
	}
};

/*Print Average Days In Course*/
void Roster::printAverageDaysInCourse(string student_id)
{
	for (int i = 0; i <= Roster::lastI; i = i + 1)
	{
		cout << studentRoster[i].getstudent_id() << ": ";
		cout << (studentRoster[i].getdays_in_course()[0] + studentRoster[i].getdays_in_course()[1] + studentRoster[i].getdays_in_course()[2])/3 << endl;
	}
};


/*Print By Degree Program*/
void Roster::printByDegreeProgram(DegreeProgram degree_program)
{
	for (int i = 0; i <= Roster::number_of_students; i = i + 1)
	{
		if (Roster::studentRoster[i].getdegree_program() == degree_program)
			studentRoster[i].print();
	}
	cout << std::endl;
};


/*Remove Student A3*/
void Roster::removeStudent(string student_id)
{
	
	bool success = false;
	for (int i = 0; i < number_of_students; i = i + 1) 
	{
		
		if (studentRoster[i].getstudent_id() == student_id) 
		{
			success = true;
			Student* newRoster = new Student[number_of_students - 1];
			for (int j = 0; j < number_of_students - 1; j=j+1) 
			{
				if (j < i) 
				{
					newRoster[j] = studentRoster[j];
				}
				else if (j >= i) 
				{
					newRoster[j] = studentRoster[j + 1];
				}
			}
			studentRoster = newRoster;
			Roster::number_of_students--;
			Roster::lastI--;
			break;
		}
	}
	if (success)
	{
		cout << "Removing Student " << student_id << endl;
		printAll();
	}
	else cout << "Student " << student_id << " was not found" << endl;
};
