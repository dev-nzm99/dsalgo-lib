# Greedy Patterns: Interval Merging/Scheduling

## 1. Pattern Overview
Imagine you’re a conference organizer with a list of talks, each with a start and end time. Your job is to schedule them in rooms so that no two talks in the same room overlap, or perhaps to find out when the rooms are free. This is the heart of **Interval Merging/Scheduling**—a greedy pattern that deals with events or tasks that each occupy a span of time or space.

Think of intervals as colored blocks on a timeline. Sometimes, these blocks overlap, and you want to merge them into a single block (like combining overlapping appointments into one). Other times, you want to find gaps (like free time between meetings), or figure out the minimum number of rooms needed so that no two overlapping events share a room.


<p align="center">
  <img src="https://github.com/dev-nzm99/DSA-Pathshala/blob/main/src/img/Overlapping%20Intervals.png" width="90%">
</p>

This pattern is incredibly useful in real-world scenarios:

- `Calendar apps` merging overlapping meetings.
- `CPU scheduling` where jobs must not overlap.
- `Booking systems` for rooms or resources.
- `Finding common free time` among employees.

The key is to process intervals in a way that lets you efficiently answer questions about overlaps, gaps, and groupings. By sorting and scanning through intervals, you can often make greedy decisions—always taking the next best local step (like merging or assigning a room) to reach an optimal solution.

---

## 2. Core Concepts
Let’s break down the main ideas behind interval merging and scheduling:

### 1. Sorting Intervals
**Why sort?** Imagine lining up all your appointments by start time on a whiteboard. This makes it easy to see overlaps and gaps.  
Sorting by start time (or end time, depending on the problem) is almost always the first step.

### 2. Merging Intervals
**Visualize**: As you scan from left to right, if the next interval starts before the previous one ends, they overlap—merge them!  
**Technique**: Keep a "current interval" and compare it to the next. If they overlap, extend the current interval’s end. If not, add the current interval to your result and move on.

### 3. Scheduling Without Overlap
**Greedy allocation**: Assign each interval to a group (like a room) so that no two in the same group overlap.  
**Data structures**: Use a min-heap (priority queue) to track the earliest end time of ongoing intervals. If a new interval starts after the earliest end, reuse the group; otherwise, start a new group.

### 4. Finding Intersections
**Two pointers**: When given two sorted lists of intervals, use two pointers to walk through both, finding where intervals overlap.

### 5. Time and Space Complexity
- **Sorting**: O(N log N), where N is the number of intervals.
- **Scanning/Merging**: O(N), as you process each interval once.
- **Heap operations**: O(log K) per interval, where K is the number of groups/rooms.  

**Analogy**: Think of reading a book page by page (linear scan) versus flipping randomly (inefficient). Sorting lets you process intervals in order, and heaps help you quickly find the next available "slot" (like the soonest available room).

---

## 3. Implementation Approach
Let’s build a mental model for tackling interval merging/scheduling problems:

### Step 1: Identify the Problem Type
- Are you merging overlaps? (e.g., combining busy times)
- Are you assigning groups/rooms? (e.g., scheduling meetings)
- Are you finding intersections or gaps? (e.g., shared free time)

### Step 2: Sort the Intervals
Ask yourself: Should I sort by start or end time?
- **Merging**: Sort by start time.
- **Scheduling**: Often sort by start time, but sometimes end time is useful.

### Step 3: Choose the Right Technique
- **Merging**: Keep a result list and a "current interval." For each interval:
  - If it overlaps with the current, merge.
  - Else, add the current to the result and start a new current.
- **Scheduling/Grouping**: Use a min-heap to track end times.
  - For each interval, if it starts after the earliest end, reuse that group (pop from heap).
  - Else, allocate a new group (push to heap).
- **Intersections**: Use two pointers to walk through both lists, adding overlaps.

### Step 4: Handle Edge Cases
- **Empty input**: What if there are no intervals?
- **Single interval**: Should return as-is.
- **Fully overlapping intervals**: All merge into one.
- **Touching intervals**: Decide if [1,3] and [3,5] are overlapping or not (depends on problem definition).

### Step 5: Validate with Examples
- Draw timelines for small examples.
- Walk through each step as if you’re the computer.

**Decision Tree**:
- Merging? → Sort by start, scan and merge.
- Grouping? → Sort, use min-heap for end times.
- Intersection? → Two pointers.

Remember: Greedy works because at each step, you make the best local choice (merge now, assign to earliest room, etc.), and sorting ensures you never miss an overlap.

---

## 4. Prectice problems

### 🟢 Easy 

| # | Problem | Link | Concept | Difficulty |
|:-:|:---------|:------|:-----------|:------------|
| 1 | **Merge Intervals** | [LeetCode #56](https://leetcode.com/problems/merge-intervals/) | Merge overlapping intervals | 🟢 Easy |
| 2 | **Insert Interval** | [LeetCode #57](https://leetcode.com/problems/insert-interval/) | Insert + merge new interval | 🟢 Easy |
| 3 | **Non-overlapping Intervals** | [LeetCode #435](https://leetcode.com/problems/non-overlapping-intervals/) | Minimum removals to avoid overlap | 🟢 Easy |

##

### 🟡 Medium

| # | Problem | Link | Concept | Difficulty |
|:-:|:---------|:------|:-----------|:------------|
| 4 | **Meeting Rooms** | [LeetCode #252](https://leetcode.com/problems/meeting-rooms/) | Check if all meetings can be attended | 🟡 Medium |
| 5 | **Meeting Rooms II** | [LeetCode #253](https://leetcode.com/problems/meeting-rooms-ii/) | Minimum rooms required | 🟡 Medium |
| 6 | **Employee Free Time** | [LeetCode #759](https://leetcode.com/problems/employee-free-time/) | Common free intervals | 🟡 Medium |
| 7 | **Minimum Number of Arrows to Burst Balloons** | [LeetCode #452](https://leetcode.com/problems/minimum-number-of-arrows-to-burst-balloons/) | Overlap-based greedy grouping | 🟡 Medium |
| 8 | **Interval List Intersections** | [LeetCode #986](https://leetcode.com/problems/interval-list-intersections/) | Two-pointer intersection of intervals | 🟡 Medium |

##

### 🔵 Hard

| # | Problem | Link | Concept | Difficulty |
|:-:|:---------|:------|:-----------|:------------|
| 9 | **Car Pooling** | [LeetCode #1094](https://leetcode.com/problems/car-pooling/) | Sweep line / interval sum check | 🔵 Hard |
| 10 | **My Calendar I** | [LeetCode #729](https://leetcode.com/problems/my-calendar-i/) | Book intervals without overlap | 🔵 Hard |
| 11 | **My Calendar II** | [LeetCode #731](https://leetcode.com/problems/my-calendar-ii/) | Allow double booking, avoid triple | 🔵 Hard |
| 12 | **My Calendar III** | [LeetCode #732](https://leetcode.com/problems/my-calendar-iii/) | Maximum simultaneous overlaps | 🔵 Hard |
| 13 | **Meeting Scheduler** | [LeetCode #1229](https://leetcode.com/problems/meeting-scheduler/) | Find earliest common available slot | 🔵 Hard |
| 14 | **Maximum Profit in Job Scheduling** | [LeetCode #1235](https://leetcode.com/problems/maximum-profit-in-job-scheduling/) | Weighted interval scheduling (DP + Greedy) | 🔵 Hard |

---

