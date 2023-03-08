class Solution {
public:
    long long check(long long mid , vector< int >& vc ){
        long long co(0);
        int len =  vc.size() ;
        for (int i = 0; i < len ; i++)
        {
            if(vc[i] <= mid) co++;
            else{
                co +=(((vc[i]) / (mid)) + (((vc[i]) % (mid) ) ? 1 : 0)) ;
            }
        }
        return co ;
    }
    long long minEatingSpeed(vector< int >& piles, int h) {
        sort(piles.begin() , piles.end());
        int len =  piles.size() ;
        int l = 1 , r = piles[len-1] , ans = -1;
        while (l <= r)
        {
            long long  mid = l + (r-l)/2 ;
            if(check(mid ,piles) <= h){
                ans = mid  ;
                r = mid -1 ;
            }else l = mid + 1 ;
        }
        return ans ;
    }
};