class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n=letters.size();
        int s=0;
        int e=n-1;
        int ans=-1;

        while(s<=e){
            int mid= s+(e-s)/2;

            if(letters[mid] == target){  //agr mid target ke equal hai toh left jake fydda ni kyuki hme smallest letter greater than target dhundna h jo ki only right size milega as array sorted in ascending order
            s= mid+1;
            }

            if(letters[mid] < target){ //if mid chota h target se toh uske left jake fyda ni kyuki vha sare aur chote milege elements blki hame toh smallest letter greater than target dhundna h jo ki only right size milega of mid as array sorted in ascending order
            s= mid+1;
            }

            if(letters[mid] > target){ //b mid h jo ki bda hai target se toh isko ham store krwa lege ans mein aur best ans ko still dhundege kyuki ham yeh gurantee ni h ki yeh smallest letter greater than target h  ya ni
            ans= letters[mid];
            e=mid-1; //left jane ka reason yeh h ki left side hi smallest letter greater than target milega na ki right side because right side already aur bde bde elements milege ko ki nh chiye hme
            }
        }
        return (ans == -1) ? letters[0] : ans;
    }
};