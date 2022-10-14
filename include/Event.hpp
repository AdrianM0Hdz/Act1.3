/**
 * @file Event.hpp
 * @author Adrian Hernandez (a01747038@tec.mx)
 * @brief Event class declaration 
 * @version 0.1
 * @date 2022-09-15
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#pragma once

#include <string>
#include <vector>
#include <map>

class Event {
    private:
        std::string message;
        std::string date; // month day hour:min:sec (time)
        std::string ip;
        
        // two forms of ordering
        
        int numDate; // for bin search
        std::vector<int> arrDate; // for bucket sorting

        unsigned long long int numIp;
        std::vector<int> arrIp;
        

        // for parsing date into numerical values
        std::map<std::string, int> monthsToNums;

        void constructMap();
        
        // to update the date each time string 
        // date is changed
        void updateNumDate();
        // to update the ip each time the
        void updateNumIp();

    public:
        Event();
        Event(std::string, std::string, std::string);

        std::string getMessage() const;
        std::string getIp() const;
        std::string getDate() const;

        void setMessage(std::string);
        void setIp(std::string);
        void setDate(std::string);

        int getNumDate() const;
        unsigned long long int getNumIp() const;
        
        // for radix sort like sorting
        std::vector<int> getArrDate() const;
        std::vector<int> getArrIp() const;

        // parses raw row data
        void loadData(std::string);

        std::string str() const;
};