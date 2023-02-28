#include <iostream>

class Song
{
public:

    explicit Song(std::string name)
        : name_(std::move(name))
        , next_(nullptr)
    {}

    void next(Song* song)
    {
        this->next_ = song;
    }

    bool isInRepeatingPlaylist()
    {
        Song* fast = this;
        Song* slow = this;

        while(fast && fast->next_)
        {
            fast = fast->next_->next_;
            slow = slow->next_;

            if(fast == slow)
            {
                return true;
            }
        }

        return false;
    }

private:
    const std::string name_;
    Song* next_;
};

int main()
{
    Song* first = new Song("Hello");
    Song* second = new Song("Eye of the tiger");

    first->next(second);
    second->next(first);

    std::cout << std::boolalpha << first->isInRepeatingPlaylist();
}