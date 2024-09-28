#include "User.h"
#include <iostream>

// Constructor to initialize userName and email
User::User(const std::string& name, const std::string& emailAddress) {
    userName = name;
    email = emailAddress;
}

// Set the user name
void User::setUserName(const std::string& name) {
    userName = name;
}

// Set the email address
void User::setEmail(const std::string& emailAddress) {
    email = emailAddress;
}

// Get the user name
std::string User::getUserName() const {
    return userName;
}

// Get the email address
std::string User::getEmail() const {
    return email;
}

// Add a friend to the friend list
void User::addFriend(User* friendUser) {
    if (friendList.size() < 100) {
        friendList.push_back(friendUser);
    } else {
        std::cout << "Error: Friend list is full.\n";
    }
}

// Remove a friend by username
void User::removeFriend(const std::string& friendName) {
    for (auto friendVal = friendList.begin(); friendVal != friendList.end(); friendVal++) {
        if ((*friendVal)->getUserName() == friendName) {
            friendList.erase(friendVal);
            return;
        }
    }
    std::cout << "Friend " << friendName << " not found.\n";
}

// Return the number of friends
int User::numFriends() const {
    return friendList.size();
}

// Get a friend at a given index
User* User::getFriendAt(int i) const {
    if (i >= 0 && i < numFriends()) {
        return friendList[i];
    }
    std::cout << "Error: Invalid index.\n";
    return nullptr;
}
