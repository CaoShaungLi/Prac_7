#include <iostream>
#include <cmath>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

const int MAX_P = 1000;
const int MAX_N = 1000 / 2;

int main() {
    map<int, vector<tuple<int, int, double, int>>> res;
    int best_len = 1;
    int best_p = 0;

    for (int a = 1; a <= MAX_N; ++a) {
        for (int b = a; b <= MAX_N; ++b) {
            float c = sqrt(a * a + b * b);
            int ic = static_cast<int>(c);

            if (c == ic) {
                int p = a + b + ic;

                if (p > MAX_P) {
                    continue;
                }

                if (res.find(p) != res.end()) {
                    res[p].push_back(make_tuple(a, b, c, p));
                } else {
                    res[p] = {make_tuple(a, b, c, p)};
                }

                int new_len = res[p].size();
                if (new_len > best_len) {
                    best_len = new_len;
                    best_p = p;
                    for (const auto& item : res[p]) {
                        cout << "(" << get<0>(item) << ", " << get<1>(item) << ", " << get<2>(item) << ", " << get<3>(item) << "), ";
                    }
                    cout << endl;
                }
            }
        }
    }

    cout << best_len << endl;
    cout << "DONE" << endl;

    return 0;
}