class NestedIterator {
public:
    stack<NestedInteger> st;

    NestedIterator(vector<NestedInteger> &nestedList) {
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    void makeTopReady() {
        while (!st.empty() && !st.top().isInteger()) {
            vector<NestedInteger> lst = st.top().getList();
            st.pop();

            for (int i = lst.size() - 1; i >= 0; i--) {
                st.push(lst[i]);
            }
        }
    }

    int next() {
        makeTopReady();
        int val = st.top().getInteger();
        st.pop();
        return val;
    }

    bool hasNext() {
        makeTopReady();
        return !st.empty();
    }
};