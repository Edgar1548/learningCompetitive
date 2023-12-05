#include <bits/stdc++.h>
using namespace std;
void read(int &hour, int &minute, int &second, char colon){
    cin >> hour >> colon >> minute >> colon >> second;
}

int convertToSeconds(int hour, int minute, int second){
    return hour * 3600 + minute * 60 + second;
};

void convertToFormat(int seconds, int arr[]){
    arr[0] = seconds / 3600;
    arr[1] = (seconds % 3600) / 60;
    arr[2] = seconds  - arr[0] * 3600 - arr[1] * 60;
}
    
void solve(int hour, int hourExp, int minute, int minuteExp, int second, int secondExp){
    int timeInSeconds = convertToSeconds(hour, minute, second);
    int timeInSecondsExp = convertToSeconds(hourExp, minuteExp, secondExp);
    int difference = timeInSecondsExp - timeInSeconds;
    int arr[3];
    convertToFormat(difference <= 0 ? difference + 86400 : difference, arr);
    cout << setfill('0');
    cout << setw(2) << arr[0] << ":"
        << setw(2) << arr[1] << ":"
        << setw(2) << arr[2]; 
}
int main(){
    int hour; int hourExp;
    int minute; int minuteExp;
    int second; int secondExp;
    char colon;
    read(hour, minute, second, colon);
    read(hourExp, minuteExp, secondExp, colon);
    solve(hour, hourExp, minute, minuteExp, second, secondExp);
    return 0;
}      