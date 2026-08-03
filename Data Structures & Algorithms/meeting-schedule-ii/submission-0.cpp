/**
 * Definition of Interval:
 * class Interval {
 * public:
 *     int start, end;
 *     Interval(int start, int end) {
 *         this->start = start;
 *         this->end = end;
 *     }
 * }
 */

class Solution {
public:
    int minMeetingRooms(vector<Interval>& intervals) {

        std::vector<int> end_times{};
        std::vector<int> start_times{};

        start_times.reserve(intervals.size());
        end_times.reserve(intervals.size());


        for(const auto& interval : intervals){
            start_times.push_back(interval.start);
            end_times.push_back(interval.end);
        }
        std::sort(start_times.begin(), start_times.end());
        std::sort(end_times.begin(), end_times.end());
        int s{};
        int e{};

        int count{};
        int max{};

        while (s < intervals.size()){
            if(start_times[s] < end_times[e]){
                count++;
                s++;
            }
            else{
                count--;
                e++;
            }

            max = std::max(count, max);
        } 

        return max;

        
    }
};
