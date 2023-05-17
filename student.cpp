#include "student.h"
using namespace std;


Student::Student()
{
	p_student_id = "";
	p_first_name = "";
	p_last_name = "";
	p_email_address = "";
	p_age = 0;
	for (int i = 0; i < 3; i = i + 1)
	{
		p_days_in_course[i] = 0;
	}
	p_degree_program = SECURITY;
}

//Student constructor
Student::Student(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree_program)
{
	SetStudent(student_id, first_name, last_name, email_address, age, days_in_course, degree_program);
}

//Student function
void Student::SetStudent(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree_program)
//Public to Private
{
	p_student_id = student_id;
	p_first_name = first_name;
	p_last_name = last_name;
	p_email_address = email_address;
	p_age = age;
	for (int i = 0; i < 3; i = i + 1)
		{p_days_in_course[i] = days_in_course[i]; }
	p_degree_program = degree_program;
}

string Student::getstudent_id() {
	return p_student_id;
}

string Student::getfirst_name()
{
	return p_first_name;
}

string Student::getlast_name()
{
	return p_last_name;
}

string Student::getemail_address()
{
	return p_email_address;
}

int Student::getage()
{
	return p_age;
}

int* Student::getdays_in_course()
{
	return p_days_in_course;
}

DegreeProgram Student::getdegree_program()
{
	return p_degree_program;
}


void Student::setstudent_id(string p_student_id) {
	this->p_student_id = p_student_id;}
void Student::setfirst_name(string p_first_name) { 
	this->p_first_name = p_first_name; }
void Student::setlast_name(string p_last_name) {
	this->p_last_name = p_last_name;}
void Student::setemail_address(string p_email_address) { 
	this->p_email_address = p_email_address; }
void Student::setage(int p_age) { 
	this->p_age = p_age; }
void Student::setdays_in_course(int p_days_in_course) {
	for (int i = 0; i < 3; i = i + 1) { this->p_days_in_course[i] = p_days_in_course; }}
void Student::setdegree_program(DegreeProgram degree_program) {
	this->p_degree_program = p_degree_program; }


void Student::print()
{
	    cout << this->getstudent_id() << '\t';
		cout << this->getfirst_name() << '\t';
		cout << this->getlast_name() << '\t';
		cout << this->getemail_address() << '\t';
		cout << this->getage() << '\t';
		cout << this->getdays_in_course()[0] << ',';
		cout << this->getdays_in_course()[1] << ',';
		cout << this->getdays_in_course()[2] << '\t';
		if (this->getdegree_program() == SECURITY) {
			cout << "SECURITY \t\n";
		}
		if (this->getdegree_program() == NETWORK) {
			cout << "NETWORK \t\n";
		}
		if (this->getdegree_program() == SOFTWARE) {
		cout << "SOFTWARE \t\n";
		}
}
		
