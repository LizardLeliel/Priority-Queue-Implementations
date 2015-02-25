Priority Queue Implementations
==============================

This short program has various implementations for priority queues defined.
Which implementation is to be used can be selected at compile time (by changing a macro - I plan to change this soon so the algorithms can be selected at run time).

The purpose of this is to not only have a code demonstration of each implementation, but as well as compare the efficiency of implementations.



Implementation Timings and Averages (user time only)
====================================================

Unsorted circular lists
-----------------------

For 5 sets of 100,000 random inputs, the times reported are: <br>
36.342s, 35.169s, 35.687s, 35.560s, 35.835s <br>
Average: 35.719 seconds

Sorted linear lists
-------------------

For 10 sets of 100,000 random inputs, the times reported are: <br>
58.81s, 59.44s, 65.07s 68.24s 78.28s, 79.01s, 65.81s, 62.00s, 61.71, 74.86s <br>
Average: 67.32 seconds
