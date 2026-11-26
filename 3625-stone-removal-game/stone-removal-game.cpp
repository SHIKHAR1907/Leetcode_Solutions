class Solution {
public:
    bool canAliceWin(int n) {
        int stones = 10;
        bool aliceWin =   true;

        while(n >= stones){
            n -= stones;
            stones--;
            aliceWin = !aliceWin;
        }

        return !aliceWin;
    }
};