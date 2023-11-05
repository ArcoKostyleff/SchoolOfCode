#include <iostream>
#include <string>
#include<windows.h>


void textDelay(std::string message,int delay) {
    for (int i = 0; i < message.length(); i++) {
        Sleep(delay);
        std::cout << message[i];
    }
    std::cout << "\n";
}

int main() {

    const int n_sub = 4;
    const int n_com = 3;
    const int max_marks = 100;
    int allMarks[n_sub][max_marks] = { };

    std::string menu = "Menu: ";
    

    const std::string subjects[n_sub] = {
        "Russia",
        "Math",
        "Physics",
        "PE"
    };

    const std::string commands[n_com] = {
        "Add marks",
        "Show average mark",
        "Exit"
    };

    //menu + commads
    

    
    std::string a;
    do {
        textDelay(menu, 45);
        for (int i_com = 1; i_com <= n_com; i_com++) {
            std::cout << i_com << ") ";
            textDelay(commands[i_com - 1], 40);
        }
        do {
            std::getline(std::cin, a);
        } while (a.empty());

        if (a == "Add marks" || a == "1" || a == "add marks") {

            
            int marks_sub = -1;

            do {
                textDelay("Enter you subject", 35);
                for (int i_sub = 1; i_sub <= n_sub; i_sub++) {
                    std::cout << i_sub << ") ";
                    textDelay(subjects[i_sub - 1], 40);
                }

                std::string subject;
                std::getline(std::cin, subject);

                if (subject == "Russia" || subject == "russia" || subject == "1") {
                    marks_sub = 0;
                }
                else if (subject == "Math" || subject == "math" || subject == "2") {
                    marks_sub = 1;
                }
                else if (subject == "Physics" || subject == "physics" || subject == "3") {
                    marks_sub = 2;
                }
                else if (subject == "PE" || subject == "pe" || subject == "4") {
                    marks_sub = 3;
                }
                else {
                    textDelay("Brovskiy, i dont know this subject(, select another", 30);
                }

            } while (marks_sub == -1);
            std::string marks = "";
            std::string marks_copy;
            int len_marks;
            int buffer = 0;
            do {
                textDelay("Enter your marks", 35);
                buffer = 0;
                
                
                std::cin >>marks;

                marks_copy = marks;
                
                len_marks = marks.length();
                
                for (int i = 0; i < len_marks; i++) {
                    
                    switch (marks[i]) {
                    
                    case '2': {
                        buffer += 2;
                        break;
                    }case '3': {
                        buffer += 3;
                        break;
                    }case '4': {
                        buffer += 4;
                        break;
                    }case '5': {
                        buffer += 5;
                        break;
                    }default:
                        textDelay("Something is wrong, try again", 30);
                        break;
                    }
                }
                
            } while (buffer <= 0);
            

            allMarks[marks_sub][0] += buffer;

            for (int i = 0; i < len_marks; i++) {
                switch (marks_copy[i]) {
                case '2': {
                    allMarks[marks_sub][i + 2 + allMarks[marks_sub][1]] += 2;
                    break;
                }case '3': {
                    allMarks[marks_sub][i + 2 + allMarks[marks_sub][1]] += 3;
                    break;
                }case '4': {
                    allMarks[marks_sub][i + 2 + allMarks[marks_sub][1]] += 4;
                    break;
                }case '5': {
                    allMarks[marks_sub][i + 2 + allMarks[marks_sub][1]] += 5;
                    break;
                }
                }
            }
            allMarks[marks_sub][1] += len_marks;


            textDelay("Okey, I remembered", 60);
        }
        if (a == "Show average mark" || a == "2" || a == "show average mark") {

            int marks_sub = -1;

            do {
                textDelay("Enter you subject", 35);
                for (int i_sub = 1; i_sub <= n_sub; i_sub++) {
                    std::cout << i_sub << ") ";
                    textDelay(subjects[i_sub - 1], 40);
                }

                std::string subject;
                std::getline(std::cin, subject);

                if (subject == "Russia" || subject == "russia" || subject == "1") {
                    marks_sub = 0;
                }
                else if (subject == "Math" || subject == "math" || subject == "2") {
                    marks_sub = 1;
                }
                else if (subject == "Physics" || subject == "physics" || subject == "3") {
                    marks_sub = 2;
                }
                else if (subject == "PE" || subject == "pe" || subject == "4") {
                    marks_sub = 3;
                }
                else {
                    textDelay("Brovskiy, i dont know this subject(, select another", 30);
                }

            } while (marks_sub == -1);
            if (allMarks[marks_sub][0] == 0) {
                textDelay("Sorry, you dont have any marks",35);
            }
            else {
                //Subject
                int len_mean;
                float mean = trunc(float(allMarks[marks_sub][0]) / float(allMarks[marks_sub][1]) * 10)/ 10.0;
                if (mean == trunc(mean)) {
                    len_mean = 1;
                }
                else {
                    len_mean = 3; 
                }
                std::cout << "+";
                for (int i = 0; i < subjects[marks_sub].length(); i++) {
                    std::cout << "-";
                }
                std::cout << "+";
                //all marks
                for (int i = 0; i < allMarks[marks_sub][1]; i++) {
                    std::cout << "-";
                }
                std::cout << "+";
                for (int i = 0; i < len_mean; i++) {
                    std::cout << "-";
                }
                std::cout << "+" << "\n";
                std::cout << "|";
                std::cout << subjects[marks_sub];
                std::cout << "|";
                for (int i = 2; i < allMarks[marks_sub][1] + 2; i++) {
                    std::cout << allMarks[marks_sub][i];
                }
                std::cout << "|";
                
                std::cout << mean;
                std::cout << "|" << "\n";
                std::cout << "+";
                for (int i = 0; i < subjects[marks_sub].length(); i++) {
                    std::cout << "-";
                }
                std::cout << "+";
                //all marks
                for (int i = 0; i < allMarks[marks_sub][1]; i++) {
                    std::cout << "-";
                }
                std::cout << "+";
                for (int i = 0; i < len_mean; i++) {
                    std::cout << "-";
                }
                std::cout << "+" << "\n";
            }
        }
        if (a == "Exit" || a == "exit" || a == "3") {
            textDelay("Ok ok, i remembered you", 70);
            return 0;
        }
    
    } while (a != "Exit" || a != "exit" || a != "3");
}
