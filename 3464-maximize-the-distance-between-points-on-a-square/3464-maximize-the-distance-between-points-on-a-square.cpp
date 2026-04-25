class Solution {
public:
    public:
    long long map_point(long long x, long long y, long long side) {
        if (y == 0) return x;                                      
        if (x == side) return side + y;                            
        if (y == side) return 2LL * side + (side - x);             
        if (x == 0) return 3LL * side + (side - y);                
        return 0; 
    }

    bool check(long long D, const vector<long long>& unrolled, int N, int k, long long L) {
        int M = 2 * N;
        vector<int> nxt(M, M);
        
        int j = 0;
        for (int i = 0; i < M; ++i) {
            j = max(j, i + 1); 
            while (j < M && unrolled[j] - unrolled[i] < D) {
                j++;
            }
            if (j < M) {
                nxt[i] = j;
            }
        }
        
        for (int i = 0; i < N; ++i) {
            int curr = i;
            int count = 1;
            
            for (int step = 1; step < k; ++step) {
                curr = nxt[curr];
                if (curr >= M) break;
                count++;
            }
            
            if (count == k && curr < M && unrolled[i] + L - unrolled[curr] >= D) {
                return true;
            }
        }
        return false;
    }
    int maxDistance(int side, vector<vector<int>>& points, int k) {
        int N = points.size();
        vector<long long> arr(N);
        
        for (int i = 0; i < N; ++i) {
            arr[i] = map_point(points[i][0], points[i][1], side);
        }
        
        sort(arr.begin(), arr.end());
        
        long long L = 4LL * side;
        vector<long long> unrolled(2 * N);
        
        for (int i = 0; i < N; ++i) {
            unrolled[i] = arr[i];
            unrolled[i + N] = arr[i] + L;
        }

        long long low = 0, high = side;
        long long ans = 0;
        
        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (check(mid, unrolled, N, k, L)) {
                ans = mid;
                low = mid + 1; 
            } else {
                high = mid - 1; 
            }
        }
        
        return ans;
    }
};