public class Solution {
    public bool CanVisitAllRooms(IList<IList<int>> rooms) {
        HashSet<int> visited = new HashSet<int>();
        Queue<int> toVisit = new Queue<int>();
        toVisit.Enqueue(0);
        while(toVisit.Count != 0)
        {
            int room = toVisit.Dequeue();
            visited.Add(room);
            foreach(int key in rooms[room])
            {
                if(!visited.Contains(key))
                {
                    toVisit.Enqueue(key);
                }
            }
            
        }
        
        return (visited.Count == rooms.Count);
    }
}