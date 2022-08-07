#include <iostream>
#include <string>
#include <map>
#include <windows.h>
#include <shellapi.h>

class Login {
    // Private variables who are going to be stored in map container.
    std::string username;
    std::string password;
    std::map<std::string, std::string> map_of_users;
    
public:
    void user() {
        do {
            std::cout << "Username: ";
            std::cin >> username;
            // Checks if username already exists in map container (map_of_users).
            if (map_of_users.find(username) == map_of_users.end()) break;
            else {
                system("cls");
                std::cout << "Username already exists.\n";
            }
        } while (map_of_users.find(username) != map_of_users.end());
        std::cout << "Password: ";
        std::cin >> password;
        // Saves inserted valid username and password inside map container (map_of_users).
        map_of_users.insert({ username, password });
    }

    void login() {
        std::string name, parole;
        std::cout << "----------LOGIN----------" << std::endl;
        do {
            std::cout << "Username: ";
            std::cin >> name;
            // Checks if username exists in map container (map_of_users).
            if (map_of_users.count(name) > 0) break;
            else {
                system("cls");
                std::cout << "Username does not exist.\n";
            }
        } while (map_of_users.count(name) == 0);
        
        int count = 3;
        do {
            std::cout << "Password: ";
            std::cin >> parole;
            // Checks if in map container (map_of_users), key NAME have value PAROLE. User have 3 oportunities to guess the password.
            if (map_of_users.at(name) == parole) break;
            system("cls");
            std::cout << name << std::endl;
            std::cout << "Incorrect password.\n\n\n";
            count--;
        } while (map_of_users.at(name) != parole && count >= 1);
      
        if (map_of_users.at(name) == parole) {
            std::cout << "\nWelcome to MATRIX...\n";
            ShellExecute(0, 0, L"https://www.youtube.com/watch?v=dQw4w9WgXcQ", 0, 0, SW_SHOW);
        }
        else {
            std::cout << "Your have been permamently blocked from visiting MATRIX.\n";
        }
    }

    // This function displays all key, value pairs in map_of_users container. For debuging.
    void display() {
        for (auto user : map_of_users) {
            std::cout << user.first << " : " << user.second << std::endl;
        }
    }
};

int main()
{
    Login uldis;
    for (int i = 0; i < 2; i++) {
        uldis.user();
        system("cls");
    }
    uldis.login();

    return 0;
}
