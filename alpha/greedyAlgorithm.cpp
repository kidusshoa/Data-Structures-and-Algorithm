#include <iostream>
#include <vector>
#include <algorithm>

struct Activity {
    int start;
    int finish;
};

bool activityCompare(Activity a, Activity b) {
    return a.finish < b.finish;
}

void activitySelection(std::vector<Activity> activities) {

    std::sort(activities.begin(), activities.end(), activityCompare);

    int selected = 0;
    std::cout << "Selected activities: \n";
    std::cout << "(" << activities[selected].start << ", " << activities[selected].finish << ")\n";

    for (int i = 1; i < activities.size(); i++) {
        if (activities[i].start >= activities[selected].finish) {
            std::cout << "(" << activities[i].start << ", " << activities[i].finish << ")\n";
            selected = i; 
        }
    }
}

int main() {
    // Define a list of activities with start and finish times
    std::vector<Activity> activities = {
        {1, 3}, {2, 5}, {4, 7}, {1, 8}, {5, 9}, {8, 10}
    };

    // Call the activity selection function
    activitySelection(activities);

    return 0;
}
