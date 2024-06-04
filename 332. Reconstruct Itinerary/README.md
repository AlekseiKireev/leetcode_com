https://leetcode.com/problems/reconstruct-itinerary/description/

https://walkccc.me/LeetCode/problems/332/

related: https://contest.yandex.ru/contest/28069/problems/I/

У Федора Меньшикова разбор отсут-т!


    To visualize the recursive call stack for the given code and the input tickets = [["JFK","SFO"],["JFK","ATL"],["SFO","ATL"],["ATL","JFK"],["ATL","SFO"]], let's break down the process step-by-step and observe the state of the targets map at each step.
    
    Initial Setup
    First, we build the targets map from the given tickets:
    

    map<string, multiset<string>> targets;
    Tickets processing:
    
    Insert JFK -> SFO
    Insert JFK -> ATL
    Insert SFO -> ATL
    Insert ATL -> JFK
    Insert ATL -> SFO
    The targets map after processing all tickets:
    

    targets = {
        "JFK": {"ATL", "SFO"},
        "SFO": {"ATL"},
        "ATL": {"JFK", "SFO"}
    }
    Recursive Visit Function Execution
    Starting with visit("JFK"):
    
    visit("JFK"):
    Current state: targets["JFK"] = {"ATL", "SFO"}
    Choose ATL (lexicographically smaller)
    targets["JFK"] becomes {"SFO"}
    Call stack:
    

    visit("JFK")
    └── visit("ATL")
    visit("ATL"):
    Current state: targets["ATL"] = {"JFK", "SFO"}
    Choose JFK
    targets["ATL"] becomes {"SFO"}
    Call stack:
    

    visit("JFK")
    └── visit("ATL")
        └── visit("JFK")
    visit("JFK"):
    Current state: targets["JFK"] = {"SFO"}
    Choose SFO
    targets["JFK"] becomes {}
    Call stack:
    

    visit("JFK")
    └── visit("ATL")
        └── visit("JFK")
            └── visit("SFO")
    visit("SFO"):
    Current state: targets["SFO"] = {"ATL"}
    Choose ATL
    targets["SFO"] becomes {}
    Call stack:
    

    visit("JFK")
    └── visit("ATL")
        └── visit("JFK")
            └── visit("SFO")
                └── visit("ATL")
    visit("ATL"):
    Current state: targets["ATL"] = {"SFO"}
    Choose SFO
    targets["ATL"] becomes {}
    Call stack:
    

    visit("JFK")
    └── visit("ATL")
        └── visit("JFK")
            └── visit("SFO")
                └── visit("ATL")
                    └── visit("SFO")
    visit("SFO"):
    Current state: targets["SFO"] = {}
    No more destinations, add SFO to route
    Call stack unwinding begins, adding elements to route:
    

    visit("JFK")
    └── visit("ATL")
        └── visit("JFK")
            └── visit("SFO")
                └── visit("ATL")
                    └── visit("SFO") // Add "SFO" to route
                    └── // Add "ATL" to route
                └── // Add "SFO" to route
            └── // Add "JFK" to route
        └── // Add "ATL" to route
    └── // Add "JFK" to route
    Final Route
    The route array in reverse order is ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"].
    
    Thus, the final output is:
    

    ["JFK", "ATL", "JFK", "SFO", "ATL", "SFO"]
    Explanation
    At each step, we recursively visit the smallest lexicographical destination available from the current airport. When we run out of destinations for a specific airport, we add that airport to the route and backtrack. This ensures that all flights are used and the itinerary is constructed in the correct order.
    
    The recursive nature of the function ensures that we fully explore each branch before backtracking, and the use of a multiset ensures that destinations are processed in lexicographical order.
