/*
 * File: searchByType.h
 * ---------------
 * This file is the extension of searchStrategy and the implementation to search by eventType.
 */
#ifndef searchByType_h
#define searchByType_h

#include "searchStrategy.h"
#include <iostream>

class SearchByType : public SearchStrategy {
private:
    std::string eventType;

public:
    // Constructor
    SearchByType(std::string& type) : eventType(type) {}

    // Overriden search function
    std::vector<Event*> search(std::vector<Event*>& events) {
        std::vector<Event*> foundEvent;
        for (auto event : events) {
            std::cout << "EventType" << event->getEventType() << std::endl;
            if (event->getEventType() == eventType) {
                foundEvent.push_back(event);
            }
        }
        return foundEvent;
    }
};

#endif
