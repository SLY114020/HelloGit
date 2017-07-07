// 59ms
int arrayPairSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> hash(20001,0);
        for (int i=0; i<n; i++){ hash[nums[i]+10000] += 1; }
        int i = 0;
        int ans = 0;
        int temp = 0;
        while (1){
        	while ((i<20001)&&(hash[i]==0)) i++;
            if (i==20001) break;
            int w = i-10000;
            int n = hash[i];
            if (n%2==0) { ans += (n/2)*w; } else{
                if (temp==0) { ans += (n/2+1)*w; temp = 1;} else{
                    ans += (n/2)*w; temp = 0;
                }
            }
            i++;
        }
        return ans;
    }
	
	
//56ms
	int arrayPairSum(vector<int>& nums) {
    array<int, 20001> buckets{0};

    auto max = -10000;
    auto min = 10000;
    for (auto v : nums) {
        ++buckets[v + 10000]; // right shift [-10000, 10000] to [0, 20000]
        if (v < min) {
            min = v;
        }
        if (max < v) {
            max = v;
        }
    }

    auto sum = 0;
    auto jump = 0;
    for (int i = min + 10000; i <= max + 10000; ++i) {
        if (buckets[i]) {
            auto count = (buckets[i] - jump + 1) / 2;
            sum += (i - 10000) * count;
            jump = (buckets[i] - jump) % 2;
        }
    }
    return sum;
   
    }