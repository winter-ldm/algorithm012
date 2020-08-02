class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        unordered_map<int, int> mymap;

        if (bills[0] != 5) {
            return false;
        }
        mymap[5] = 1;
        for (int i = 1; i < bills.size(); i++) {
            if (bills[i] == 5) {
                mymap[5]++;
            }
            else if (bills[i] == 10) {
                if (mymap.find(5) == mymap.end()) {
                    return false;
                }
                if (--mymap[5] == 0) {
                    mymap.erase(5);
                }
                mymap[10]++;
            }
            else {
                if ( mymap.find(10) == mymap.end() && (mymap.find(5) == mymap.end() || mymap[5] == 1)) {
                    return false;
                }
                else if (mymap.find(5) == mymap.end()) {
                    return false;
                }
                
                if (mymap.find(10) == mymap.end()) {
                    mymap[5] -= 3;
                    if (mymap[5] < 0) {
                        return false;
                    }
                    else if (mymap[5] == 0){
                        mymap.erase(5);
                    }
                    continue;
                }
                if (--mymap[5] == 0) {
                    mymap.erase(5);
                }
                if (--mymap[10] == 0) {
                    mymap.erase(10);
                }
            }
        }
        return true;
    }
};

class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int five = 0, ten = 0;
        
        for (int i = 0; i < bills.size(); i++) {
            if (bills[i] == 5) {
                five++;
            }
            else if (bills[i] == 10) {
                five--;
                ten++;
            }
            else if (ten > 0) {
                ten--;
                five--;
            }
            else {
                five -= 3;
            }
            if (five < 0) {
                return false;
            }
        }
        return true;
    }
};