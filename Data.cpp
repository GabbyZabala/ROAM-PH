#include <iostream>
#include <string>
#include <windows.h>
#include <fstream>

#include <limits>
#include <vector>
using namespace std;

#define end return 0
#define data int
#define print cout
#define lad void
#define prompt 
#define enter cin
#define n endl
#define Main_screen main()
#define clearsys system("cls")
#define bg system("color 70")
#define endgame clearsys;an.animation("\n\n\t\tTerminating program.........");end;

const int totalrequired_run = 10000; // value container
const int totalplaneavailable = 3;//availble planes in the port

struct animatics{ // structure for animation
	void animation(string input){
		for (int i = 0; i < input.length(); ++i) {
		        cout << input[i] << flush;
		        Sleep(25); // Adjust the delay in milliseconds
		    }
		return;
	}
	void dot_animation(){
		string loading = "...";//dot loading
		for (int i = 0; i < loading.length(); ++i) {
		        cout << loading[i] << flush;
		        Sleep(500); // Adjust the delay in milliseconds
		    }
		return;
	}
}an;

struct Variables {
	data locale = 1;//display location
	data run = 0;// total run timeloop
	string fullcommand;//error command display
	data ticket_no = 0;//ticket data for struct
	char errorcatch;//error command catcher
	bool index = true;// loop
	bool logstatus; // operator
}var;

struct UserData {
    string userName; // Consumer name
    string location; // Consumer target place
    data planeTicket; // Ticket number
    string seatClass; // Seat Type
    data seat;
    void visual_receipt(){
        print << "\tTicket Data:\t" <<planeTicket<<n;
        print << "\tConsumer Name:\t"<<userName<<n; 
        print << "\tLocation:\t" <<location<<n;
        print << "\tSeat:\t\t" <<seat<<n;
        print << "\tClass:\t\t"<<seatClass<<n;
    }
} duser[totalrequired_run];

struct AirplaneData {//later na this
	string planeName;
	data planeID;
	data current_passanger;
	data max_passanger;
	data time;
	string flight_plan;
	void output(){
		cout<<planeID<<"\t"<<planeName<<"   \t| ";
		cout<<"\t"<<current_passanger<<" / "<<max_passanger<<"   \t| ";
		cout<<"\t"<<flight_plan<<"     \t"<<time<<endl;
	}
} dplane[totalplaneavailable];

struct Display { // structure for display
	void header(){
		print<<"\t    ____  \t________    _____      _____    ____"<<n;
		print<<"\t   / --- \\     / ____  /   /  ^  \\    |     \\  /    |  =   _____"<<n;
		print<<"\t  / /__/ /    / /   / /   /  /_\\  \\   |  |\\  \\/  /| |  A  |  PH |"<<n;
		print<<"\t /  /\\  \\    / /___/ /   /  /   \\  \\  |  | \\    / | |  =  |_____|"<<n;
		print<<"\t/_ /  \\ _\\  /_______/   |__|    |__|  |__|  \\__/  |_|"<<n;
		print <<"\n\t=========== Plane Ticket System ===========\n\n";
	}
	void header2(){
		print <<"\t      ______     __________     ___      ____       ____"<<n;
		print <<"============/  ---  \\===/  ______  \\==/  ^  \\===|     \\===/     |=====+++++"<<n;
		print <<"-----------/  /__/  /--/  /-----/  /-/  /_\\  \\--|  |\\  \\_/  /|  |--A-|  PH |"<<n;
		print <<"==========/  ____  \\==/  /_____/  /=/  /===\\  \\=|  |=\\     /=|  |=====TTTTT"<<n;
		print <<"\t /_ /    \\_ \\ \\__________/ /__/     \\__\\|__|  \\___/  |__|"<<n;
		print <<"\n\t<================= Plane Ticket System =================>\n\n";
	}
	void displayFlight(){
		string gotoCountry[3] = {"Brasil", "USA","Canada"};
		string timeplace[3] = {"10:30","14:50","20:35"};
		print<<"\t========================================================================="<<n;
		print<<"\t|\tCountry\t\t|\t\tTime Available\t\t\t|"<<n;
		print<<"\t========================================================================="<<n;
		for(int i = 0; i<=2; i++) {
			print<<"\t|\t"<<gotoCountry[i]<<"\t\t|";
			for(int x = 0; x<=2; x++) {
				print<<"\t"<<timeplace[x]<<"\t";
			}
			print<<"|"<<n;
		}
		print<<"\t========================================================================="<<n;
	}
	void directory(int locale) {
		print<<"\t\\\\Index\\";
		if(locale == 2) print<<"BuyFly.cpp";
		else if(locale == 3) print<<"Profile.exe";
		
		print<<n;
	}
	void base_entry(Variables &var){
		if (var.logstatus){
			print<<"\t\t[ 1 ] - Buy a ticket\n\t\t[ 2 ] - View User Profile \n\t\t[ 3 ] - View Available Flight\n\t\t[ 4 ] - Exit"<<n;
		}
		else {
			print<<"\t\t[ 1 ] - Buy a ticket\n\t\t[ 2 ] - View User Profile \n\t\t[ 3 ] - Exit"<<n;
		}
	}
	void base_atc1(){
		print<<"\n\t\t[ 1 ] - Add plan on ticket\n\t\t[ 2 ] - Delete a flight\n\t\t[ 3 ] - Add a flight\n\t\t[ 4 ] - Save Ticket Plan\n\t\t[ 5 ] - Return to Index"<<n;
	}
	void base_profile(){
		print<<"\n\t\t[ 1 ] - View Current Available Ticket\n\t\t[ 2 ] - Delete Active Ticket\n\t\t[ 3 ] - View History\n\t\t[ 4 ] - Return to Index"<<n;
	}
}display;

struct Login{
	void log(Variables &var){
		bool loop = false;
		do {
			char input;
			print<<"\n\n\tWhat Account would you like to use?"<<n;
			print<<"\n\t\t[ 1 ] - User\n\t\t[ 2 ] - Administrator\n\n\tCommand: ";
			cin>>input;
			clearsys;
			if (input == '1') {
				var.logstatus = false;
				an.animation("\n\n\t\tlogging into user mode...");
				break;
			}
			else if (input == '2') {
				var.logstatus = true;
				an.animation("\n\n\t\tlogging into Administrator");
				break;
			}
			else an.animation("\n\n\t\tError input..please try again");
			clearsys;
		}while (!loop);
		clearsys;
		an.animation("\n\n\t\tWelcome To ROAM-PH..");
		clearsys;
		for(int i = 0; i<= 1; ++i)
		{
			print<<"\n\n\t\tWelcome To ROAM-PH\n\t\tSystem loading";
			an.dot_animation();
			clearsys;
		}
	}
}start;

int strap = 0;
lad AIcoms(Variables &var){
	if(var.locale != 3) print<<"\n\tDeborah: ";
	switch (var.locale){
		case 1:
			if(strap == 0) {
				print<<"Hello there travelers! Welcome to ROAM-PH what can i do for you?";
				strap++;
			}
			if(strap == 1){
				print<<"Hello there travelers! Where do you want to go this time?";
				strap++;
			}
			else if(strap == 2){
				print<<"Hello there travelers! Do you want to go to places where you want to spent your vacation!";
				strap++;
			}
			else if(strap == 3){
				print<<"Hello there travelers! Travel Again?";
				strap++;
			}
			else {
				print<<"Hello there travelers! Going somewhere?";
				strap = 1 ;
			}
			break;
		default:
			
			break;
	}
	print<<n<<n;
}

class File_Part_Data {//restore file
	private: 
		Variables var;
		AirplaneData ap[totalplaneavailable];
	public:
		void Optionon(){
			
		}
		
		
};

data Main_screen {
	duser[0] = {"Gabby", "Brazil - 10:30 UTC", var.ticket_no, "First-Class", 1};
	Variables var;
	bg;sys:
	string errorinput;
	data error = 0;//error allert
    start.log(var);
    bool user = var.logstatus;
    while(var.index){
    	string command;
    	cout<<var.locale<<var.run<<var.logstatus<<var.ticket_no;display.directory(var.locale);
    	display.header2();
    	AIcoms(var);
		switch (var.locale) {
			case 1:
				display.base_entry(var);
				break;
			case 2:
				display.base_atc1();
				break;
			case 3:
				duser[0].visual_receipt();
				display.base_profile();
				break;
			default:
				print<<"\t\tError Display.. IDK how you did it but damn.."<<n;
				system("pause");	
				break;
		}
		if ( error >= 1) {
			print<<"\n\t//Error named < "<<var.errorcatch<<" > input detected "<<n;
			print<<"\t\t - "<<var.fullcommand<<n;
			--error;
		}
		else print<<n;
		print<<"\tEnter Choice: ";
		getline(enter,command);
		char base_command = command[0];
		if(!user) {
			if(base_command=='1' && var.locale == 1) {
				var.locale = 2;
			}
			else if(base_command == '2' && var.locale == 1) var.locale = 3;
			else if(base_command == '3' && var.locale == 1) {endgame;}
			else if(base_command == '/' && var.locale == 1) {clearsys;goto sys;}
			else if(base_command == '~') {var.locale = 1;}
			else if(base_command == '1' && var.locale == 2) {
				print<<"Option 1"<<n;
				system("pause");
			}
			else if(base_command == '2' && var.locale == 2) {
				print<<"Option 2"<<n;
				system("pause");
			}
			else if(base_command == '3' && var.locale == 2) {
				print<<"Option 3"<<n;
				system("pause");
			}
			else if(base_command == '4' && var.locale == 2) {
				print<<"Option 4"<<n;
				system("pause");	
			}
			else if(base_command == '5' && var.locale == 2) {
				var.locale = 1;	
			}
			else if(base_command =='4' && var.locale == 3){
				var.locale = 1;
			}
			else {	
				var.errorcatch = base_command;
				var.fullcommand = command;
				if(var.run >= 1) ++error;
			}
		}
		else {
			if(base_command=='1' && var.locale == 1) var.locale = 2;
			else if(base_command == '4' && var.locale == 1) {endgame;}
			else if(base_command == '/' && var.locale == 1) {clearsys;goto sys;} 
			else if(base_command == '~') {var.locale = 1;}
			else if(base_command == '1' && var.locale == 2) {
				print<<"Option 1"<<n;
			}
			else if(base_command == '2' && var.locale == 2) {
				print<<"Option 2"<<n;
			}
			else if(base_command == '3' && var.locale == 2) {
				print<<"Option 3"<<n;
			}
			else if(base_command == '4' && var.locale == 2) {
				print<<"Option 4"<<n;	
			}
			else if(base_command == '5' && var.locale == 2) {
				var.locale = 1;	
			}
			else {	var.errorcatch = base_command;
				var.fullcommand = command;
				if(var.run >= 1) ++error ;
				}
		}
		clearsys;
		cin.clear();
		++var.run;
	}
	end;
}
