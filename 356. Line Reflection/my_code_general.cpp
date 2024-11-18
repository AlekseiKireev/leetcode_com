/*
Time complexity: O(n)
Space complexity: O(n)
*/
class Solution {
public:
    struct Point {
        int x;
        int y;

        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };

    struct PointHash {
        size_t operator()(const Point& point) const {
            return hash<int>()(point.x) ^ hash<int>()(point.y);
        }
    };

    bool isReflected(vector<vector<int>>& points) {
        if (points.empty()) {return true;}

        unordered_map<Point, int, PointHash> PtsToCnt;
        int x_min = points[0][0];
        int x_max = points[0][0];

        for (const auto& point : points) {
            PtsToCnt[{point[0], point[1]}]++;
            x_min = min(x_min, point[0]);
            x_max = max(x_max, point[0]);
        }

        int sum = x_min + x_max;

        for (const auto& pt : PtsToCnt) {
            if (PtsToCnt[{sum - pt.first.x, pt.first.y}] != PtsToCnt[{pt.first.x, pt.first.y}]) {
                return false;
            }else{
                PtsToCnt[{sum - pt.first.x, pt.first.y}] = -1;
                PtsToCnt[{pt.first.x, pt.first.y}] = -1;
            }
        }

        return true;
    }
};

/*
class Solution {
public:
    struct Point {
        int x;
        int y;

        bool operator==(const Point& other) const {
            return x == other.x && y == other.y;
        }
    };

    struct PointHash {
        size_t operator()(const Point& point) const {
            return hash<int>()(point.x) ^ hash<int>()(point.y);
        }
    };

    bool isReflected(vector<vector<int>>& points) {
        if (points.empty()) {return true;}

        unordered_set<Point, PointHash> pts;
        int x_min = points[0][0];
        int x_max = points[0][0];

        for (const auto& point : points) {
            pts.insert({point[0], point[1]});
            x_min = min(x_min, point[0]);
            x_max = max(x_max, point[0]);
        }

        int sum = x_min + x_max;

        for (const auto& pt : pts) {
            if (pts.count({sum - pt.x, pt.y}) == 0) {
                return false;
            }
        }

        return true;
    }
};
*/
