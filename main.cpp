#include "roster.h"

int main()
{
	cout <<
		"Course: Scripting and Programming - Applications - C867" << endl;
	cout <<
		"Programing Language: C++" << endl;
	cout <<
		"Student ID:004472910" << endl;
	cout <<
		"Student Name: Samuel Rohan" << endl;
	cout << endl;



	const string studentData[5] =
	{
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Samuel,Rohan,srohan1@wgu.edu,21,31,42,53,SOFTWARE"
	};

	const int number_of_students = 5;
	Roster roster;

	cout << "Print All \n";
	for (int i = 0; i < number_of_students; i = i + 1) roster.parse(studentData[i]);
	roster.printAll();
	cout << endl;

	cout << "Print Invalid Emails\n";
	roster.printInvalidEmails();
	cout << endl;
	
	cout << "Print Average Days In Course\n";
	roster.printAverageDaysInCourse("All");
	cout << endl;

	cout << "Print By Degree Program (SOFTWARE) \n";
	roster.printByDegreeProgram(SOFTWARE);
	cout << endl;

	cout << "Remove Student A3\n";
	roster.removeStudent("A3");
	cout << endl;

	cout << "Student A3 Removed \n";
	roster.removeStudent("A3");
	cout << endl;
}
