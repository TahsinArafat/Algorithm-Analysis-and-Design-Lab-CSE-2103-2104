#include <iostream>
#include <queue>
using namespace std;

typedef struct {
    int data, from, to;
} node;

int totItems = 0;
node last = { -1, -1, -1 }, first = { -1, 0, -1 }; // -1 is unknown
int lastIndex = -1;

void input(node space[], int value, queue<int>& freeSpace)
{
    int index = freeSpace.front();
    if (totItems == 0)
        first.to = index;
    freeSpace.pop();
    space[index].data = value;
    space[index].from = lastIndex;
    if (lastIndex != -1)
        space[lastIndex].to = index;
    space[index].to = -1;
    lastIndex = index;
    last = space[index];
    totItems++;
}

void remove(node space[], int value, queue<int>& freeSpace)
{
    int index = first.to;
    if (index == -1) {
        return;
    }
    while (index != -1) {
        if (space[index].data == value) {
            if (space[index].from == -1)
                first.to = space[index].to;
            space[space[index].from].to = space[index].to;
            space[space[index].to].from = space[index].from;
            freeSpace.push(index);
            totItems--;
            if (totItems == 0)
                first.to = -1;
            return;
        }
        index = space[index].to;
    }
    cout << value << " <-- Cannot be found\n";
}

void print(node space[])
{
    cout << "{ ";
    int index = first.to;
    while (index != -1) {
        cout << space[index].data << ", ";
        index = space[index].to;
    }
    cout << " }\n";
}

int main()
{
    node space[100000];
    int start = -2, end = -1;
    queue<int> freeSpace;
    for (int i = 1; i < 100000; i++) {
        freeSpace.push(i);
    }
    while (1) {
        int queryType;
        cin >> queryType;
        if (queryType == 0)
            break;
        else if (queryType == 1) {
            int value;
            cin >> value;
            input(space, value, freeSpace);
        } else {
            int value;
            cin >> value;
            remove(space, value, freeSpace);
        }
        print(space);
    }
}
