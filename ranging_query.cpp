/*
    Time Complexity: O( ( Q * log( N ) ) + N )
    Space Complexity: O( N )

    where Q and N denote the number of queries and size of the array respectively.
*/

// Recursive function to find the minimum element in the [rangeL, rangeH].
int minQuery(int curNode, int rangeL, int rangeH, int queryL, int queryH, vector < int > & segTree) {
    // If [rangeL, rangeH] lies completely inside [queryL, queryR].
    if (queryL <= rangeL && rangeH <= queryH) {
        return segTree[curNode];
    }

    // If [rangeL, rangeH] lies completely outside [queryL, queryR].
    if (queryL > rangeH || queryH < rangeL) {
        return INT_MAX;
    }

    // Variable to store mid point of the current range.
    int mid = (rangeL + rangeH) / 2;

    // Recursive call to both the children nodes.
    return min(minQuery(2 * curNode, rangeL, mid, queryL, queryH, segTree),
        minQuery(2 * curNode + 1, mid + 1, rangeH, queryL, queryH, segTree));;
}


vector < int > rangeMinimumQuery(int n, vector < int > arr, int q, vector < vector < int >> query) {

    // Run a while loop, and insert INT_MAX until size of array is not equal to 2^X - 1.
    // __builtin_popcount(N) tells the number of ON bits in binary representation of ‘N’,
    // directly use it and end the while loop when __builtin_popcount(N) is equal to 1.
    while (__builtin_popcount(n) != 1) {
        arr.push_back(INT_MAX);
        n++;
    }

    // Declare 'segTree' to store the segment tree.
    vector < int > segTree;
    segTree.resize(2 * n);

    // Fill the last 'N' positions with the elements of 'ARR'.
    for (int i = 0; i < n; i++) {
        segTree[i + n] = arr[i];
    }

    // Fill the remaining positions of 'segTree'.
    for (int i = n - 1; i >= 1; i--) {
        segTree[i] = min(segTree[2 * i], segTree[2 * i + 1]);
    }

    // Array to store the minimum element for each query.
    vector < int > ans;

    // Process queries.
    for (int i = 0; i < q; i++) {
        // Left end of the current query.
        int l = query[i][0];

        // Right end of the current query.
        int r = query[i][1];

        // Initial call to the recursive function 'minQuery'.
        ans.push_back(minQuery(1, 0, n - 1, l, r, segTree));
    }

    // Finaly, return 'ans'.
    return ans;

}