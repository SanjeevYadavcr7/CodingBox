#include<bits/stdc++.h>
using namespace std;

int getMinCostToPaint(vector<vector<int>> cost, int total_houses){
    int red_cost = cost[0][0], blue_cost = cost[0][1], green_cost = cost[0][2];
    int temp_red_cost, temp_blue_cost, temp_green_cost; 
    for(int curr_house = 1; curr_house < total_houses; curr_house++){
        temp_red_cost = min(blue_cost,green_cost) + cost[curr_house][0];
        temp_blue_cost = min(red_cost,green_cost) + cost[curr_house][1];
        temp_green_cost = min(red_cost,blue_cost) + cost[curr_house][2];
    
        red_cost = temp_red_cost;
        blue_cost = temp_blue_cost;
        green_cost = temp_green_cost;
    }
    int min_cost = min(red_cost, min(blue_cost,green_cost));
    return min_cost;
}

int main(){
    int n;
    cin >> n;
    vector<vector<int>> cost;
    for(int i=0;i<n;i++){
        vector<int> rgb_cost;
        for(int j=0;j<3;j++){
            int paint_cost;
            cin >> paint_cost;
            rgb_cost.push_back(paint_cost);
        } 
        cost.push_back(rgb_cost);
    }

    int min_cost = getMinCostToPaint(cost,n);
    cout<<min_cost<<"\n";

    return 0;
}