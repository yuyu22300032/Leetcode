/*
1401. Circle and Rectangle Overlapping


Description:

You are given a circle represented as (radius, xCenter, yCenter) and an axis-aligned rectangle represented as (x1, y1, x2, y2), where (x1, y1) are the coordinates of the bottom-left corner, and (x2, y2) are the coordinates of the top-right corner of the rectangle.

Return true if the circle and rectangle are overlapped otherwise return false. In other words, check if there is any point (xi, yi) that belongs to the circle and the rectangle at the same time.

 

Example 1:

Input: radius = 1, xCenter = 0, yCenter = 0, x1 = 1, y1 = -1, x2 = 3, y2 = 1
Output: true
Explanation: Circle and rectangle share the point (1,0).

Example 2:

Input: radius = 1, xCenter = 1, yCenter = 1, x1 = 1, y1 = -3, x2 = 2, y2 = -1
Output: false

Example 3:

Input: radius = 1, xCenter = 0, yCenter = 0, x1 = -1, y1 = 0, x2 = 0, y2 = 1
Output: true

 

Constraints:

    1 <= radius <= 2000
    -104 <= xCenter, yCenter <= 104
    -104 <= x1 < x2 <= 104
    -104 <= y1 < y2 <= 104


*/

class Solution {
    bool cornerInside(int radius, int xCenter, int yCenter, int x, int y) {
        int x_dist = x - xCenter;
        int y_dist = y - yCenter;
        int dist_2 = x_dist * x_dist + y_dist * y_dist;
        return radius * radius >= dist_2;
    }
public:
    bool checkOverlap(int radius, int xCenter, int yCenter, int x1, int y1, int x2, int y2) {
        if (cornerInside(radius, xCenter, yCenter, x1, y1) ||
            cornerInside(radius, xCenter, yCenter, x1, y2) ||
            cornerInside(radius, xCenter, yCenter, x2, y1) ||
            cornerInside(radius, xCenter, yCenter, x2, y2)) {
            return true;
        }
        if (xCenter >= x1 && xCenter <= x2) {
            if (yCenter >= (y1 - radius) && yCenter <= (y2 + radius)) {
                return true;
            }
        }
        if (yCenter >= y1 && yCenter <= y2) {
            if (xCenter >= (x1 - radius) && xCenter <= (x2 + radius)) {
                return true;
            }
        }
        return false;
    }
};
