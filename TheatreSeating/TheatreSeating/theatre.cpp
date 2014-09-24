#include <iostream>
#include <iomanip>

using namespace std;

int totalSales = 0;
int totalAvailable = 0;
int row = 0;
int seat = 0;
int seatsSold = 0;
int userChoice = 0; // ****UPDATE**** forgot to make the userChoice variable during our class-time tuesday.
int seatsPerRow = 0; // (3rd commit addition)


int seatingChart[15][30];
int sales[15];

void displayMenu();   // Kevin
void promptRowSeat();	// Kevin
void displayAvailable(); // Kevin (3rd commit addition)
void displaySales();	// Rodger
void promptRowPrices();	// Rodger
void getRowPrice();		// Rodger
void displayChart();	// Matt
void fillArray();		// Matt	
void changeSeatStatus();	// Matt

int main()
{
	// Fill the array ( fillArray() )
	fillArray(); // fillAray needs to be defined below

	// Prompt for row prices
	promptRowPrices();  // promptRowPrices needs to be defined below
	
	// Display Menu outside of while and set userChoice
	displayMenu();

	// While(userChoice !=3)
	while(userChoice != 4){

		switch(userChoice){
			
			case 1: 
				promptRowSeat();
				displayChart();
				displayMenu();
				break;
			case 2:
				displayChart();
				displayAvailable();
				displayMenu();
				break;
			case 3:
				displaySales();
				displayMenu();
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
	cout << "3. View Total Sales"<< endl;
	cout << "4. Quit" << endl;
	cout << "Type your choice # and press enter (1, 2, 3, or 4): ";
	cin >> userChoice;
	cout << endl;
}

void displayAvailable(){
	// Displays total amount of seats sold
	cout << "# of seats sold: " << seatsSold << endl;		
	

	// Displays seats available in each row
	for(int i = 0; i > 15; i++){
		for(int j = 0; j > 30; j++){
			if (seatingChart[i][j] == '#')
				seatsPerRow++;
		}
		cout << endl << "Seats availabe in Row " << (i + 1) << ": " << seatsPerRow << endl;
		totalAvailable += seatsPerRow;	// Add seats available in that row to totalAvailable
		seatsPerRow = 0;				// reset seatsPerRow
	}

	// Displays total number of seats left in auditorium
	cout << "Total # of seats left: " << totalAvailable << endl;
	
}
void displaySales(){
// define displaySales here
	// assume totalSales is already correct (calculated in promptRowSeat() )
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
	// Get Row and Seat # from user
	cout << "Here is what is available: " << endl << displayChart() << endl;
	cout << "Enter the Row # of the seat you would like to purchase (1-15): ";
	cin >> row;
	cout << endl << "Enter the Seat # in that row you would like to purchase (1-30): ";
	cin >> seat;

	// If the seat is available, change the seat's status in the seating chart, add to totalSales, and increment seatsSold
	if(seatingChart[row-1][seat-1] == '#'){
		changeSeatStatus();
		cout << "Sold! That seat cost $" << getRowPrice() << "." << endl;
		totalSales += sales[row];
		seatsSold++;
	}
	else if(seatingChart[row-1][seat-1] == '*'){
		cout << "That seat is already taken. Try again!" << endl;
	}
	else{
		cout << "Incorrect Row # or Seat #" << endl;
	}

}

void getRowPrice(){ 
// define getRowPrice here
	// assume the 'row' variable is already set to the index of the row you are searching for
	// the function should ultimately output the price of the row ( ex. cout << sales[row-1] << endl )
	// reminder, row 1 == sales[0], row 15 == sales[14];
}

void changeSeatStatus(){
// define changeSeatStatus here
	// assume the 'row' and 'seat' variables are already set to the indexes of the row and seat you are trying to change
	// reminder, row 1 seat 30 == seatingChart[0][29]
}