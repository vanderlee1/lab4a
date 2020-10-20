/*
Rebecca van der Lee
C++ Fall 2019
Lab 4 Temperature Output
Design and write a C++ program that inputs a series of hourly temperature from a file, and outputs a bar chart (using stars) of the temperatures. The temperature should be
printed to the left of the corresponding bar, and there should be a heading that gives the scale of the chart. The range of temperatures should be from  -30 to 120. Because
it is hard to display 150 characters on the screen, you should have each star represent a range of 3 degrees. That way, the bars will be at most 50 characters wide. Use
meaningful variable names, proper indentation, and appropriate comments. Thoroughly test the program using your own data sets. Make sure to vet the values from the input
file.

*/



#include <iostream>// standard needed for c++
#include <iomanip> // to calculate the functions
#include <string> //for string
#include <fstream> //for file input
using namespace std;



//function prototype

void table(); //preconditions: runs withour returning to 1, postcondition text of the table chart is outputted on the screen
 

void positivevalues(float); //precondition file stream must be valid, and tempvalues will meet meet >=0, 
                            //postcondition tempvalues will be outputted on the screen then count controlled loop will run and stars will be on the screen through stars,
                            //flow of control returns to the main function

void negativevalues(float);//precondition tempvalues must be valid, file stream must be valid, and tempadata will meet <0
                           //postcondition tempvalues will be outputted on the screen then count controlled loop will run and stars will be on the screen through stars, 
                           //flow of control returns to the main function



int main()
{
	float tempvalues; //variable for the temperatures from the file

	string Text = "C:/Users/VANDERLEE1/source/repos/lab4a/lab4a/Text.txt";
	ifstream infile;
	infile.open(Text);
	infile >> tempvalues;


	// This will check is if the file can be opened if it cannot be opened it will output on the screen that the the inut file failed.
	if (!infile)
	{
		cout << "Input file failed";
		return 0;
	}


	if (!infile)  //This statetement will check if all values are numbers. If the values are charcters it will output on the screen that the user should not use characters
	{
		cout << "Input file error, please do not use characters" << endl;
		return 0;
	}


	table();


	while (infile) // End-of-of-file-controlled-loop, this displays the bar chart on the screen.
	{

		if (tempvalues < -30 || tempvalues > 120) //evaluates "tempvalues" is within the valid range. It will output: is an invalid temperature when not in range
		{
			cout << setw(8) << tempvalues << " This is an invalid temperature" << endl;
		}
		
			if (tempvalues < -30 || tempvalues > 120) //end of file controlled loop. This will give the range of numbers whcih is -30-120
			{
				cout << setw(8) << tempvalues << " This is not a valid temperature" << endl;
			}

			else if (tempvalues >= 0)  //Nested if statement calls the postive function when values in the document are postive. 
			{
				positivevalues(tempvalues);
			}
			else if (tempvalues < 0)  //Nested statement which calls the negative function when values in the document are negative. 
			{
				negativevalues(tempvalues);
			}

			infile >> tempvalues; //reads the next value from the docutment

			



		

	}
	 return 0;
}


void table() //definition table function
{
	string space = "        ";

	cout << "Temperatures for 24 hours ('*' represents 3 degrees) :" << endl;
	cout << "        " << -30 << space << "0" << space << "30" << space << "60" << space << "90" << space << "120" << endl;
}






void positivevalues(float tempvalues) //function definition for positveevalues, it uses the tempvalues variable 
{                                 
	int count1 = 1;
	float star = (tempvalues / float(3)); //the star variable defines the number of stars which should be outputted on the screen
										
	cout << setw(8) << tempvalues;
	cout << "           |";             
										

	while (count1 <= int(star + 0.5))   //sets the temperature and spac
	{                                   
		cout << "*";                   
		count1++;
		if (count1 > int(star + 0.5))  //count controlled loop outputs the temperature rounded to the nearest integer
		{
			cout << endl;
		}
	}
}

void negativevalues(float tempvalues) //function definition for negativevalues, it uses the tempvalues variable 
{                                
	int count1 = 1;
	float star = (tempvalues / float(3)); //the star variable defines the number of stars which should be outputted on the screen
										
	cout << setw(8) << tempvalues;
	cout << setw(int(star - 0.5) + 12);   //sets the temperature and space
										

	while (count1 <= int((-(star)) + 0.5)) //count controlled loop outputs the temperature rounded to the nearest integer
	{                                     
		cout << "*";                       
										  
		count1++;
		if (count1 > int((-(star)) + 0.5))
		{
			cout << "|" << endl;
		}
	}
}

