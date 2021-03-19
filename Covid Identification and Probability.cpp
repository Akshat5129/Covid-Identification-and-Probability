/*
Problem statement:

For the assigned key area, a fully redesigned code with the appropriate input parameters and 
the expected output with all the concepts of the object-oriented programming to be done.

Task to be performed:

Apply the concepts of OOP for the given problem statement.
Apply the features of OOP for the given problem statement.
Apply the advanced feature of OOP for the problem statement.
Fully functioning application with the appropriate input parameter and the expected output.*/


#include <iostream>
#include <conio.h>
#include <fstream>
#include <string.h>
#include <stdlib.h>
using namespace std;
class details {                                          //base class for details
	public:
		string name, g, add, bg, mob;
		void user_details() {                            //Details of the user
			system("Color F9");
			cout << "Enter your name -> ";
			cin >> name;
			cout << "Gender -> ";
			cin >> g;
			cout << "Enter city name -> ";
			cin >> add;
			cout << "Enter blood group -> ";
			cin >> bg;
		}
		void user_details(int age) {
			cout << "Enter Age -> ";
			cin >> age;
		}
		// exception handling
		char a[10];
		int error;
		void user_num() {

			do {
				cout << "Enter your number -> ";
				cin >> a;
				try {
					if (strlen(a) != 10)

						throw "\nPlease enter a valid 10 digit number example - 9826945611\n";
					error = 0;
					//cout<<"your number - "<<a;
				} catch (const char* b) {
					cout << "\nIvalid number" << b;
					error = 1;
				}
			} while (error);
		}

		//Polymorphism - the condition of occurring in several different forms.
	public:
		void detail() { //method to call user datails
			//function overriding
			user_details();
			user_num();
			user_details(1); //method with different signature
		}
};
class health_issues : public details { //derived class 1 - multilevel inheritance
	public:
		health_issues() { //Constructor
			cout << "              |------------------------------------------------------------------------------|\n";
			cout << "              |               Welcome to the Covid Identification Application                |\n";
			cout << "              |------------------------------------------------------------------------------|\n";
			cout << "\n\n                  << Please register your details before using the application >>     \n\n";
		}
		//Encapsulation - Binding the hospital_details() and functions and hiding them from the outside world.
	private:
		string med[9] = { "asthma", "chronic obstructive pulmonary disease (COPD)", "emphysema or bronchitis", "chronic heart disease",
		                  "kidney disease", "brain stroke", "A weakened immune system", "HIV and AIDS", "diabetes"
		                };
		string med_1, yes, no, y, n, Y, N;
		void pre_med_condition() {
			cout << "\nDo you have any pre medical conditions? Yes or No. Please Enter\n>> ";
			cin >> med_1;

			if (med_1 == "yes" || med_1 == "Y" || med_1 == "y" || med_1 == "Yes") {
				for (int i = 0; i < 9; i++) {
					cout << i + 1 << " " << med[i] << "\n";
				}
				int values;
				int i;
				int max = 0;
				cout << "Enter number of medical conditions you have - ";
				cin >> values;

				int arr[values];
				for (i = 0; i < values; i++) {
					cout << "Enter the index of medical conditions - ";
					cin >> arr[i];
				}
			} else if (med_1 != "yes" || med_1 != "Y" || med_1 != "y" || med_1 != "Yes") {
				cout << "Continue to Symptoms";
			}
		}

		string sym[6] = { "fever", "dry cough", "tiredness", "difficulty breathing or shortness of breath",
		                  "chest pain or pressure", "loss of speech or movement"
		                };
		string sym_1;
		int value_1;
		void symptoms() {
			{
				cout << "\nDo you have any symptoms? Yes or No. Please Enter\n";
				cin >> sym_1;

				if (sym_1 == "yes" || sym_1 == "Y" || sym_1 == "y" || sym_1 == "Yes")

				{
					for (int j = 0; j < 6; j++) {
						cout << j + 1 << " " << sym[j] << "\n";
					}
					int j;
					int max = 0;
					cout << "Enter the number of symptoms - ";
					cin >> value_1;

					int arr[value_1];
					for (j = 0; j < value_1; j++) {
						cout << "Enter the index of Symptoms - ";
						cin >> arr[j];
					}
				} else if (sym_1 != "yes" || sym_1 != "Y" || sym_1 != "y" || sym_1 != "Yes") {
					cout << "Continue to causes\n";
				}
			}
		}
		string caus_1, caus_2;
		void causes() {
			cout << "\nWhat are the causes?\n";
			cout << "\n1-  Have you travelled anywhere internationally in the last14 days? y/n\n>> ";
			cin >> caus_1;
			cout << "Which of the following applies to you?\n";
			cout << "1 - I have recently interacted or lived with someone who has tested positive for COVID-19\n2 - I am a healthcare worker and I examined a COVID-19 confirmed case without protective gear.\n3 - None of the above\n>> ";
			cin >> caus_2;
			{
				cout << "\n------------Health Assesment Completed-------------\n\n\nAdvice is given on the basis of your assesment and we will be forwarding your details to government.\n";
			}
		}

		void advice() {
			// inner if condition for symptoms
			if (value_1 <= 2) {
				cout << "\nYou are at low risk but you can take doctor's consultation." << endl;
				cout << "\nYou can find our hospital details from the main menu." << endl;
			} else if ((value_1 >= 3 && value_1 <= 6)) {
				cout << "\nYou are at high risk. You need to get treatment ASAP!" << endl;
				cout << "\nYou can see our hospital branches from main menu in the hospital details." << endl;
			}

			else if (sym_1 == "no" || sym_1 == "N" || sym_1 == "n" || sym_1 == "No") {
				cout << "\nYou don't have any risk but you should follow general precautions to avoid risks.'" << endl;
			}
		}

	protected:
		void operator++() { //opeartor overloading - The operator calls
			pre_med_condition();
			symptoms();
			causes();
			advice();
		}
		~health_issues() { //Destructor to delete the object
			cout << "\n\n-------------Thank You for using our application---------------\n";
		}
};

class data : public health_issues { //derived class 2 for hospital details
	public:
		//Hospital branches
		void general_precautions() {
			cout << "\n-----------General Advice that you should follow-----------\n";

			cout << "\n1. Regularly and thoroughly clean your hands with an alcohol-based hand rub or wash them with soap and water.\n";
			cout << "\n2. Maintain at least 1 metre (3 feet) distance between yourself and others.\n";
			cout << "\n3. Avoid going to crowded places.\n";
			cout << "\n4. Stay home and self-isolate even with minor symptoms such as cough, headache, mild fever, until you recover. Have someone bring you supplies. If you need to leave your house, wear a mask to avoid infecting others.\n";
			cout << "\n5. Make sure you, and the people around you, follow good respiratory hygiene. This means covering your mouth and nose with your bent elbow or tissue when you cough or sneeze. Then dispose of the used tissue immediately and wash your hands. \n";
			cout << "\n6. If you have a fever, cough and difficulty breathing, seek medical attention, but call by telephone in advance if possible and follow the directions of your local health authority. \n";
			cout << "\n7. Avoid touching eyes, nose and mouth.\n";
		}
		void hospital_details() {
			cout << "         \n-----------------Hospital Details-----------------------------";

			cout << "\nName - Narayana Multispeciality Hospital\nAddress: Police Station, Nr. Chakudiya Mahadev, Cross Rd, opp. Rakhial, Rakhial, Ahmedabad, Gujarat 380023\nPhone: 080675 06878\n";
			cout << "\nName - SANNIDHYA MATERNITY & MULTISPECIALITY HOSPITAL IN AHMEDABAD\nAddress: 4th Floor, Orchid Centre, opp. Safal Parisar Road, South Bopal, Ahmedabad, Gujarat 380058\nPhone: 091575 03000\n";
			cout << "\nName - Zydus Hospitals\nAddress: Zydus Hospitals Road, Nr. Sola Bridge, Sarkhej - Gandhinagar Hwy, Ahmedabad, Gujarat 380054\nPhone: 079 6619 0201\n";
			cout << "\nName - Sterling Hospital\nAddress: Sterling Hospital Road near Maharaja Agrasen Vidhyalaya, Memnagar, Ahmedabad, Gujarat 380052\nPhone: 079 4001 1111\n";
			cout << "\nName - CIMS Hospital\nAddress: Science City Rd, Science City, Panchamrut Bunglows II, Sola, Ahmedabad, Gujarat 380060\nPhone: 098250 66664\n";
		}
};
class file_handle : public data { //derived class 3
		string display, text, r;
		char m;
		void show_data() {
			cout << "\nDo you want to see the stored data - (y/n)  " << endl;
			cin >> m;
			if (m == 'y' || m == 'Y') {
				cout << "\n\n---------------------User details to be stored--------------------\n";
				cout << "\nName - " << name;
				cout << "\nGender - " << g;
				cout << "\nBlood group -" << bg;
				cout << "\nMobile number - " << a;
				cout << "\nCity - " << add;
				cout << "\n---------------------------------------------------------------------\n";
			}
		}

	protected:
		void file_exe() //File Handling
		//File handling is used to display the user details that user inputs whean the program asks for details.
		{
			fstream file;
			file.open("user_details.txt", ios_base::app); //ios_base::app is used to append data in the file

			file << name << "\n" << a << "\n" << g << "\n" << add << "\n" << bg << "\n" << endl;

			//closing the file
			file.close();

			file.open("user_details.txt", ios::ate);
			//closing the file
			while (getline(file, text)) {
				cout << text;
			}
			file.close();

			show_data(); //function call to show data
		}
};
class Menu : public file_handle { //derived class 4
	public:
		int m;
		void menu() {
			while(1) {
				cout << "\n\n We provide the following services ~\n" << endl;
				cout << "      1. Self- Health Assesment\n" << endl;
				cout << "      2. Hospital Details\n" << endl;
				cout << "      3. General Precautions\n" << endl;
				cout << "      4. Quit\n" << endl;
				cout << " Please select the type of help you want (1/2/3/4)\n>>  ";
				cin >> m;
				if (m <= 0 || m > 4) {
					cout << "Invalid input" << endl;
					return;
				} else if (m == 1) {
					++(*this);
					file_exe();
				} else if (m == 2) {
					hospital_details();
					file_exe();
				} else if (m == 3) {
					general_precautions();
					file_exe();
				} else if (m == 4)
					break;
			}
		}
};

int main() { //Main function containing all the methods
	Menu object;
	object.detail();
	object.menu();
	return 0;
}

