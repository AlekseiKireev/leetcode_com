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
            if (pts.find({sum - pt.x, pt.y}) == pts.end()) {
                return false;
            }
        }

        return true;
    }
};
