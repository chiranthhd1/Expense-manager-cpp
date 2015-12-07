// Authors Chiranth , Prasad , Sanjan
#ifndef _MAIN2_H
#define _MAIN2_H

#include "attributes.h"
#include <stdexcept>

int Auth::Usepwdcheck()
{
//handling exception if password lenght and username lenght is less than 6 and 4 respectively also if not matched.
        int maxchar = 10;
	int f=3;
	while (f > 0){
        try {
        	cout << green << " \t\t Enter Username : ";
        	cin >> username;
        	if ( username.length() < 4)
        	{
                	throw "ERROR";
		}
 		else if (username != USERNAME)
        	{
                	throw 1.5;
        	}

 		else {

			cout << green << " \t\t Enter Password : ";
        		cin >> password;
			if ( password.length() < 4)
        		{
                		throw "ERROR";
        		}

			else if (password != PASSWORD) 
			{
                		throw -1;

        		}

        		else {
                		return 0;
	     		     }
		}

        	if ( username.length() > maxchar || password.length() > maxchar)
        	{
                	throw 12;
        	}
        }

        	catch(const char* Message)
        	{
			cout << red <<  " \t\t Incorrect!! (username and password should be more than 4): " << endl<<endl;
        	}
        	catch(const int p)
        	{
                	cout << " \t\t Entered Value is too long "<< endl<<endl;
        	}
		catch(const double v)
        	{
			cout << red <<  " \t\t  Incorrect Username " << endl<<endl;
        	}
		catch(signed int m)
        	{
			cout << red <<  " \t\t  Incorrect Password" << endl<<endl;
        	}
		
		f--;
			cout <<  green << " \t\t you have " << f << "trie(s) left " << endl << endl;
		}
		cin.ignore();
		return 1;
}


int Auth::Maincheck()
{
	a = Usepwdcheck();
	if (a == 0) {
		return 0;
	}
	else
	{
		return 1;

	}


}


string AttributeDB::ReadNthLine(int N)
{
	
	AttributeDB db;
	fstream in("xman.txt");

        string s;

	for(int i =0; i < N; ++i)
		getline(in, s);
	getline(in,s);
	
	return s;
	
}

string AttributeDB::GetNthLine(int a, int b)	
{
	a= (a-1)*9+(b-1);
        string s =new char[1000];
	string e;
	int d;
        string buf; // Have a buffer string
        vector<string> token; // Create vector to hold our words
       token.reserve(150);
        
       	for ( int i =0 ; i < 15; i++)
        {
                s = ReadNthLine( i);
                //cout << s << endl;
                stringstream ss(s); // Insert the string into a stream
                while (ss >> buf)
		{
                
			token.push_back(buf);

                }
        }
        return token.at(a);
} 

int AttributeDB::WriteNthLine(int a, int b, string e)
{
	a = (a-1)*9+(b-1);
        string s = new char[1000];
	int d;
        string buf; // Have a buffer string

        vector<string> token; // Create vector to hold our words
	token.reserve(1500);
        for ( int i=0; i<15 ; i++)
        {
                s = ReadNthLine(i);
    		//cout << s << endl;
		stringstream ss(s); // Insert the string into a stream
                while (ss >> buf)
		{
                
			token.push_back(buf);

                }
        }
	
	ofstream out ("xman.txt");
        token.at(a) = e;
        for ( vector<string> ::iterator s = token.begin(); s!= token.end(); ++s)
	{
                if ( *s == "n")
                {       out << "n";
                        out << "\n";
                }
                else
                {
                        out << *s;
                        out << "\t";
                }
        }
	return 0;


}



string Attribute::GetUsername()
{
	return username;
}
int  Attribute::GetValue(int b)
{
	string s;
	string r;
	int y;
	AttributeDB db;
	int month = GetMonth();
	cout << magenta << " \t\t Existing value is : " << db.GetNthLine(month,b)<< endl << endl;
	cout << red << " \t\t Please enter the new value :";
	cin >> r;
	cout << endl << endl;
	cout << magenta << " \t\t 1.Yes " << endl;
	cout << magenta << " \t\t 2.No " << endl << yellow;

	cout << red << " \t\t Please confirm :";
	cin >> y;
	cout << endl;
	if (y == 1)
	{
		db.WriteNthLine(month,b,r);
		cout << yellow << " \t\t Selection Confirmed" << endl << endl;
		return 0;
	}
	else
	{ 
		return 1;
	}
	
}


	
int Attribute::GetMonth()
{
	Display d;
	string mon;
	cout << magenta << " \t\t Please enter the month(eg: january or jan) : ";
	cin.ignore();
	getline(cin, mon);
	//cin >> month;
	if (mon == "jan" || mon == "january" || mon == "feb" || mon == "february" || mon == "mar" || mon == "march" || mon == "apr"||mon == "april" || mon == "may" || mon == "jun" || mon == "june" || mon == "jul" || mon == "july" || mon == "aug" || mon == "august" || mon == "sep" || mon == "september" || mon == "oct" || mon == "october" || mon == "nov" || mon == "november" || mon == "dec" || mon == "december") {
               // throw runtime_error(" Wrong Input ");
                
		
		while ( cin.good()==true)
		{
			map < string, int > month;
			month["jan"] = 1;
			month["january"] = 1;

			month["feb"] = 2;
			month["february"] = 2;

			month["mar"] = 3;
			month["march"] = 3;

			month["apr"] = 4;
			month["april"] = 4;

			month["may"] = 5;

			month["jun"] = 6;
			month["june"] = 6;

			month["jul"] = 7;
			month["july"] = 7;

			month["aug"] = 8;
			month["august"] = 8;

			month["sep"] = 9;
			month["september"] = 9;

			month["oct"] = 10;
			month["october"] = 10;

			month["nov"] = 11;
			month["november"] = 11;

			month["dec"] = 12;
			month["december"] = 12;


			return month[mon];
		}
	}

	else
	{
		cout << " Please Try again " << endl;
		d.Mainmenu();
	} 

}

double Attribute::SetCarLoan(int a)
{
	cout << "a" << a << endl;
	carloan = a;
}
double Attribute::SetInsurance(int a)
{
	cout << "\t a" << a << endl;
	insurance = a;
}

double Attribute::SetElecGas(int a)
{
	cout << "\t a" << a << endl;
	elecgas = a;

}
double Attribute::SetPhone(int a)
{
	cout << "\t a" << a << endl;
	phone = a;

}

double Attribute::SetGroceries(int a)
{
	cout << "\t a" << a << endl;
	groceries = a;
}

double Attribute::SetCommute(int a)
{
	cout << "\t a" << a << endl;
	groceries = a;
}

void Display::Time()
{
	time_t now = time(0);
	tm*ltm = localtime(&now);
	cout << 1 + ltm->tm_mon << "/" << 1 + ltm->tm_mday << "/" << 1900 + ltm->tm_year << "  " << ltm->tm_hour << ":" << ltm->tm_min << ":" << ltm->tm_sec << endl;
}

void Display::welcome()
{
	cout << " \n\n\n";

	cout << red << " \t ****************************************************************************************" << endl;
	cout << red << " \t ****************************" << blue << " Welcome to Expense Manager " << red << "********************************" << endl;

	cout << red << " \t ****************************************************************************************" << endl;
	cout << endl;
	cout << endl;
	cout << reset;
}

void Display::top(string s)
{
	cout << " \n\n\n";
	cout << red << " \t ****************************************************************************************" << endl;
	cout << red << " \t ****************************" << blue << " Welcome to Expense Manager " << red << "********************************" << endl;
	cout << red << " \t ****************************************************************************************" << endl;
	cout << white << " \t\t\t\t\t\t\t\t Date & Time:";
	Time();
	cout << blue << " \t (" << s << ")" << "\t\t" << endl;
	cout << reset << endl;
}

void Display::DisGoback()
{
	cout << magenta << " \t\t 1. Go to Previous Menu" << endl;
	cout << magenta << " \t\t 2. Go to Main Menu" << endl;
	cout << reset << endl;
}
void Display::ViewAdd(string s)
{
	top(s);
	cout << magenta << " \t\t 1. View  " << endl;
	cout << magenta << " \t\t 2. Edit  " << endl;
	cout << magenta << " \t\t 3. Add  " << endl << endl;
	cout << magenta << " \t\t Choice : ";

}

void Display::dismainmenu(string s) {
	top(s);
	cout << magenta << " \t\t 1. Rent " << endl;
	cout << magenta << " \t\t 2. car loan " << endl;
	cout << magenta << " \t\t 3. Electricity and gas " << endl;
	cout << magenta << " \t\t 4. Phone " << endl;
	cout << magenta << " \t\t 5. Insurance " << endl;
	cout << magenta << " \t\t 6. Groceries " << endl;
	cout << magenta << " \t\t 7. Commute " << endl;
	cout << magenta << " \t\t 8. Miscellaneous " << endl;
	cout << magenta << " \t\t 9. Previous Menu " << endl;
	cout << magenta << " \t\t 10. Exit " << endl;
	cout << yellow << " \n\t\t choose an option : ";

}


int Display::Mainmenu() {
	int g, h, i;
	char c;
	system("clear");
	//dismainmenu(" Main Menu ");
	ViewAdd(" Main ");
	cin >> h;
	if (cin.good() == true)
	{
		system(" clear");
		switch (h)
		{
		case 1:
			Menu(h,"view");
			break;
		case 2:
			Menu(h,"edit");
			break;
		case 3:
			Menu(h,"add");
			break;
		default:
			cout << " \n\n\n ";
			cout << cyan << " \t\t Please provide an valid input " << endl;
			cout << cyan << " \t\t Press enter to continue " << endl;
			cin.ignore();
			cin.ignore();
			Mainmenu();
			break;
		}
		cin.ignore();
		system("clear");
	}
	else
	{
		cout << endl;
		cout << cyan << " \t\t Please enter an Integer value " << endl;
		cout << cyan << " \t\t Press any key to continue : ";
		cin.ignore();
		cin.ignore();
		cin.ignore();
		system("./a ");
	}
}

int Display::Menu(int a, string s) {
	int g, h, i;
	char c;
	system("clear");
	dismainmenu(" Main Menu --> "+ s);
	cin >> h;
	if (cin.good() == true)
	{
		system(" clear");
		switch (h)
		{
		case 1:
			MainRent(a);
			break;
		case 2:
			MainCarLoan(a);
			break;
		case 3:
			MainElecGas(a);
			break;
		case 4:
			MainPhone(a);
			break; 

		case 5:
			MainInsurance(a);
			break;
		case 6:
			MainGroceries(a);
			break; 
		case 7:
			MainCommute(a);
			break;
		case 8:
			MainMisc(a);
			break;

		case 9:
			Mainmenu();
			break;
		case 10:
			exit(1);
		default:
			cout << " \n\n\n ";
			cout << cyan << " \t\t Please provide an valid input " << endl;
			cout << cyan << " \t\t Press enter to continue " << endl;
			cin.ignore();
			cin.ignore();
			Mainmenu();
			break;
		}
		cin.ignore();
		system("clear");
	}
	else
	{
		cout << endl;
		cout << cyan << " \t\t Please enter an Integer value " << endl;
		cout << cyan << " \t\t Press any key to continue : ";
		cin.ignore();
		cin.ignore();
		cin.ignore();
		/*	cin >> c;
		if (c)
		{
		cin.ignore();
		cin.ignore();
		Mainmenu();
		}
		else
		{
		exit(1);
		//		return -1;
		}

		*/
		system("./xman.exe");
		//Mainmenu();
	}
}

int Display::View(string a, int c) {

	Attribute b;
	AttributeDB db;
	int month;
	system("clear");
	top(a);
	month = b.GetMonth();
	cout << cyan << " \t\t Value : " << db.GetNthLine(month,c)  << endl << endl;
	DisGoback();
	Goback(1);
}
int Display::Edit(string s, int b)
{
	Attribute a;
	AttributeDB db;
	system("clear");
	top(s); //sets new value of rent and rec flag to 1
	a.ew = a.GetValue(b);
	if (a.ew != 1)
	{
		DisGoback();
		Goback(2);
	}
	else
	{
		Mainmenu();
	}

}
int Display::Add(string s, int b)
{
	Attribute a;
	AttributeDB db;
	system("clear");
	top(s); //sets new value of rent and rec flag to 1
	//int month = a.GetMonth();
	//a.ew = db.WriteNthLine(month,b);
	a.ew = a.GetValue(b);
	if (a.ew != 1)
	{
		DisGoback();
		Goback(2);
	}
	else
	{
		Mainmenu();
	}

}
int Display::MainRent(int h) {

	Attribute a;
	system("clear");
	switch (h)
	{

	case 1: // this views the value of rent
		View(" Main Menu --> View --> Rent", 1);
		break;

	case 2:// this changes or adds the value of rent along with rec o non rec
		Edit(" Main Menu --> Edit --> Rent", 1);
		break;


	case 3:// this changes or adds the value of rent along with rec o non rec
		Add(" Main Menu --> Add --> Rent", 1);
		break;

	default:
		cout << " \t\t please provide an input " << endl;
		cin.ignore();
		cin.ignore();
		system("clear");
		cin.ignore();
		cout << reset;
		break;

	}
}

int Display::MainCommute(int h) {

	Attribute a;
	system("clear");
	switch (h)
	{

	case 1: // this views the value of Commute
		View(" Main Menu --> View --> Commute", 7);
		break;

	case 2:// this changes or adds the value of rent along with rec o non rec
		Edit(" Main Menu --> Edit --> Commute", 7);
		break;

	default:
		cout << " \t\t please provide an input " << endl;
		cin.ignore();
		cin.ignore();
		system("clear");
		cin.ignore();
		cout << reset;
		break;

	}
}

int Display::MainCarLoan(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of CarLoan
                View(" Main Menu --> View --> CarLoan", 2);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> CarLoan", 2);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}

int Display::MainInsurance(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Insurance 
                View(" Main Menu --> View --> Insurance", 5);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> Insurance", 5);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}

int Display::MainGroceries(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Groceries", 6);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> Groceries", 6);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}
int Display::MainElecGas(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Electricity and Gas", 3);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit --> Electricity and Gas", 3);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}
int Display::MainPhone(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Phone", 4);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit--> Phone", 4);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;

        }
}

int Display::MainMisc(int h) {

        Attribute a;
        system("clear");
        switch (h)
        {

        case 1: // this views the value of Groceries
                View(" Main Menu --> View --> Misc", 8);
                break;

        case 2:// this changes or adds the value of rent along with rec o non rec
                Edit(" Main Menu --> Edit--> Misc", 8);
                break;

        default:
                cout << " \t\t please provide an input " << endl;
                cin.ignore();
                cin.ignore();
                system("clear");
                cin.ignore();
                cout << reset;
                break;
	}
}
    
int Display::Goback(int j) { // This is for go back option for all menu.

	int i;
	cout << yellow << " \t\t choose an option : ";
	cin >> i;
	if (cin.good() == false)
	{
		cout << " \t\t Please enter an integer " << endl;
		cin.ignore();
		cin.ignore();
		return -1;
	}
	else
	{
		system("clear");
		if (i == 1 && j == 1)
		{
			Menu(1," View");
		}
		else if (i == 1 && j == 2)
		{
			Menu(2," Edit");
		}
		else if (i == 1 && j == 2)
		{
			Menu(3," Add");
		}
	
		else
		{
			Mainmenu();
		}
	}
}



#endif
