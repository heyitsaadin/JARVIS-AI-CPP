#include <iostream>
#include <string>
#include <ctime>
#include <fstream>
#include <unistd.h>
using namespace std;

void registerUser(string username, string password) {
    ofstream file("users.txt", ios::app);
    file << username << " " << password << "\n";
    file.close();
}

void printSlow(string text) {
    for (char c : text) {
        cout << c << flush;
        usleep(50000);
    }
    cout << endl;
}

void createResponses() {
    ofstream file("responses.txt");
    file << "hello,Hello! How are you doing?\n";
    file << "hi,Hey there! How can I help?\n";
    file << "name,My name is Jarvis AI!\n";
    file << "how are you,I am doing great thank you!\n";
    file << "joke,Why do programmers prefer dark mode? Because light attracts bugs!\n";
    file<<"who are you,hey! Iam Jarvis an Ai I can help you with some basic maths some simple questions etc!\n";
    file<<"purpose,My purpose as an Ai is to solve your problems and improve myself\n";
    file<<"motivate me,Hey don't give whatever your problems are I'm sure you will find a way to solve it stay strong!\n";
    file<<"fine,Alright good to know so How can I assist you today?\n";
    file.close();
}
bool loginUser(string username, string password) {
    ifstream file("users.txt");
    string u, p;
    while (file >> u >> p) {
        if (u == username && p == password) {
            file.close();
            return true;
        }
    }
    file.close();
    return false;
}

string getResponse(string input) {
    ifstream file("responses.txt");
    string line;
    while (getline(file, line)) {
        int comma = line.find(",");
        string keyword = line.substr(0, comma);
        string response = line.substr(comma + 1);
        if (input.find(keyword) != string::npos) {
            file.close();
            return response;
        }
    }
    file.close();
    return "";
}

void askAi(string input) {
    string response = getResponse(input);
    if (response != "") {
        printSlow("AI: " + response);
        return;
    }
    time_t now = time(0);
    tm *ltm = localtime(&now);
    if (input.find("time") != string::npos) {
        int h = ltm->tm_hour;
        string p = (h >= 12) ? "PM" : "AM";
        if (h > 12) h -= 12;
        if (h == 0) h = 12;
        string timeStr = "AI: The time is " + to_string(h) + ":" + (ltm->tm_min < 10 ? "0" : "") + to_string(ltm->tm_min) + " " + p;
        printSlow(timeStr);
    }
    else if (input.find("day") != string::npos || input.find("date") != string::npos) {
        string days[] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
        printSlow("AI: Today is " + days[ltm->tm_wday]);
    }
    else {
        float a, b;
        char op;
        if (sscanf(input.c_str(), "what is %f %c %f", &a, &op, &b) == 3 || sscanf(input.c_str(), "%f %c %f", &a, &op, &b) == 3) {
            float res = 0;
            if (op == '+') res = a + b;
            else if (op == '-') res = a - b;
            printSlow("AI: " + to_string(a) + " " + op + " " + to_string(b) + " is " + to_string(res));
        } else {
            printSlow("AI: I don't know that yet, but I am learning...");
        }
    }
}

int main() {
    createResponses();
    string username, password, choice;
    printSlow("enter 1 for Register\nenter 2 for Login\nChoice: ");
    cin >> choice;
    printSlow("Username: ");
    cin >> username;
    printSlow("Password: ");
    cin >> password;
    if (choice == "1") {
        registerUser(username, password);
        printSlow("Registered successfully!");
    } else if (choice == "2") {
        if (loginUser(username, password)) {
            printSlow("Login successful! Welcome " + username + "!");
            printSlow("How can I help you " + username + "?");
            string request;
            cin.ignore();
            while (true) {
                cout << "You: ";
                getline(cin, request);
                if (request == "exit") break;
                askAi(request);
            }
        } else {
            printSlow("Incorrect credentials.");
        }
    }
    return 0;
}
