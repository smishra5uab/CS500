/*
 * File: eventUi.h
 * ---------------
 * This file is the definition of the EventUi class.
 * The class is responsible for handling the UI of the program. It handles the functions such as
 * adding event, searching events, displaying events, listing the upcoming events, and performing
 * functionalities on rsvp features.
 */
#ifndef eventUi_h
#define eventUi_h
#include "eventFactory.h"

class EventUi {
    private:
        std::vector<Event*> events;
        EventFactory eventFactory;

    public:
        // Function to add an event
        void addEvent();

        // Function to search events based on certain criteria
        void searchEvent();

        // Function to display the event based on it's name
        void displayEvent();

        // Function to list all upcoming events against current date
        void listUpcomingEvents();

        // Function to perform the RSVP for a specific event
        void rsvpForEvent();

        // Function to view all attendees of the specific event
        void viewAttendees();

        // Destructor
        ~EventUi();
};

#endif