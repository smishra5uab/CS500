/*
 * File: searchByDate.h
 * ---------------
 * This file is the extension of searchStrategy and the implementation to search by date.
 */
#ifndef searchByDate_h
#define searchByDate_h

#include "searchStrategy.h"
#include <iostream>

class SearchByDate : public SearchStrategy {
private:
    std::string searchDate;

public:
    // Constructor
    SearchByDate(std::string& date) : searchDate(date) {}

    // Overriden search function
    std::vector<Event*> search(std::vector<Event*>& events) {
        std::vector<Event*> foundEvent;
        for (auto event : events) {
            if (event->getEventDate() == searchDate) {
                foundEvent.push_back(event);
            }
        }
        return foundEvent;
    }
};

#endif
