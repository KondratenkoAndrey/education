//
//  main.cpp
//  overloadingPart2
//
//  Created by Андрей Кондратенко on 31.05.2018.
//  Copyright © 2018 Andrey Kondratenko. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

using namespace std;

struct Duration {
    int hour;
    int minute;
    Duration(int h = 0, int m = 0) {
        int total = h * 60 + m;
        hour = total / 60;
        minute = total % 60;
    }
};

istream& operator>>(istream& stream, Duration& duration) {
    stream >> duration.hour;
    stream.ignore(1);
    stream >> duration.minute;
    return stream;
}

ostream& operator<<(ostream& stream, const Duration& duration) {
    stream << setfill('0');
    stream << setw(2) << duration.hour << ":"
    << setw(2) << duration.minute;
    return stream;
}

Duration operator+(const Duration& lhs, const Duration& rhs) {
    return Duration(lhs.hour + rhs.hour, lhs.minute + rhs.minute);
}

bool operator< (const Duration& lhs, const Duration& rhs) {
    if (lhs.hour == rhs.hour) {
        return lhs.minute < rhs.minute;
    } else {
        return lhs.hour < rhs.hour;
    }
}

void PrintVector(const vector<Duration>& vectorOfDurations) {
    for (const Duration& duration : vectorOfDurations) {
        cout << duration << " ";
    }
    cout << endl;
}

int main(int argc, const char * argv[]) {
    
    stringstream durSS("02:50");
    Duration someDuration;
    durSS >> someDuration;
    
    Duration anotherDuration = {0, 35};
    Duration sumOfDurations = someDuration + anotherDuration;
    
    vector<Duration> vectorOfDurations = {
        someDuration,
        sumOfDurations,
        anotherDuration
    };
    
    PrintVector(vectorOfDurations);
    
    cout << "sum of durations is " << sumOfDurations << endl;
    
    sort(begin(vectorOfDurations), end(vectorOfDurations));
    PrintVector(vectorOfDurations);
    
    return 0;
}
