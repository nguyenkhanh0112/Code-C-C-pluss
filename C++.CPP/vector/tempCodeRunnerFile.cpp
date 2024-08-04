vector<int> breakingRecords(vector<int> scores) {
    vector<int> dem;
    int highest = scores[0];
    int lowest = scores[0];
    int x=0,y=0;
    for(int i=1;i<=scores.size();i++){
        if(highest>scores[i]){
            x++;
            highest=scores[i];
        }
        if(lowest<scores[i]){
            y++;
            lowest=scores[i];
        }
    }
    dem.push_back(y);
    dem.push_back(x);
    for(int i=0;i<dem.size();i++){
        cout<<dem[i]<<" ";
    }
    return dem;
}