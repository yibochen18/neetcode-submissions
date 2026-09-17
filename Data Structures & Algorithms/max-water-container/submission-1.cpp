class Solution {
public:
    int maxArea(vector<int>& heights) {
        //area given two heights is diff between indexes * smallest height arg
        //maybe a two pointer approach since we only care about the max area

        int l = 0, r = heights.size() - 1;
        int max = 0;

        while (l != r)
        {
            // cout << heights[l] << ',' << heights[r] << "\n";
            int area = (r - l) * min(heights[l], heights[r]);
            // cout << "area is:" << area << "\n";
            if (area > max)
            {
                max = area;
            }

            heights[l] > heights[r] ? r-- : l++;
        }

        return max;
    }
};
