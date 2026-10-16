class Solution {
    static const int MOD = 1e9 + 7;

    struct Node {
        long long sum = 0;      
        long long sqSum = 0;    
        long long lazy = 0;     
    };

    vector<Node> tree;

    void apply(int node, int l, int r, long long val)
    {
        long long len = r - l + 1;

        tree[node].sqSum =
            (tree[node].sqSum
            + 2LL * val * tree[node].sum
            + val * val % MOD * len) % MOD;

        tree[node].sum =
            (tree[node].sum + val * len) % MOD;

        tree[node].lazy =
            (tree[node].lazy + val) % MOD;
    }

    void push(int node, int l, int r)
    {
        if(tree[node].lazy == 0 || l == r)
            return;

        int mid = (l + r) / 2;

        apply(node * 2, l, mid, tree[node].lazy);
        apply(node * 2 + 1, mid + 1, r, tree[node].lazy);

        tree[node].lazy = 0;
    }

    void update(int node, int l, int r, int ql, int qr)
    {
        if(qr < l || r < ql)
            return;

        if(ql <= l && r <= qr)
        {
            apply(node, l, r, 1);
            return;
        }

        push(node, l, r);

        int mid = (l + r) / 2;

        update(node * 2, l, mid, ql, qr);
        update(node * 2 + 1, mid + 1, r, ql, qr);

        tree[node].sum =
            (tree[node * 2].sum + tree[node * 2 + 1].sum) % MOD;

        tree[node].sqSum =
            (tree[node * 2].sqSum + tree[node * 2 + 1].sqSum) % MOD;
    }

public:
    int sumCounts(vector<int>& nums) {
        int n = nums.size();

        tree.resize(4 * n);

        unordered_map<int, int> last;

        long long ans = 0;

        for(int i = 0; i < n; i++)
        {
            int prev = -1;

            if(last.find(nums[i]) != last.end())
                prev = last[nums[i]];
            update(1, 0, n - 1, prev + 1, i);
            ans = (ans + tree[1].sqSum) % MOD;

            last[nums[i]] = i;
        }

        return ans;
    }
};