class Solution {

vector<string> PathTravel;

unordered_map<string, multiset<string>> TicketToEndPoint; 

void DFS(const string& depart = "JFK"){

    while(TicketToEndPoint[depart].empty() == false){

        const string NextNode = *TicketToEndPoint[depart].begin();
        TicketToEndPoint[depart].erase(TicketToEndPoint[depart].begin()); 
        DFS(NextNode);

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
