// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        //hme sirf number n versions diye h na ki array toh ham s ko 1 se initalize krege aur ko e ko n se
        int s=1;
        int e=n;
        int ans=-1;

        while(s<=e){
            int mid= s+(e-s)/2;

            if(isBadVersion(mid)){
                ans=mid;
                 //means yeh mid ek bad version h toh means iske bd ke bhi sare bad versions hoge but hme niklna h 1st bad version toh ab 2 possibilities bnti h ya toh yhi bad version h toh uske liye ans mein mid store krwa diya aur left move krdiya ki isse bhi phele bad version aa chuka h ya ni agr nh aya hoga toh means yhi 1st bad version h toh hmne ans return krdia vrna vpis se check hoke ans update hojega;
                e=mid-1;
            }else{
                s=mid+1;//means yeh mid bad version nh h toh mtlb isse phele bhi bad version ni aya hoga so right move krte h to see ki aage kha h bad version
            }
        }
        return ans;
    }
};

            