public class Solution {
    /* A HUGE OPTIMIZATION IS ADDING THE ROOM TO VISITED AS SOON AS U GET
     * THE KEY - worst case O(n). If you only add it once you enter, its possible to have
     * the room multiple times in the queue leading to longer runtime
     * and time complexity of O(!n) in worse case since with every while 
     * loop we ensure we'll never add the current room to the queue again.
    */
    public bool CanVisitAllRooms(IList<IList<int>> rooms) {
        HashSet<int> visited = new HashSet<int>();
        Queue<int> toVisit = new Queue<int>();
        toVisit.Enqueue(0);
        visited.Add(0);
        while(toVisit.Count != 0)
        {
            int room = toVisit.Dequeue();
            foreach(int key in rooms[room])
            {
                if(!visited.Contains(key))
                {
                    toVisit.Enqueue(key);
                    visited.Add(key);
                }
            }
            
        }
        return (visited.Count == rooms.Count);
    }
}