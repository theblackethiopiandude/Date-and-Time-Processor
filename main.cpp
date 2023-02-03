#include <iostream>
//#include <time.h>
using namespace std;
int main() {
    short userInput, day, month , year , newDay, newMonth, newYear;
    char separator;
    string weekChart[7] = {"Sunday", "Monday", "Tuesday", "Wednesday", "Thursday", "Friday", "Saturday"};
    string monthsGC[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    string monthsEC[13] = {"Meskerem", "Tikimt", "Hidar", "Tahisas", "Tir", "Yekatit", "Megabit", "Miazia", "Ginbot", "Sene", "Hamle", "Nehase", "Puagme"};
    int monthChart [12] = {0, 3, 3, 6, 1, 4, 6, 2, 5, 0, 3, 5};
    int centuryChart[4] = {6, 4, 2, 0};
    while (true){
        int monthOffSetGCtoEC[12] = {22,23,21,22,22,23,23,24, 25,20,21,21};
        int monthOffSetECtoGC[13] = {10, 10, 9, 9, 8, 7, 9, 8, 8, 7, 7, 6, 5};
        int gcToEcMonthMap[12] = {4,5,6,7,8,9,10,11, 12, 1,2,3};
        int ecToGcMonthMap[13] = {9, 10, 11,12,1,2,3,4,5,6,7,8, 9};
        int sizeOfMonthGC[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sizeOfMonthGC1[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
        int sizeOfMonthEC[13] = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5};
        int sizeOfMonthEC1[13] = {30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 30, 5};
        cout << endl;
        cout << "\t1. Show Local Date and Time" << endl;
        cout << "\t2. Convert Date" << endl;
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
                cout << __DATE__ << endl;
                cout << __TIME__ << endl;
        }else if(userInput == 2){
            cout << "\t1. GC TO EC" << endl;
            cout << "\t2. EC TO GC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {
                cout << "Enter Date in GC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator >> year;
                if ((year % 100 != 0 && year % 4 == 0 )|| (year  % 400 == 0)){ // checks for gregorian leap year
                    sizeOfMonthEC[12] = 6;
                    for (int i = 0; i < 2; ++i) // to decrement the off set by 1
                        monthOffSetGCtoEC[i]--;
                }
                newDay = day + monthOffSetGCtoEC[month - 1];
                newYear = year - 8;

                newMonth = gcToEcMonthMap[month - 1];
                if (month > 9)
                    newYear++;

                while (sizeOfMonthEC[newMonth - 1] < newDay){
                    newDay -= sizeOfMonthEC[newMonth - 1];
                    newMonth++;
                    if (newMonth > size(sizeOfMonthEC)){
                        newMonth -= size(sizeOfMonthEC);
                        newYear++;
                    }
                }
                cout << monthsGC[month - 1] << " " << day << ", " << year << "  in Ethiopian Calendar is  " << monthsEC[newMonth - 1] << " " << newDay << ", " << newYear << endl;


            } else if (userInput == 2) {
                cout << "Enter Date in EC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator >> year;
                if ((year % 100 != 0 && year % 4 == 0 )|| (year  % 400 == 0)){ // checks for ethiopian leap year
                    sizeOfMonthGC[1] = 29;
                    for (int i = 0; i < 6; ++i) // to increment the off set by 1
                        monthOffSetECtoGC[i]++;
                }
                newDay = day + monthOffSetECtoGC[month - 1];
                newYear = year + 7;

                newMonth = ecToGcMonthMap[month - 1];
                if (month > 4)
                    newYear++;

                while (sizeOfMonthGC[newMonth - 1] < newDay){
                    newDay -= sizeOfMonthGC[newMonth - 1];
                    newMonth++;
                    if (newMonth > size(sizeOfMonthGC)){
                        newMonth -= size(sizeOfMonthGC);
                        newYear++;
                    }
                }
                cout << newDay << separator << newMonth << separator << newYear << endl;
                cout << monthsEC[month - 1] << " " << day << ", " << year << "  in Gregorian Calendar is  " << monthsGC[newMonth - 1] << " " << newDay << ", " << newYear << endl;
            }else
                continue;

        }else if(userInput == 3){
            int numberOfDays, oneYear=365;
            cout << "\t1. GC" << endl;
            cout << "\t2. EC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {
                cout << "Enter Date in GC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator >> year;
                newDay = day;newMonth = month;newYear = year;
                if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0) // checks for leap year
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
                cout << "Enter Date in EC(dd/mm/yyyy): ";
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
            int dayDifference;
            cout << "\t1. GC" << endl;
            cout << "\t2. EC" << endl;
            cout << "> ";
            cin >> userInput;
            if (userInput == 1) {
                cout << "First Date in GC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator >> year;
                cout << "Second Date in GC(dd/mm/yyyy): ";
                cin >> newDay >> separator >> newMonth >> separator >> newYear;
                if (year % 100 != 0 && year % 4 == 0 || year % 400 == 0)
                    sizeOfMonthGC[1] = 29;
                if (newYear % 100 != 0 && newYear % 4 == 0 || newYear % 400 == 0)
                    sizeOfMonthGC1[1] = 29;
                if(year == newYear) {
                    if (month == newMonth) {
                        if (day == newDay)      //for same year, same month, same day
                            dayDifference = 0;
                        else
                            dayDifference = abs(day - newDay);  //for same year, same month but dayDifference days
                    } else if (month < newMonth) {
                        int result = 0;
                        for (int i = month; i < newMonth; i++)
                            result = result + sizeOfMonthGC[i - 1];
                        if (day == newDay)      //for same year, same day but dayDifference month
                            dayDifference = result;
                        else if (newDay < day){
                            dayDifference = result - (day - newDay) ;
                        }

                        else
                            dayDifference = result + (newDay - day);
                    }else{
                        int result=0;
                        for(int i=newMonth; i < month; i++)
                            result= result + sizeOfMonthGC1[i - 1];

                        if(day == newDay)
                            dayDifference = result;
                        else if(newDay < day)
                            dayDifference = result + (day - newDay);
                        else
                            dayDifference = result - (newDay - day);

                    }
                }
                else if(year < newYear){
                    int temp=0;
                    for(int i=year; i < newYear; i++){
                        if ((i % 100 != 0 && i % 4 == 0 )|| (i % 400 == 0))
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if(month == newMonth){
                        if(day == newDay)      //for same month, same day but dayDifference year
                            dayDifference = temp;
                        else if(day < newDay)
                            dayDifference = temp + (newDay - day);
                        else
                            dayDifference = temp - (day - newDay);
                    }
                    else if(month < newMonth){
                        int result = 0;
                        for(int i=month; i < newMonth; i++)
                            result = result + sizeOfMonthGC1[i - 1];
                        if(day == newDay)      // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if(day < newDay)
                            dayDifference = temp + result + (newDay - day);
                        else
                            dayDifference = temp + result - (day - newDay);
                    }
                    else{
                        int result=0;
                        for(int i=newMonth; i < month; i++)
                            result= result + sizeOfMonthGC1[i - 1];

                        if(day == newDay)
                            dayDifference = temp - result;
                        else if(newDay < day)
                            dayDifference = temp - (result + (day - newDay));
                        else
                            dayDifference = temp - (result - (newDay - newDay));

                    }
                } else {
                    int temp = 0;
                    for (int i = newYear; i < year; i++) {
                        if ((i % 100 != 0 && i % 4 == 0) || (i % 400 == 0))
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if (month == newMonth) {
                        if (day == newDay)      // for same day, same month but dayDifference year
                            dayDifference = temp;
                        else if (newDay < day)
                            dayDifference = temp + (day - newDay);
                        else
                            dayDifference = temp - (newDay - day);
                    } else if (newMonth < month) {
                        int result = 0;
                        for (int i = newMonth; i < month; i++)
                            result = result + sizeOfMonthGC[i - 1];
                        if (day == newDay)     // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if (newDay < day) {
                            dayDifference = temp + (result + (day - newDay));
                        } else {
                            dayDifference = temp + (result - (day - newDay));
                        }
                    } else {
                        int result = 0;
                        for (int i = month; i < newMonth; i++)
                            result = result + sizeOfMonthGC[i - 1];

                        if (day == newDay)
                            dayDifference = temp - result;
                        else if (day < newDay) {
                            dayDifference = temp - (result + (newDay - day));
                        } else {
                            dayDifference = temp - (result - (day - newDay));
                        }
                    }
                }
                cout << "The Difference is: " << dayDifference << " Days" << endl;

            } else if (userInput == 2) {
                cout << "First Date in EC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator >> year;
                cout << "Second Date in EC(dd/mm/yyyy): ";
                cin >> newDay >> separator >> newMonth >> separator >> newYear;
                if ((year + 1) % 100 != 0 && (year + 1) % 4 == 0  || (year + 1) % 400 == 0)
                    sizeOfMonthEC[12] = 6;
                if ((newYear + 1) % 100 != 0 && (newYear + 1) % 4 == 0 || (newYear + 1) % 400 == 0)
                    sizeOfMonthEC1[12] = 6;
                if(year == newYear) {
                    if (month == newMonth) {
                        if (day == newDay)      //for same year, same month, same day
                            dayDifference = 0;
                        else
                            dayDifference = abs(day - newDay);  //for same year, same month but dayDifference days
                    } else if (month < newMonth) {
                        int result = 0;
                        for (int i = month; i < newMonth; i++)
                            result = result + sizeOfMonthEC[i - 1];
                        if (day == newDay)      //for same year, same day but dayDifference month
                            dayDifference = result;
                        else if (newDay < day)
                            dayDifference = result - (day - newDay);
                        else
                            dayDifference = result + (newDay - day);
                    }else{
                        int result=0;
                        for(int i=newMonth; i < month; i++)
                            result= result + sizeOfMonthEC[i - 1];

                        if(day == newDay)
                            dayDifference = result;
                        else if(newDay < day)
                            dayDifference = result + (day - newDay);
                        else
                            dayDifference = result - (newDay - day);

                    }
                }
                else if(year < newYear){
                    int temp=0;
                    for(int i=year; i < newYear; i++){
                        if ((i + 1) % 100 != 0 && (i + 1) % 4 == 0  || (i + 1) % 400 == 0)
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if(month == newMonth){
                        if(day == newDay)      //for same month, same day but dayDifference year
                            dayDifference = temp;
                        else if(day < newDay)
                            dayDifference = temp + (newDay - day);
                        else
                            dayDifference = temp - (day - newDay);
                    }else if(month < newMonth){
                        int result = 0;
                        for(int i=month; i < newMonth; i++)
                            result = result + sizeOfMonthEC1[i - 1];
                        if(day == newDay)      // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if(day < newDay)
                            dayDifference = temp + (result + (newDay - day));
                        else
                            dayDifference = temp + (result - (day - newDay));
                    }else{
                        int result=0;
                        for(int i=newMonth; i < month; i++)
                            result= result + sizeOfMonthEC1[i - 1];

                        if(day == newDay)
                            dayDifference = temp - result;
                        else if(newDay < day)
                            dayDifference = temp - (result + (day - newDay));
                        else
                            dayDifference = temp - (result - (newDay - newDay));
                    }
                }else {
                    int temp = 0;
                    for (int i = newYear; i < year; i++) {
                        if ((i + 1) % 100 != 0 && (i + 1) % 4 == 0  || (i + 1) % 400 == 0)
                            temp = temp + 366;
                        else
                            temp = temp + 365;
                    }
                    if (month == newMonth) {
                        if (day == newDay)      // for same day, same month but dayDifference year
                            dayDifference = temp;
                        else if (newDay < day)
                            dayDifference = temp + (day - newDay);
                        else
                            dayDifference = temp - (newDay - day);
                    } else if (newMonth < month) {
                        int result = 0;
                        for (int i = newMonth; i < month; i++)
                            result = result + sizeOfMonthEC[i - 1];
                        if (day == newDay)     // for same day, dayDifference year and dayDifference month
                            dayDifference = temp + result;
                        else if (newDay < day) {
                            dayDifference = temp + result - (day - newDay);
                        } else {
                            dayDifference = temp + result + (day - newDay);
                        }
                    } else {
                        int result = 0;
                        for (int i = month; i < newMonth; i++)
                            result = result + sizeOfMonthEC[i - 1];

                        if (day == newDay)
                            dayDifference = temp - result;
                        else if (day < newDay) {
                            dayDifference = temp - (result - (newDay - day));
                        } else {
                            dayDifference = temp - (result + (day - newDay));
                        }
                    }
                }
                cout << "The Difference is: " << dayDifference << " Days" << endl;
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
                    if (month == 1 || month == 2){
                        if ((index - 1) == -1) {
                            index = size(weekChart) - 1 ;
                        }
                        index--;
                    }
                }
                cout << monthsGC[month - 1] << " " << day << ", " << year << " is on " << weekChart[index] << endl;
            }else if (userInput == 2) {
                cout << "Enter Date in EC(dd/mm/yyyy): ";
                cin >> day >> separator >> month >> separator >> year;
                if ((year % 100 != 0 && year % 4 == 0 )|| (year  % 400 == 0)){ // checks for ethiopian leap year
                    sizeOfMonthGC[1] = 29;
                    for (int i = 0; i < 6; ++i) // to increment the off set by 1
                        monthOffSetECtoGC[i]++;
                }
                newDay = day + monthOffSetECtoGC[month - 1];
                newYear = year + 7;

                newMonth = ecToGcMonthMap[month - 1];
                if (month > 4)
                    newYear++;

                while (sizeOfMonthGC[newMonth - 1] < newDay){
                    newDay -= sizeOfMonthGC[newMonth - 1];
                    newMonth++;
                    if (newMonth > size(sizeOfMonthGC)){
                        newMonth -= size(sizeOfMonthGC);
                        newYear++;
                    }
                }
                int term = newYear / 100;
                int value = 4 * (term / size(centuryChart));
                int index = (newDay + monthChart[newMonth - 1] + centuryChart[(term - value)] + (newYear%100) + ((newYear%100) / 4)) % 7;
                if (newYear % 100 != 0 && newYear % 4 == 0 || newYear % 400 == 0) {
                    if (month == 1 || month == 2){
                        if ((index - 1) == -1) {
                            index = size(weekChart) - 1 ;
                        }
                        index--;
                    }
                }
                cout << monthsEC[month - 1] << " " << day << ", " << year << " is on " << weekChart[index] << endl;
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
