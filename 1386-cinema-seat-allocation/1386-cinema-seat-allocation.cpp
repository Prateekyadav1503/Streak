class Solution {
public:
    int maxNumberOfFamilies(int n, std::vector<std::vector<int>>& reservedSeats) {
        int maxGroups = 0;
        std::unordered_map<int, int> rowToSeatsMask;

        // Step 1: Represent the reserved seats of each row using bitmasks
        for (const auto& seat : reservedSeats) {
            int row = seat[0];
            int col = seat[1];
            // Set the bit corresponding to the column (1-indexed to 0-indexed)
            rowToSeatsMask[row] |= (1 << (col - 1));
        }

        // Define masks for the three valid 4-seat blocks (using 0-indexed bits)
        // Seats 2,3,4,5 -> Bits 1,2,3,4 -> 0b0000011110 (binary)
        int leftBlock   = 0b0000011110; 
        // Seats 4,5,6,7 -> Bits 3,4,5,6 -> 0b0001111000 (binary)
        int middleBlock = 0b0001111000; 
        // Seats 6,7,8,9 -> Bits 5,6,7,8 -> 0b0111100000 (binary)
        int rightBlock  = 0b0111100000; 

        // Step 2: Process only the rows that have reservations
        for (const auto& [row, mask] : rowToSeatsMask) {
            bool leftFree   = (mask & leftBlock) == 0;
            bool middleFree = (mask & middleBlock) == 0;
            bool rightFree  = (mask & rightBlock) == 0;

            if (leftFree && rightFree) {
                // If both left and right blocks are completely free, we fit 2 groups
                maxGroups += 2;
            } else if (leftFree || middleFree || rightFree) {
                // If they overlap or conflict, but at least one block is free, we fit 1 group
                maxGroups += 1;
            }
            // If no blocks are free, 0 groups are added for this row
        }

        // Step 3: Add 2 groups for every row that has no reservations at all
        int unreservedRows = n - rowToSeatsMask.size();
        maxGroups += unreservedRows * 2;

        return maxGroups;
    }
};