/**
 * @file Event.cpp
 * @author Adrian Hernandez (a01747038@tec.mx)
 * @brief Event class implementation
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */

#pragma once 

#include <Event.hpp>

#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>

void Event::constructMap() {
    monthsToNums["Jan"] = 1; 
    monthsToNums["Feb"] = 2;
    monthsToNums["Mar"] = 3;
    monthsToNums["Apr"] = 4;
    monthsToNums["May"] = 5;
    monthsToNums["Jun"] = 6;
    monthsToNums["Jul"] = 7;
    monthsToNums["Aug"] = 8;
    monthsToNums["Sep"] = 9;
    monthsToNums["Oct"] = 10;
    monthsToNums["Nov"] = 11;
    monthsToNums["Dec"] = 12;
}

void Event::updateNumDate() {
    std::stringstream dateStream;
    dateStream << date;

    // update arrDate

    std::string month;
    std::string day;
    std::string time;

    std::getline(dateStream, month, ' ');
    std::getline(dateStream, day, ' ');
    std::getline(dateStream, time, ' ');
        
    int nMonth = monthsToNums[month];
    int nDay = std::stoi(day);

    // pase time 
    std::stringstream timeStream;
    timeStream << time;

    std::string hour;
    std::string min;
    std::string sec;

    getline(timeStream, hour, ':');
    getline(timeStream, min, ':');
    getline(timeStream, sec, ':');

    int nHour = std::stoi(hour);
    int nMin = std::stoi(min);
    int nSec = std::stoi(sec);

    arrDate = {nMonth, nDay, nHour, nMin, nSec};
    
    // update numDate
    numDate = 0;
    
    numDate += nMonth * std::pow(60, 4);
    numDate += nDay * std::pow(60, 3);
    numDate += nHour * std::pow(60, 2);
    numDate += nMin * 60;
    numDate += nSec;
}

void Event::updateNumIp() {
    // get numerical ip value and ip array value from
    // this->ip
    std::stringstream ipStream;
    ipStream << this->ip;

    std::string first;
    std::string second;
    std::string third;
    std::string fourth;

    std::getline(ipStream, first, '.');
    std::getline(ipStream, second, '.');
    std::getline(ipStream, third, '.');
    std::getline(ipStream, fourth, ':');

    int nFirst = std::stoi(first);
    int nSecond = std::stoi(second);
    int nThird = std::stoi(third);
    int nFourth = std::stoi(fourth);    
    
    this->arrIp = {nFirst, nSecond, nThird, nFourth};

    this->numIp = 0;
    this->numIp += nFirst * std::pow(1000, 3);
    this->numIp += nSecond * std::pow(1000, 2);
    this->numIp += nThird * 1000;
    this->numIp += nFourth;
}

Event::Event() {
     constructMap();
}

Event::Event(std::string _message, std::string _date, std::string _ip) {
    constructMap();
    
    message = _message;
    date = _date;
    ip = _ip;
    
    updateNumDate();
    updateNumIp();
}

std::string Event::getMessage() const {
    return message;
}

std::string Event::getDate() const {
    return date;
}

std::string Event::getIp() const {
    return ip;
}

void Event::setMessage(std::string _message) {
    message = _message;
}

void Event::setDate(std::string _date) {
    date = _date;
    updateNumDate();
}

void Event::setIp(std::string _ip) {
    ip = _ip;
    updateNumIp();
}

int Event::getNumDate() const {
    return numDate;
}

unsigned long long int Event::getNumIp() const {
    return this->numIp;
}

std::vector<int> Event::getArrDate() const {
    return arrDate;
}

std::vector<int> Event::getArrIp() const {
    return arrIp;
}

void Event::loadData(std::string data) {
    std::stringstream dataStream;
    dataStream << data;

    std::stringstream dateStream;
    std::stringstream ipStream;
    std::stringstream messageStream;

    std::string temp;
    
    // add date data
    for (int i=0; i<3; i++) {
        std::getline(dataStream, temp, ' ');
        dateStream << temp << " ";
    }

    // add the ip 
    std::getline(dataStream, temp, ' ');
    ipStream << temp;

    // add the rest of the message
    while (std::getline(dataStream, temp, ' ')) {
       messageStream << temp << " "; 
    }

    date = dateStream.str();
    ip =  ipStream.str();
    message = messageStream.str();

    updateNumDate();
    updateNumIp();
}

std::string Event::str() const {
    std::stringstream msg;
    msg << date << " " << ip << " " << message; 
    return msg.str();
}