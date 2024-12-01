#include <algorithm>
#include <vector>
#include <iostream>
#include <numeric>
#include <fstream>

using namespace std;

void fillLists(vector<int>& left, vector<int>& right) {
    ifstream inputFile("input");
    if (!inputFile) {
        cerr << "file is fkd" << endl;
    }

    int number;
    int i {};
    while (inputFile >> number) {
        if (i % 2 == 0) {
            left.push_back(number);
        } else {
            right.push_back(number);
        }
        i++;
    }
}

int getDistance(vector<int>& left, vector<int>& right) {
    vector<int> result;
    ranges::sort(left);
    ranges::sort(right);

    for (int i = 0; i < left.size(); ++i) {
        if (left[i] > right[i]) {
            result.push_back(left[i] - right[i]);
        } else {
            result.push_back(right[i] - left[i]);
        }
    }
    return reduce(result.begin(), result.end());
}

int getSimilarity(vector<int>& left, vector<int>& right) {

    vector<int> results;

    for (int number : left) {
        const size_t number_count = ranges::count(right, number);
        results.push_back((number * static_cast<int>(number_count)));
    }

    return reduce(results.begin(), results.end());;
}

int main() {

    vector<int> left {};
    vector<int> right {};

    fillLists(left, right);

    const int distance = getDistance(left, right);
    cout << distance << endl;

    int similartity {};
    similartity = getSimilarity(left, right);
    cout << similartity << endl;


}
