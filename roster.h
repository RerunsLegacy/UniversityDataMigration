
#include "student.h"

class Roster
{
private:

	int lastI = -1;
	int number_of_students = 5;
	Student* studentRoster;


public:

	Roster() { studentRoster = new Student[number_of_students]; }
	void parse(string row);
	void add(string student_id, string first_name, string last_name, string email_address, int age, int day_one, int day_two, int day_three, DegreeProgram degree_program);
	void printAll();
	void printInvalidEmails();
	void printAverageDaysInCourse(string student_id);
	void printByDegreeProgram(DegreeProgram degree_program);
	void removeStudent(string student_id);
};
