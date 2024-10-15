/*
 * File: eventUi.cpp
 * -----------------
 * This file is the implementation of eventUi.h
 */
#include "eventUi.h"
#include "searchByDate.h"
#include "searchByLocation.h"
#include "searchByType.h"

/*
 * Function: addEvent()
 * Usage: addEvent()
 * -----------------
 * This function shall add an event by it's details to the events vector.
 */
void EventUi::addEvent() {
    std::string eventType;
    std::string eventName;
    std::string eventDate;
    std::string location;

    // Get the details that are common to all events
    std::cout << "\n===========================================\n";
    std::cout << "Enter the event type (Workshop/Conference/Concert): ";
    std::getline(std::cin, eventType);
    std::cout << "Enter the name of the event: ";
    std::getline(std::cin, eventName);
    std::cout << "Enter the date of the event in yyyy-mm-dd format: ";
    std::getline(std::cin, eventDate);
    std::cout << "Enter the location of the event: ";
    std::getline(std::cin, location);

    if (eventType == "workshop") {
        // If the event is a Workshop, get details of instructor and duration of the event.
        std::string instructor;
        std::string duration;
        int durationNum;

        std::cout << "Enter instructor name: ";
        std::getline(std::cin, instructor);
        std::cout << "Enter duration in hours: ";
        std::getline(std::cin, duration);
        durationNum = std::stoi(duration);

        // Create and push the workshop event to the events vector
        events.push_back(eventFactory.createEvent("Workshop", eventName, eventDate, location, 
            instructor, "", durationNum));
    } else if (eventType == "conference") {
        // If the event is a conference, get details of the speaker and the topic
        std::string speaker;
        std::string topic;

        std::cout << "Enter speaker name: ";
        std::getline(std::cin, speaker);
        std::cout << "Enter topic name: ";
        std::getline(std::cin, topic);
        // Create and push the conference to the events vector
        events.push_back(eventFactory.createEvent("Conference", eventName, eventDate, location, 
            speaker, topic));
    } else if (eventType == "concert") {
        // If the event is a concert, get details of the band and the genre
        std::string band;
        std::string genre;

        std::cout << "Enter band name: ";
        std::getline(std::cin, band);
        std::cout << "Enter the genre: ";
        std::getline(std::cin, genre);
        // Create and push the concert to the events vector
        events.push_back(eventFactory.createEvent("Concert", eventName, eventDate, location, 
            band, genre));
    } else {
        std::cout << "Invalid event type.\n";
    }
}

/*
 * Function: displayEvent()
 * Usage: displayEvent()
 * -----------------
 * This function shall look for the event by the entered name and return it's details using the
 * specific event's member getDetails member function. Prints an error if event not found by the
 * entered name.
 */
void EventUi::displayEvent() {
    std::string eventName;
    std::cout << "Enter the event name: ";
    std::getline(std::cin, eventName);
    for (auto event : events) {
        if (event->getEventName() == eventName) {
            std::cout << "\n------------------------------\n";
            std::cout << event->getDetails() << "\n";
            return;
        }
    }
    std::cout << "Event not found.\n";
}

/*
 * Function: listUpcomingEvents()
 * Usage: listUpcomingEvents()
 * -----------------
 * This function shall look for the events that have the isUpcoming flag set to true and print their
 * details.
 */
void EventUi::listUpcomingEvents() {
    std::cout << "\n==============================\n";
    for (auto event : events) {
        if (event->isUpcoming()) {
            std::cout << "\n------------------------------\n";
            std::cout << event->getDetails() << "\n";
        }
    }
}

/*
 * Function: searchEvent()
 * Usage: searchEvent()
 * -----------------
 * This function shall search the events based on the criterion selected by the user.
 * Strategy design pattern is implemented here to search based on selected strategy.
 */
void EventUi::searchEvent() {
    int choice;
    SearchStrategy* strategy;

    std::cout << "\n==============================\n";
    std::cout << "Choose search criterion:\n";
    std::cout << "1. Search by Date\n";
    std::cout << "2. Search by Location\n";
    std::cout << "3. Search by Event Type\n";
    std::cout << "Enter your choice: ";
    std::cin >> choice;
    std::cin.ignore();

    // Switch between choices to select the strategy to search
    switch (choice) {
        case 1: {
            std::string date;
            std::cout << "Enter date (YYYY-MM-DD): ";
            std::getline(std::cin, date);
            strategy = new SearchByDate(date);
            break;
        }
        case 2: {
            std::string location;
            std::cout << "Enter location: ";
            getline(std::cin, location);
            strategy = new SearchByLocation(location);
            break;
        }
        case 3: {
            std::string type;
            std::cout << "Enter event type with the first letter capitalized (Workshop/Conference/Concert): ";
            getline(std::cin, type);
            strategy = new SearchByType(type);
            break;
        }
        default:
            std::cout << "Invalid choice!\n";
            return;
    }

    // Store the events returned from the search into a vector based on selected strategy.
    // If the result vector is empty, print error. Else print the event details.
    std::vector<Event*> result = strategy->search(events);
    if (result.empty()) {
        std::cout << "No events found.\n";
    } else {
        std::cout << "Found events:\n";
        for (auto event : result) {
            std::cout << "\n------------------------------\n";
            std::cout << event->getDetails() << "\n";
        }
    }
}

/*
 * Function: rsvpForEvent()
 * Usage: rsvpForEvent()
 * -----------------
 * This function shall first find event by name and then allow to RSVP for an attendee and add them
 * to the list of attendees for the specific event. If event is not found, print an error.
 */
void EventUi::rsvpForEvent() {
    std::string eventName;
    std::string attendeeName;
    
    std::cout << "\n==============================\n";
    std::cout << "Enter the event name to RSVP: ";
    std::getline(std::cin, eventName);
    
    for (auto event : events) {
        if (event->getEventName() == eventName) {
            std::cout << "Enter your name: ";
            std::getline(std::cin, attendeeName);
            event->addAttendee(attendeeName);
            std::cout << "RSVP successful for " << attendeeName << "!\n";
            return;
        }
    }
    std::cout << "Event not found.\n";
}

/*
 * Function: viewAttendees()
 * Usage: viewAttendees()
 * -----------------
 * This function is responsible to view all attendees to a specific event searched by its name.
 * If the specified event is not found, an error is printed.
 * If no attendees have RSVP'd yet, it shall print an error.
 */
void EventUi::viewAttendees() {
    std::string eventName;

    std::cout << "\n==============================\n";
    std::cout << "Enter the event name: ";
    std::getline(std::cin, eventName);

    for (auto event : events) {
        if (event->getEventName() == eventName) {
            std::vector<std::string> attendees = event->getAttendees();
            if (attendees.empty()) {
                std::cout << "No attendees have RSVP'd yet.\n";
            } else {
                std::cout << "Attendees for " << eventName << ":\n";
                for (const auto& attendee : attendees) {
                    std::cout << attendee << "\n";
                }
            }
            return;
        }
    }
    std::cout << "Event not found.\n";
}

// Destructor
EventUi::~EventUi() {
    for (auto event : events) {
        delete event;
    }
}