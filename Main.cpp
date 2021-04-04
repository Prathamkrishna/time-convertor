// cpp prog to convert time to hrs or time into world time
#include<bits/stdc++.h>
using namespace std;

int minstohours(int x);
int loctoglobe(string zone, int y, int z);
int gmtconvert(int y, int z);
int istconvert(int y, int z);
int edtconvert(int y, int z);
int cstconvert(int y, int z);

int main() {
    int options;
    cout << "enter 0 to convert minutes into hours and 1 for converting local time to world time" << endl;
    cin >> options;
    switch (options) {
    case 0:
        cout << "enter time in minutes" << endl;
        int minutes;
        cin >> minutes;
        minstohours(minutes);
        break;
    case 1:
        cout << "enter time zone" << endl;
        string timezone;
        cin >> timezone;
        cout << "enter time as hours" << endl;
        int hours;
        cin >> hours;
        cout << "enter time as mins" << endl;
        int mins;
        cin >> mins;
        loctoglobe(timezone, hours, mins);
        break;
    }
}

int minstohours(int x) {
    int minsafterconversion;
    int hrsafterconversion;
    minsafterconversion = x % 60;
    hrsafterconversion = x / 60;
    if (hrsafterconversion > 24) {
        int daysafterconversion;
        daysafterconversion = hrsafterconversion / 24;
        hrsafterconversion = hrsafterconversion % 24;
        cout << "the time converted into days and hours is: " << endl;
        cout << "DAYS: " << daysafterconversion << " HOURS: " << hrsafterconversion << " MINS: " << minsafterconversion << endl;
    }
    else {
        cout << "the time converted into hours is: " << endl;
        cout << "HOURS: " << hrsafterconversion << " MINS: " << minsafterconversion << endl;
    }
    return 0;
}

int loctoglobe(string zone, int y, int z) {
    int isthrs, istmins, gmthrs, gmtmins, edthrs, edtmins, csthrs, cstmins;
    //timezones used are gmt, ist, edt, cst
    if (zone == "gmt" || zone == "GMT") {
        gmtconvert(y, z);
    }
    else if (zone == "ist" || zone == "IST") {
        istconvert(y, z);
    }
    else if (zone == "edt" || zone == "EDT") {
        edtconvert(y, z);
    }
    else if (zone == "cst" || zone == "CST") {
        cstconvert(y, z);
    }
    else{
        cout<<"invalid input"<<endl;
    }
    return 0;
}

int gmtconvert(int y, int z){
    int isthrs, istmins, gmthrs, gmtmins, edthrs, edtmins, csthrs, cstmins;
        isthrs = y + 5;
        istmins = z + 30;
        if (istmins > 60) {
            isthrs++;
            istmins = istmins - 60;
        }
        if (isthrs >= 24) {
            isthrs = isthrs - 24;
        }
        cout << "Time(ist): " << isthrs << ":" << istmins << endl;

        //gmt to edt

        edthrs = y - 8;
        edtmins = z;
        if (edtmins > 60) {
            edthrs++;
            edtmins = edtmins - 60;
        }
        if (edthrs <= 0) {
            edthrs = edthrs + 24;
        }
        cout << "Time(edt): " << edthrs << ":" << edtmins << endl;

        //gmt to cst

        csthrs = y - 5;
        cstmins = z;
        if (cstmins > 60) {
            csthrs++;
            cstmins = cstmins - 60;
        }
        if (csthrs <= 0) {
            csthrs = csthrs + 24;
        }
        cout << "Time(cst): " << csthrs << ":" << cstmins << endl;

}

int istconvert(int y, int z){
    int isthrs, istmins, gmthrs, gmtmins, edthrs, edtmins, csthrs, cstmins;

    //ist to gmt

    gmthrs = y - 5;
    gmtmins = z - 30;
    if (gmtmins < 0) {
        gmtmins = gmtmins + 60;
        gmthrs--;
    }
    if (gmthrs < 0) {
        gmthrs = gmthrs + 24;
    }
    cout << "Time(gmt): " << gmthrs << ":" << gmtmins << endl;

    //ist to edt

    edthrs = y - 9;
    edtmins = z - 30;
    if (edtmins < 0) {
        edtmins = edtmins + 60;
        edthrs--;
    }
    if (edthrs < 0) {
        edthrs = edthrs + 24;
    }
    cout << "Time(edt): " << edthrs << ":" << edtmins << endl;

    //ist to cst

    csthrs = y - 10;
    cstmins = z - 30;
    if (cstmins < 0) {
        cstmins = cstmins + 60;
        csthrs--;
    }
    if (csthrs < 0) {
        csthrs = csthrs + 24;
    }
    cout << "Time(cst): " << csthrs << ":" << cstmins << endl;
    
}

int edtconvert(int y, int z){
    int isthrs, istmins, gmthrs, gmtmins, edthrs, edtmins, csthrs, cstmins;
    
    //edt to gmt
    
    gmthrs = y + 4;
    gmtmins = z;
    if (gmthrs >= 24) {
        gmthrs = gmthrs - 24;
    }
    cout << "Time(gmt): " << gmthrs << ":" << gmtmins << endl;

    //edt to ist

    isthrs = y + 9;
    istmins = z + 30;
    if (istmins >= 60) {
        istmins = istmins - 60;
        isthrs++;
    }
    if (isthrs >= 24) {
        isthrs = isthrs - 24;
    }
    cout << "Time(ist): " << isthrs << ":" << istmins << endl;
    
    //edt to cst
    
    csthrs = y - 1;
    cstmins = z;
    if (csthrs < 0) {
        csthrs = csthrs + 24;
    }
    cout << "Time(cst): " << csthrs << ":" << cstmins << endl;
}

int cstconvert(int y, int z){
    int isthrs, istmins, gmthrs, gmtmins, edthrs, edtmins, csthrs, cstmins;
    
    //cst to gmt
    
    gmthrs = y + 5;
    gmtmins = z;
    if (gmthrs >= 24) {
        gmthrs = gmthrs - 24;
    }
    cout << "Time(gmt): " << gmthrs << ":" << gmtmins << endl;

    //cst to ist

    isthrs = y + 10;
    istmins = z + 30;
    if (istmins >= 60) {
        istmins = istmins - 60;
        isthrs++;
    }
    if (isthrs >= 24) {
        isthrs = isthrs - 24;
    }
    cout << "Time(ist): " << isthrs << ":" << istmins << endl;

    //cst to edt

    edthrs = y + 1;
    edtmins = z;
    if (edthrs > 24) {
        edthrs = edthrs - 24;
    }
    cout << "Time(edt): " << edthrs << ":" << edtmins << endl;

}
