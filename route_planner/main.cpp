#include <iostream>
#include <vector>
#include <algorithm>
#include <map>

struct Point
{
    int row_;
    int col_;

    explicit Point(int row = -1, int col = -1)
        : row_(row)
        , col_(col)
    {}

    bool operator==(const Point& p) const
    {
        return this->row_ == p.row_ && this->col_ == p.col_;
    }

    Point shiftLeft() const
    {
        return Point(row_, col_ - 1);
    }
    Point shiftRight() const
    {
        return Point(row_, col_ + 1);
    }
    Point shiftUp() const
    {
        return Point(row_ - 1, col_);
    }
    Point shiftDown() const
    {
        return Point(row_ + 1, col_);
    }
};

bool operator<(const Point& lhs, const Point& rhs)
{
    return (lhs.row_ < rhs.row_) || ((lhs.row_ == rhs.row_) && (lhs.col_ < rhs.col_));
}

std::ostream& operator<<(std::ostream& out, const Point& p)
{
    out << "(" << p.row_ << "," << p.col_ << ")";
    return out;
}

inline bool contains(const std::vector<Point>& visited, Point p)
{
    return std::find(visited.begin(), visited.end(), p) != visited.end();
}


bool routeExistsInternal(int fromRow, int fromColumn, int toRow, int toColumn, std::map<Point, bool>& visited, const std::vector<std::vector<bool>>& mapMatrix)
{
    Point from{fromRow, fromColumn};
    Point to{toRow, toColumn};

    if(from == to)
    {
        return true;
    }
    if(visited[from])
    {
        return false;
    }

    visited[from] = true;

    bool canGoLeft 	= (fromColumn != 0)							    && mapMatrix[fromRow][fromColumn - 1];
    bool canGoRight = (fromColumn != mapMatrix[fromRow].size() - 1) && mapMatrix[fromRow][fromColumn + 1];
    bool canGoUp 	= (fromRow != 0) 							    && mapMatrix[fromRow - 1][fromColumn];
    bool canGoDown  = (fromRow != mapMatrix.size() - 1) 			&& mapMatrix[fromRow + 1][fromColumn];

    return (canGoLeft  && routeExistsInternal(fromRow, fromColumn - 1, toRow, toColumn, visited, mapMatrix))
           || (canGoRight && routeExistsInternal(fromRow, fromColumn + 1, toRow, toColumn, visited, mapMatrix))
           || (canGoUp    && routeExistsInternal(fromRow - 1, fromColumn, toRow, toColumn, visited, mapMatrix))
           || (canGoDown  && routeExistsInternal(fromRow + 1, fromColumn, toRow, toColumn, visited, mapMatrix));
}

bool routeExists(int fromRow, int fromColumn, int toRow, int toColumn,
                 const std::vector<std::vector<bool>>& mapMatrix)
{
    std::map<Point, bool> visited;

    for(int i = 0; i < mapMatrix.size(); ++i)
    {
        for(int j = 0; j < mapMatrix[i].size(); ++i)
        {
            visited.emplace(Point(i, j), false);
        }
    }

    return routeExistsInternal(fromRow, fromColumn, toRow, toColumn, visited, mapMatrix);
}

int main()
{
    std::vector<std::vector<bool>> mapMatrix {
            {true, false, false},
            {true, true, false},
            {false, true, true}
    };

    std::cout << std::boolalpha << routeExists(0, 0, 2, 2, mapMatrix) << std::endl;
}

