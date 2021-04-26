int check(int mid_value)
{
    // to do fix
    return mid_value;
}

int binary_search1(int q[], int l, int r)
{
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if(check(q[mid])) l = mid;
        else r = mid - 1;
    }
    return l;
}

int binary_search2(int q[], int l, int r)
{
    while (l < r) {
        int mid = l + r >> 1;
        if(check(q[mid])) r = mid;
        else l = mid + 1;
    }
    return l;
}
