typedef pair<int, int> P;

sort(vec.begin(), vec.end(), [](const P &p1, const P &p2) {
                    if (p1.second < p2.second) return true;
                    if (p1.second == p2.second) return p1.first < p2.first;
                    return false;});
