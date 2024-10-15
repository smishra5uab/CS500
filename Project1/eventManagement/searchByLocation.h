/*
 * File: searchByLocation.h
 * ---------------
 * This file is the extension of searchStrategy and the implementation to search by location.
 */
#ifndef searchByLocation_h
#define searchByLocation_h

#include "searchStrategy.h"
#include <iostream>

class SearchByLocation : public SearchStrategy {
private:
    std::string searchLocation;

public:
    // Constructor
    SearchByLocation(std::string& location) : searchLocation(location) {}

    // Overriden search function
    std::vector<Event*> search(std::vector<Event*>& events) {
        std::vector<Event*> foundEvent;
        for (auto event : events) {
            if (event->getLocation() == searchLocation) {
                foundEvent.push_back(event);
            }
        }
        return foundEvent;
    }
};

#endif
