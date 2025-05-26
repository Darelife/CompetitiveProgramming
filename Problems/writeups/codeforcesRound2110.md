# Codeforces Round 1026 (Div. 2)

## [A. Fashionable Array](../A_Fashionable_Array.cpp)

An array is fasionable if,
(min(arr) + max(arr))%2==0

try all possible subsets basically. O(n^3) solution

N^2 to get 2 elements (a[i], and a[j]). 
N to find all the elements in its range (between min and max of them....basically if a[i] and a[j] were the min and max elements)

ans = min(ans, n-elementsInItsRange)

## [B. Down with Brackets](../B_Down_with_Brackets.cpp)

We've been given the task to remove 2 brackets (one opening, and one closing) so that the array doesn't stay balanced. Basically if there are any multiple....like, groups {like, ()() = 2 groups, ()()() = 3 groups, (())() = 2 groups....u get the point ig}

so, just keep counting....add 1 if u see an opening bracket, and subtract 1 if u see a closing bracket. If u find ur ans as 0 (unless it's the last element), that means that there are multiple groups....so, "NO", otherwise, "YES"

## [C. Racing](../C_Racing.cpp)

This was a nice question. I initially assumed that it was DP, but i still tried a regular approach, cuz I felt like the contest maker wouldn't instantly jump to a DP question are 2 simple questions.......so here was my approach. Loop from the first to last element, and for each index, maintain the range pair. Basically if D[i] != -1 for it, then, range[i] = {range[i-1].first+D[i], range[i-1].second+D[i]}. Otherwise, make it {range[i-1].first+1, range[i-1].second}. Cuz this will give us the ultimate max range. Also, while doing this, check for 1 more thing. If D[i].first < obstacle's lower limit or D[i].second > obstacle's upper limit. If that's the case, return -1. 

Now, once we have the range, we'll traverse the indices backwards, (i did it cuz i felt like we'd have the most options, cuz the range difference will be the max in the end, and all). So, since at any point, we can't decrease our height, it can only remain the same or increase by 1, we'll make our starting point as the least value in our range, so, it will start from (in 0 based indexing) range[n-1].second. 

Then, as we move backwards, we'll just see if we need to decrease our height (i didn't say increase, as we are moving backwards; from n to 1)...depending on that, and on whether the value of D[i] was -1 or not...we can set our values

## [D. Fewer Batteries](../D_Fewer_Batteries.cpp)

In this question, as soon as I read it, for some reason i instantly though of dijkstra. It took me a while to realize that I was wrong. So, we'll actually need to do 
binary search....and i'll traversed by going to every vertex (eg: 1), and then just checked its edges, then moved to the next vertex (Eg: 2, then 3, ....so on). 

First lets discuss the question, before i move to the solution. So, we've to go from vertex 1 to vertex n. Along the path, at each vertex, we can pick up b[i] batteries. And at every stop, all our batteries get recharged. (It keeps all its collected batteries). Each edge has a weight. And to cross it, we'll need to use weight[i] batteries. Also, it's mentioned that S[i] < T[i]. Which means that the direction of the edges is always from a smaller number to a larger number. So it as to be an acyclic graph. Our task is to reach from 1 to n, with the lease possible batteries in hand. 

We can do a binary search on the maxb (max batteries). We'll try to find the minimum value of maxb so that we never carry more than maxb batteries in our entire journey. (This is a monotonic function, as if we can do it with x batteries, we can definitely do it with x+1 batteries. Therefore, binary search). Also, in this part, instead of doing it from 0 to 1e9, we can just do it for all the weights, as the min value for the maxb has to be the weight (u can only cross an edge if u have (batteries >= weight)).

Now moving to the checker function. 
Lets create an array, (capacity), that stores the number of batteries u'll have after reaching node i.Initialize it with, capacity[0] = min(batteries[0], maxb). Now when we traverse, we'll go to each node, and look at all of the weights of the places we can visit from that node. If that weight <= maxb, then we can cross it. So, capacity[nextNode] = min({capacity[nextNode], maxb, capacity[currentNode]+b[nextNode]). In the end, if capacity[n-1] >= 0, then the path is possible.