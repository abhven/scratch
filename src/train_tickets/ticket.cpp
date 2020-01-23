#include <vector>
#include <unordered_map>
#include <cassert>
#include <queue>

using namespace std;

bool check_path_one_to_one(vector<pair<char,char>>& tickets, char src, char dst) {
    unordered_map<char, char> ticket_map;
    for(auto i = tickets.begin(); i!= tickets.end(); i++)
        ticket_map[i->first] = i->second;

    while(1) {
        if(!ticket_map[src])
            return false;
        if(ticket_map[src] == dst)
            return true;
        else
            src = ticket_map[src];
    }
    return false;
}

bool check_path_one_to_many(vector<pair<char,char>>& tickets, char src, char dst) {
    unordered_multimap<char, char> ticket_map;
    for (auto i = tickets.begin(); i!= tickets.end(); i++)
        ticket_map.insert(*i);
    
    queue<char> ticket_lead;
    ticket_lead.push(src);
    while(!ticket_lead.empty()) {
        char c = ticket_lead.front();
        auto i = ticket_map.find(c);
        while(i!= ticket_map.end()) {
            if(i->second == dst)
                return true;
            else {
                ticket_lead.push(i->second);
                ticket_map.erase(i);
                i = ticket_map.find(c);
            }
        }
        ticket_lead.pop();
    }
    return 0;
}

int main() {
    vector<pair<char, char>> tickets1 = {{'A','B'}, {'B','C'}, {'D', 'E'} };
    assert(check_path_one_to_one(tickets1, 'A', 'C'));
    assert(!check_path_one_to_one(tickets1, 'A', 'E'));
    
    vector<pair<char, char>> tickets2 = {{'A','B'}, {'B','C'}, {'D', 'E'}, {'B','D'}, {'B', 'F'} };
    assert(check_path_one_to_many(tickets2, 'A', 'C'));
    assert(check_path_one_to_many(tickets2, 'A', 'E'));

    return 0;
}