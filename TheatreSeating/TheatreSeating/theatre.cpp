#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

int totalSales = 0;
int totalAvailable = 0;
int row = 0;
int seat = 0;
int seatsSold = 0;
int userChoice = 0; 
int seatsPerRow = 0; 


char seatingChart[15][30];
int sales[15];

void displayMenu();   // Kevin
void promptRowSeat();	// Kevin
void displayAvailable(); // Kevin
void displaySales();	// Rodger
void promptRowPrices();	// Rodger
void getRowPrice();		// Rodger
void displayChart();	// Matt -- created 9/27/14
void fillArray();		// Matt	-- created 9/27/14
void changeSeatStatus();	// Matt -- created 9/27/14

int main()
{
	// Fill the array 
	fillArray();


	// Prompt for row prices
	promptRowPrices();  
	
	// Display Menu outside of while and set userChoice
	displayMenu();

	// While(userChoice !=4)
	while(userChoice != 4){

		switch(userChoice){
			
			case 1: 
				promptRowSeat();		// Ask the user for Row and Seat #
				displayChart();			// Display the seating chart
				displayMenu();			// Display the menu
				break;
			case 2:
				displayChart();
				displayAvailable();		// Display available seating left in each row
				displayMenu();
				break;
			case 3:
				displaySales();			// Display the total sales
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
	for(int i = 0; i < 15; i++){
		for(int j = 0; j < 30; j++){
			if (seatingChart[i][j] == '#')
				seatsPerRow++;
		}
		cout << endl << "Seats availabe in Row " << (i + 1) << ": " << seatsPerRow << endl;
		totalAvailable += seatsPerRow;	// Add seats available in that row to totalAvailable
		seatsPerRow = 0;				// reset seatsPerRow
	}

	// Displays total number of seats left in auditorium
	cout << "Total # of seats left: " << totalAvailable << endl << endl;

	// Reset variables so they will be correct if the client chooses option 2 (Ticket Availabilty) again
	totalAvailable = 0;
	seatsPerRow = 0;
	
}
void displaySales(){
// Display the total sales so far. totalSales is incremented in promptRowSeat
	cout << "The total sales are: " << totalSales << endl;
}	

void displayChart(){ //Matt
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
		cout << endl << endl;
	}
}

void fillArray(){ //Matt
// Fill the array at the start of the program
	for (int i = 0; i < 15; ++i){
		for (int j = 0; j < 30; ++j){
			seatingChart[i][j] = '#';
		}
	}
}

void promptRowPrices(){
// Ask the user to enter the prices for each row
	int rowPrices;

	for (int i = 0; i < 15; i++){
		cout << "Enter the price of Row #" << (i + 1) << endl;
		cin >> rowPrices;
		sales[i] = rowPrices;
	}
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
		cout << "Sold! That seat cost: $";
		getRowPrice();
		cout << endl;
		totalSales += sales[row-1];
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
// Output the price of the corresponding row in the sales[] array

	int price;
		if(row==0)
			price = sales[row];
		else
			price = sales[row - 1];
	cout << price << endl;

}

void changeSeatStatus(){ //Matt
// Change the char at the row and seat index of the seatingChart array
	seatingChart[row - 1][seat - 1] = '*';
}
