/*
 * File: event.h
 * ---------------
 * This file holds the definitions of event class and it's member functions.
 */
#ifndef event_h
#define event_h

#include <string>
#include <iostream>


class Event {
protected:
    // Member variables of Event class
    std::string eventName;
    std::string eventDate;
    std::string location;
    std::string eventType;
    std::vector<std::string> attendees;

public:
    // Constructor
    Event(std::string name, std::string date, std::string loc, std::string type)
        : eventName(name), eventDate(date), location(loc), eventType(type) {}

    // Destructor
    virtual ~Event() {};

    // Setters
    void setEventName(std::string name);
    void setEventDate(std::string date);
    void setLocation(std::string loc);
    void setEventType(std::string type);

    // Getters
    std::string getEventName();
    std::string getEventDate();
    std::string getLocation();
    std::string getEventType();

    // This function checks if a specific event is upcoming i.e. the event date is 
    // beyond today's date
    bool isUpcoming();

    // This function shall be responsible to add attendees to the attendees vector
    void addAttendee(std::string& attendee) {
        attendees.push_back(attendee);
    }

    // This is a simple function that returns all attendees to the specific event
    std::vector<std::string> getAttendees() {
        return attendees;
    }

    // This is a pure virtual function that shall be overriden in child classes
    virtual std::string getDetails() = 0;
};

/*
 * Workshop is the class defined for Workshops and is an extension of Event class.
 * This handles extra variables such as instructor and duration.
 * The getDetails function is overriden here.
 */
class Workshop : public Event {
private:
    std::string instructor;
    int duration;

public:
    // Constructor
    Workshop(std::string name, std::string date, std::string loc, std::string type, 
        std::string instr, int dur);

    std::string getDetails();
};

/*
 * Conference is the class defined for Conferences and is an extension of Event class.
 * This handles extra variables such as speaker and topic.
 * The getDetails function is overriden here.
 */
class Conference : public Event {
private:
    std::string speaker;
    std::string topic;

public:
    // Constructor
    Conference(std::string name, std::string date, std::string loc, std::string type, 
        std::string speak, std::string top);

    std::string getDetails();
};

/*
 * Concert is the class defined for Concerts and is an extension of Event class.
 * This holds extra variables such as bandName and genre.
 * The getDetails function is overriden here.
 */
class Concert : public Event {
private:
    std::string bandName;
    std::string genre;

public:
    // Constructor
    Concert(std::string name, std::string date, std::string loc, std::string type, 
        std::string band, std::string gen);

    std::string getDetails();
};

#endif
