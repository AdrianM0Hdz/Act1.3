#include <iostream>
#include <vector>

#include "Event.cpp"
#include "EventLog.cpp"

int main() {
    EventLog el;
    // global path of "bitacora.txt"
    el.loadEvents("/mnt/c/Users/adrhe/AloritmosYEstrucutrasTec/Act1.3/src/bitacora.txt");
    el.saveEvents("/mnt/c/Users/adrhe/AloritmosYEstrucutrasTec/Act1.3/src/ordenado.txt");
    
    // usuario
    std::string startIp, endIp;

    while (true) {
        std::cout << "To get events by range enter a start ip and an end ip in\n";
        std::cout << "the following format: (892.36.686.11:4594) \n \n";

        std::cout << "START IP: \n";
        std::getline(std::cin, startIp);
        std::cout << "END IP: \n";
        std::getline(std::cin, endIp);

        std::vector<Event> events = el.getEventsByIpRange(startIp, endIp);
        std::cout << "DISPLAYING EVENTS IN RANGE \n";

        for (Event event: events) {
            std::cout << event.str() << "\n";
        }
    }
}