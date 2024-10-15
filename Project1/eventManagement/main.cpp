/*
 * File: main.cpp
 * ---------------
 * This is where all the magic happens!
 * The main function is merely just being used to call for the UI usecases and exit when asked.
 */
#include "eventUi.h"
#include <iostream>

int main() {
    int choice;
    EventUi ui;
    do {
        std::cout << "\n=============================\n";
        std::cout << "\nEvent Management System\n";
        std::cout << "1. Create New Event\n";
        std::cout << "2. Search for Events\n";
        std::cout << "3. Display Details of a Specific Event\n";
        std::cout << "4. List All Upcoming Events\n";
        std::cout << "5. RSVP for Event\n";
        std::cout << "6. View Event Attendees\n";
        std::cout << "7. Exit\n";
        std::cout << "Enter your choice: ";
        std::cin >> choice;
        std::cin.ignore();
        
        switch(choice) {
            case 1:
                ui.addEvent();
                break;
            case 2:
                ui.searchEvent();
                break;
            case 3:
                ui.displayEvent();
                break;
            case 4:
                ui.listUpcomingEvents();
                break;
            case 5:
                ui.rsvpForEvent();
                break;
            case 6:
                ui.viewAttendees();
                break;
            case 7:
                std::cout << "Exiting from the menu!\n";
                break;
            default:
                std::cout << "Invalid input\n";
        }
    } while (choice != 7);

    return 0;
}
