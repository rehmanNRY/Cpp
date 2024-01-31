#include <iostream>
#include <climits>
#include <fstream>
#include <sstream>
#include <iomanip>
#include <algorithm>
#include <conio.h>

using namespace std;

// Admin Credentials
const string adminName = "admin";
const string adminPass = "admin";

// =============== Functions Declarations ================

void title();

void adminLogin();
void adminDashboard();

void showAllCars();
void showAllCarsList();
void addCar();
void removeCar();
void UpdateCar();
void searchACar();
void searchCars();
void showSales();
void showFeedbacks();

void userLogin();
void createUserAccount();
bool isUsernameExists(const string& username);
void existingLoginUser();

void userDashboard();
void showCarsUser();
void searchCarUser();
void getFeedback();
void purchaseCar();

void drawCar(int position, int screenWidth);
void drawRoad(int screenWidth);
void carAnimation();
// =============== Main Function ================
int main(){
    while (true){
        system("CLS");
        title();
        cout << "\n \nMain Menu > Log-in \n\n";
        int loginChoice;
        login:
        cout << string(65, '=');
        cout << "\n==> Select one of the following option: \n \n";
        cout << "=>> 1. Admin Log-in \n";
        cout << "=>> 2. User Log-in \n";
        cout << "=>> 3. Exit \n";
        cout << "=>> Your Selection: ";
        cin >> loginChoice;
        if(cin.fail() || loginChoice < 1 || loginChoice > 3){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<endl << string(65, '=');
            cout << "\n==> Invalid choice! Choose again! \n";
            goto login;
        }
        switch (loginChoice){
        case 1:
            adminLogin();
            break;
        case 2:
            userLogin();
            break;
        case 3:
            cout << "\n==> Exiting the program..";
            exit(0);
        default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<endl << string(65, '=');
            cout << "\n Invalid choice! Choose again! \n";
            goto login;
            break;
        }
    }
}

// =============== Functions Definitions ================
// Program Title
void title(){
    cout << string(65, '=');
    cout << "\n|\t(Abdul Rehman)\t \tCar Management System\t \t| \n";
    cout << string(65, '=');
}

// Admin Login
void adminLogin(){
    system("CLS");
    title();
    cout << "\n \nMain Menu > Log-in > Admin-Login\n\n";
    cout << string(65, '=') << endl;
    string adminLoginName, adminLoginPass;
    cout << "==> Enter Admin Username: ";
    cin >> adminLoginName;
    cout << "==> Enter Admin Password: ";
    cin >> adminLoginPass;
    if(adminLoginName != adminName || adminLoginPass != adminPass){
        cout << endl << string(65, '=');
        cout << "\n==> Invalid Credentials! Try again! \n";
        int adminInvalidChoice;
        adminInvalid:
        cout << string(65, '=');
        cout << "\n==> Select what to do now: \n \n";
        cout << "=>> 1. Try Admin Log-in again \n";
        cout << "=>> 2. Back to Main-Menu \n";
        cout << "=>> 3. Exit program \n";
        cout << "=>> Your Selection: ";
        cin >> adminInvalidChoice;
        if(cin.fail() || adminInvalidChoice < 1 || adminInvalidChoice > 3){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<endl << string(65, '=');
            cout << "\n==> Invalid choice! Choose again! \n";
            goto adminInvalid;
        }
        switch (adminInvalidChoice){
        case 1:
            adminLogin();
            break;
        case 2:
            cout << "==> Back to main-menu";
            main();
            break;
        case 3:
            cout << "\n==> Exiting the program..";
            exit(0);
        default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<endl << string(65, '=');
            cout << "\n Invalid choice! Choose again! \n";
            goto adminInvalid;
            break;
        }
    }else{
        cout << endl << string(65, '=');
        cout << "\n==> Logged in as admin successfully!";
        cout << endl << string(65, '=');
        adminDashboard();
    }
}

// Admin Dashboard
void adminDashboard(){
    system("CLS");
    title();
    cout << "\n \n## Welcome to Admin Dashboard\n\n";
    int adminDashChoice;
    adminDash:
    cout << string(65, '=');
    cout << "\n==> Select one of the following option: \n \n";
    cout << "=>> 1. Show all Cars------------ \n";
    cout << "=>> 2. Add a NEW Car------------ \n";
    cout << "=>> 3. Remove a Car------------- \n";
    cout << "=>> 4. Update Car Details------- \n";
    cout << "=>> 5. Search a Car------------- \n";
    cout << "=>> 6. Show Sales/Customers----- \n";
    cout << "=>> 7. Show Feedback/Complains-- \n";
    cout << "=>> 8. Back to Main-Menu-------- \n";
    cout << "=>> 9. Exit program------------- \n";
    cout << "=>> Your Selection: ";
    cin >> adminDashChoice;
    if(cin.fail() || adminDashChoice < 1 || adminDashChoice > 8){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto adminDash;
    }
    switch (adminDashChoice){
    case 1:
        showAllCars();
        break;
    case 2:
        addCar();
        break;
    case 3:
        removeCar();
        break;
    case 4:
        UpdateCar();
        break;
    case 5:
        searchCars();
        break;
    case 6:
        showSales();
        break;
    case 7:
        showFeedbacks();
        break;
    case 8:
        cout << "==> Back to main-menu";
        main();
        break;
    case 9:
        cout << "\n==> Exiting the program..";
        exit(0);
    default:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto adminDash;
        break;
    }
}

// Show all cars list
void showAllCarsList(){
    // Open excel file
    ifstream excelFile("carsData.csv");
    if (!excelFile.is_open()) {
        cerr << "Failed to open excel file!" << endl;
        return;
    }
    string line;
    getline(excelFile, line);  // Read and ignore the header line
    cout << setw(10) << "Company" << setw(10) << "Year" << setw(10) << "Color" << setw(10) << "Price" << setw(15) << "Total Cars" << endl;
    cout << string(55, '-') << endl;
    const int arraySize = 5;
    string tokens[arraySize];
    while (getline(excelFile, line)) {
        istringstream ss(line);
        for (int i = 0; i < arraySize; ++i) {
            getline(ss, tokens[i], ',');
        }
        if (excelFile.fail()) {
            break;
        }
        cout << setw(10) << tokens[0] << setw(10) << tokens[1] << setw(10) << tokens[2] << setw(10) << tokens[3] << setw(15) << tokens[4] << endl;
        cout << string(55, '-') << endl;
    }
    excelFile.close();
}

// Show all Cars
void showAllCars(){
    system("CLS");
    title();
    cout << "\n \nAdmin Dashboard > Show All Cars\n\n";
    cout << string(65, '=') << endl;
    showAllCarsList();
    // Showing options after displaying data
    int showCarsOption;
    showCarsOptions:
    cout << string(65, '=');
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Back to Admin Dashboard";
    cout << "\n =>> 2. Back to Main-Menu";
    cout << "\n =>> 3. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> showCarsOption;
    if(cin.fail() || showCarsOption < 1 || showCarsOption > 3){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto showCarsOptions;
    }
    switch (showCarsOption){
    case 1:
        adminDashboard();
        break;
    case 2:
        main();
        break;
    case 3:
        cout << "\n==> Exiting the program..";
        exit(0);
        break;
    default:
    cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto showCarsOptions;
        break;
    }
}

// Add a NEW Car
void addCar(){
    system("CLS");
    title();
    cout << "\n \nAdmin Dashboard > Add Car\n\n";
    cout << string(65, '=');
    string carBrand, carModel, carColor, carPrice, carTotal;
    // Getting Car Information
    addingCar:
    cout << "\n==> Fill the information to add Car... \n";
    cout << " =>> Car Brand: ";
    cin >> carBrand;
    cout << " =>> Manufacturing year: ";
    cin >> carModel;
    cout << " =>> Car Color: ";
    cin >> carColor;
    cout << " =>> Car Price: ";
    cin >> carPrice;
    cout << " =>> Total cars: ";
    cin >> carTotal;
    // Saving Data in excel file
    ofstream excelFile("carsData.csv", ios::app); // Open in append mode
    if (!excelFile.is_open()) {
        cerr << "Failed to open excel file!" << endl;
    }
    // Check if the file is empty
    excelFile.seekp(0, ios::end);
    bool isEmpty = excelFile.tellp() == 0;
    // If the file is empty, write headers
    if (isEmpty) {
        excelFile << "Company,Year,Color,Price,Total Cars\n";
    }
    // Append data to the file
    excelFile << carBrand << "," << carModel << "," << carColor << "," << carPrice << "," << carTotal << "\n";
    excelFile.close();
    cout << string(65, '=') << endl;
    cout << carTotal << " " << carColor << " " << carBrand << " cars from " << carModel << ", priced at $" << carPrice << ", added to the data.\n";
    int addingCarOption;
    addingCarOptions:
    cout << string(65, '=');
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Add another car";
    cout << "\n =>> 2. Back to Admin Dashboard";
    cout << "\n =>> 3. Back to Main-Menu";
    cout << "\n =>> 4. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> addingCarOption;
    if(cin.fail() || addingCarOption < 1 || addingCarOption > 4){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto addingCarOptions;
    }
    switch (addingCarOption)
    {
    case 1:
        goto addingCar;
        break;
    case 2:
        adminDashboard();
        break;
    case 3:
        main();
        break;
    case 4:
        cout << "\n==> Exiting the program..";
        exit(0);
        break;
    default:
    cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto addingCarOptions;
        break;
    }
}

// Remove a Car
void removeCar() {
    system("CLS");
    title();
    cout << "\n \nAdmin Dashboard > Remove Car\n\n";
    cout << string(65, '=') << endl;

    // Display the list of cars before removal
    showAllCarsList();

    // Input the details of the car to be removed
    string carBrandToRemove;
    cout << string(65, '=') << endl;
    cout << "\n==> Enter the brand of the car to remove: ";
    cin >> carBrandToRemove;

    // Open the original file and a temporary file
    ifstream inputFile("carsData.csv");
    ofstream tempFile("tempData.csv", ios::app);

    // Check if the files are open
    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Failed to open files!" << endl;
        return;
    }

    // Copy data from the original file to the temporary file, excluding the specified car
    string line;
    getline(inputFile, line); // Read and ignore the header line

    tempFile << line << "\n"; // Write the header line to the temporary file

    while (getline(inputFile, line)) {
        istringstream ss(line);
        string brand;
        getline(ss, brand, ',');

        if (brand != carBrandToRemove) {
            tempFile << line << "\n"; // Write the line to the temporary file
        }
    }

    // Close the files
    inputFile.close();
    tempFile.close();

    // Remove the original file and rename the temporary file
    remove("carsData.csv");
    rename("tempData.csv", "carsData.csv");
    cout << endl << string(65, '=');
    cout << "\n==> Car removed successfully! \n";

    // Ask the user for further actions
    int removeCarOption;
    removeCarOptions:
    cout << string(65, '=') << endl;
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Remove another car";
    cout << "\n =>> 2. Show remaining cars";
    cout << "\n =>> 3. Back to Admin Dashboard";
    cout << "\n =>> 4. Back to Main-Menu";
    cout << "\n =>> 5. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> removeCarOption;

    if (cin.fail() || removeCarOption < 1 || removeCarOption > 3) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto removeCarOptions;
    }

    switch (removeCarOption) {
    case 1:
        removeCar();
        break;
    case 2:
        showAllCarsList();
        goto removeCarOptions;
        break;
    case 3:
        adminDashboard();
        break;
    case 4:
        main();
        break;
    case 5:
        cout << "\n==> Exiting the program..";
        exit(0);
        break;
    default:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto removeCarOptions;
        break;
    }
}

// Update Car
void UpdateCar(){
    system("CLS");
    title();
    cout << "\n \nAdmin Dashboard > Update Car\n\n";
    cout << string(65, '=') << endl;

    // Display the list of cars before updating
    showAllCarsList();

    // Input the details of the car to be updated
    string carBrandToUpdate;
    cout << string(65, '=') << endl;
    cout << "\n==> Enter the brand of the car to update: ";
    cin >> carBrandToUpdate;

    // Open the original file and a temporary file
    ifstream inputFile("carsData.csv");
    ofstream tempFile("tempData.csv", ios::app);

    // Check if the files are open
    if (!inputFile.is_open() || !tempFile.is_open()) {
        cerr << "Failed to open files!" << endl;
        return;
    }

    // Copy data from the original file to the temporary file, updating the specified car
    string line;
    getline(inputFile, line); // Read and ignore the header line

    tempFile << line << "\n"; // Write the header line to the temporary file

    const int arraySize = 5; // Add this line to declare array size
    string tokens[arraySize]; // Add this line to declare the tokens array

    while (getline(inputFile, line)) {
        istringstream ss(line);
        for (int i = 0; i < arraySize; ++i) {
            getline(ss, tokens[i], ',');
        }

        string brand = tokens[0]; // Use tokens array instead of getline

        if (brand == carBrandToUpdate) {
            // Display the current details of the car
            cout << "\n==> Current details of " << carBrandToUpdate << ":\n";
            cout << "Current Manufacturing Year: " << tokens[1] << "\n";
            cout << "Current Color: " << tokens[2] << "\n";
            cout << "Current Price: " << tokens[3] << "\n";
            cout << "Current Total Cars: " << tokens[4] << "\n";

            // Input the updated details
            string newCarModel, newCarColor, newCarPrice, newCarTotal;
            cout << "\n==> Enter new manufacturing year: ";
            cin >> newCarModel;
            cout << "==> Enter new color: ";
            cin >> newCarColor;
            cout << "==> Enter new price: ";
            cin >> newCarPrice;
            cout << "==> Enter new total cars: ";
            cin >> newCarTotal;
            // Write the updated details to the temporary file
            tempFile << carBrandToUpdate << "," << newCarModel << "," << newCarColor << "," << newCarPrice << "," << newCarTotal << "\n";
            cout << "\n==> Car details updated successfully!\n";
        } else {
            // If the brand doesn't match, just copy the line as is
            tempFile << line << "\n";
        }
    }

    // Close the files
    inputFile.close();
    tempFile.close();

    // Remove the original file and rename the temporary file
    remove("carsData.csv");
    rename("tempData.csv", "carsData.csv");

    // Ask the user for further actions
    int updateCarOption;
    updateCarOptions:
    cout << string(65, '=') << endl;
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Update details of another car";
    cout << "\n =>> 2. Show updated cars list";
    cout << "\n =>> 3. Back to Admin Dashboard";
    cout << "\n =>> 4. Back to Main-Menu";
    cout << "\n =>> 5. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> updateCarOption;

    if (cin.fail() || updateCarOption < 1 || updateCarOption > 3) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto updateCarOptions;
    }
    switch (updateCarOption) {
    case 1:
        UpdateCar();
        break;
    case 2:
        showAllCarsList();
        goto updateCarOptions;
        break;
    case 3:
        adminDashboard();
        break;
    case 4:
        main();
        break;
    case 5:
        cout << "\n==> Exiting the program..";
        exit(0);
        break;
    default:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto updateCarOptions;
        break;
    }
}

// Search a Car
void searchACar(){
    int searchOption;
    cout << "\n==> Select search criteria:";
    cout << "\n=>> 1. Brand";
    cout << "\n=>> 2. Year";
    cout << "\n=>> 3. Color";
    cout << "\n=>> 4. Price";
    cout << "\n=>> 5. Total Cars";
    cout << "\n=>> 6. Back to Admin Dashboard";
    cout << "\n=>> Your Choice: ";
    cin >> searchOption;

    if (cin.fail() || searchOption < 1 || searchOption > 6) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        searchCars();
    }

    string searchValue;
    cout << "\n==> Enter the search value: ";
    cin >> searchValue;

    // Open the file for reading
    ifstream inputFile("carsData.csv");

    if (!inputFile.is_open()) {
        cerr << "Failed to open file for reading!" << endl;
        return;
    }

    string line;
    getline(inputFile, line); // Read and ignore the header line

    const int arraySize = 5;
    string tokens[arraySize];

    bool found = false;

    // Display matching results based on the chosen search criteria
    while (getline(inputFile, line)) {
        istringstream ss(line);
        for (int i = 0; i < arraySize; ++i) {
            getline(ss, tokens[i], ',');
        }

        string value = tokens[searchOption - 1]; // Adjust index for array

        // Perform case-insensitive search
        transform(value.begin(), value.end(), value.begin(), ::tolower);
        transform(searchValue.begin(), searchValue.end(), searchValue.begin(), ::tolower);

        if (value.find(searchValue) != string::npos) {
            if (!found) {
                // Display header if this is the first matching result
                cout << setw(10) << "Company" << setw(10) << "Year" << setw(10) << "Color" << setw(10) << "Price" << setw(15) << "Total Cars" << endl;
                cout << string(55, '-') << endl;
                found = true;
            }

            // Display the matching result
            cout << setw(10) << tokens[0] << setw(10) << tokens[1] << setw(10) << tokens[2] << setw(10) << tokens[3] << setw(15) << tokens[4] << endl;
        }
    }

    // Close the file
    inputFile.close();

    if (!found) {
        cout << "\n==> No matching results found.\n";
    }
}

// Search Car
void searchCars() {
    system("CLS");
    title();
    cout << "\n \nAdmin Dashboard > Search Cars\n\n";
    cout << string(65, '=') << endl;

    searchACar();

    // Ask the user for further actions
    int searchCarsOption;
    searchCarsOptions:
    cout << string(65, '=') << endl;
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Search again";
    cout << "\n =>> 2. Back to Admin Dashboard";
    cout << "\n =>> 3. Back to Main-Menu";
    cout << "\n =>> 4. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> searchCarsOption;

    if (cin.fail() || searchCarsOption < 1 || searchCarsOption > 4) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto searchCarsOptions;
    }

    switch (searchCarsOption) {
    case 1:
        searchCars();
        break;
    case 2:
        adminDashboard();
        break;
    case 3:
        main();
        break;
    case 4:
        cout << "\n==> Exiting the program..";
        exit(0);
        break;
    default:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto searchCarsOptions;
        break;
    }
}

// Show Sales/Customers
void showSales(){
    system("CLS");
    title();
    cout << "\n \nAdmin Dashboard > Show Sales/Customers\n\n";
    cout << string(65, '=') << endl;
    // Open the purchaseInfo file
    ifstream purchaseInfoFile("purchaseInfo.csv");
    if (!purchaseInfoFile.is_open()) {
        cerr << "Failed to open purchaseInfo file!" << endl;
        return;
    }
    string line;
    getline(purchaseInfoFile, line); // Read and ignore the header line
    cout << setw(20) << "Customer Name" << setw(20) << "Customer Address" << setw(20) << "Purchased Car" << endl;
    cout << string(65, '-') << endl;

    while (getline(purchaseInfoFile, line)) {
        istringstream ss(line);
        string userName, userAddress, purchasedCar;

        getline(ss, userName, ',');
        getline(ss, userAddress, ',');
        getline(ss, purchasedCar, ',');

        cout << setw(20) << userName << setw(20) << userAddress << setw(20) << purchasedCar << endl;
        cout << string(65, '-') << endl;
    }

    // Close the file
    purchaseInfoFile.close();

    // Showing options after displaying data
    int showDataOption;
    showDataOptions:
    cout << string(65, '=');
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Back to Admin Dashboard";
    cout << "\n =>> 2. Back to Main-Menu";
    cout << "\n =>> 3. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> showDataOption;

    if(cin.fail() || showDataOption < 1 || showDataOption > 3){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto showDataOptions;
    }

    switch (showDataOption) {
        case 1:
            adminDashboard();
            break;
        case 2:
            main();
            break;
        case 3:
            cout << "\n==> Exiting the program..";
            exit(0);
            break;
        default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << string(65, '=');
            cout << "\n Invalid choice! Choose again! \n";
            goto showDataOptions;
            break;
    }
}

// Show Feedbacks
void showFeedbacks() {
    system("CLS");
    title();
    cout << "\n \nAdmin Dashboard > Show Feedbacks\n\n";
    cout << string(65, '=') << endl;
    // Open excel file
    ifstream excelFile("feedback.csv");
    if (!excelFile.is_open()) {
        cerr << "Failed to open excel file!" << endl;
        return;
    }
    string line;
    getline(excelFile, line);  // Read and ignore the header line
    cout << setw(15) << "Title" << setw(30) << "Detail" << endl;
    cout << string(65, '-') << endl;
    const int arraySize = 2;
    string tokens[arraySize];
    while (getline(excelFile, line)) {
        istringstream ss(line);
        for (int i = 0; i < arraySize; ++i) {
            getline(ss, tokens[i], ',');
        }
        if (excelFile.fail()) {
            break;
        }
        cout << setw(15) << tokens[0] << " || "<< setw(15) << tokens[1] << endl;
        cout << string(65, '-') << endl;
    }
    excelFile.close();

    // Showing options after displaying data
    int showDataOption;
    showDataOptions:
    cout << string(65, '=');
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Back to Admin Dashboard";
    cout << "\n =>> 2. Back to Main-Menu";
    cout << "\n =>> 3. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> showDataOption;

    if(cin.fail() || showDataOption < 1 || showDataOption > 3){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto showDataOptions;
    }

    switch (showDataOption) {
        case 1:
            adminDashboard();
            break;
        case 2:
            main();
            break;
        case 3:
            cout << "\n==> Exiting the program..";
            exit(0);
            break;
        default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << string(65, '=');
            cout << "\n Invalid choice! Choose again! \n";
            goto showDataOptions;
            break;
    }
}

// User Login
void userLogin(){
    system("CLS");
    title();
    cout << "\n \nMain Menu > Log-in > User-Login\n\n";
    int userLoginChoice;
    userLoginSelect:
    cout << string(65, '=') << endl;
    cout << "==> Select Log-in method: ";
    cout << "\n =>> 1. Log-in existing account";
    cout << "\n =>> 2. Create a new account";
    cout << "\n =>> 3. Back to Main-Menu";
    cout << "\n =>> 4. Exit program";
    cout << "\n =>> Your choice: ";
    cin >> userLoginChoice;
    if(cin.fail() || userLoginChoice < 1 || userLoginChoice > 4){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto userLoginSelect;
    }
    switch (userLoginChoice){
    case 1:
        existingLoginUser();
        break;
    case 2:
        createUserAccount();
        break;
    case 3:
        cout << "\n==> Back to main-menu";
        main();
    case 4:
        cout << "\n==> Exiting the program..";
        exit(0);
    default:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto userLoginSelect;
        break;
    }
}

// Check if the username already exists
bool isUsernameExists(const string& username) {
    ifstream userFile("accountsData.csv");
    // ofstream userFile("accountsData.csv", ios::app);
    if (userFile.is_open()) {
        string line;
        getline(userFile, line); // Read and ignore the header line
        while (getline(userFile, line)) {
            istringstream ss(line);
            string existingUsername;
            getline(ss, existingUsername, ',');
            if (existingUsername == username) {
                userFile.close();
                return true;
            }
        }
        userFile.close();
    } else {
        cerr << "Failed to open user data file!" << endl;
    }
    return false;
}

// Create a user account
void createUserAccount() {
    system("CLS");
    title();
    cout << "\n \nMain Menu > Log-in > User-Login > Create User Account\n\n";
    cout << string(65, '=') << endl;

    // Get user input for account details
    string username, fullName, email, password, address;

    // Check if the username already exists
    bool usernameExists;
    do {
        makeUsername:
        cout << " =>> Enter Username: ";
        cin >> username;
        usernameExists = isUsernameExists(username);
        if (usernameExists) {
            cout << "\n==> Username already exists! Please choose another username.\n";
            goto makeUsername;
        }
    } while (usernameExists);

    // Get other user details
    cout << " =>> Enter Full Name: ";
    cin.ignore(); // Clear the buffer
    getline(cin, fullName);
    cout << " =>> Enter Email: ";
    cin >> email;
    cout << " =>> Enter Password: ";
    cin >> password;
    cout << " =>> Enter Address: ";
    cin.ignore(); // Clear the buffer
    getline(cin, address);

    // Save user data in the user data file
    ofstream accountsFile("accountsData.csv", ios::app); // Open in append mode
    if (!accountsFile.is_open()) {
        cerr << "Failed to open accounts data file!" << endl;
    }
    // Check if the file is empty
    accountsFile.seekp(0, ios::end);
    bool isEmpty = accountsFile.tellp() == 0;
    // If the file is empty, write headers
    if (isEmpty) {
        accountsFile << "Username,FullName,Email,Password,Address\n";
    }
    if (accountsFile.is_open()) {
        accountsFile << username << "," << fullName << "," << email << "," << password << "," << address << "\n";
        accountsFile.close();
        cout << endl << string(65, '=');
        cout << "\n==> Account created successfully, " << username << endl;
        cout << string(65, '=') << endl;
        cout << "\n==> Press any key to Goto User Dashboard!...";
        _getch();
        userDashboard();
    } else {
        cerr << "Failed to open user account data file for writing!" << endl;
        // After creating the account, show further options
        int userOptions;
        userOptionsSelect:
        cout << string(65, '=') << endl;
        cout << "\n==> Select what to do now:";
        cout << "\n =>> 1. Log-in account";
        cout << "\n =>> 2. Back to Main-Menu";
        cout << "\n =>> 3. Exit program";
        cout << "\n =>> Your Choice: ";
        cin >> userOptions;
        if(cin.fail() || userOptions < 1 || userOptions > 3){
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout <<endl << string(65, '=');
            cout << "\n==> Invalid choice! Choose again! \n";
            goto userOptionsSelect;
        }
        switch (userOptions){
            case 1:
                existingLoginUser();
                break;
            case 2:
                main();
                break;
            case 3:
                cout << "\n==> Exiting the program..";
                exit(0);
            default:
                cin.clear();
                cin.ignore(INT_MAX, '\n');
                cout <<endl << string(65, '=');
                cout << "\n Invalid choice! Choose again! \n";
                goto userOptionsSelect;
                break;
        }
    }

}

// Login User Account
void existingLoginUser() {
    system("CLS");
    title();
    cout << "\n \nMain Menu > Log-in > User-Login > Log-in account\n\n";
    cout << string(65, '=') << endl;

    string enteredUsername, enteredPassword;

    // Get user input for login
    cout << " =>> Enter Username: ";
    cin >> enteredUsername;
    cout << " =>> Enter Password: ";
    cin >> enteredPassword;

    // Open the user data file for reading
    ifstream accountsFile("accountsData.csv");

    if (!accountsFile.is_open()) {
        cerr << "Failed to open accounts data file!" << endl;
        return;
    }

    string line;
    getline(accountsFile, line); // Read and ignore the header line

    bool found = false;

    while (getline(accountsFile, line)) {
        istringstream ss(line);
        string username, fullName, email, password, address;

        // Assuming the data is tab-separated, adjust if it's comma-separated
        getline(ss, username, ',');
        getline(ss, fullName, ',');
        getline(ss, email, ',');
        getline(ss, password, ',');
        getline(ss, address, ',');

        if (enteredUsername == username && enteredPassword == password) {
            found = true;
            break;
        }
    }

    // Close the file
    accountsFile.close();

    if (found) {
        cout << "\n==> Login successful! Welcome, " << enteredUsername << "!\n";
        userDashboard();
    } else {
        cout << endl << string(65, '=');
        cout << "\n==> Invalid credentials! Please try again.\n";
        // After attempting login, show further options
        int userOptions;
        userOptionsSelect:
        cout << string(65, '=') << endl;
        cout << "\n==> Select what to do now:";
        cout << "\n =>> 1. Try login again";
        cout << "\n =>> 2. Back to Main-Menu";
        cout << "\n =>> 3. Exit program";
        cout << "\n =>> Your Choice: ";
        cin >> userOptions;

        if (cin.fail() || userOptions < 1 || userOptions > 3) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << string(65, '=');
            cout << "\n==> Invalid choice! Choose again! \n";
            goto userOptionsSelect;
        }

        switch (userOptions) {
        case 1:
            existingLoginUser();
            break;
        case 2:
            main();
            break;
        case 3:
            cout << "\n==> Exiting the program..";
            exit(0);
            break;
        default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << string(65, '=');
            cout << "\n Invalid choice! Choose again! \n";
            goto userOptionsSelect;
            break;
        }
    }

}

// User Dshboard
void userDashboard(){
    system("CLS");
    title();
    cout << "\n \n## Welcome to User Dashboard\n\n";
    int userDashChoice;
    userDash:
    cout << string(65, '=');
    cout << "\n==> Select one of the following option: \n \n";
    cout << "=>> 1. Show avalible Cars-------\n";
    cout << "=>> 2. Purchase a Car----------- \n";
    cout << "=>> 3. Search a Car--------------- \n";
    cout << "=>> 4. Write Complain/Feedback-- \n";
    cout << "=>> 5. Back to Main-Menu-------- \n";
    cout << "=>> 6. Exit program------------- \n";
    cout << "=>> Your Selection: ";
    cin >> userDashChoice;
    if(cin.fail() || userDashChoice < 1 || userDashChoice > 7){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto userDash;
    }
    switch (userDashChoice){
    case 1:
        showCarsUser();
        break;
    case 2:
        purchaseCar();
        break;
    case 3:
        searchCarUser();
        break;
    case 4:
        getFeedback();
        break;
    case 5:
        cout << "==> Back to main-menu";
        main();
        break;
    case 6:
        cout << "\n==> Exiting the program..";
        exit(0);
    default:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto userDash;
        break;
    }
}

// Show all Cras User
void showCarsUser(){
    system("CLS");
    title();
    cout << "\n \nUser Dashboard > Show Avalible Cars\n\n";
    cout << string(65, '=') << endl;
    showAllCarsList();
    // Showing options after displaying data
    int showCarsOption;
    showCarsOptions:
    cout << string(65, '=');
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Back to User Dashboard";
    cout << "\n =>> 2. Back to Main-Menu";
    cout << "\n =>> 3. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> showCarsOption;
    if(cin.fail() || showCarsOption < 1 || showCarsOption > 3){
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto showCarsOptions;
    }
    switch (showCarsOption){
    case 1:
        userDashboard();
        break;
    case 2:
        main();
        break;
    case 3:
        cout << "\n==> Exiting the program..";
        exit(0);
        break;
    default:
    cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout <<endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto showCarsOptions;
        break;
    }
}

// Search a Car User
void searchCarUser(){
    system("CLS");
    title();
    cout << "\n \nUser Dashboard > Search Cars\n\n";
    cout << string(65, '=') << endl;

    searchACar();

    // Ask the user for further actions
    int searchCarsOption;
    searchCarsOptions:
    cout << string(65, '=') << endl;
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Search again";
    cout << "\n =>> 2. Back to User Dashboard";
    cout << "\n =>> 3. Back to Main-Menu";
    cout << "\n =>> 4. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> searchCarsOption;

    if (cin.fail() || searchCarsOption < 1 || searchCarsOption > 4) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto searchCarsOptions;
    }

    switch (searchCarsOption) {
    case 1:
        searchCars();
        break;
    case 2:
        userDashboard();
        break;
    case 3:
        main();
        break;
    case 4:
        cout << "\n==> Exiting the program..";
        exit(0);
        break;
    default:
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n Invalid choice! Choose again! \n";
        goto searchCarsOptions;
        break;
    }
}

// Purchase A Car
void purchaseCar() {
    system("CLS");
    title();
    cout << "\n \nUser Dashboard > Purchase a Car\n\n";
    cout << string(65, '=') << endl;

    // Show available cars
    showAllCarsList();

    // Get user input for purchasing a car
    string brandToPurchase;
    cout << "\n=>> Enter the brand of the car you want to purchase: ";
    cin >> brandToPurchase;

    // Check if the provided brand exists
    ifstream carsDataFile("carsData.csv");
    if (!carsDataFile.is_open()) {
        cerr << "Failed to open cars data file!" << endl;
        return;
    }

    string line;
    getline(carsDataFile, line); // Read and ignore the header line
    bool brandExists = false;

    while (getline(carsDataFile, line)) {
        istringstream ss(line);
        string brand, year, color, price, quantity;

        getline(ss, brand, ',');
        getline(ss, year, ',');
        getline(ss, color, ',');
        getline(ss, price, ',');
        getline(ss, quantity, ',');

        if (brandToPurchase == brand) {
            brandExists = true;
            break;
        }
    }

    carsDataFile.close();

    if (!brandExists) {
        cout << "\n==> The provided brand does not exist. Please choose again.\n";
        purchaseCar(); // Prompt user again
        return;
    }

    // Brand exists, proceed with the purchase
    string userName, userAddress;
    cout << "=>> Enter your name: ";
    cin.ignore();
    getline(cin, userName);

    cout << "=>> Enter your address: ";
    getline(cin, userAddress);

    // Imaginary payment option
    char paymentChoice;
    cout << "=>> Do you want to pay money(not real)? (y/n): ";
    cin >> paymentChoice;

    if (paymentChoice == 'y' || paymentChoice == 'Y') {
        // Payment successful, show car purchased
        cout << string(65, '=') << endl;
        cout << "\n==> Car purchased successfully!\n";
        cout << "Press any key to Get Test Drive...";
        _getch();
        carAnimation();
        // Save purchase information in a file
        ofstream purchaseInfoFile("purchaseInfo.csv", ios::app); // Open in append mode

        if (purchaseInfoFile.is_open()) {
            // Check if the file is empty
            purchaseInfoFile.seekp(0, ios::end);
            bool isEmpty = purchaseInfoFile.tellp() == 0;
            // If the file is empty, write headers
            if (isEmpty) {
                purchaseInfoFile << "Name,Address,Car Purchased\n";
            }
            purchaseInfoFile << userName << "," << userAddress << "," << brandToPurchase << "\n";
            purchaseInfoFile.close();
        } else {
            cerr << "Failed to open purchaseInfo file for writing!" << endl;
        }
    } else {
        // Payment declined
        cout << "\n==> Payment declined. Car not purchased.\n";
    }

    // After purchasing a car, show further options
    int userOptions;
    userOptionsSelect:
    cout << string(65, '=') << endl;
    cout << "\n==> Select what to do now:";
    cout << "\n =>> 1. Purchase another car";
    cout << "\n =>> 2. Back to User Dashboard";
    cout << "\n =>> 3. Back to Main-Menu";
    cout << "\n =>> 4. Exit program";
    cout << "\n =>> Your Choice: ";
    cin >> userOptions;

    if (cin.fail() || userOptions < 1 || userOptions > 4) {
        cin.clear();
        cin.ignore(INT_MAX, '\n');
        cout << endl << string(65, '=');
        cout << "\n==> Invalid choice! Choose again! \n";
        goto userOptionsSelect;
    }

    switch (userOptions) {
        case 1:
            purchaseCar();
            break;
        case 2:
            userDashboard();
            break;
        case 3:
            main();
            break;
        case 4:
            cout << "\n==> Exiting the program..";
            exit(0);
            break;
        default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << string(65, '=');
            cout << "\n Invalid choice! Choose again! \n";
            goto userOptionsSelect;
            break;
    }
}

// Write Feed Back User
void getFeedback() {
    system("CLS");
    title();
    cout << "\n \nUser Dashboard > Write Feedback\n\n";
    cout << string(65, '=') << endl;

    // Get user input for feedback
    string feedbackTitle, feedbackDetail;

    cout << " =>> Enter Feedback Title: ";
    cin.ignore();
    getline(cin, feedbackTitle);

    cout << " =>> Enter Feedback Detail: ";
    getline(cin, feedbackDetail);

    // Save feedback data in the feedback file
    ofstream feedbackFile("feedback.csv", ios::app); // Open in append mode
    if (!feedbackFile.is_open()) {
        cerr << "Failed to open feedback file!" << endl;
        return;
    }

    // Check if the file is empty
    feedbackFile.seekp(0, ios::end);
    bool isEmpty = feedbackFile.tellp() == 0;

    // If the file is empty, write headers
    if (isEmpty) {
        feedbackFile << "Title,Detail\n";
    }

    if (feedbackFile.is_open()) {
        feedbackFile << feedbackTitle << "," << feedbackDetail << "\n";
        feedbackFile.close();
        cout << endl << string(65, '=');
        cout << "\n==> Feedback submitted successfully!\n";
        // After submitting feedback, show further options
        int userOptions;
        userOptionsSelect:
        cout << string(65, '=') << endl;
        cout << "\n==> Select what to do now:";
        cout << "\n =>> 1. Write another feedback";
        cout << "\n =>> 2. Back to User Dashboard";
        cout << "\n =>> 3. Back to Main-Menu";
        cout << "\n =>> 4. Exit program";
        cout << "\n =>> Your Choice: ";
        cin >> userOptions;

        if (cin.fail() || userOptions < 1 || userOptions > 4) {
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << string(65, '=');
            cout << "\n==> Invalid choice! Choose again! \n";
            goto userOptionsSelect;
        }

        switch (userOptions) {
        case 1:
            getFeedback();
            break;
        case 2:
            userDashboard();
            break;
        case 3:
            main();
            break;
        case 4:
            cout << "\n==> Exiting the program..";
            exit(0);
            break;
        default:
            cin.clear();
            cin.ignore(INT_MAX, '\n');
            cout << endl << string(65, '=');
            cout << "\n Invalid choice! Choose again! \n";
            goto userOptionsSelect;
            break;
        }
    } else {
        cerr << "Failed to open feedback file for writing!" << endl;
    }
}

// Drawing Car
void drawCar(int position, int screenWidth) {
    cout << "\n\n";
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
    }
}