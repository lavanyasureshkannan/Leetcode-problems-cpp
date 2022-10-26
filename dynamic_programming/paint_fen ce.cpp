class Solution {
    public int numWays(int n, int k) {
        if (n == 1) return k;
        
        int twoPostsBack = k;
        int onePostBack = k * k;
        
        for (int i = 3; i <= n; i++) {
            int curr = (k - 1) * (onePostBack + twoPostsBack);
            twoPostsBack = onePostBack;
            onePostBack = curr;
        }
        
        return onePostBack;
    }
}

/*
Initialize two variables, twoPostsBack and onePostBack, that represent the number of ways to paint the previous two posts. Since we start iteration from post three, twoPostsBack initially represents the number of ways to paint one post, and onePostBack initially represents the number of ways to paint two posts. Set their values twoPostsBack = k, onePostBack = k * k, because they are equivalent to our base cases..

Iterate n - 2 times. At each iteration, simulate moving i up by one. Use the recurrence relation to calculate the number of ways for the current step and store it in a variable curr. "Moving up" means twoPostsBack will now refer to onePostBack, so update twoPostsBack = onePostBack. onePostBack will now refer to the current step, so update onePostBack = curr.

In the end, return onePostBack, since "moving up" after the last step would mean onePostBack is the number of ways to paint n fence posts.


*/