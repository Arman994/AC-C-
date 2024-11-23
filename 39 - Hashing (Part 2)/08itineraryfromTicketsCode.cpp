#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

void printItinerary(unordered_map<string, string> tickets) {
    //Startin point
    unordered_set<string> to;

    for(pair<string, string> ticket : tickets) {
        to.insert(ticket.second);
    }

    string start = "";
    for(pair<string, string> ticket : tickets) {
        if(to.find(ticket.first) == to.end()) { //means not found
            start = ticket.first;
        }
    }

    //Plan print
    cout << start << " ->";
    while(tickets.count(start)) {
        cout << tickets[start] << " ->";
        start = tickets[start];
    }
    cout << "destination\n";
}

int main() {
    unordered_map<string, string> tickets;
    tickets["Chennai"] = "Bengaluru";
    tickets["Mumbai"] = "Delhi";
    tickets["Goa"] = "Chennai";
    tickets["Delhi"] = "Goa";

    printItinerary(tickets);
    return 0;
}