#include <iostream>
#include <vector>
#include <string>

using namespace std;

// Define a structure to represent a flight
struct Flight {
    string flightNumber;
    string origin;
    string destination;
    int capacity;
    int bookedSeats;
};

// Function to display flight details
void displayFlightDetails(const Flight& flight) {
    cout << "Flight Number: " << flight.flightNumber << endl;
    cout << "Origin: " << flight.origin << endl;
    cout << "Destination: " << flight.destination << endl;
    cout << "Capacity: " << flight.capacity << endl;
    cout << "Booked Seats: " << flight.bookedSeats << endl;
}

// Function to check seat availability and book a seat
void bookSeat(Flight& flight) {
    if (flight.bookedSeats < flight.capacity) {
        flight.bookedSeats++;
        cout << "Seat booked successfully!" << endl;
    } else {
        cout << "Sorry, the flight is full. No seats available." << endl;
    }
}

int main() {
    // Create some sample flights
    vector<Flight> flights = {
        {"F101", "New York", "Los Angeles", 200, 0},
        {"F102", "Los Angeles", "Chicago", 150, 0},
        {"F103", "Chicago", "Houston", 180, 0}
    };

    int choice, flightIndex;

    do {
        cout << "\nAirline Reservation System\n";
        cout << "1. Display Flight Details\n";
        cout << "2. Book a Seat\n";
        cout << "3. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "\nFlight Details\n";
                cout << "-----------------------------------" << endl;
                for (size_t i = 0; i < flights.size(); ++i) {
                    cout << i + 1 << ". ";
                    displayFlightDetails(flights[i]);
                    cout << "-----------------------------------" << endl;
                }
                break;
            case 2:
                cout << "Enter the index of the flight to book a seat: ";
                cin >> flightIndex;
                if (flightIndex >= 1 && flightIndex <= flights.size()) {
                    bookSeat(flights[flightIndex - 1]);
                } else {
                    cout << "Invalid flight index." << endl;
                }
                break;
            case 3:
                cout << "Exiting...";
                break;
            default:
                cout << "Invalid choice. Please enter a number from 1 to 3." << endl;
        }
    } while (choice != 3);

    return 0;
}
