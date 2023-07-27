#include<iostream>
#include<fstream>
#include<cctype>
using namespace std;

/*
Structure is used to help organise and store guest data. 
*/
struct Guest {
	int No = 1;
	string Date, Time;
	string Name;
	string Room;
	int Days = 1;
	double Spend = 0;
};

int main()
{
	int x = 1;
	char again;

	while (x == 1) {
		/* Welcome */
		cout << "^_^ Welcome to ABC Hotel ^_^" << endl << endl;

		/* Show menu */
		cout << "_____________________________________" << endl;
		cout << "Available room types. " << endl;
		cout << "_____________________________________" << endl;
		cout << "Room type\tPrice per night (RM)" << endl;
		cout << "Standard (S)\t250" << endl;
		cout << "Deluxe (D)\t300" << endl;
		cout << "Family (F)\t450" << endl;
		cout << "Executive (E)\t600" << endl;
		cout << "_____________________________________" << endl << endl;

		/* Room types */
		/*
		Store types of rooms offered by hotel in structure so that room type and price are linked. 
		Easier to refer room types and price when needed later on. 
		New room types can be added easily to the structure and linked with its price for ease of use. 
		*/
		struct {
			string roomtype;
			int price = 0;
		}Standard, Deluxe, Family, Executive;

		Standard.roomtype = "Standard";		// Standard room
		Standard.price = 250;

		Deluxe.roomtype = "Deluxe";			// Deluxe room
		Deluxe.price = 300;

		Family.roomtype = "Family";			// Family room
		Family.price = 450;

		Executive.roomtype = "Executive";		// Executive room
		Executive.price = 600;

		/* Guest information */
		char GuestName[50];
		char RoomType, ROOMTYPE, BookType, BOOKTYPE;
		int NumDays;

		cout << "Your name? " << endl;		// Name
		cin.getline(GuestName, sizeof(GuestName)); 

		/*
		Prompt user for desired room type, include toupper function to convert all inputs to upper case for formatting purposes. 
		Include while loop for error checking of user inputs to ensure input corresponds with rooms offered. 
		*/
		cout << "Type of room: (Please enter the corresponding letter to room type.)" << endl;	// Room
		cin >> RoomType;
		ROOMTYPE = toupper(RoomType);
		while (ROOMTYPE != 'S' &&
			ROOMTYPE != 'D' &&
			ROOMTYPE != 'E' &&
			ROOMTYPE != 'F') {
			cout << "Please enter the corresponding letter to the desired room type. " << endl;
			cin >> RoomType;
			
			ROOMTYPE = toupper(RoomType);
		}

		/*
		Prompt user for number of days they wish to stay. 
		Include while loop for error checking and request user to input correct data if characters, strings or numbers less than zero are input. 
		*/
		cout << "How many days are you staying? " << endl;		// Days
		cin >> NumDays;
		while (x == 1) {
			if (cin.fail() || NumDays < 1) {
				cout << "Please enter a positive integer. " << endl;
				cin.clear();
				cin.ignore(256, '\n');
				cin >> NumDays;

			}
			else if (cin.good()) {
				x = 0;
			}
		}

		/*
		Prompt user for booking type to give discount, include toupper function to convert all inputs to upper case for formatting purposes. 
		Include while loop for error checking, only accept 'O' and 'M' as inputs. 
		*/
		cout << "Are you booking online or manually? ('O' for online, 'M' for manually)" << endl;	// Booking type
		cin >> BookType;
		BOOKTYPE = toupper(BookType);
		while (BOOKTYPE != 'O' &&
			BOOKTYPE != 'M') {
			cout << "Please enter 'O' for online or 'M' for manually. " << endl;
			cin >> BookType;
			BOOKTYPE = toupper(BookType);
		}

		/* Calculation */
		/*
		Calculating payments based on chosen room type by referring to the structure above. 
		*/
		int rate;
		double taxrate = 0.08, TaxAmount, TotalPayment = 0, TotalDiscount = 0;
		if (ROOMTYPE == 'S') {
			rate = NumDays * Standard.price;
			TaxAmount = rate * taxrate;
			TotalPayment = rate + TaxAmount;
		}
		else if (ROOMTYPE == 'D') {
			rate = NumDays * Deluxe.price;
			TaxAmount = rate * taxrate;
			TotalPayment = rate + TaxAmount;
		}
		else if (ROOMTYPE == 'F') {
			rate = NumDays * Family.price;
			TaxAmount = rate * taxrate;
			TotalPayment = rate + TaxAmount;
		}
		else if (ROOMTYPE == 'E') {
			rate = NumDays * Executive.price;
			TaxAmount = rate * taxrate;
			TotalPayment = rate + TaxAmount;
		}
		if (BOOKTYPE == 'O') {
			TotalPayment *= 0.8;
			TotalDiscount = rate + TaxAmount - TotalPayment;
		}
		/* Receipt */
		/*
		Output receipt for each booking made by user. 
		*/
		string date = __DATE__, time = __TIME__, room;
		cout << "\nHere is your receipt " << endl << endl;
		cout << "**************************************" << endl;
		cout << "WELCOME TO ABC HOTEL\n" << endl;
		cout << "Date\t\t:" << date << endl;
		cout << "Time\t\t:" << time << endl << endl;
		cout << "Guest name\t:" << GuestName << endl;

		/*
		Cross check ROOMTYPE input with roomtype in structure to get full name of room instead of abbreviation. 
		Easier to read the information. 
		*/
		if (ROOMTYPE == 'F')
			room = Family.roomtype;
		if (ROOMTYPE == 'S')
			room = Standard.roomtype;
		if (ROOMTYPE == 'D')
			room = Deluxe.roomtype;
		if (ROOMTYPE == 'E')
			room = Executive.roomtype;
		cout << "Type of room\t:" << room << endl;

		/*
		Check for number of days booked to ensure receipt is grammatically correct. 
		*/
		if (NumDays == 1) {
			cout << "No. of day\t:" << NumDays << endl;
		}
		else {
			cout << "No. of days\t:" << NumDays << endl;
		}
		cout << "Total discount\t:" << "RM" << TotalDiscount << endl;
		cout << "Total payment\t:" << "RM" << TotalPayment << endl << endl;
		cout << "Thank you. Enjoy your stay! " << endl;
		cout << "**************************************" << endl;

		/* Again? */
		/*
		Prompt user for repeated booking. Include while loop for error checking. 
		Only accept 'Y' and 'N' as inputs. Restarts program if 'Y' is input. End program if 'N' is input. 
		*/
		cout << "\nDo you want to book another room? ('Y' for yes, 'N' for no)" << endl;
		cin >> again;
		char AGAIN = toupper(again);
		while (AGAIN != 'Y' &&
			AGAIN != 'N') {
			cout << "Enter 'Y' for yes, 'N' for no. " << endl;
			cin >> again;
			AGAIN = toupper(again);
		}
		if (AGAIN == 'N') {
			cout << "Goodbye :) " << endl;
			x = 0;
		}
		else if (AGAIN == 'Y') {
			x = 1;
		}

		/* Store guest info. */
		Guest Guest1;			// New guest
		Guest1.Date = date;
		Guest1.Time = time;
		Guest1.Name = GuestName;
		Guest1.Room = room;
		Guest1.Spend = TotalPayment;

		/*
		Open file and store guest info in file for future reference. 
		*/
		ofstream StoreInfo;
		StoreInfo.open("GuestInfo.txt", ios::app);
		StoreInfo << Guest1.Date << "\t\t"
			<< Guest1.Time << "\t\t"
			<< Guest1.Name << "\t\t\t"
			<< Guest1.Room << "\t\t"
			<< Guest1.Spend << endl;
	}
}