#include<bits/stdc++.h>
     
    using namespace std;
     
    bool canPlaceCows(int64_t points[], int64_t number_of_points, int64_t minimum_distance, int64_t max_cows){
        int64_t last = points[0], placed = 1;    // greedily place it at the first point
     
        for(int64_t i = 1; i < number_of_points; i ++){
            if(points[i] - last >= minimum_distance){           // place a cow here, since it is greater than or equal to the permissible limit
                last = points[i];
                placed ++;
            }
            if(placed == max_cows)            // placed all the cows required
                return true;
        }
        return false;
    }
     
    int main() {
        int64_t T;
        cin >> T;
     
        while(T --){
            int64_t N, C;
            cin >> N >> C;
     
            int64_t points[N];
            for(int64_t i = 0; i < N; i ++)
                cin >> points[i];
     
            sort(points, points + N);
     
            // binary search the min_dist : min = 0, max = points[N - 1] - points[0]
            int64_t lo_min_dist = 0, hi_min_dist = points[N - 1] - points[0], mid_min_dist;
     
            // find last occurence of true value returned by function canPlaceCows - maximized minimum distance
            while(hi_min_dist - lo_min_dist > 1){
     
                mid_min_dist = lo_min_dist + (hi_min_dist - lo_min_dist) / 2;
     
                if(canPlaceCows(points, N, mid_min_dist, C)){   // predicate is true for this, then this can be one of the contenders for the last occurrence of true predicate
                    lo_min_dist = mid_min_dist;
                } else {
                    hi_min_dist = mid_min_dist;
                }
            }
     
            cout << lo_min_dist << "\n";
     
        }
        return 0;
    }   