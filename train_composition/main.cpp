#include <iostream>

#include <list>

class TrainComposition
{
public:

    void attachWagonFromLeft(int wagonId)
    {
        wagons_.emplace_front(wagonId);
    }

    void attachWagonFromRight(int wagonId)
    {
        wagons_.emplace_back(wagonId);
    }

    int detachWagonFromLeft()
    {
        int wagonId = wagons_.front();
        wagons_.pop_front();

        return wagonId;
    }

    int detachWagonFromRight()
    {
        int wagonId = wagons_.back();
        wagons_.pop_back();

        return wagonId;
    }

private:

    std::list<int> wagons_;
};

int main()
{
    TrainComposition train;
    train.attachWagonFromLeft(7);
    train.attachWagonFromLeft(13);
    std::cout << train.detachWagonFromRight() << std::endl; // 7
    std::cout << train.detachWagonFromLeft() << std::endl; // 13
}

