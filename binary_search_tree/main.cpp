#include <iostream>

class Node
{
public:
    Node(int value, Node* left, Node* right)
    {
        this->value = value;
        this->left = left;
        this->right = right;
    }

    int getValue() const
    {
        return value;
    }

    Node* getLeft() const
    {
        return left;
    }

    Node* getRight() const
    {
        return right;
    }

private:
    int value;
    Node* left;
    Node* right;
};

class BinarySearchTree
{
public:
    static bool contains(const Node& root, int value)
    {
        if(value == root.getValue())
        {
            return true;
        }

        if(value < root.getValue())
        {
            return (root.getLeft() != nullptr) && contains(*root.getLeft(), value);
        }

        if(value > root.getValue())
        {
            return (root.getRight() != nullptr) && contains(*root.getRight(), value);
        }
    }
};

int main()
{
    Node n1(1, nullptr, nullptr);
    Node n3(3, nullptr, nullptr);
    Node n2(2, &n1, &n3);

    std::cout << std::boolalpha << BinarySearchTree::contains(n2, 3);
}

