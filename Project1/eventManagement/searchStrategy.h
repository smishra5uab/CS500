/*
 * File: searchStrategy.h
 * ---------------
 * This file defines the search strategy interface that shall be overriden to implement in each
 * search strategy.
 */
#ifndef searchStrategy_h
#define searchStrategy_h

#include "event.h"
#include <vector>

// This is the base class that shall be implemented all across other strategies
class SearchStrategy {
public:
    virtual ~SearchStrategy() {};

    virtual std::vector<Event*> search(std::vector<Event*>& events) = 0;
};

#endif
