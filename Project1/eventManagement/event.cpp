/*
 * File: event.cpp
 * -----------------
 * This file is the implementation of event.h
 */
#include "event.h"
#include <ctime>
#include <cstdio>

// Setter for event name
void Event::setEventName(std::string name) {
    eventName = name;
}

// Setter for event date
void Event::setEventDate(std::string date) {
    eventDate = date;
}

// Setter for event location
void Event::setLocation(std::string loc) {
    location = loc;
}

// Setter for event type
void Event::setEventType(std::string type) {
    eventType = type;
}

// Getter for event name
std::string Event::getEventName() {
    return eventName;
}

// Getter for event date
std::string Event::getEventDate() {
    return eventDate;
}

// Getter for event location
std::string Event::getLocation() {
    return location;
}

// Getter for event type
std::string Event::getEventType() {
    return eventType;
}

/*
 * Function: isUpcoming
 * Usage: isUpcoming()
 * -----------------------
 * The isUpcoming function checks and compares the local current date with the date of the event.
 * If the event is on a day beyond today, it returns a true. Else returns false.
 */
bool Event::isUpcoming() {
    time_t now = time(0);
    tm* local = localtime(&now);
    
    char currentDate[11];
    // Format the current date in the format YYYY-MM-DD.
    // Note: I took help from stackOverFlow for this functionality
    sprintf(currentDate, "%04d-%02d-%02d", 1900 + local->tm_year, 1 + local->tm_mon, local->tm_mday);
    
    return eventDate > currentDate;
}

// Constructor for Workshop
Workshop::Workshop(std::string name, std::string date, std::string loc, std::string type, 
    std::string instr, int dur): Event(name, date, loc, type), instructor(instr), duration(dur) {}

/*
 * Function: Workshop::getDetails
 * Usage: Workshop::getDetails()
 * -----------------------
 * This function returns all details of the asked workshop in new lines per detail.
 */
std::string Workshop::getDetails() {
    return "Workshop: " + eventName + "\nDate: " + eventDate + "\nLocation: " + location +
           "\nInstructor: " + instructor + "\nDuration: " + std::to_string(duration) + 
           " hours\nEventType: " + eventType + "\n";
}

// Constructor for Conference
Conference::Conference(std::string name, std::string date, std::string loc, std::string type, 
    std::string speak, std::string top) : Event(name, date, loc, type), speaker(speak), topic(top) {}

/*
 * Function: Conference::getDetails
 * Usage: Conference::getDetails()
 * -----------------------
 * This function returns all details of the asked conference in new lines per detail.
 */
std::string Conference::getDetails() {
    return "Conference: " + eventName + "\nDate: " + eventDate + "\nLocation: " + location +
           "\nSpeaker: " + speaker + "\nTopic: " + topic + "\nEventType: " + eventType + "\n";
}

// Constructor for Concert
Concert::Concert(std::string name, std::string date, std::string loc, std::string type, 
    std::string band, std::string gen) : Event(name, date, loc, type), bandName(band), genre(gen) {}

/*
 * Function: Concert::getDetails
 * Usage: Concert::getDetails()
 * -----------------------
 * This function returns all details of the asked concert in new lines per detail.
 */
std::string Concert::getDetails() {
    return "Concert: " + eventName + "\nDate: " + eventDate + "\nLocation: " + location +
           "\nBand: " + bandName + "\nGenre: " + genre + "\nEventType: " + eventType + "\n";
}
