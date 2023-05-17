
#include <string>
#include <iostream>
#include "degree.h"
using namespace std;

//Create class "student"
class Student
{

//Private
private:
	string p_student_id;
	string p_first_name;
	string p_last_name;
	string p_email_address;
	int p_age;
	int p_days_in_course[3];
	DegreeProgram p_degree_program;
	
	
//Public
public:
	
	
Student();
	//Constructor
Student(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree_program);

	void SetStudent(string student_id, string first_name, string last_name, string email_address, int age, int days_in_course[], DegreeProgram degree_program);
	
	//Getters
	string getstudent_id();
	string getfirst_name();
	string getlast_name();
	string getemail_address();
	int getage();
	int* getdays_in_course();
	DegreeProgram getdegree_program();

	//Setters
	void setstudent_id(string p_student_id);
	void setfirst_name(string p_first_name);
	void setlast_name(string p_last_name);
	void setemail_address(string p_email_address);
	void setage(int p_age);
	void setdays_in_course(int p_days_in_course);
	void setdegree_program(DegreeProgram p_degree_program);

	void print();
	
};
