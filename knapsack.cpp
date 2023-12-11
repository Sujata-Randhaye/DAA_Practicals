#include<iostream>
#include <algorithm>
// #include<iomanip>
using namespace std;

struct Item {
   int profit;
   int weight;
};

    bool static comp(Item a, Item b) {
        double r1 = (double) a.profit / (double) a.weight;
        double r2 = (double) b.profit / (double) b.weight;
        return r1 > r2;
    }
   // function to return fractionalweights
   double fractionalKnapsack(int W, Item arr[], int n) {

      sort(arr, arr + n, comp);

      int curWeight = 0;
      double finalprofit = 0.0;

      for (int i = 0; i < n; i++) {

        if (curWeight + arr[i].weight <= W) {
            curWeight += arr[i].weight;
            finalprofit += arr[i].profit;
        } else {
            int remain = W - curWeight;
            finalprofit += (arr[i].profit / (double) arr[i].weight) * (double) remain;
            break;
        }
      }

      return finalprofit;

   }

int main() {
   int n = 3, weight = 50;
   Item arr[n] = { {100,20},{60,10},{120,30} };
   double ans = fractionalKnapsack(weight, arr, n);
// cout << "The maximum value is " << setprecision(2) << fixed << ans;
    cout << "The maximum profit is " << ans;

   return 0;
}