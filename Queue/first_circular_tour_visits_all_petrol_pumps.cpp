#include <iostream>

using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};

int printTour(petrolPump p[], int n)
{
    int start = 0;
    int end = 1;

    int curr_petrol = p[start].petrol - p[start].distance;

    while (curr_petrol < 0 || start != end)
    {

        while (curr_petrol < 0 && start != end)
        {
            curr_petrol -= p[start].petrol - p[start].distance;
            start = (start + 1) % n;

            if (start == 0)
                return -1;
        }

        curr_petrol += p[end].petrol - p[end].distance;
        end = (end + 1) % n;
    }
    return start;
}

int main()
{
    petrolPump arr[] = {{6, 4}, {3, 6}, {7, 3}};

    int n = sizeof(arr) / sizeof(arr[0]);
    int start = printTour(arr, n);

    if (start == -1)
    {
        cout << "No solution";
    }
    else
    {
        cout << "Start = " << start;
    }

    return 0;
}