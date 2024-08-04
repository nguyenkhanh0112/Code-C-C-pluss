int getMoneySpent(vector<int> keyboards, vector<int> drives, int b) {
    /*
     * Write your code here.
     */
    vector<int> arr;
    for(int i=0;i<keyboards.size();i++){
        for(int j=0;j<drives.size();j++){
            if(keyboards[i]+drives[j]<=b){
                int x;
                x=keyboards[i]+drives[j];
                arr.push_back(x);
            }
        }
    }
    int max=0;
    for(int i=0;i<arr.size();i++){
        if(max<=arr[i]){
            max=arr[i];
        }
    }
    if(max>b)
        return -1;
    return max;
}