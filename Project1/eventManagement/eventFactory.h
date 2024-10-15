/*
 * File: eventFactory.h
 * ---------------
 * This file holds the EventFactory class that follows the factory design pattern.
 */
#ifndef eventFactory_h
#define eventFactory_h

#include "event.h"
#include <string>

class EventFactory {
public:
    // Constructor
    EventFactory() {}

    /*
     * This createEvent function is created to generically create an event based on the event type
     * passed to it.
     * Based on the event type passed, it calls and creates a new event and fills it in with the
     * details passed for the specific event.
     */
    Event* createEvent(std::string eventType, 
                       std::string name, 
                       std::string date, 
                       std::string location,
                       std::string instructor = "",
                       std::string topic = "",
                       int duration = 0) {
        if (eventType == "Workshop") {
            return new Workshop(name, date, location, eventType, instructor, duration);
        } else if (eventType == "Conference") {
            return new Conference(name, date, location, eventType, instructor, topic);
        } else if (eventType == "Concert") {
            return new Concert(name, date, location, eventType, instructor, topic);
        }
        return nullptr;
    }

    // Destructor
    ~EventFactory() {}
};

#endif
