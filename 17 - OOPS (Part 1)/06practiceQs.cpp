#include <iostream>
using namespace std;

class User {
private:
    int id;
    string password;

public:
    string username;

    User(int id) {
        this->id = id;
    }

    //Getter cause private
    string getPassword() {
        return password;
    }
    
    //Setter cause private
    void setPassword(string password) {
        this->password = password;
    }
  };

int main() {
    User user1(94);
    user1.username = "SuperPro";
    user1.setPassword("Pro");

    cout << "username : " << user1.username << endl;
    cout << "password : " << user1.getPassword() << endl;
     
    return 0;
}