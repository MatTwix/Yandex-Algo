#include <iostream>
#include <vector>

using namespace std;

int main(void) {
    int n;
    cin >> n;
    
    vector<int> segments(n);
    
    long long sqSum = 0;
    for (int i = 0; i < n; ++i) {
        cin >> segments[i];
        sqSum += segments[i] * segments[i];
    }
    
    cout << sqSum << endl;
    
    int k;
    cin >> k;
    
    segments.reserve(n + k);
    
    for (int i = 0; i < k; ++i) {
        int type, pos;
        cin >> type >> pos;
        pos--;
        
        if (type == 1) {
            sqSum -= segments[pos] * segments[pos];
            
            if (pos == 0) {
                sqSum -= (long long)segments[1] * segments[1];
                segments[1] += segments[0];
                sqSum += segments[1] * segments[1];
                segments.erase(segments.begin());
            } else if (pos == segments.size() - 1) {
                sqSum -= segments[pos - 1] * segments[pos - 1];
                segments[pos - 1] += segments[pos];
                sqSum += segments[pos - 1] * segments[pos - 1];
                segments.pop_back();
            } else {
                sqSum -= segments[pos - 1] * segments[pos - 1] + segments[pos + 1] * segments[pos + 1];
                
                int upstream_part, downstream_part;
                upstream_part = segments[pos] / 2;
                downstream_part = (segments[pos] + 1) / 2;
                
                segments[pos - 1] += upstream_part;
                segments[pos + 1] += downstream_part;
                
                sqSum += (long long)segments[pos - 1] * segments[pos - 1] + (long long)segments[pos + 1] * segments[pos + 1];
                
                segments.erase(segments.begin() + pos);
            }
        } else {
            sqSum -= segments[pos] * segments[pos];
            
            int upstream_part, downstream_part;
            upstream_part = segments[pos] / 2;
            downstream_part = (segments[pos] + 1) / 2;
            
            segments[pos] = upstream_part;
            
            segments.insert(segments.begin() + pos + 1, downstream_part);
            
            sqSum += upstream_part * upstream_part;
            sqSum += downstream_part * downstream_part;
        }
        
        cout << sqSum << endl;
    }
    
    return 0;
}
