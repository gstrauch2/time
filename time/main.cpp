// George Strauch
// 24hr time to 12 hr and vise versa
// 03/29/2018

/* asks if 24 or 12 hour time
 * determines what the other time format would be
 * prints the result*/


#include <iostream>
using namespace std;

// returns 24 for converting to 24hr time or 12 for 12 hr time
int getChoice(){

    int intInput = 0;
    cout << "are you converting to 12 or 24 hour time? [enter '1' for 12hr, or '2' for 24]" << endl;
    cin >> intInput;

    switch(intInput){
        case 1:
            return 12;
        case 2:
            return 24;
        default:
            cerr << "choosing 12hr by default" << endl;
            return 12;
    }
}

//                                          (converting to)     (is it in the pm?)
void setTime(int *intArdMin, int *intAdrHr, int int24or12, bool *bolIsPm){
    int intTmp = 0;
    int inTmp2 = 0;
    cout << "what is the hour of the time?" << endl;
    cin >> intTmp;
    *intArdMin = intTmp;

    cout << "what is the minute of the time?" << endl;
    cin >> inTmp2;
    *intAdrHr = inTmp2;

    if(int24or12 == 24){
        char chTmp = 0;
        cout << "is this in the am or pm? ['a' for am, 'p' for pm]" << endl;
        cin >> chTmp;

        if(chTmp == 'a'){
            *bolIsPm = false;
        }
        else{
            *bolIsPm = true;
        }
    }
}

string get24Time(int intHr, int intMin, bool bolIsPm){

    string strHr = "";
    string strMin = "";

    if(bolIsPm){
        intHr += 12;
    }

    strHr = to_string(intHr);
    strMin = to_string(intMin);

    strHr.insert(strHr.begin(), 2 - strHr.length(), '0');
    strMin.insert(strMin.begin(), 2 - strMin.length(), '0');

    return strHr + ":" + strMin;
}

string get12Time(int intHr, int intMin){
    string strHr = "";
    string strMin = "";
    string strAmOrPm = "AM";

    if(intHr > 12){
        intHr = (intHr % 12);
        strAmOrPm = "PM";
    }


    strHr = to_string(intHr);
    strMin = to_string(intMin);

    strHr.insert(strHr.begin(), 2 - strHr.length(), '0');
    strMin.insert(strMin.begin(), 2 - strMin.length(), '0');

    return strHr + ":" + strMin +" " + strAmOrPm;
}

void print(string str12, string str24, int int24or12){
    if(int24or12 == 12){
        cout << "the 12 hour time format of \"" << str24 << "\" is \"" << str12 << "\"" << endl;
    }
    else{
        cout << "the 24 hour time format of \"" << str12 << "\" is \"" << str24 << "\"" << endl;
    }
}

int main(){

    int intConvertTo = 0;
    int intTimeHr = 0;
    int intTimeMin = 0;
    bool bolIsPm = false;
    string str24Time = "";
    string srt12Time = "";

    intConvertTo = getChoice();
    setTime(&intTimeMin, &intTimeHr, intConvertTo, &bolIsPm);
    str24Time = get24Time(intTimeHr, intTimeMin, bolIsPm);
    srt12Time = get12Time(intTimeHr, intTimeMin);
    print(srt12Time, str24Time, intConvertTo);

    return 0;
}