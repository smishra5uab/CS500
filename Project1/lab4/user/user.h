#ifndef user_h
#define user_h

#include <string>
#include <vector>

class User {
private:
    std::string userName;         
    std::string email;            
    std::vector<User*> friendList;

public:
    // Constructor
    User(const std::string& name, const std::string& emailAddress);

    // Setters
    void setUserName(const std::string& name);
    void setEmail(const std::string& emailAddress);

    // Getters
    std::string getUserName() const;
    std::string getEmail() const;

    void addFriend(User* friendUser);
    void removeFriend(const std::string& friendName);
    int numFriends() const;
    User* getFriendAt(int index) const;
};

#endif
