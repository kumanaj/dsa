# Problems

LeetCode practice, grouped by NeetCode pattern. Each problem is a stub `class Solution` with the LeetCode signature, so a working solution can be pasted straight into LeetCode.

## How it's organised

- One folder per pattern, numbered in the order of the [NeetCode Blind 75](https://neetcode.io/practice/practice/blind75) page.
- One header per problem, named `<4-digit LeetCode number>_<title>.hpp`, e.g. `01_arrays_hashing/0001_two_sum.hpp`.
- Each header has the problem in short, a link, which lists it belongs to, examples, constraints, and a **My notes** block for your approach and complexity.
- Each `Solution` sits in its own namespace (`lc0001::Solution`). Without it, 75 different `Solution` classes would clash.
- Add whatever `#include`s your solution needs (LeetCode includes everything for you; here you have to).
- `common/` has LeetCode's `ListNode` and `TreeNode`, defined exactly as on LeetCode, plus helpers the tests use to build and free them.
- Design problems (Implement Trie, Find Median, Serialize/Deserialize, ...) use LeetCode's class name instead of `Solution`.
- LeetCode Premium problems link NeetCode's free version and use its signature (e.g. Meeting Rooms takes NeetCode's `Interval`).
- Tests live in `tests/problems/<same folder>/test_<same name>.cpp`, 2–3 cases each.

## Running tests

```bash
cmake -B build && cmake --build build                         # re-run cmake after adding files or folders
ctest --test-dir build -L arrays_hashing --output-on-failure  # one pattern
ctest --test-dir build -L problems                            # every problem
./build/tests/problems_01_arrays_hashing --gtest_filter='TwoSumTest.*'   # one problem
```

A stub throws until you write it, so a problem is solved when all its tests pass.

## Blind 75 progress

75 problems: 19 Easy, 49 Medium, 7 Hard. Mark a problem ✅ when its tests pass. NeetCode 150 problems will be added to the same folders later.

### 01 · Arrays & Hashing

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 217 | [Contains Duplicate](./01_arrays_hashing/0217_contains_duplicate.hpp) | Easy |
| ⬜ | 242 | [Valid Anagram](./01_arrays_hashing/0242_valid_anagram.hpp) | Easy |
| ⬜ | 1 | [Two Sum](./01_arrays_hashing/0001_two_sum.hpp) | Easy |
| ⬜ | 49 | [Group Anagrams](./01_arrays_hashing/0049_group_anagrams.hpp) | Medium |
| ⬜ | 347 | [Top K Frequent Elements](./01_arrays_hashing/0347_top_k_frequent_elements.hpp) | Medium |
| ⬜ | 271 | [Encode and Decode Strings](./01_arrays_hashing/0271_encode_and_decode_strings.hpp) | Medium |
| ⬜ | 238 | [Product of Array Except Self](./01_arrays_hashing/0238_product_of_array_except_self.hpp) | Medium |
| ⬜ | 128 | [Longest Consecutive Sequence](./01_arrays_hashing/0128_longest_consecutive_sequence.hpp) | Medium |

### 02 · Two Pointers

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 125 | [Valid Palindrome](./02_two_pointers/0125_valid_palindrome.hpp) | Easy |
| ⬜ | 15 | [3Sum](./02_two_pointers/0015_three_sum.hpp) | Medium |
| ⬜ | 11 | [Container With Most Water](./02_two_pointers/0011_container_with_most_water.hpp) | Medium |

### 03 · Sliding Window

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 121 | [Best Time to Buy and Sell Stock](./03_sliding_window/0121_best_time_to_buy_and_sell_stock.hpp) | Easy |
| ⬜ | 3 | [Longest Substring Without Repeating Characters](./03_sliding_window/0003_longest_substring_without_repeating_characters.hpp) | Medium |
| ⬜ | 424 | [Longest Repeating Character Replacement](./03_sliding_window/0424_longest_repeating_character_replacement.hpp) | Medium |
| ⬜ | 76 | [Minimum Window Substring](./03_sliding_window/0076_minimum_window_substring.hpp) | Hard |

### 04 · Binary Search

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 153 | [Find Minimum in Rotated Sorted Array](./04_binary_search/0153_find_minimum_in_rotated_sorted_array.hpp) | Medium |
| ⬜ | 33 | [Search in Rotated Sorted Array](./04_binary_search/0033_search_in_rotated_sorted_array.hpp) | Medium |

### 05 · Linked List

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 206 | [Reverse Linked List](./05_linked_list/0206_reverse_linked_list.hpp) | Easy |
| ⬜ | 21 | [Merge Two Sorted Lists](./05_linked_list/0021_merge_two_sorted_lists.hpp) | Easy |
| ⬜ | 143 | [Reorder List](./05_linked_list/0143_reorder_list.hpp) | Medium |
| ⬜ | 19 | [Remove Nth Node From End of List](./05_linked_list/0019_remove_nth_node_from_end_of_list.hpp) | Medium |
| ⬜ | 141 | [Linked List Cycle](./05_linked_list/0141_linked_list_cycle.hpp) | Easy |
| ⬜ | 23 | [Merge k Sorted Lists](./05_linked_list/0023_merge_k_sorted_lists.hpp) | Hard |

### 06 · Stack

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 20 | [Valid Parentheses](./06_stack/0020_valid_parentheses.hpp) | Easy |

### 07 · Trees

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 226 | [Invert Binary Tree](./07_trees/0226_invert_binary_tree.hpp) | Easy |
| ⬜ | 104 | [Maximum Depth of Binary Tree](./07_trees/0104_maximum_depth_of_binary_tree.hpp) | Easy |
| ⬜ | 100 | [Same Tree](./07_trees/0100_same_tree.hpp) | Easy |
| ⬜ | 572 | [Subtree of Another Tree](./07_trees/0572_subtree_of_another_tree.hpp) | Easy |
| ⬜ | 235 | [Lowest Common Ancestor of a Binary Search Tree](./07_trees/0235_lowest_common_ancestor_of_a_binary_search_tree.hpp) | Medium |
| ⬜ | 102 | [Binary Tree Level Order Traversal](./07_trees/0102_binary_tree_level_order_traversal.hpp) | Medium |
| ⬜ | 98 | [Validate Binary Search Tree](./07_trees/0098_validate_binary_search_tree.hpp) | Medium |
| ⬜ | 230 | [Kth Smallest Element in a BST](./07_trees/0230_kth_smallest_element_in_a_bst.hpp) | Medium |
| ⬜ | 105 | [Construct Binary Tree from Preorder and Inorder Traversal](./07_trees/0105_construct_binary_tree_from_preorder_and_inorder_traversal.hpp) | Medium |
| ⬜ | 124 | [Binary Tree Maximum Path Sum](./07_trees/0124_binary_tree_maximum_path_sum.hpp) | Hard |
| ⬜ | 297 | [Serialize and Deserialize Binary Tree](./07_trees/0297_serialize_and_deserialize_binary_tree.hpp) | Hard |

### 08 · Tries

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 208 | [Implement Trie (Prefix Tree)](./08_tries/0208_implement_trie_prefix_tree.hpp) | Medium |
| ⬜ | 211 | [Design Add and Search Words Data Structure](./08_tries/0211_design_add_and_search_words_data_structure.hpp) | Medium |
| ⬜ | 212 | [Word Search II](./08_tries/0212_word_search_ii.hpp) | Hard |

### 09 · Backtracking

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 39 | [Combination Sum](./09_backtracking/0039_combination_sum.hpp) | Medium |
| ⬜ | 79 | [Word Search](./09_backtracking/0079_word_search.hpp) | Medium |

### 10 · Heap / Priority Queue

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 295 | [Find Median from Data Stream](./10_heap/0295_find_median_from_data_stream.hpp) | Hard |

### 11 · Graphs

| | # | Problem | Difficulty |
|---|---|---|---|
| ✅ | 200 | [Number of Islands](./11_graphs/0200_number_of_islands.hpp) | Medium |
| ⬜ | 133 | [Clone Graph](./11_graphs/0133_clone_graph.hpp) | Medium |
| ⬜ | 417 | [Pacific Atlantic Water Flow](./11_graphs/0417_pacific_atlantic_water_flow.hpp) | Medium |
| ⬜ | 207 | [Course Schedule](./11_graphs/0207_course_schedule.hpp) | Medium |
| ⬜ | 261 | [Graph Valid Tree](./11_graphs/0261_graph_valid_tree.hpp) | Medium |
| ⬜ | 323 | [Number of Connected Components in an Undirected Graph](./11_graphs/0323_number_of_connected_components_in_an_undirected_graph.hpp) | Medium |

### 12 · Advanced Graphs

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 269 | [Alien Dictionary](./12_advanced_graphs/0269_alien_dictionary.hpp) | Hard |

### 13 · 1-D Dynamic Programming

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 70 | [Climbing Stairs](./13_1d_dp/0070_climbing_stairs.hpp) | Easy |
| ⬜ | 198 | [House Robber](./13_1d_dp/0198_house_robber.hpp) | Medium |
| ⬜ | 213 | [House Robber II](./13_1d_dp/0213_house_robber_ii.hpp) | Medium |
| ⬜ | 5 | [Longest Palindromic Substring](./13_1d_dp/0005_longest_palindromic_substring.hpp) | Medium |
| ⬜ | 647 | [Palindromic Substrings](./13_1d_dp/0647_palindromic_substrings.hpp) | Medium |
| ⬜ | 91 | [Decode Ways](./13_1d_dp/0091_decode_ways.hpp) | Medium |
| ⬜ | 322 | [Coin Change](./13_1d_dp/0322_coin_change.hpp) | Medium |
| ⬜ | 152 | [Maximum Product Subarray](./13_1d_dp/0152_maximum_product_subarray.hpp) | Medium |
| ⬜ | 139 | [Word Break](./13_1d_dp/0139_word_break.hpp) | Medium |
| ⬜ | 300 | [Longest Increasing Subsequence](./13_1d_dp/0300_longest_increasing_subsequence.hpp) | Medium |

### 14 · 2-D Dynamic Programming

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 62 | [Unique Paths](./14_2d_dp/0062_unique_paths.hpp) | Medium |
| ⬜ | 1143 | [Longest Common Subsequence](./14_2d_dp/1143_longest_common_subsequence.hpp) | Medium |

### 15 · Greedy

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 53 | [Maximum Subarray](./15_greedy/0053_maximum_subarray.hpp) | Medium |
| ⬜ | 55 | [Jump Game](./15_greedy/0055_jump_game.hpp) | Medium |

### 16 · Intervals

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 57 | [Insert Interval](./16_intervals/0057_insert_interval.hpp) | Medium |
| ⬜ | 56 | [Merge Intervals](./16_intervals/0056_merge_intervals.hpp) | Medium |
| ⬜ | 435 | [Non-overlapping Intervals](./16_intervals/0435_non_overlapping_intervals.hpp) | Medium |
| ⬜ | 252 | [Meeting Rooms](./16_intervals/0252_meeting_rooms.hpp) | Easy |
| ⬜ | 253 | [Meeting Rooms II](./16_intervals/0253_meeting_rooms_ii.hpp) | Medium |

### 17 · Bit Manipulation

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 191 | [Number of 1 Bits](./17_bit_manipulation/0191_number_of_1_bits.hpp) | Easy |
| ⬜ | 338 | [Counting Bits](./17_bit_manipulation/0338_counting_bits.hpp) | Easy |
| ⬜ | 190 | [Reverse Bits](./17_bit_manipulation/0190_reverse_bits.hpp) | Easy |
| ⬜ | 268 | [Missing Number](./17_bit_manipulation/0268_missing_number.hpp) | Easy |
| ⬜ | 371 | [Sum of Two Integers](./17_bit_manipulation/0371_sum_of_two_integers.hpp) | Medium |

### 18 · Math & Geometry

| | # | Problem | Difficulty |
|---|---|---|---|
| ⬜ | 48 | [Rotate Image](./18_math_geometry/0048_rotate_image.hpp) | Medium |
| ⬜ | 54 | [Spiral Matrix](./18_math_geometry/0054_spiral_matrix.hpp) | Medium |
| ⬜ | 73 | [Set Matrix Zeroes](./18_math_geometry/0073_set_matrix_zeroes.hpp) | Medium |
