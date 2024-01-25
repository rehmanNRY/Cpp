#include <iostream>
#include <fstream>
#include <string>
#include <cstdio>
#include <windows.h>

using namespace std;

struct ChallanInfo {
    string cnicNumber;
    string name;
    string carModel;
    string carNumber;
};

// Drawing Car and Traffic signal
void drawCar(int position, int screenWidth) {
    cout << "\n\n";
    cout << string(screenWidth - 5, ' ') << "   _____\n";
    cout << string(screenWidth - 5, ' ') << "  |  R  |\n";
    cout << string(screenWidth - 5, ' ') << "  |-----|\n";
    cout << string(screenWidth - 5, ' ') << "  |  Y  |\n";
    cout << string(screenWidth - 5, ' ') << "  |-----|\n";
    cout << string(screenWidth - 5, ' ') << "  |  G  |\n";
    cout << string(screenWidth - 5, ' ') << "  |_____|\n";
    cout << string(screenWidth - 5, ' ') << "    ||\n";
    cout << string(position, ' ') << "  ______" 
         << string(screenWidth - 5 - position - 8, ' ') << "    ||\n";
    cout << string(position, ' ') << " /|_||_\\`.__" 
         << string(screenWidth - 5 - position - 12, ' ') << "    ||\n";
    cout << string(position, ' ') << "(   _    _ _\\" 
         << string(screenWidth - 5 - position - 13, ' ') << "    ||\n";
    cout << string(position, ' ') << "=`-(_)--(_)-'" 
         << string(screenWidth - 5 - position - 13, ' ') << "    ||\n";
}

// Draw Road
void drawRoad(int screenWidth) {
    cout << string(screenWidth + 4, '_') << endl;
}

// Car Animation
void carAnimation(){
    const int screenWidth = 75; // Adjust this based on your console width
    int carPosition = 0;
    while (true) {
        system("CLS");
        drawCar(carPosition, screenWidth);
        drawRoad(screenWidth);
        if (carPosition >= screenWidth - 19) {
            break; // Exit the loop when the car reaches the end
        }
        carPosition = (carPosition + 1) % (screenWidth + 10);
        Sleep(5); // Sleep for 5 milliseconds
    }
}

// Pay Challan and save details to file
void payChallan(ChallanInfo& challanInfo){
    cout << "-----------------------------\n";
    cout << "        Challan Payment\n";
    cout << "-----------------------------\n";

    cout << "Enter CNIC Number: ";
    cin >> challanInfo.cnicNumber;

    cout << "Enter Driver's Name: ";
    cin.ignore();
    getline(cin, challanInfo.name);

    cout << "Enter Car Model: ";
    getline(cin, challanInfo.carModel);

    cout << "Enter Car Number: ";
    getline(cin, challanInfo.carNumber);

    // Displaying Challan Information
    cout << "\nChallan Information:" << endl;
    cout << "CNIC Number: " << challanInfo.cnicNumber << endl;
    cout << "Driver's Name: " << challanInfo.name << endl;
    cout << "Car Model: " << challanInfo.carModel << endl;
    cout << "Car Number: " << challanInfo.carNumber << endl;

    // Save details to file
    ofstream outFile("challan_details.txt", ios::app);
    if (outFile.is_open()) {
        outFile << "-----------------------------\n";
        outFile << "Challan Information:\n";
        outFile << "CNIC Number: " << challanInfo.cnicNumber << endl;
        outFile << "Driver's Name: " << challanInfo.name << endl;
        outFile << "Car Model: " << challanInfo.carModel << endl;
        outFile << "Car Number: " << challanInfo.carNumber << endl;
        outFile << "-----------------------------\n";
        outFile.close();
    }

    cout << "\n=>> Challan Paid successfully!" << endl;
    Sleep(1000);
}

int main() {
    bool programRunning = true;
    while (programRunning){
        carAnimation();
        char redSignalChoice, greenSignalChoice, signalStatus = 'r';
        ChallanInfo challanInfo;

        cout << "==> Attention, there's a traffic signal!" << endl << endl;
        Sleep(800);
        cout << " =>> Signal Status: Red" << endl << endl;
        Sleep(800);
        cout << "==> Select what action to take: " << endl 
             << " =>> 1. Stop car's movement" << endl 
             << " =>> 2. Carry on driving" << endl << " =>> ";
        cin >> greenSignalChoice;

        if(greenSignalChoice == '1' && signalStatus == 'r'){
            Sleep(800);
            cout << "\n==> We've stopped the car!" << endl << "==> Await the signal to change." << endl;
            Sleep(800);
            cout << endl << " =>> Signal Status: Yellow" << endl;
            Sleep(800);
            cout << " =>> Signal Status: Green" << endl;
            signalStatus = 'g';
            
            cout << "\n==> Ready to go? Are all set?" << endl << " =>> 1. Let's go." << endl << " =>> 2. Terminate the program." << endl << " =>> ";
            cin >> greenSignalChoice;
            switch (greenSignalChoice){
            case '1':
                Sleep(800);
                cout << endl << "==> Turning on the engine.";
                Sleep(800);
                cout << endl << "==> Let's Go!";
                Sleep(1100);
                break;
            case '2':
                Sleep(800);
                cout << "\n=>> Closing the program.";
                Sleep(800);
                programRunning = false;
                break;
            default:
                Sleep(800);
                cout << endl << "=>> Invalid choice!" << endl << "=>> Rebooting in progress.." << endl;
                Sleep(1500);
                break;
            }
        } else if(greenSignalChoice == '2' && signalStatus == 'r'){
            cout << endl << "==> Pay the challan due to a traffic violation." << endl;
            payChallan(challanInfo);
            cout << "==> Again starting the journey..";
            Sleep(800);
        } else {
            cout << endl << "=>> Invalid choice!" << endl << "Rebooting in progress..";
            Sleep(800);
        }
    }
    return 0;
}
