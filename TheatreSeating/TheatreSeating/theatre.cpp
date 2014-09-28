#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int totalSales = 0;
int totalAvailable = 0;
int row = 0;
int seat = 0;
int seatsSold = 0;
int userChoice = 0; // ****UPDATE**** forgot to make the userChoice variable during our class-time tuesday.
int seatsPerRow = 0; // (3rd commit addition)


char seatingChart[14][29];
int sales[14];

void displayMenu();   // Kevin
void promptRowSeat();	// Kevin
void displayAvailable(); // Kevin (3rd commit addition)
void displaySales();	// Rodger
void promptRowPrices();	// Rodger
void getRowPrice();		// Rodger
void displayChart();	// Matt -- created 9/27/14
void fillArray();		// Matt	-- created 9/27/14
void changeSeatStatus();	// Matt -- created 9/27/14

int main()
{
	// Fill the array 
	fillArray(); // fillAray needs to be defined below


	// Prompt for row prices
	promptRowPrices();  // promptRowPrices needs to be defined below
	
	// Display Menu outside of while and set userChoice
	displayMenu();

	// While(userChoice !=4)
	while(userChoice != 4){

		switch(userChoice){
			
			case 1: 
				promptRowSeat();
				changeSeatStatus();
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
				displayChart();
				displayMenu();
				break;
			default:
				displayMenu();
				break;
		}

	}
	cout << "Enjoy the show!" << endl;

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

	// Reset variables so they will be correct if the client chooses option 2 (Ticket Availabilty) again
	totalAvailable = 0;
	seatsPerRow = 0;
	
}
void displaySales(){
// define displaySales here
	// assume totalSales is already correct (calculated in promptRowSeat() )
	cout << "The total sales are: " << totalSales << endl;
}	

void displayChart(){ //Matt
// define displayChart here
	cout << "\t";
	for (int i = 0; i < 3; i++){
		for (int j = 1; j < 11; j++){
			if (j != 10){
				cout << j;
			}
			else {
				cout << 0;
			}
		}
	}
	cout << endl;
	for (int i = 0; i < 15; i++){
		cout << "Row " << i + 1 << "\t";
		for (int j = 0; j < 30; j++){
			cout << seatingChart[i][j];
		}
		cout << endl;
	}
}

void fillArray(){ //Matt
// define fillArray here
	// *4th commit* changed the seatingChart array from a int array to a char array
	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 30; ++j){
			seatingChart[i][j] = '#';
		}
	}
}

void promptRowPrices(){
// define promptRowPrices here
// Prompts user to enter the price of purchasing a seat row by row and initializes each price with the correspoding row in "sales" array
// reminder, row 1 == sales[0], row 15 == sales[14];
	int rowPrices;

	for (int i=0; i < 15; i++){
		cout << "Enter The Amount For Row " << (i +1) << endl;
		cin >> rowPrices;
		sales[i] = rowPrices;
}

void promptRowSeat(){
	// Get Row and Seat # from user
	cout << "Here is what is available: " << endl;
	displayChart();
	cout << endl;
	cout << "Enter the Row # of the seat you would like to purchase (1-15): ";
	cin >> row;
	cout << endl << "Enter the Seat # in that row you would like to purchase (1-30): ";
	cin >> seat;

	// If the seat is available, change the seat's status in the seating chart, add to totalSales, and increment seatsSold
	if(seatingChart[row-1][seat-1] == '#'){
		changeSeatStatus();
		cout << "Sold! That seat cost : $";
		getRowPrice();
		cout << "." << endl;
		totalSales += sales[row];
		seatsSold++;
	}
	else if(seatingChart[row-1][seat-1] == '*'){
		cout << endl << "That seat is already taken. Try again!" << endl;
	}
	else{
		cout << endl << "Incorrect Row # or Seat #" << endl;
	}

}

void getRowPrice(){ 
// define getRowPrice here
	// assume the 'row' variable is already set to the index of the row you are searching for
	// the function should ultimately output the price of the row ( ex. cout << sales[row-1] << endl )
	// reminder, row 1 == sales[0], row 15 == sales[14];
		int price = sales[row - 1];

	cout << "The price for that row is: " << price << endl;

}

void changeSeatStatus(){ //Matt
// define changeSeatStatus here
	// assume the 'row' and 'seat' variables are already set to the indexes of the row and seat you are trying to change
	// reminder, row 1 seat 30 == seatingChart[0][29]
	seatingChart[row - 1][seat - 1] = '*';
}
