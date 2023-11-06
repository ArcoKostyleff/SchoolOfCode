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

    const int NSubjects = 4;
    const int NSystemMarks = 2;

    const int nMeanCommand = 3;
    const int NComands = 3;
    const int max_marks = 100;
    int allMarks[NSubjects][max_marks] = { };
    int systemMArks[NSubjects][NSystemMarks] = { };

    std::string menu = "Menu: ";
    

    const std::string subjects[NSubjects] = {
        "Russian",
        "Math",
        "Physics",
        "PE"
    };
    const std::string MeanCommand[nMeanCommand] = {
        "All",
        "Best subject",
        "Worst subject"
    };

    const std::string commands[NComands] = {
        "Add marks",
        "Show average mark",
        "Exit"
    };

    //menu + commads
    
    std::string AskSubject = "Enter you subject ";
    std::string AskMarks = "Enter you marks ";
    std::string Saved = "Ok men, i saved it ";
    std::string AverageMark = "Bro, what marks do you want to see: ";
    std::string AnyMArks = "Brovskiy, you dont have any marks yet( ";
    std::string ByeBye = "Bye bye";

    std::string nCommand;
    std::string EnteredSubject;
    std::string marks;
    std::string AverageCommand;

    bool AllEmpty;
    bool flag = true;

    int StatusCommand;

    int statusObject;
    int marks_sub;
    int buffer = 0;
    int len_marks;
    
    int maxLen;
    int maxLenMean = 0;
    int maxLenSubject = 0;
    int MaxLenMarks = 0;

    int MaxSubject = -1;
    float MaxAverage = 0;

    int MinSubject = -1;
    float MinAverage = 6;

    int lenSub;

    int lenMeanMax = 0;
    int len_mean;
    int len_mean1;
    float mean;
    float mean1;
    do {
        //menu
        textDelay(menu, 45);
        for (int comand = 1; comand <= NComands; comand++) {
            std::cout << comand << ") ";
            textDelay(commands[comand - 1], 40);
        }
        do {
            std::getline(std::cin, nCommand);
        } while (nCommand == " ");
        // check what is command
        if (nCommand == "Add marks" || nCommand == "1" || nCommand == "add marks") {
            
            //check entered subject
            
            marks_sub = -1;
            do {
                textDelay(AskSubject, 35);
                for (int i = 1; i <= NSubjects; i++) {
                    std::cout << i << ") ";
                    textDelay(subjects[i - 1], 40);
                }

                
                std::getline(std::cin, EnteredSubject);

                if (EnteredSubject == "Russian" || EnteredSubject == "russian" || EnteredSubject == "1") {
                    marks_sub = 0;
                }
                else if (EnteredSubject == "Math" || EnteredSubject == "math" || EnteredSubject == "2") {
                    marks_sub = 1;
                }
                else if (EnteredSubject == "Physics" || EnteredSubject == "physics" || EnteredSubject == "3") {
                    marks_sub = 2;
                }
                else if (EnteredSubject == "PE" || EnteredSubject == "pe" || EnteredSubject == "4") {
                    marks_sub = 3;
                }
                else {
                    textDelay("Brovskiy, i dont know this subject(, select another", 30);
                }

            } while (marks_sub == -1);
            
            
            do {
                //ask for marks 
                textDelay(AskMarks, 30);
                // проверка на пустоту
                do {
                    std::getline(std::cin, marks);
                } while (marks == " ");

                buffer = 0;
                len_marks = marks.length();
                // считание оценок
                for (int i = 0; i < len_marks; i++) {

                    switch (marks[i])
                    {
                    case '2': {
                        buffer += 2;
                        break;
                    }case '3': {
                        buffer += 3;
                        break;
                    }case '4':
                        buffer += 4;
                        break;
                    case '5':
                        buffer += 5;
                        break;
                    default:
                        textDelay("Something is wrong, try again", 30);
                        buffer = -300;
                        i = len_marks;
                        break;
                    }
                }
            } while (buffer <= 0);
            //len marks
            
            //sum marks
            systemMArks[marks_sub][1] += buffer;

            for (int i = 0; i < len_marks; i++) {
                switch (marks[i])
                {
                case '2': {
                    allMarks[marks_sub][i + systemMArks[marks_sub][0]] = 2;
                    break;
                }case '3': {
                    allMarks[marks_sub][i + systemMArks[marks_sub][0]] = 3;
                    break;
                }case '4':
                    allMarks[marks_sub][i + systemMArks[marks_sub][0]] = 4;
                    break;
                case '5':
                    allMarks[marks_sub][i + systemMArks[marks_sub][0]] = 5;
                    break;
                default:
                    break;
                }
            }
            systemMArks[marks_sub][0] += len_marks;

            lenSub = subjects[marks_sub].length();

            if (lenSub > maxLenSubject) {
                maxLenSubject = lenSub;
            }
            if (systemMArks[marks_sub][0] > MaxLenMarks) {
                MaxLenMarks = systemMArks[marks_sub][0];
            }

            mean1 = trunc(float(systemMArks[marks_sub][1]) / float(systemMArks[marks_sub][0]) * 10) / 10.0;
            if (mean1 == trunc(mean1)) {
                len_mean1 = 1;
            }
            else {
                len_mean1 = 3;
            }

            if (len_mean1 > maxLenMean) {
                maxLenMean = len_mean1;
            }

            if (mean1 > MaxAverage) {
                MaxAverage = mean1;
                MaxSubject = marks_sub;
            }
            if (mean1 < MinAverage) {
                MinAverage = mean1;
                MinSubject = marks_sub;
            }

            textDelay(Saved, 30);
        }
        if (nCommand == "Show average mark" || nCommand == "2" || nCommand == "show average mark") {

            textDelay(AverageMark, 35);
            int i;
            for (i = 1; i <= NSubjects; i++) {
                std::cout << i << ") ";
                textDelay(subjects[i - 1], 40);
            }for (int j = 1; j <= nMeanCommand; j++) {
                std::cout << i + j - 1 << ") ";
                textDelay(MeanCommand[j - 1], 40);
            }
            do {
                std::getline(std::cin, AverageCommand);
            } while (AverageCommand == " ");

            StatusCommand = 0;
            // 0 = subject; 1 = all; 2 = Best subject; 3 = Worst subject;
            statusObject = -1;
            //check
            if (AverageCommand == "Russian" || AverageCommand == "russian" || AverageCommand == "1") {
                StatusCommand = 0;
                statusObject = 0;
            }
            else if (AverageCommand == "Math" || AverageCommand == "math" || AverageCommand == "2") {
                StatusCommand = 0;
                statusObject = 1;
            }
            else if (AverageCommand == "Physics" || AverageCommand == "physics" || AverageCommand == "3") {
                StatusCommand = 0;
                statusObject = 2;
            }
            else if (AverageCommand == "PE" || AverageCommand == "pe" || AverageCommand == "4") {
                StatusCommand = 0;
                statusObject = 3;
            }
            else if (AverageCommand == "All" || AverageCommand == "all" || AverageCommand == "5") {
                StatusCommand = 1;

            }
            else if (AverageCommand == "Best subject" || AverageCommand == "best subject" || AverageCommand == "6") {
                StatusCommand = 2;
            }
            else if (AverageCommand == "Worst subject" || AverageCommand == "worst subject" || AverageCommand == "7") {
                StatusCommand = 3;
            }

            
            if (StatusCommand == 0) {
                if (systemMArks[statusObject][1] != 0) {

                    mean = trunc(float(systemMArks[statusObject][1]) / float(systemMArks[statusObject][0]) * 10) / 10.0;
                    if (mean == trunc(mean)) {
                        len_mean = 1;
                    }
                    else {
                        len_mean = 3;
                    }

                    std::cout << "+";
                    //lenght Subject
                    for (int i = 0; i < subjects[statusObject].length(); i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                    //lenght marks;
                    for (int i = 0; i < systemMArks[statusObject][0]; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";

                    for (int i = 0; i < len_mean; i++) {
                        std::cout << "-";
                    }

                    std::cout << "+" << "\n";
                    //new line
                    std::cout << "|";
                    // object
                    std::cout << subjects[statusObject];
                    std::cout << "|";
                    //marks 
                    for (int i = 0; i < systemMArks[statusObject][0]; i++) {
                        std::cout << allMarks[statusObject][i];
                    }
                    std::cout << "|";

                    std::cout << mean;

                    std::cout << "|" << '\n';

                    std::cout << "+";
                    //lenght Subject
                    for (int i = 0; i < subjects[statusObject].length(); i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                    //lenght marks;
                    for (int i = 0; i < systemMArks[statusObject][0]; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";

                    for (int i = 0; i < len_mean; i++) {
                        std::cout << "-";
                    }

                    std::cout << "+" << "\n";

                    }
                else {
                    textDelay(AnyMArks, 20);
                }     
            }
            else if (StatusCommand == 1) {
                AllEmpty = true;
                for (int obj = 0; obj < NSubjects; obj++) {
                    if (systemMArks[obj][1] != 0) {
                        AllEmpty = false;
                    }
                }if(AllEmpty == false){
                    for (int obj = 0; obj < NSubjects; obj++) {
                        if (systemMArks[obj][1] != 0) {
                            mean = trunc(float(systemMArks[obj][1]) / float(systemMArks[obj][0]) * 10) / 10.0; if (mean == trunc(mean)) {
                                len_mean = 1;
                            }
                            else {
                                len_mean = 3;
                            }
                            std::cout << "+";
                            for (int i = 0; i < maxLenSubject; i++) {
                                std::cout << "-";
                            }
                            std::cout << '+';
                            for (int i = 0; i < MaxLenMarks; i++) {
                                std::cout << "-";
                            }
                            std::cout << "+";
                            for (int i = 0; i < maxLenMean; i++) {
                                std::cout << "-";
                            }
                            std::cout << "+" << "\n";
                            
                            std::cout << "|";
                            lenSub = subjects[obj].length();

                            std::cout << subjects[obj];
                            for (int i = 0; i < maxLenSubject - lenSub; i++) {
                                std::cout << " ";
                            }
                            std::cout << "|";
                            for (int i = 0; i < systemMArks[obj][0];i++) {
                                std::cout << allMarks[obj][i];
                            }

                            for (int i = 0; i < MaxLenMarks - systemMArks[obj][0]; i++) {
                                std::cout << " ";
                            }
                            std::cout << "|";
                            std::cout << mean;
                            for (int i = 0; i < maxLenMean - len_mean; i++) {
                                std::cout << " ";
                            }
                            std::cout << "|" << "\n";
                        }
                    }std::cout << "+";
                    for (int i = 0; i < maxLenSubject; i++) {
                        std::cout << "-";
                    }
                    std::cout << '+';
                    for (int i = 0; i < MaxLenMarks; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                    for (int i = 0; i < maxLenMean; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+" << "\n";
                }
                else {
                    textDelay(AnyMArks, 20);
                }
            }
            else if (StatusCommand == 2) {
                if (MaxSubject != 6) {

                    if (MaxAverage == trunc(MaxAverage)) {
                        len_mean = 1;
                    }
                    else {
                        len_mean = 3;
                    }

                    std::cout << "+";
                    //lenght Subject
                    for (int i = 0; i < subjects[MaxSubject].length(); i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                    //lenght marks;
                    for (int i = 0; i < systemMArks[MaxSubject][0]; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";

                    for (int i = 0; i < len_mean; i++) {
                        std::cout << "-";
                    }

                    std::cout << "+" << "\n";
                    //new line
                    std::cout << "|";
                    // object
                    std::cout << subjects[MaxSubject];
                    std::cout << "|";
                    //marks 
                    for (int i = 0; i < systemMArks[MaxSubject][0]; i++) {
                        std::cout << allMarks[MaxSubject][i];
                    }
                    std::cout << "|";

                    std::cout << MaxAverage;

                    std::cout << "|" << '\n';

                    std::cout << "+";
                    //lenght Subject
                    for (int i = 0; i < subjects[MaxSubject].length(); i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                    //lenght marks;
                    for (int i = 0; i < systemMArks[MaxSubject][0]; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";

                    for (int i = 0; i < len_mean; i++) {
                        std::cout << "-";
                    }

                    std::cout << "+" << "\n";
                }
                else {
                    textDelay(AnyMArks, 20);
                }
            }
            else if (StatusCommand == 3) {
                if (MinSubject != 6) {

                    if (MinAverage == trunc(MinAverage)) {
                        len_mean = 1;
                    }
                    else {
                        len_mean = 3;
                    }

                    std::cout << "+";
                    //lenght Subject
                    for (int i = 0; i < subjects[MinSubject].length(); i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                    //lenght marks;
                    for (int i = 0; i < systemMArks[MinSubject][0]; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";

                    for (int i = 0; i < len_mean; i++) {
                        std::cout << "-";
                    }

                    std::cout << "+" << "\n";
                    //new line
                    std::cout << "|";
                    // object
                    std::cout << subjects[MinSubject];
                    std::cout << "|";
                    //marks 
                    for (int i = 0; i < systemMArks[MinSubject][0]; i++) {
                        std::cout << allMarks[MinSubject][i];
                    }
                    std::cout << "|";

                    std::cout << MinAverage;

                    std::cout << "|" << '\n';

                    std::cout << "+";
                    //lenght Subject
                    for (int i = 0; i < subjects[MinSubject].length(); i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";
                    //lenght marks;
                    for (int i = 0; i < systemMArks[MinSubject][0]; i++) {
                        std::cout << "-";
                    }
                    std::cout << "+";

                    for (int i = 0; i < len_mean; i++) {
                        std::cout << "-";
                    }

                    std::cout << "+" << "\n";
                }
                else {
                    textDelay(AnyMArks, 20);
                }
            }
        }if (nCommand == "Exit" || nCommand == "3" || nCommand == "exit") {
            flag = false;
            textDelay(ByeBye, 40);
        }
    } while (flag);
}
