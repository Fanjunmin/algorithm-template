struct seg_tree {
    int l, r;
    int val;
};
class NumArray {
private:
    vector<seg_tree> st;
    void _build_tree(int p, int l, int r, const vector<int>& nums) {
        st[p].l = l, st[p].r = r;
        if (l == r) {
            st[p].val = nums[l];
            return;
        }
        int mid = (l + r) >> 1;
        int l_node = 2 * p + 1, r_node = 2 * p + 2;
        _build_tree(l_node, l, mid, nums);
        _build_tree(r_node, mid + 1, r, nums);
        st[p].val = st[l_node].val + st[r_node].val;
    }
    void _update(int p, int index, int val) {
        if (st[p].l == st[p].r) {
            st[p].val = val;
            return;
        };
        int mid = (st[p].l + st[p].r) >> 1;
        int l_node = 2 * p + 1, r_node = 2 * p + 2;
        if (index <= mid) _update(l_node, index, val);
        else _update(r_node, index, val);
        st[p].val = st[l_node].val + st[r_node].val;
    }
    int _query(int p, int l, int r) {
        if (st[p].l >= l && st[p].r <= r) return st[p].val;
        int mid = (st[p].l + st[p].r) >> 1;
        int l_node = 2 * p + 1, r_node = 2 * p + 2;
        int val = 0;
        if (l <= mid) val += _query(l_node, l, r);
        if (r > mid) val += _query(r_node, l, r);
        return val;
    }
public:
    NumArray(vector<int>& nums) {
        int len = nums.size();
        st.resize(len * 4);
        _build_tree(0, 0, len - 1, nums);
    }
    
    void update(int index, int val) {
        // cout << index << ", " << val << endl;
        _update(0, index, val);
    }
    
    int sumRange(int left, int right) {
        return _query(0, left, right);
        // return 0;
    }
};

/**
 * Your NumArray object will be instantiated and called as such:
 * NumArray* obj = new NumArray(nums);
 * obj->update(index,val);
 * int param_2 = obj->sumRange(left,right);
 */