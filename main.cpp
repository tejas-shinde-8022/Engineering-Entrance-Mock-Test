#include <iostream>
#include <fstream>
#include <sstream>
#include <ctime>
#include <cstdlib>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;

struct User {
    string userId;
    string mobileNo;
    string password;
    bool isLoggedIn;
};

User currentUser;




void saveScore(const string& group, int score) {
    //ofstream scoresFile;
    /* ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << user.userId <<"," << user.password << "," << user.mobileNo<<"," << user.isLoggedIn << endl;
        file.close();
    } else {
        cout << "Unable to open file for saving user." << endl;
    }*/
    if (group == "1") {
            ofstream file("PCM_scores.txt", ios::app);
    if (file.is_open()) {
        file << currentUser.userId <<","<< score << endl;
        file.close();
    }
       /* scoresFile.open("PCM_scores.txt", ios::app);
        scoresFile << score << endl;
        scoresFile.close();
        cout << "PCM score saved successfully." << endl;*/
    } else if (group == "2") {
        ofstream file("PCB_scores.txt", ios::app);
    if (file.is_open()) {
        file << currentUser.userId <<","<< score << endl;
        file.close();
    }
        /*scoresFile.open("PCB_scores.txt", ios::app);
        scoresFile << score << endl;
        scoresFile.close();
        cout << "PCB score saved successfully." << endl;*/
    } else {
        cout << "Invalid group." << endl;
    }
}

string intToString(int num) {
    stringstream ss;
    ss << num;
    return ss.str();
}
string generateUserId() {
    srand(time(NULL));
    int randomId = rand() % 10000 + 1000;
    return "USER" + intToString(randomId);
}
void showOptions();
void displayScore(const string& groupNumber, const string& userId) {
    string group;
    if (groupNumber == "1") {
        group = "PCM";
    } else if (groupNumber == "2") {
        group = "PCB";
    } else {
        cout << "Invalid group number. Please try again." << endl;
        return;
    }
    string scoreFileName = group + "_scores.txt";
    ifstream scoreFile(scoreFileName);

    if (scoreFile.is_open()) {
        string line;
        int testNumber = 1;

        while (getline(scoreFile, line)) {
            stringstream ss(line);
            string testUserId, score;
            getline(ss, testUserId, ',');
            getline(ss, score, ',');

            if (testUserId == userId) {
                cout << "Score for Test " << testNumber << ": " << score << endl;
                testNumber++;
            }
        }

        scoreFile.close();

        if (testNumber == 1) {
            cout << "No scores found for the selected group." << endl;
        }
    } else {
        cout << "Unable to open score file." << endl;
    }

    // Ask for next action using showOptions function
    showOptions();
}

void saveUser(const User& user) {
    ofstream file("users.txt", ios::app);
    if (file.is_open()) {
        file << user.userId <<"," << user.password << "," << user.mobileNo<<"," << user.isLoggedIn << endl;
        file.close();
    } else {
        cout << "Unable to open file for saving user." << endl;
    }
}

void showQuestions(const string& group) {
    ifstream questionsFile;
    ifstream answersFile;
    string questionsFileName;
    string answersFileName;

    if (group == "1") {
        questionsFileName = "PCM.txt";
        answersFileName = "PCM_ans.txt";
    } else if (group == "2") {
        questionsFileName = "PCB.txt";
        answersFileName = "PCB_ans.txt";
    } else {
        cout << "Invalid group. Please try again." << endl;
        return;
    }

    questionsFile.open(questionsFileName.c_str());
    answersFile.open(answersFileName.c_str());

    if (questionsFile.is_open() && answersFile.is_open()) {
        string question, answer;
        int questionNumber = 1;
        int score = 0;

        while (getline(questionsFile, question) && getline(answersFile, answer)) {
            cout << "Question " << questionNumber << ": " << question << endl;
            questionNumber++;

            // Display options
            for (int i = 0; i < 4; i++) {
                getline(questionsFile, question);
                cout << question << endl;
            }

            // User input for answer
           /* string userAnswer;
            cout << "Enter your answer (A, B, C, or D): ";
            cin >> userAnswer;
            cout << endl;

            if (userAnswer.size() != 1 || userAnswer.find_first_not_of("ABCD") != string::npos) {
                cout << "Invalid option. Please enter a valid option (A, B, C, or D)." << endl;
                questionNumber--;  // Show the same question again
                continue;
            }*/
            string userAnswer;
            bool validAnswer = false;

            while (!validAnswer) {
                cout << "Enter your answer (A, B, C, or D): ";
                cin >> userAnswer;
                cout << endl;

                // Check if the answer is a valid option (A, B, C, or D)
                if (userAnswer.size() == 1 && userAnswer.find_first_not_of("ABCD") == string::npos) {
                    validAnswer = true;
                } else {
                    cout << "Invalid option. Please enter A, B, C, or D." << endl;
                }
            }


            // Extract the correct answer from the line
            char correctAnswer = answer[0];

            // Compare the user's answer with the correct answer
            if (userAnswer[0] == correctAnswer) {
                score++;
            }
        }

        questionsFile.close();
        answersFile.close();

        cout << "Test completed!" << endl;
        cout << "Your score: " << score << "/" << questionNumber - 1 << endl;
        saveScore(group, score);
        showOptions();
    } else {
        cout << "Unable to open questions or answers file." << endl;
    }
}



void showOptions() {
    string option;
    cout << "\nSelect an option:\n";
    cout << "1. Take a test\n";
    cout << "2. View scores\n";
    cout << "3. Logout\n";
    cout << "Enter your choice (1-3): ";
    cin >> option;

    if (option == "1") {
        string group;
        cout << "\nSelect your group:\n";
        cout << "1. PCM\n";
        cout << "2. PCB\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> group;
        showQuestions(group);
    } else if (option == "2") {
        string group;
        cout << "\nSelect group to view scores:\n";
        cout << "1. PCM\n";
        cout << "2. PCB\n";
        cout << "Enter your choice (1 or 2): ";
        cin >> group;
        displayScore(group,currentUser.userId);
    } else if (option == "3") {
        currentUser.isLoggedIn = false;
        cout << "Logged out successfully." << endl;
    } else {
        cout << "Invalid option. Please try again." << endl;
    }
}
void home();
bool isMobileNumberRegistered(const string& mobileNo) {
    ifstream usersFile("users.txt");
    string line;
    while (getline(usersFile, line)) {
        istringstream iss(line);
        string registeredMobileNo, userId, password;
        if (getline(iss, userId, ',') && getline(iss, password, ',')&& getline(iss, registeredMobileNo, ',') ) {
            if (registeredMobileNo == mobileNo) {
                usersFile.close();
                return true; // Mobile number is already registered
            }
        }
    }
    usersFile.close();
    return false; // Mobile number is not registered
}

bool isValidMobileNumber(const string& mobileNumber) {
    if (mobileNumber.length() != 10)
        return false;

    for (size_t i = 0; i < mobileNumber.length(); i++) {
        if (!isdigit(mobileNumber[i]))
            return false;
    }

    return true;
}

void registerUser() {
    string mobileNo;
    cout << "Enter your mobile number: ";
    cin >> mobileNo;

    if (!isValidMobileNumber(mobileNo)) {
        cout << "Invalid mobile number. Please enter a 10-digit number." << endl;
        home();
    }

    if (isMobileNumberRegistered(mobileNo)) {
        cout << "Mobile number already registered. Please login." << endl;
        home();
    }

    currentUser.mobileNo = mobileNo;
    cout << "Enter your password: ";
    cin >> currentUser.password;
    currentUser.userId = generateUserId();
    currentUser.isLoggedIn = true;
    saveUser(currentUser);
    //saveScore(currentUser.userId, 0);
    cout << "Registration successful! Your User ID is: " << currentUser.userId << endl;
    showOptions();
}


bool isPasswordCorrect(const string& username, const string& password) {
    ifstream usersFile("users.txt");
    if (usersFile.is_open()) {
        string line;
        while (getline(usersFile, line)) {
            stringstream ss(line);
            string storedUsername, storedPassword;
            int userId;
            getline(ss, storedUsername, ',');
            getline(ss, storedPassword, ',');
            ss >> userId;
            if (storedUsername == username && storedPassword == password) {
                usersFile.close();
                return true; // Password is correct
            }
        }
        usersFile.close();
    }
    return false; // Password is incorrect or user not found
}

bool isUsernameRegistered(const string& username) {
    ifstream usersFile("users.txt");
    string line;

    if (usersFile.is_open()) {
        while (getline(usersFile, line)) {
            // Split the line into username and mobile number
            stringstream ss(line);
            string storedUsername, mobileNumber;
            getline(ss, storedUsername, ',');
            getline(ss, mobileNumber, ',');

            if (storedUsername == username) {
                usersFile.close();
                return true;  // Username found
            }
        }

        usersFile.close();
    }

    return false;  // Username not found
}


void login() {
    string username;
    cout << "Enter your username: ";
    cin >> username;

    if (!isUsernameRegistered(username)) {
        cout << "Username not found. Please register first." << endl;
        return;
    }

    string password;
    cout << "Enter your password: ";
    cin >> password;

    if (!isPasswordCorrect(username, password)) {
        cout << "Invalid password. Please try again." << endl;
        return;
    }

   // int userId = getUserId(username);
    cout << "Login successful!" << endl;
    showOptions();
   // cout << "User ID: " << userId << endl;
}



void home() {
    string option;
    while (true) {
        cout << "\nMain Menu\n";
        cout << "1. Register\n";
        cout << "2. Login\n";
        cout << "3. Exit\n";
        cout << "Enter your choice (1-3): ";
        cin >> option;

        if (option == "1") {
            registerUser();
        } else if (option == "2") {
            login();
            if (currentUser.isLoggedIn) {
                break;
            }
        } else if (option == "3") {
            cout << "Exiting the program. Goodbye!" << endl;
            exit(0);
        } else {
            cout << "Invalid option. Please try again." << endl;
        }
    }
}

int main() {
    cout << "Welcome to the Test Portal!" << endl;

    while (true) {
        if (currentUser.isLoggedIn) {
            showOptions();
        } else {
            home();
        }
    }

    return 0;
}
