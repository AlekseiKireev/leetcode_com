class Solution {

vector<string> PathTravel;

// "All of the tickets belong to a man who departs from "JFK", thus, the itinerary must begin with "JFK". ...
// You may assume all tickets form at least one valid itinerary. "
//"you should return the itinerary that has the smallest lexical order when read as a single string." --> multiset
unordered_map<string, multiset<string>> TicketToEndPoint; // multiset -- так как мультиграф
// если использовать set будет ошибка в тесте: 
/* Wrong Answer 16 / 81 
Input tickets = [["EZE","AXA"],["TIA","ANU"],["ANU","JFK"],["JFK","ANU"],["ANU","EZE"],["TIA","ANU"],["AXA","TIA"],["TIA","JFK"],["ANU","TIA"],["JFK","TIA"]]   
Expected ["JFK","ANU","EZE","AXA","TIA","ANU","JFK","TIA","ANU","TIA","JFK"]*/

void DFS(const string& depart = "JFK"){

    while(TicketToEndPoint[depart].empty() == false){

        const string NextNode = *TicketToEndPoint[depart].begin();
        TicketToEndPoint[depart].erase(TicketToEndPoint[depart].begin()); // помечаем посещенной, тут хорошо видно, почему именно multiset -- удобно удалять
        DFS(NextNode);
        //PathTravel.push_back(depart); // в целом верно, но не будет класться последняя вершина на стеке!
    }
    PathTravel.push_back(depart);
    
}

public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        for(auto ticket : tickets){
            TicketToEndPoint[ticket.front()].insert(ticket.back());
        }
        DFS();
        ranges::reverse(PathTravel);
        return PathTravel;
    }
};
