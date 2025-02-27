pair<int, int> findTarget(const vector<int>& I, const int target){


    unordered_map<int, int>PStoIdx; // Idx == идекс исходного массива
    int PS = 0;
    // PStoIdx[PS] = 0; // [5, 1, 4, -6,1234], 10

    for(int i = 0; i < I.size(); ++i){
        
        PS += I[i];
        if(PS == target){return {0,i};}

        const int k =  PS - target;
        if(PStoIdx.count(k)/*{0,1}*/){
            return {PStoIdx[k] + 1,i}; 
        }else{
            PStoIdx[PS] = i;
        }

    }

    return {-1,-1};
}
/*
pair<int, int> findTarget(const vector<int>& I, const int target){


    unordered_map<int, int>PStoIdx; 
    int PS = 0;
    PStoIdx[PS] = -1; // [5, 1, 4, -6,1234], 10

    for(int i = 0; i < I.size(); ++i){
        
        PS += I[i];
        const int k =  PS - target;
        if(PStoIdx.count(k) == 1){
            return {PStoIdx[k] + 1,i}; 
        }else{
            PStoIdx[PS] = i;
        }

    }

    return {-1,-1};
}
*/
