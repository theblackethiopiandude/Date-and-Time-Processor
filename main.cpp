#include <iostream>
//#include <time.h>
using namespace std;
int main() {
    short userInput, day, month ,year;
    char separator;
    string weekChart[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string monthsGC[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string monthsEC[13] = {"Meskerem", "Tikimt", "Hidar", "Tahisas", "Tir", "Yekatit", "Megabit", "Miazia", "Ginbot", "Sene", "Hamle", "Nehase", "Puagme"};
    int monthChart [12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int centuryChart[4] = {6, 4, 2, 0};
    while (true){
        int sizeOfMonthGC[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sizeOfMonthGC1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sizeOfMonthEC[13] = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5};
        int sizeOfMonthEC1[13] = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5};
        cout << endl;
        cout << "\t1. Show Local Date and Time" << endl;
        cout << "\t2. " << endl;
        cout << "\t3. Add n Days To Date" << endl;
        cout << "\t4. Date Difference Between Two Dates" << endl;
        cout << "\t5. Show Zemen" << endl;
        cout << "\t6. Check Leap Year" << endl;
        cout << "\t7. The Weekday For A Given Date" << endl;
        cout << "\t8. " << endl;
        cout << "\t9. " << endl;
        cout << "\t10. Exit" << endl;
        cout << "> ";
        cin >> userInput;
        if (userInput == 1){

        }else if(userInput == 2){
            cout << "\t1. GC TO EC" << endl;
            cout << "\t2. EC TO GC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {


            } else if (userInput == 2) {

            }else
                continue;

        }else if(userInput == 3){
            int newDay, newMonth, newYear, numberOfDays, oneYear=365;
            cout << "\t1. GC" << endl;
            cout << "\t2. EC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {
                cout << "Date: ";
                cin >> day >> separator >> month >> separator >> year;
                newDay = day;newMonth = month;newYear = year;
                if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
                    sizeOfMonthGC[1] = 29;
                cout<<"Number of Days You Want To Add: ";
                cin >> numberOfDays;
                newDay = day + numberOfDays;
                while (newDay >= oneYear){
                    newDay -= oneYear;
                    newYear++;
                }while (sizeOfMonthGC[newMonth - 1] < newDay){
                    newDay -= sizeOfMonthGC[newMonth - 1];
                    newMonth++;
                    if (newMonth > size(sizeOfMonthGC)){
                        newMonth -= size(sizeOfMonthGC);
                        newYear++;
                    }
                }
                cout << monthsGC[month - 1] << " " << day << ", " << year << " After " << numberOfDays << " Days is " << monthsGC[newMonth - 1] << " " << newDay << ", " << newYear << endl;
            }else if (userInput == 2) {
                cout << "Date: ";
                cin >> day >> separator >> month >> separator >> year;
                newDay = day;newMonth = month;newYear = year;
                if ((year + 1) % 100 != 0 && (year + 1) % 4 == 0  || (year + 1) % 400 == 0)
                    sizeOfMonthEC[12] = 6;
                cout<<"Number of Days You Want To Add: ";
                cin >> numberOfDays;
                newDay = day + numberOfDays;
                while (newDay >= oneYear){
                    newDay -= oneYear;
                    newYear++;
                }while (sizeOfMonthEC[newMonth - 1] < newDay){
                    newDay -= sizeOfMonthEC[newMonth - 1];
                    newMonth++;
                    if (newMonth > size(sizeOfMonthEC)){
                        newMonth -= size(sizeOfMonthEC);
                        newYear++;
                    }
                }
                cout << monthsEC[month - 1] << " " << day << ", " << year << " After " << numberOfDays << " Days is " << monthsEC[newMonth - 1] << " " << newDay << ", " << newYear << endl;

            }else
                continue;

        }else if(userInput == 4){
            int day1, month1, year1, dayDifference;
            cout << "\t1. GC" << endl;
            cout << "\t2. EC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {
                cout << "First Date GC: ";
                cin >> day >> separator >> month >> separator >> year;
                cout << "Second Date GC: ";
                cin >> day1 >> separator >> month1 >> separator >> year1;
                if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
                    sizeOfMonthGC[1] = 29;
                if (year1 % 100 != 0 && year1 % 4 == 0 || year1 % 400 == 0)
                    sizeOfMonthGC1[1] = 29;
                if(year==year1) {
                    if (month == month1) {
                        if (day == day1)      //for same year, same month, same day
                            dayDifference = 0;
                        else
                            dayDifference = abs(day - day1);  //for same year, same month but dayDifference days
                    } else if (month < month1) {
                        int result = 0;
                        for (int i = month; i < month1; i++)
                            result = result + sizeOfMonthGC[i - 1];
                        if (day == day1)      //for same year, same day but dayDifference month
                            dayDifference = result;
                        else if (day1 < day)
                            dayDifference = result + (day - day1);
                        else
                            dayDifference = result - (day1 - day);
                    }
                }
                else if(year<year1){
                    int temp=0;
                    for(int i=year; i<year1; i++){
                        if ((i % 100 != 0 && i % 4 == 0 )|| (i % 400 == 0))
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if(month == month1){
                        if(day==day1)      //for same month, same day but dayDifference year
                            dayDifference = temp;
                        else if(day<day1)
                            dayDifference = temp + (day1 - day);
                        else
                            dayDifference = temp - (day - day1);
                    }
                    else if(month<month1){
                        int result = 0;
                        for(int i=month; i<month1; i++)
                            result = result + sizeOfMonthGC1[i - 1];
                        if(day == day1)      // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if(day < day1)
                            dayDifference = temp + result + (day1 - day);
                        else
                            dayDifference = temp + result - (day - day1);
                    }
                    else{
                        int result=0;
                        for(int i=month1; i<month; i++)
                            result= result + sizeOfMonthGC1[i - 1];

                        if(day == day1)
                            dayDifference = temp - result;
                        else if(day1<day)
                            dayDifference = temp - (result + (day - day1));
                        else
                            dayDifference = temp - (result - (day1 - day1));

                    }
                } else {
                    int temp = 0;
                    for (int i = year1; i < year; i++) {
                        if ((i % 100 != 0 && i % 4 == 0) || (i % 400 == 0))
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if (month == month1) {
                        if (day == day1)      // for same day, same month but dayDifference year
                            dayDifference = temp;
                        else if (day1 < day)
                            dayDifference = temp + (day - day1);
                        else
                            dayDifference = temp - (day1 - day);
                    } else if (month1 < month) {
                        int result = 0;
                        for (int i = month1; i < month; i++)
                            result = result + sizeOfMonthGC[i - 1];
                        if (day == day1)     // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if (day1 < day) {
                            dayDifference = temp + result + (day - day1);
                        } else {
                            dayDifference = temp + result - (day - day1);
                        }
                    } else {
                        int result = 0;
                        for (int i = month; i < month1; i++)
                            result = result + sizeOfMonthGC[i - 1];

                        if (day == day1)
                            dayDifference = temp - result;
                        else if (day < day1) {
                            dayDifference = temp - result + (day1 - day);
                        } else {
                            dayDifference = temp - result - (day - day1);
                        }
                    }
                }
                cout << "The Difference is: " << dayDifference << " Days";

            } else if (userInput == 2) {
                cout << "First Date EC: ";
                cin >> day >> separator >> month >> separator >> year;
                cout << "Second Date EC: ";
                cin >> day1 >> separator >> month1 >> separator >> year1;
                if ((year + 1) % 100 != 0 && (year + 1) % 4 == 0  || (year + 1) % 400 == 0)
                    sizeOfMonthEC[12] = 6;
                if ((year1 + 1) % 100 != 0 && (year1 + 1) % 4 == 0  || (year1 + 1) % 400 == 0)
                    sizeOfMonthEC1[12] = 6;
                if(year==year1) {
                    if (month == month1) {
                        if (day == day1)      //for same year, same month, same day
                            dayDifference = 0;
                        else
                            dayDifference = abs(day - day1);  //for same year, same month but dayDifference days
                    } else if (month < month1) {
                        int result = 0;
                        for (int i = month; i < month1; i++)
                            result = result + sizeOfMonthEC[i - 1];
                        if (day == day1)      //for same year, same day but dayDifference month
                            dayDifference = result;
                        else if (day1 < day)
                            dayDifference = result + (day - day1);
                        else
                            dayDifference = result - (day1 - day);
                    }
                }
                else if(year<year1){
                    int temp=0;
                    for(int i=year; i<year1; i++){
                        if ((i + 1) % 100 != 0 && (i + 1) % 4 == 0  || (i + 1) % 400 == 0)
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if(month == month1){
                        if(day==day1)      //for same month, same day but dayDifference year
                            dayDifference = temp;
                        else if(day<day1)
                            dayDifference = temp + (day1 - day);
                        else
                            dayDifference = temp - (day - day1);
                    }else if(month<month1){
                        int result = 0;
                        for(int i=month; i<month1; i++)
                            result = result + sizeOfMonthEC1[i - 1];
                        if(day == day1)      // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if(day < day1)
                            dayDifference = temp + result + (day1 - day);
                        else
                            dayDifference = temp + result - (day - day1);
                    }else{
                        int result=0;
                        for(int i=month1; i<month; i++)
                            result= result + sizeOfMonthEC1[i - 1];

                        if(day == day1)
                            dayDifference = temp - result;
                        else if(day1<day)
                            dayDifference = temp - (result + (day - day1));
                        else
                            dayDifference = temp - (result - (day1 - day1));
                    }
                }else {
                    int temp = 0;
                    for (int i = year1; i < year; i++) {
                        if ((i + 1) % 100 != 0 && (i + 1) % 4 == 0  || (i + 1) % 400 == 0)
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if (month == month1) {
                        if (day == day1)      // for same day, same month but dayDifference year
                            dayDifference = temp;
                        else if (day1 < day)
                            dayDifference = temp + (day - day1);
                        else
                            dayDifference = temp - (day1 - day);
                    } else if (month1 < month) {
                        int result = 0;
                        for (int i = month1; i < month; i++)
                            result = result + sizeOfMonthEC[i - 1];
                        if (day == day1)     // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if (day1 < day) {
                            dayDifference = temp + result + (day - day1);
                        } else {
                            dayDifference = temp + result - (day - day1);
                        }
                    } else {
                        int result = 0;
                        for (int i = month; i < month1; i++)
                            result = result + sizeOfMonthEC[i - 1];

                        if (day == day1)
                            dayDifference = temp - result;
                        else if (day < day1) {
                            dayDifference = temp - result + (day1 - day);
                        } else {
                            dayDifference = temp - result - (day - day1);
                        }
                    }
                }
                cout << "The Difference is: " << dayDifference << " Days";
            }else
                continue;

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
        }else if (userInput == 7){
            cout << "\t1. GC" << endl;
            cout << "\t2. EC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {
                cout << "Enter Date GC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator>> year;
                int term = year / 100;
                int value = 4 * (term / size(centuryChart));
                int index = (day + monthChart[month - 1] + centuryChart[(term - value)] + (year%100) + ((year%100) / 4)) % 7;
                if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0) {
                    if ((index - 1) == -1) {
                        index = size(weekChart) ;
                    }
                    index--;
                }
                cout << monthsGC[month - 1] << " " << day << ", " << year << " is on " << weekChart[index] << endl;
            }else if (userInput == 2) {
                cout << "Enter Date EC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator>> year;
            } else{
                continue;
            }
        }else if (userInput == 8){
            break;
        }else if (userInput == 9){
            break;
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
