#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
	int totalSales = 0;
	int row = 0;
	int seat = 0;
	int seatsSold = 0;
	int userChoice = 0; // ****UPDATE**** forgot to make the userChoice variable during our class-time tuesday.

	int seatingChart[15][30];
	int sales[15];

	void displayMenu();   // Kevin
	void promptRowSeat();	// Kevin
	void displaySales();	// Rodger
	void promptRowPrices();	// Rodger
	void getRowPrice();		// Rodger
	void displayChart();	// Matt
	void fillArray();		// Matt	
	void changeSeatStatus();	// Matt


	// Fill the array ( fillArray() )
	fillArray(); // fillAray needs to be defined below

	// Prompt for row prices
	promptRowPrices();  // promptRowPrices needs to be defined below
	
	// Display Menu outside of while and set userChoice
	displayMenu();

	// While(userChoice !=3)
	while(userChoice != 3){

		switch(userChoice){
			
			case 1: 
				promptRowSeat();
				displayChart();
				break;
			case 2:
				displaySales();
				displayChart();					
				break;
			case 3:
				break;
			default:
				displayMenu();
				break;
		}

	}
	cout << "Enjoy the show!";

}
void displayMenu(){
	cout << "___Theatre Seating Ticket Booth___" << endl;
	cout << "1. Purchase tickets" << endl;
	cout << "2. Ticket Availability" << endl;
	cout << "3. Quit" << endl;
	cout << "Type your choice # and press enter (1,2, or 3): ";
	cin >> userChoice;
	cout << endl;
}

void displaySales(){
// define displaySales here
	// should call getRowPrices() inside of a for loop, setting row to 'i' just before calling the function.

}	

void displayChart(){
// define displayChart here
}

void fillArray(){
// define fillArray here
}

void promptRowPrices(){
// define promptRowPrices here
// Prompts user to enter the price of purchasing a seat row by row and initializes each price with the correspoding row in "sales" array
// reminder, row 1 == sales[0], row 15 == sales[14];
}

void promptRowSeat(){
// define promptRowSeat here
}

void getRowPrice(){
// define getRowPrice here
	// assume the 'row' variable is already set to the index of the row you are searching for
	// reminder, row 1 == sales[0], row 15 == sales[14];
}

void changeSeatStatus(){
// define changeSeatStatus here
	// assume the 'row' and 'seat' variables are already set to the indexes of the row and seat you are trying to change
}