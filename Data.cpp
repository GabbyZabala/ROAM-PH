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
		data locales = 1;//reference
	data run = 0;// total run timeloop
	string fullcommand;//error command display
	data ticket_no = 0;//ticket data for struct
	data bland = 0;
	data label = 0;// if ticket to be displayed in monitor
	char errorcatch;//error command catcher
	bool index = true;// loop
	bool logstatus; // operator
	bool confirmation = false;
	bool optlock = false;// for option 1
}var;

struct UserData {
    string userName; // Consumer name
    string location; // Consumer target place
    data planeTicket; // Ticket number
    string seatClass; // Seat Type
    data maxTicket[3] = {0,0,0};//storage for access
    data ticketuse = 0;//ticket indicator
    data tickettotal = sizeof(maxTicket)/sizeof(maxTicket[0]);//info check
    void visual_receipt(){
        print << "\tTicket Data:\t" <<planeTicket<<n;
        print << "\tConsumer Name:\t"<<userName<<n; 
        print << "\tLocation:\t" <<location<<n;
        print << "\tClass:\t\t"<<seatClass<<n;
        print << "\tTicket availble:\t"<<ticketuse<<"/"<<tickettotal<<n;
    }
} duser[totalrequired_run];

struct AirplaneData {//later na this
	string planeName;
	data planeID;
	data current_passanger;
	data max_passanger;
	string time;
	string flight_plan;
	void output(){
		cout<<planeID<<"\t"<<planeName<<"   \t| ";
		cout<<"\t"<<current_passanger<<" / "<<max_passanger<<"   \t| ";
		cout<<"\t"<<flight_plan<<"     \t"<<time<<endl;
	}
} dplane[totalplaneavailable];

//major system data above

//view part below
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
		switch(locale){
			case 1:
				print<<"Home";
				break;
			case 2:
				print<<"BuyFly.cpp";
				break;
			case 3:
				print<<"Profile.exe";
				break;
			case 44:
				print<<"AirLiner.roam";
				break;
			case 51:
				print<<"Notice\\";
				break;
			case 505:
				print<<"Confirmation.txt";
				break;
			default:
				print<<"No_Directory.##";
				break;
		}
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
	void base_atc1(data label){
		if(label > 0){
			print<<"\t\t[ N/A ] - Quick plan on ticket\n\t\t[ N/A ] - Delete a flight\n\t\t[ N/A ] - Add a flight\n\t\t[  4  ] - Save Ticket Plan\n\t\t[  5  ] - Return to Index"<<n;
		}
		else{
			print<<"\t\t[ 1 ] - Quick plan on ticket\n\t\t[ 2 ] - Delete a flight\n\t\t[ 3 ] - Add a flight\n\t\t[ 4 ] - Save Ticket Plan\n\t\t[ 5 ] - Return to Index"<<n;
		}
	}
	void base_profile(){
		print<<"\n\t\t[ 1 ] - View Current Available Ticket\n\t\t[ 2 ] - Delete Active Ticket\n\t\t[ 3 ] - View History\n\t\t[ 4 ] - Return to Index"<<n;
	}
	void apDashboard(){
		string headr[4] = {"ID", "Airplane Name","Passangers", "Distination\t Time"};
		cout<<"\t\t";
		for(int i = 0; i<=3; i++){
			cout<<"\t"<<headr[i];
			if(i<1)	cout<<" "; 
			else if(i == 3) cout<<"\t";
			else cout<<"\t|";
		}
		cout<<endl;
	}
	void frNap(){
		cout<<"\t\t[ 1 ] - Yes\n\t\t[ 2 ] - No";
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
lad AIcoms(Variables &var, animatics &an){
	if(var.locale != 3) print<<"\n\tDeborah: ";
	switch (var.locale){
		case 1:
			if(strap == 1) {
				print<<"Hello there travelers! Welcome to ROAM-PH what can i do for you?";
				strap++;
			}
			else if(strap == 2){
				print<<"Hello there travelers! Where do you want to go this time?";
				strap++;
			}
			else if(strap == 3){
				print<<"Hello there travelers! Do you want to go to places where you want to spent your vacation?";
				strap++;
			}
			else if(strap == 1){
				print<<"Hello there travelers! Travel Again?";
				strap++;
			}
			else {
				print<<"Hello there travelers! Going somewhere?";
				strap = 1 ;
			}
			break;
		case 2:
			if(strap == 1){
				print<<"Travel Again?";
				strap++;
			}
			else if(strap == 2){
				print<<"Gonna travel again? Go and find here the best vacation place you want..";
				strap++;
			}
			else {
				print<<"?????";
				strap = 1;
			}
			break;
		case 44:
			print<<"Here's the Available Flight you can choose..";
			break;
		case 51:
			switch(strap){
				case 505:
					print<<"there's nothing to save...";
					break;
				default:
					print<<"Blank -w-";
					strap = 1;
					break;
			}
			break;
		case 99:
			print<<"Do you want to save your progress?..";
			break;
		default:
			print<<"hello what can i do for you?";
			break;
	}
	print<<n<<n;
}

//functions part here
struct Functions{
	Variables var;
	UserData duser[totalrequired_run];
	AirplaneData dplane[totalplaneavailable];
	void Indi(Variables var){
		cout<<var.locale*var.run;
	}
	void showAP(AirplaneData dplane[]){
		dplane[0] = {"Boing",104,5,20,"18:30 UTC","brazil"};
		dplane[1] = {"Jetty",140,22,77,"13:40 UTC","USA"};
		dplane[2] = {"Binladen",911,222,147,"07:20 UTC","WorldTrade"};
		for(int i = 0; i<=2;++i){
			cout<<"\t\t[ "<<i+1<<" ]\t";
			dplane[i].output();
			if(i== 2){
				print<<"\t\t[ "<<i+2<<" ]\tCancel Plan";
			}
		}
	}
	void QuickTicker(Variables var,UserData duser[]){
		duser[0].maxTicket[var.label] = var.ticket_no;
		duser[0].ticketuse++;
	}
	void SaveTicket(Variables var){
		if(var.label >= 1){
			
		}
	}
}action;

data Main_screen {
	duser[0] = {"Gabby", "Brazil - 10:30 UTC", var.ticket_no, "First-Class", 1};
	Variables var;
	bg;sys:
	string errorinput;
	data error = 0;//error allert
    start.log(var);
    bool user = var.logstatus;
    while(var.index){
    	head:
    	string command;
    	cout<<var.locale<<var.run<<var.logstatus<<var.ticket_no<<var.locales;
		display.directory(var.locale);
		action.Indi(var);
    	display.header2();
    	AIcoms(var, an);
		switch (var.locale) {//display manager
			case 1:
				display.base_entry(var);
				break;
			case 2:		
		    	if(var.label>0){
		    		display.apDashboard();
		    		print<<"\t\t\t";dplane[var.ticket_no-1].output();
		    	}
				display.base_atc1(var.label);
				break;
			case 3:
				duser[0].visual_receipt();
				display.base_profile();
				break;
			case 44:
				display.apDashboard();
				action.showAP(dplane);
				break;
			case 99:
				display.frNap();
				break;
			case 51:
				print<<"\t\t\t";
				system("pause");
				clearsys;
				var.locale = var.locales;
				goto head;
				break;				
			default:
				print<<"\t\tError Display.. IDK how you did it but damn.."<<n;
				system("pause");	
				break;
		}
		if ( error >= 1) {//error relay
			print<<"\n\t//Error named < "<<var.errorcatch<<" > input detected "<<n;
			print<<"\t\t - "<<var.fullcommand<<n;
			--error;
		}
		else print<<n;
		print<<"\tEnter Choice: ";
		getline(enter,command);
		char base_command = command[0];
		if(var.optlock){//function 1 ticket
			if(base_command == '1' && var.locale == 2  && var.label == 0) {//quick flight
				var.locale = 44;
			}
			else if(base_command == '2' && var.locale == 2  && var.label == 0) {//delete a flight
				system("pause");
			}
			else if(base_command == '3' && var.locale == 2  && var.label == 0) {//add a flight
				print<<"Option 3"<<n;
				system("pause");
			}
			else if(base_command == '4' && var.locale == 2 && var.label > 0) {//save ticket
				var.label = 0;
				var.ticket_no = 0;
				var.optlock = false;
				var.locale = 1;
			}
			else if(base_command == '4' && var.locale == 2 && var.label == 0) {//save ticket
				strap = 505;
				var.locale = 51;
				clearsys;
				goto head;
			}
			else if(base_command == '5' && var.locale == 2  && var.label > 0){
				var.locale = 99;
				var.confirmation = true;
			}
			else if(base_command == '5' && var.locale == 2  && var.label == 0||base_command == '~') {//'~' is hardreset
				var.locale = 1;
				var.optlock = false;	 
			}
			else if(base_command== '1' && var.locale == 44){
				action.QuickTicker(var,duser);
				var.ticket_no = 1;
				var.label++;
				var.locale = 2;
			}
			else if(base_command== '2' && var.locale == 44){
				action.QuickTicker(var,duser);
				var.ticket_no = 2;
				var.label++;
				var.locale= 2;
			}
			else if(base_command== '3' && var.locale == 44){
				action.QuickTicker(var,duser);
				var.ticket_no = 3;
				var.label++;
				var.locale= 2;
			}			
			else if(base_command == '4' && var.locale == 44){
				var.locale = 2;
			}
			else {	
				var.errorcatch = base_command;
				var.fullcommand = command;
				if(var.run >= 1) ++error ;
				}
		}
	else if(var.confirmation){
		switch (var.locale){
			case 99:
				if(base_command == '2'){
					duser[0].maxTicket[var.label] = 0;
					duser[0].ticketuse--;
					var.confirmation = false;
				}
				else {
					var.locale = 2;
					var.confirmation = false;
				}
				break;
			default:
				clearsys;
				var.confirmation = false;
				print<<"There's seems to be an error in your code.."<<n;
				system("pause");
				break;
		}
	}
	else {
		if(!user) {
			if(base_command=='1' && var.locale == 1) {
				var.locale = 2;
				var.optlock = true;
			}
			else if(base_command == '2' && var.locale == 1) var.locale = 3;
			else if(base_command == '3' && var.locale == 1) {endgame;}
			else if(base_command == '/' && var.locale == 1) {clearsys;goto sys;}
			else if(base_command == '~') {var.locale = 1;}
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
			else {	var.errorcatch = base_command;
				var.fullcommand = command;
				if(var.run >= 1) ++error ;
				}
		}
	}	
	clearsys;
	cin.clear();
	++var.run;
	var.locales = var.locale;
	}
	end;
}
