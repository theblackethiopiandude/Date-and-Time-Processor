#include <iostream>
//#include <time.h>
using namespace std;
int main() {
    short userInput, year;
    char separator;
    while (true){
        cout << endl;
        cout << "\t1. Show Local Date and Time" << endl;
        cout << "\t2. " << endl;
        cout << "\t3. " << endl;
        cout << "\t4. " << endl;
        cout << "\t5. Show Zemen" << endl;
        cout << "\t6. Check Leap Year" << endl;
        cout << "\t7. " << endl;
        cout << "\t8. " << endl;
        cout << "\t9. " << endl;
        cout << "\t10. Exit" << endl;
        cout << "> ";
        cin >> userInput;
        if (userInput == 1){

        }else if (userInput == 5){
            cout << "Enter year in EC: ";
            cin >> year;
            if (year <= 0){
                continue;
            }
            else{
                if (year % 4 == 0)
                    cout << "ZEMENE YOHANNES" << endl;
                else if (year % 4 == 1)
                    cout << "ZEMENE MATHIAS" << endl;
                else if (year % 4 == 2)
                    cout << "ZEMENE MARKOS" << endl;
                else if (year % 4 == 3)
                    cout << "ZEMENE LUKAS" << endl;

            }
        }else if(userInput == 6){
            cout << "\t1. GC" << endl;
            cout << "\t2. EC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {
                cout << "Enter year in GC: ";
                cin >> year;
                if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
                    cout << year << " is a leap year" << endl;
                else
                    cout << year << " is not a leap year" << endl;

            } else if (userInput == 2) {
                cout << "Enter year in EC: ";
                cin >> year;
                if ((year + 1) % 100 != 0 && (year + 1) % 4 == 0  || (year + 1) % 400 == 0)
                    cout << year << " is a leap year" << endl;
                else{
                    cout << year << " is not a leap year" << endl;

                }
            }else
                continue;
        }


        else if (userInput == 10){
            break;
        }
        else{
            cerr << "ERROR: INVALID ENTRY TRY AGAIN";

        }
    }
    return 0;
}
