/*
    Lets say you have a target
    you need to make up to the target by either picking an element or not picking an element from the array
    so make a dp table of that target 
    we always do backward loop 
    avoid reuse

    dp[num] = dp[s-num] where s will be the sum/target
*/

/*
    boolean subset problems
    dp[0] = true;
    for each num:
    for s = target → num:
        dp[s] = dp[s] || dp[s - num];
*/

/*
    dp[0] = 1;
    for each num:
    for s = target → num:
        dp[s] += dp[s - num];
*/