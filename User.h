#ifndef USER_H
#define USER_H

#include <string>
using namespace std;

class User {
private:
    int id;
    string name;

public:
    User(int userId, string userName) {
        id = userId;
        name = userName;
    }

    int getId() { return id; }
    string getName() { return name; }
};

#endif
